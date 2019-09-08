/*
 * Program Name: lefc (Line Ending File Converter)
 * File Name:    main.c
 * Purpose:      To convert text files between unix-style line endings and 
 *               windows style line endings.
 * Description:  Takes a file and outputs the converted line endings to stdout,
                 which can then be redirected to a file.
 *
 * Author:       James Olsen
 * Date:         8 September 2019
 */

#include <stdio.h>

/* Prints each character in a file adding a carriage return before each 
   newline. */
void unix_to_windows(FILE *f) {
    char c;

    do {
        c = fgetc(f);
        
        if (c == '\n') {
            printf("\r");
        }
        
        printf("%c", c);
    } while (c != EOF);
}

/* Prints each character in a file ignoring carriage returns. */
void windows_to_unix(FILE *f){
    char c;

    do {
        c = fgetc(f);

        if (c != '\r') {
            printf("%c", c);
        }
    } while (c != EOF);
}

int main(int argc, char **argv) {
    FILE *src;
    int file_index;
    int to_windows_flag = 0;
    
    /* Handling arguments. */
    switch (argc) {
        case 1:
            fprintf(stderr, "%s: No input file aruguement.\n", argv[0]);
            return 1;
            break;
        case 2:
            file_index = 1;
            break;
        case 3:
            file_index = 2;
            if (argv[1][1] == 'w') {
                to_windows_flag = 1;
            }
            break;
    }
    
    /* Opening file, and displaying error if unable to open. */
    src = fopen(argv[file_index], "r");
    if (src == NULL) {
        fprintf(stderr, "%s: Unable to open file.\n", argv[0]);
        return 1;
    }
    
    /* Convert line endings.  */
    if (to_windows_flag){
        unix_to_windows(src);
    }
    else {
        windows_to_unix(src);
    }
    
    fclose(src);
        
    return 0;
}
