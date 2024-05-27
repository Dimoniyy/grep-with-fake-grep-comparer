#ifndef C3_SIMPLEBASHUTILS_GREP_HEADERS_S21_GREP_H_
#define C3_SIMPLEBASHUTILS_GREP_HEADERS_S21_GREP_H_

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#define MATCHING_FILES_ONLY 0x1        // -l
#define CASE_INSENSITIVE 0X2           // -i
#define INVERT_MATCH 0x4               // -v
#define OUTPUT_COUNT 0X8               // -c
#define NO_FILENAME_OUTPUT 0x10        // -h
#define PROCEED_LINE_NUM 0x20          // -n
#define SUPPRESS_FILENAME_ERRORS 0x40  // -s
#define ONLY_MATCHING_PARTS_LINE 0x80  // -o

extern int fileHandler(const int arguments, regex_t reegex, FILE* stream, char* filename);
extern int argumentsWrite(char);
extern regex_t setupReegex(FILE*, const int);
extern void printUsage(void);
extern char* setupQuery(const char* query);
extern int loadQueryFileFromAnother(FILE* dest, const char* file_with_query_name);

#endif
