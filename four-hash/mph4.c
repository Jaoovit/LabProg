#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>

// macros
// Maximum number of worker processes np
#define MAXPROC 8
#define LIMIT (10LL * 1024 * 1024 * 1024)

int main(int argc, char *argv[])
{
	/**
	 * Command line execution example: ./mph4 4
	 *
	 *	argc: 2
	 * 	argv[0]: ./mph4
	 *  argv[1]: 4
	 *
	 * argc is 2 because there are 2 arguments: "./mph4" and "4"
	 */
	int np = 1;

	// If there are 2 or more arguments in program execution
	if (argc > 1)
	{
		np = atoi(argv[1]);
		if (np < 1)
		{
			np = 1;
		}
		if (np > MAXPROC)
		{
			np = MAXPROC;
		}
	}

	// Variable to store the file name that will be read
	char file_name[256];

	if (scanf("%255s", file_name) != 1)
	{
		return 1;
	}

	// Open the file in binary read mode
	FILE *file = fopen(file_name, "rb");
	if (file == NULL)
	{
		return 1;
	}

	// Move pointer to end of file to determine its size
	fseek(file, 0, SEEK_END);
	long long size = ftell(file);
	rewind(file);

	if (size > LIMIT)
	{
		fclose(file);
		return 1;
	}

	// Number of blocks assigned to each process
	long long total_blocks = (size + 3) / 4;

	int pipes[MAXPROC][2];
	pid_t pid;

	/**
	 * Parallel processing, where each process is responsible for reading its block
	 */
	for (int i = 0; i < np; i++)
	{
		// Create pipe for communication between child and parent
		if (pipe(pipes[i]) == -1)
		{
			return 1;
		}

		pid = fork();

		if (pid == -1)
		{
			return 1;
		}

		if (pid == 0)
		{
			close(pipes[i][0]);

			FILE *file = fopen(file_name, "rb");
			if (file == NULL)
			{
				exit(0);
			}

			/**
			 * Using unsigned to restrict values between 0 and 255
			 * Minimum byte value: 00000000 = 0
			 * Maximum byte value: 11111111 = 255
			 *
			 * The buffer stores blocks of 4 bytes
			 */
			unsigned char buffer[4];
			uint32_t hash_accumulator = 0;
			long long blocks_per_process = total_blocks / np;

			/**
			 * Defines where each process starts reading the file
			 */
			long long start = i * blocks_per_process;

			/**
			 * Defines where each process stops reading
			 * The last process gets the remaining blocks
			 */
			long long end = (i + 1) * blocks_per_process;

			if (i == np - 1)
			{
				end = total_blocks;
			}

			fseek(file, start * 4, SEEK_SET);

			for (long long b = start; b < end; b++)
			{
				size_t bytes_read = fread(buffer, 1, 4, file);

				// If fewer than 4 bytes, pad with zeros
				for (int j = bytes_read; j < 4; j++)
				{
					buffer[j] = 0;
				}

				/**
				 * Store buffer into a 4-byte block
				 */
				uint32_t block =
					((unsigned int)buffer[0]) |
					((unsigned int)buffer[1] << 8) |
					((unsigned int)buffer[2] << 16) |
					((unsigned int)buffer[3] << 24);

				hash_accumulator ^= block;
			}

			fclose(file);

			// Send partial hash to parent
			write(pipes[i][1], &hash_accumulator, sizeof(hash_accumulator));
			close(pipes[i][1]);

			exit(0);
		}

		close(pipes[i][1]);
	}

	// Parent process aggregates results from children
	uint32_t final_result = 0;

	for (int i = 0; i < np; i++)
	{
		uint32_t value = 0;

		read(pipes[i][0], &value, sizeof(value));
		close(pipes[i][0]);

		final_result ^= value;
	}

	for (int i = 0; i < np; i++)
	{
		wait(NULL);
	}

	// Correct format: 8 hex digits separated into two groups of 4
	printf("hash4= %04X %04X\n",
		   (final_result >> 16) & 0xFFFF,
		   final_result & 0xFFFF);

	return 0;
}

// EOF