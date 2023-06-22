%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
%token FIRST_FIVE NEXT_FOUR LAST_CHAR EOL
%%
pan:
    FIRST_FIVE NEXT_FOUR LAST_CHAR EOL    { 
        if (strlen($1) == 5 && strlen($2) == 4 && strlen($3) == 1) {
            int i;
            for (i = 0; i < 5; i++) {
                if (!isupper($1[i])) {
                    printf("Invalid PAN number: First five characters should be uppercase alphabets\n");
                    exit(1);
                }
            }
            for (i = 0; i < 4; i++) {
                if (!isdigit($2[i])) {
                    printf("Invalid PAN number: Next four characters should be numbers\n");
                    exit(1);
                }
            }
            if (!isupper($3[0])) {
                printf("Invalid PAN number: Last character should be an uppercase alphabet\n");
                exit(1);
            }
            printf("Valid PAN number\n");
        } else {
            printf("Invalid PAN number: PAN number should be 10 characters long\n");
            exit(1);
        }
    }
    ;
%%
int main() {
    yyparse();
    return 0;
}