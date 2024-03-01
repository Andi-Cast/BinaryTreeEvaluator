//Division_Node.cpp

#include "Division_Node.h"
#include "Visitor.h"

Division_Node::Division_Node (void) 
{
	left_child_ = nullptr;
	right_child_ = nullptr;
}

int Division_Node::precedence (void) 
{
	return 2;
}

void Division_Node::accept (Visitor * v) 
{
	v->visit_division_node (*this);
}
