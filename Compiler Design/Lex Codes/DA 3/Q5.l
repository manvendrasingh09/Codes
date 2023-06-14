%{
%}

%%
"<"[^>]*> {printf("%s\n", yytext); } 
. ; 
%%	

int yywrap(){}
	
int main(int argc, char*argv[])
{
	yyin = fopen("input.txt","r");

	yylex();

	return 0;
}