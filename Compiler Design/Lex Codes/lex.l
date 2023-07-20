%{
#include<stdio.h>
%}
%%
"<"[^>]*> {printf("%s\n", yytext); }
. ;
%%
int yywrap(){}
int main()
{
yyin = fopen("input.txt","r");
yylex();
return 0;
}