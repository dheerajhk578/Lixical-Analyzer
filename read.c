#include "header.h"

int flag = 0;
int real_flag = 0, real_flag1 = 0, pre_flag = 0;
int curve_flag = 0, square_flag = 0, flower_flag = 0, line = 1;
char ch;

int read_fun(char *code)
{
    FILE *fptr = fopen(code, "r");
    if (fptr == NULL)
    {
        printf("Open failed!\n");
        return 1;
    }

    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch == '#' && pre_flag == 0)
        {
            printf("%-22s : %c", "PreProcessor Line", ch);
            while ((ch = fgetc(fptr)) != '\n' && ch != EOF)
                printf("%c", ch);
            printf("\n");
            continue;
        }

        char str[100];

        if (isalpha(ch))
        {
            pre_flag++;
            for (int i = 0; i < 99; i++, ch = fgetc(fptr))
            {
                if (isalnum(ch))
                    str[i] = ch;
                else
                {
                    str[i] = '\0';
                    break;
                }
            }
            identifier_keyword(str);
        }

        flag = 0;
        real_flag = 2;

        if (isdigit(ch))
        {
            pre_flag++;
            for (int i = 0; i < 99; i++, ch = fgetc(fptr))
            {
                if (ch == '.')
                {
                    str[i] = ch;
                    i++;
                    while ((ch = fgetc(fptr)) != EOF)
                    {
                        if (isdigit(ch))
                            str[i] = ch;
                        else if (ch == ' ' || ch == ';' || ch == '\n' || ch == ',' ||
                                 ch == ')' || ch == '(' || ch == '{' || ch == '}' ||
                                 ch == '[' || ch == ']')
                        {
                            str[i] = '\0';
                            real_flag = 0;
                            break;
                        }
                        else
                        {
                            str[i] = ch;
                            real_flag1 = 1;
                        }
                        i++;
                    }
                    if (real_flag == 0)
                        break;
                }
                else if (isdigit(ch) || ch == 'x' || ch == 'X' ||
                         (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))
                {
                    str[i] = ch;
                }
                else if (ch == ' ' || ch == ';' || ch == '\n' || ch == ',' ||
                         ch == ')' || ch == '(' || ch == '{' || ch == '}' ||
                         ch == '[' || ch == ']')
                {
                    str[i] = '\0';
                    break;
                }
                else if ((ch >= 'G' && ch <= 'Z') || (ch >= 'g' && ch <= 'z'))
                {
                    str[i] = ch;
                    flag = 1;
                }
                else
                {
                    str[i] = '\0';
                    break;
                }
            }

            if (real_flag1 == 1)
            {
                printf("%-22s : %s\n", "Integer Value", str);
                printf("ERROR! : Invalid Number\n");
                real_flag1 = 0;
                continue;
            }

            if (flag == 1)
            {
                printf("%-22s : %s\n", "Numerical", str);
                printf("ERROR : Invalid Real Number\n");
                flag = 0;
                continue;
            }

            if (real_flag == 0)
            {
                printf("%-22s : %s\n", "Real Number", str);
                str[0] = '\0';
            }
            else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X') && strlen(str) > 2)
            {
                if (hexadecimal(str))
                {
                    printf("%-22s : %s\n", "Hexadecimal Number", str);
                    printf("ERROR : Hexadecimal Value Error\n");
                    continue;
                }
                printf("%-22s : %s\n", "Hexadecimal Number", str);
            }
            else if (str[0] == '0' && (str[1] == 'b' || str[1] == 'B') && strlen(str) > 2)
            {
                if (binary(str))
                {
                    printf("%-22s : %s\n", "Binary Number", str);
                    printf("ERROR: Binary Value Error!\n");
                    continue;
                }
                printf("%-22s : %s\n", "Binary Number", str);
            }
            else if (str[0] == '0' && strlen(str) > 2)
            {
                if (octal(str))
                {
                    printf("%-22s : %s\n", "Octal Number", str);
                    printf("ERROR : Octal Value Error\n");
                    continue;
                }
                printf("%-22s : %s\n", "Octal Number", str);
            }
            else
            {
                printf("%-22s : %s\n", "Integer Value", str);
                str[0] = '\0';
            }
        }

        if (ch == '"')
        {
            litral(str, ch, fptr);
        }

        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
            ch == ';' || ch == '[' || ch == ']' || ch == ',')
        {
            printf("%-22s : %c\n", "Special Character", ch);
            pre_flag++;
        }

        if (ch == '(')
            curve_flag++;
        else if (ch == ')')
            curve_flag--;

        if (ch == '[')
            square_flag++;
        else if (ch == ']')
            square_flag--;

        if (ch == '{')
            flower_flag++;
        else if (ch == '}')
            flower_flag--;

        if (ch == '\n')
        {
            if (curve_flag < 0 || square_flag < 0)
            {
                printf("ERROR : Error in line number %d\n", line);
                curve_flag = square_flag = 0;
            }
            pre_flag = 0;
            line++;
        }

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '&' || ch == '|')
        {
            printf("%-22s : %c\n", "Operator", ch);
            pre_flag++;
        }
    }

    if (flower_flag)
        printf("ERROR: Flower Bracket Closing Error\n");

    fclose(fptr);
    return 0;
}
