%{
#include<stdio.h>
%}
%%
"Hi" {printf("Hi");}
"Bye" {printf("Bye");} 
%%
int yywrap(){
return 1;
}
int main(){
printf("enter the string");
yylex();
return 0;
}