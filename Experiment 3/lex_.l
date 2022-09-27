%{
#include<string.h>
int count = 0;
%}
%%
abc {
    strcpy(yytext,"ABC");
    printf("%s",yytext);
}
%%

int main(int argc, char **argv)
{
    FILE *file;
    file=fopen("var.c","r");
    if(!file)
    {
        printf("could not open the file");
        exit(0);
    }
    yyin=file;
    yylex();

    return(0);
}
int yywrap()
{
    return(1);
}