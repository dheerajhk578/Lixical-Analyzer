#include "header.h"
char *keywords[32] = { "int","float","char","double","signed","unsigned","long",
    "short","volatile","const","for","while","do","break","goto","continue",
    "if","else","switch","case","default","auto","static","register",
    "extern","struct","union","enum","typedef","void","return","sizeof"};
    
    void identifier_keyword(char *str)
    {
        if(strlen(str) > 1 && keyword(str))
        {
            printf("%-22s : %s\n","keyword",str);
            str[0] = '\0';
        }
        else if(strlen(str) >= 1)
        {
            printf("%-22s : %s\n","Identifier",str);
            str[0] = '\0';
        }
    }
    void litral(char *str, char ch,FILE *fptr)
    {
        ch = fgetc(fptr);
        for(int i = 0; i < 50; i++,ch = fgetc(fptr))
        {
            str[i] = ch;
            if(ch == '"')
            {
                str[i] = '\0';
                break;
            }
        }
        printf("%-22s : %s\n","Litral",str);
        str[0] = '\0';
    }
    int keyword(char *str)
    {
        for(int i = 0; i<32; i++)
        {
            if(!strcmp(keywords[i],str))
            {
                return 1;
            }
        }
        return 0;
    }
    int hexadecimal(char *str)
    {
        int count = 0;
        for(int i = 0; str[i];i++)
        {
            if(str[i] == 'X' || str[i] == 'x')
            {
                count++;
            }
        }
        if(count == 1)
            return 0;
        else
            return 1;
    }
    int binary(char *str)
    {
        int count = 0;
        for(int i = 0; str[i];i++)
        {
            if(str[i] == 'B' || str[i] == 'b')
            {
                count++;
            }
        }
        int i;
        int flag = 0;
        for(i = 2; str[i];i++)
        {
            if(str[i] != '0' && str[i] != '1')
            {
                flag = 1;
                break;
            }
        }
        if(count > 1 || flag)
        {
                return 1;
        }
            else
            {
                return 0;
            }
        }
    int octal(char *str)
    {
        int count = 0;
        for(int i = 0; str[i]; i++)
        {
            if(!(str[i] >= '0' && str[i] <= '7'))
            {
                return 1;
            }
        }
        return 0;
    }