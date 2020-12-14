
#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[]) {
	string line;
	ifstream modelicaFile ("example2.txt");
	if (modelicaFile.is_open()) {
		ANTLRInputStream input(modelicaFile);
		ExprLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		tokens.fill();
		for (auto token : tokens.getTokens()) {
			std::cout << token->toString() << std::endl;
		}
                // Create a parser which parses the token stream
                // to create a parse tree.
                ExprParser parser(&tokens);
                tree::ParseTree *tree = parser.stat();
                // Print the parse tree in Lisp format.
                cout << endl << "Parse tree (Lisp format):" << endl;
                std::cout << tree->toStringTree(&parser) << endl;
		modelicaFile.close();
	}
}
