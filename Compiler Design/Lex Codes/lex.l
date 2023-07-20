%{
#include<stdio.h>
%}
%%
"Hi" {printf("Hi");}
.* {printf("Bye");} 
%%
int yywrap(){
return 1;
}
int main(){
printf("enter the string: ");
yylex();
return 0;
}