//Multiplication_Node.cpp

#include "Multiplication_Node.h"
#include "Visitor.h"

Multiplication_Node::Multiplication_Node (void) 
{
	left_child_ = nullptr;
	right_child_ = nullptr;
}

int Multiplication_Node::precedence (void) 
{
	return 2;
}

void Multiplication_Node::accept (Visitor * v)
{
	v->visit_multiplication_node(*this);
}
