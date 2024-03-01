//Addition_Node.h

#ifndef _ADDITION_NODE_H_
#define _ADDITION_NODE_H_

#include "Binary_Expr_Node.h"
class Visitor;

class Addition_Node : public Binary_Expr_Node {
public:
	//
	//Constructor
	//
	Addition_Node (void);

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
