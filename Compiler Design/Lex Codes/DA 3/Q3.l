%{
#include <stdio.h>
int wordCount = 0;
%}

%option noyywrap

%%
[a-zA-Z]+ {
    int vowels = 0;
    int i;
    for (i = 0; i < yyleng; i++) {
        if (yytext[i] == 'a' || yytext[i] == 'e' || yytext[i] == 'i' || yytext[i] == 'o' || yytext[i] == 'u' ||
            yytext[i] == 'A' || yytext[i] == 'E' || yytext[i] == 'I' || yytext[i] == 'O' || yytext[i] == 'U') {
            vowels++;
        }
    }
    if (vowels >= 2) {
        printf("%s\n", yytext);
        wordCount++;
    }
}
.|\n  { ; }
%%

int main() {
    printf("Enter the String: ");
    yylex();
    printf("Total words with at least two vowels: %d\n", wordCount);
    return 0;
}