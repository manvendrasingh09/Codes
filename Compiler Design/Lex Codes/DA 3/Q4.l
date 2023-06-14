%{
#include <stdio.h>
%}

%option noyywrap

%%
[cC][a-zA-Z]*[tT] {
    printf("%s\n", yytext);
}
[a-zA-Z]+  { ; }
.  { ; }
%%

int main() {
    printf("Enter the String: ");
    yylex();
    return 0;
}