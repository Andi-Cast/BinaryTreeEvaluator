//Binary_Expr_Node.h

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"
class Visitor;

class Binary_Expr_Node : public Expr_Node {
public:
	//
	//Constructor
	//
	Binary_Expr_Node (void);

	//
	//Destructor
	//
	~Binary_Expr_Node (void);

	//
	//precedence
	//
	virtual int precedence (void) = 0;

	//
	//accept
	//
	virtual void accept (Visitor * v) = 0;

	//
	//set_left_child
	//
	void set_left_child (Expr_Node * leftNode);

	//
	//get_left_child
	//
	Expr_Node * get_left_child (void);

	//
	//set_right_child
	//
	void set_right_child (Expr_Node * rightNode);


	//
	//get_right_child
	//
	Expr_Node * get_right_child (void);

protected:
	Expr_Node * left_child_;
	Expr_Node * right_child_;
};

#endif
