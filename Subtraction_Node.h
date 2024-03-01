//Subtraction_Node.h

#ifndef _SUBTRACTION_NODE_H_
#define _SUBTRACTION_NODE_H_

#include "Binary_Expr_Node.h"
class Visitor;

class Subtraction_Node : public Binary_Expr_Node {
public:
	//
	//Constructor
	//
	Subtraction_Node (void);

	//
	//precedence
	//
	int precedence (void);

	//
	//accept
	//
	void accept (Visitor * v);
};

#endif
