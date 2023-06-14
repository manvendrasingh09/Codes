%{
    #include <stdio.h>
    #include <string.h>
    int valid = 1;
%}

%%
A|B|AB|O {}
A[B+-]|B[B+-]|AB[B+-]|O[B+-] {}
. {valid=0;}
%%

int yywrap(){return 1;}

int main() {
    yylex();
    if(valid)
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
    return 0;
}