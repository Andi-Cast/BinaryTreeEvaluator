//driver.cpp
#include <iostream>
#include "Expr_Tree_Builder.h"
#include "Calculator.h"
#include "Eval_Visitor.h"

int main() {
	Expr_Tree_Builder builder = Expr_Tree_Builder();
	Calculator calculator(builder);


	bool Active = true;

	//While loop keeps going as long as user doesn't input 'QUIT'
	while (Active == true) {
		std::cout<<"Enter Expression: ";
		std::string input;
		std::getline(std::cin, input);

		if (input == "QUIT") {
			Active = false;
			std::cout<<"You have ended the session."<<std::endl;
			return 0;
		}
		
		std::cout<< "Result: " << calculator.evaluate(input) <<std::endl;		

	}

	return 0;
}
