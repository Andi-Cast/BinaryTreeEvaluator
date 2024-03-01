//Division_Node.h

#ifndef _DIVISION_NODE_H_
#define _DIVISION_NODE_H_

#include "Binary_Expr_Node.h"
class Visitor;

class Division_Node : public Binary_Expr_Node {
public:
	//
	//Constructor
	//
	Division_Node (void);

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
