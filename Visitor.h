//Visitor.h

#ifndef _VISITOR_H_
#define _VISITOR_H_

class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;
class Number_Node;

class Visitor {
public:
	//
	//visit_additon_node
	//
	virtual void visit_addition_node (Addition_Node & node) = 0;

	//
	//visit_subtraction_node
	//
	virtual void visit_subtraction_node (Subtraction_Node & node) = 0;

	//
	//visit_multiplication_node
	//
	virtual void visit_multiplication_node (Multiplication_Node & node) = 0;

	//
	//visit_division_node
	//
	virtual void visit_division_node (Division_Node & node) = 0;

	//
	//visit_modulus_node
	//
	virtual void visit_modulus_node (Modulus_Node & node) = 0;

	//
	//visit_number_nodr
	//
	virtual void visit_number_node (Number_Node & node) = 0;	
	
};

#endif
