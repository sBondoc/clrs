/* "util.h" - Prototypes for utility functions. */
#ifdef UTIL_H
#define UTIL_H

/* Print int array */
void fprintarr_int(FILE *stream, int *arr, int size);

/* Print char array */
void fprintarr_char(FILE *stream, char *arr, int size);

/* Print str (char *) array */
void fprintarr_str(FILE *stream, char **arr, int size);
#endif
