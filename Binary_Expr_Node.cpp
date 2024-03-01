//Binary_Expr_Node.cpp

#include "Binary_Expr_Node.h"
#include "Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node (void)
:left_child_ (nullptr),
 right_child_ (nullptr)
{

}

Binary_Expr_Node::~Binary_Expr_Node (void) 
{
	delete left_child_;
	delete right_child_;
}

void Binary_Expr_Node::set_left_child (Expr_Node * leftNode)
{
	left_child_ = leftNode;
}

Expr_Node * Binary_Expr_Node::get_left_child (void)
{
 	return left_child_;
}

void Binary_Expr_Node::set_right_child (Expr_Node * rightNode)
{
	right_child_ = rightNode;
}

Expr_Node * Binary_Expr_Node::get_right_child (void)
{
	return right_child_;
}
