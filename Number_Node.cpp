//Number_Node.cpp

#include "Number_Node.h"
#include "Visitor.h"

Number_Node::Number_Node (int number) 
:number_(number)
{

}

int Number_Node::eval (void) 
{
	return number_;
}

void Number_Node::accept (Visitor * v) 
{
	v->visit_number_node(*this);
}
