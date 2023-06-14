%{
#include <stdio.h>
int vowelCount = 0;
int consonantCount = 0;
%}

%option noyywrap

%%
[aAeEiIoOuU]  { vowelCount++; }
[^aAeEiIoOuU\n]  { consonantCount++; }
\n  { printf("Vowel count: %d\nConsonant count: %d\n", vowelCount, consonantCount); }
.|\n  { ; }
%%

int main() {
    printf("Enter the string of vowels and consonants:");
    yylex();
    printf("Number of vowels are: %d\n", vowelCount);
    printf("Number of consonants are: %d\n", consonantCount);
    return 0;
}