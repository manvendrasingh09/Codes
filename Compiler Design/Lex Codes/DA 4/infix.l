%{
#include "infix.tab.h"
%}
%%
[ \t\n]       ; 
[0-9]+        { yylval = atoi(yytext); return NUMBER; }
[+\-*/()]     { return yytext[0]; }
.             { return yytext[0]; } 
%%
int yywrap() {
    return 1;
}