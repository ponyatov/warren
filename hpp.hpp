#ifndef _H_WARREN
#define _H_WARREN

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct Sym {
	string val;
	Sym(string);
	virtual string tagval();
	string pad(int);
	virtual string dump(int=0);
	vector<Sym*> nest; void push(Sym*);
};

struct List: Sym { List(); string tagval(); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_WARREN
