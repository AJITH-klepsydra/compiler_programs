%{
int line_count=0, word_c=0, char_c=0;
%}


%%
\n {line_count++;}
([a-zA-Z]+[ |;|,|=|(\n)]) {word_c++;printf("Word: Detected %s\n",yytext);}
. char_c++;
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
    printf("\n: %d %d %d",line_count,word_c,char_c);
    return(0);
}
int yywrap()
{
    return(1);
}