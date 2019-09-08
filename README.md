# lefc (Line Endings File Converter)
Simple program to convert between unix and windows style line endings.

## Usage
The program takes a file and then outputs the converted file to stdout, which can then be redirected to a file.

### Convert from Windows to Unix
`./lefc [FILE] > [OUTPUT_FILE]`

### Convert from Unix to Windows
`./lefc -w [FILE] > [OUTPUT_FILE]`  

## Compilation
`gcc -ansi -pedantic -Wall -o lefc main.c`

