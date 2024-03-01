//Subtraction_Node.cpp

#include "Subtraction_Node.h"
#include "Visitor.h"

Subtraction_Node::Subtraction_Node (void) 
{
	left_child_ = nullptr;
	right_child_ = nullptr;
}

int Subtraction_Node::precedence (void) 
{
	return 1;
}

void Subtraction_Node::accept (Visitor * v) 
{
	v->visit_subtraction_node(*this);
}

