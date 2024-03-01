//Calculator.h

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Expr_Tree_Builder.h"
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include <sstream>    //for istringstream


class Calculator {
public:
	//
 	//Constructor
 	//
 	Calculator (Expr_Tree_Builder & builder);
  
 	//
  	//parse_expr
  	//
	//Takes in the infix string and builds the expression tree using the Expr_Tree_Builder
  	void parse_expr (const std::string & infix);

  	//
  	//evaluate
  	//
	//Returns the final answer after parsing and using the Eval_Visitor
  	int evaluate (const std::string & infix);

private:
  	Expr_Tree_Builder & builder_;
};

#endif
