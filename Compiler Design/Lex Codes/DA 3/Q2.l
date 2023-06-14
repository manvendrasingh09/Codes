%{
#include <stdio.h>
#include <string.h>

int operatorCount = 0;
int identifierCount = 0;
int keywordCount = 0;
int specialSymbolCount = 0;

int isKeyword(char* str) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    int i;
    int totalKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (i = 0; i < totalKeywords; i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }

    return 0;
}
%}

%option noyywrap

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" { keywordCount++; }
"=="|"!="|"<"|">"|"<="|">="|"+="|"-="|"*="|"/="|"%="|"<="|">="|"+="|"-="|"++"|"--"|"&&"|"||"|"!"|"+"|"-"|"*"|"/"|"%"|">>"|"<<"
"("|")"|"{"|"}"|"["|"]"|","|";"|":" { operatorCount++; }
[a-zA-Z_][a-zA-Z0-9_]* { 
    if (isKeyword(yytext) == 0) {
        identifierCount++;
    }
}
[ \t\n]  { ; }
.  { specialSymbolCount++; }
%%

int main() {
    printf("Enter the C Program: \n");
    yylex();
    printf("Operator count: %d\n", operatorCount);
    printf("Identifier count: %d\n", identifierCount);
    printf("Keyword count: %d\n", keywordCount);
    printf("Special symbol count: %d\n", specialSymbolCount);

    return 0;
}