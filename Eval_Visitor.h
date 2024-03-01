//Eval_Visitor.h

#ifndef _EVAL_VISITOR_H_
#define _EVAL_VISITOR_H_

#include "Visitor.h"
#include "Stack.h"

class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;
class Number_Node;

class Eval_Visitor : public Visitor {
public:
	//
	//Constructor
	//
	Eval_Visitor (void);

	//
        //visit_additon_node
        //
        void visit_addition_node (Addition_Node & node);

        //
        //visit_subtraction_node
        //
        void visit_subtraction_node (Subtraction_Node & node);

        //
        //visit_multiplication_node
        //
        void visit_multiplication_node (Multiplication_Node & node);

        //
        //visit_division_node
        //
        void visit_division_node (Division_Node & node);

        //
        //visit_modulus_node
        //
        void visit_modulus_node (Modulus_Node & node);

        //
        //visit_number_nodr
        //
        void visit_number_node (Number_Node & node);

	//
	//result
	//
	int result (void);
		
private:
	int result_;
	int left_value_;
	int right_value_;
	Stack<int> value_stack_;
};

#endif
