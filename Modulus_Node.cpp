//Modulus_Node.cpp

#include "Modulus_Node.h"
#include "Visitor.h"

Modulus_Node::Modulus_Node (void) 
{
	left_child_ = nullptr;
	right_child_ = nullptr;
}

int Modulus_Node::precedence (void) 
{
	return 2;
}

void Modulus_Node::accept (Visitor * v)
{
	v->visit_modulus_node (*this);
}
