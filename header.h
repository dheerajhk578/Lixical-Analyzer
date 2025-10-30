#ifndef header_h
#define header_h

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdio_ext.h>

int keyword(char* str);
int read_fun(char *filename);
int hexadecimal(char *str);
int binary(char *str);
int octal(char *str);
void identifier_keyword(char *str);
void litral(char *str,char ch,FILE *fptr);


#endif