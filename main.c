#include "header.h" 
int main(int argc,char* argv[])
{
    if( argc < 2)
    {
        printf("Invalid Arguments\n");
        return 1;
    }
    read_fun(argv[1]);
    return 0;
}