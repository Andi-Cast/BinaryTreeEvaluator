//Calculator.cpp

#include "Calculator.h"
#include "Visitor.h"
#include "Eval_Visitor.h"

Calculator::Calculator (Expr_Tree_Builder & builder)
:builder_(builder)
{
  
}

void Calculator::parse_expr (const std::string & infix)
{
	std::istringstream input(infix);
	std::string token;
        
	//This will reset the builder to make sure nothing is left 
	//from previous calculation.
	builder_.start_expression();
        
  	while (!input.eof()) {
    		input >> token;
		//This checks if the token is a number and it doesn't
		//matter if it is positive or negative.
    		if(isdigit(token[0]) == true || isdigit(token[1]) == true) {
      			int number = stoi(token);
      			builder_.build_number_node (number);
    		}
    		else if (token == "+") {
      			builder_.build_addition_node();
    		}
    		else if (token == "-") {
     			builder_.build_subtraction_node();
    		}
    		else if (token == "*") {
      			builder_.build_multiplication_node();
    		}
    		else if (token == "/") {
      			builder_.build_division_node();
    		}
    		else if (token == "%") {
      			builder_.build_modulus_node();
    		}
    		else if (token == "(") {
      			builder_.build_left_parenthesis_node();
    		}
    		else if (token == ")") {
      			builder_.build_right_parentheis_node();
    		}
  	}
	//This is called at the end to build the last part of the tree
	//since the design of this program builds the tree only once it is
	//triggered by precedence. Since the last operator doesn't have anything
	//to trigger its building, it is called at the end. 
  	builder_.build_tree();
}


int Calculator::evaluate (const std::string & infix) 
{
	//This will build the expression tree.
	parse_expr (infix);

	//Stores the root of the expression tree.
  	Expr_Node * root = builder_.get_expression();

	//This visitor will traverse the tree in postfix order
	//and store the answer. 
	Eval_Visitor * eval = new Eval_Visitor();
	root->accept(eval);

	//Returns the answer stored in visitor. 
	return eval->result();
}
