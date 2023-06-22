%{
#include "y.tab.h"
%}
%%
[A-Z]{5}            { yylval.str = strdup(yytext); return FIRST_FIVE; }
[0-9]{4}            { yylval.str = strdup(yytext); return NEXT_FOUR; }
[A-Z]               { yylval.ch = yytext[0]; return LAST_CHAR; }
\n                  { return EOL; }
[ \t]               ;  
.                   { printf("Invalid character: %s\n", yytext); }
%%
int yywrap() {
    return 1;
}
