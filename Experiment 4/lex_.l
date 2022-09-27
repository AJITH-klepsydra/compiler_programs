%{
#include<string.h>
int v_c = 0, c_c = 0;
%}
%%
["][a-zA-Z]+["] {
    for(int i=0;i<strlen(yytext);i++){

        if(yytext[i] != '\"'){
            if (yytext[i] == 'a' || yytext[i] == 'e' || yytext[i] == 'i' || yytext[i] == 'o' || yytext[i] == 'u' ){
                v_c++;
            }
            else{
                c_c++;
            }
        }
    }
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
    printf("\nVowel count:%d\nConsonant count:%d\n",v_c,c_c);
    return(0);
}
int yywrap()
{
    return(1);
}