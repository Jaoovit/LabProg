/** With error */

/* arquivo.h */

int calculator(int x);

#endif

/** Without error */

#ifndef BUG_CALCULATOR_H
#define BUG_CALCULATOR_H

int calculator(int x);

#endif


/**
 * The error in the file results from the incorrect use of header guards.
 * There is an #endif without a corresponding conditional directive (#ifndef or #ifdef),
 * which constitutes a syntax error in the preprocessor. Even before the C compilation
 * phase begins, the preprocessor analyzes the directives and, upon finding a standalone
 * #endif, stops with an error. The correction involves wrapping the header content inside
 * a proper #ifndef / #define / #endif block, ensuring the file is included only once per
 * compilation unit. This prevents redefinitions and conflicts when the header is included multiple times.
 */