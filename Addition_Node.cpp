//Addition_Node.cpp

#include "Addition_Node.h"
#include "Visitor.h"

Addition_Node::Addition_Node (void) 
{
	left_child_ = nullptr;
	right_child_ = nullptr;
}

int Addition_Node::precedence (void) 
{
	return 1;
}

void Addition_Node::accept (Visitor * v)
{
	v->visit_addition_node(*this);
}
