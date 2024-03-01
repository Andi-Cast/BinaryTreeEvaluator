//Modulus_Node.h

#ifndef _MODULUS_NODE_H_
#define _MODULUS_NODE_H_

#include "Binary_Expr_Node.h"
class Visitor;

class Modulus_Node : public Binary_Expr_Node {
public:
	//
	//Constructor
	//
	Modulus_Node (void);

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
