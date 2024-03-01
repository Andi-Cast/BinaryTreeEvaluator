//Multiplication_Node.h

#ifndef _MULTIPLICATION_NODE_H_
#define _MULTIPLICATION_NODE_H_

#include "Binary_Expr_Node.h"
class Visitor;

class Multiplication_Node : public Binary_Expr_Node {
public:
	//
	//Constructor
	//
	Multiplication_Node (void);

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
