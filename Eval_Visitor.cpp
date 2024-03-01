//Eval_Visitor.cpp

#include "Eval_Visitor.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"

Eval_Visitor::Eval_Visitor (void) 
:result_(0),
 left_value_(0),
 right_value_(0)
{

}

void Eval_Visitor::visit_addition_node (Addition_Node & node)
{
	//This will evaluate the left and right of the
	//nodes push the values onto the stack.
	node.get_left_child()->accept(this);
	node.get_right_child()->accept(this);
	
	//The top value will be the right side value
	//while the next value will be the left side value.
	right_value_ = value_stack_.top();
	value_stack_.pop();
	left_value_ = value_stack_.top();
	value_stack_.pop();
	
	//This part varies depending on the type of 
	//binary node that is visited but will do the 
	//arithmetic and store the result on the stack. 
	result_ = left_value_ + right_value_;
	value_stack_.push(result_);
}

void Eval_Visitor::visit_subtraction_node (Subtraction_Node & node) 
{
	node.get_left_child()->accept(this);
        node.get_right_child()->accept(this);

        right_value_ = value_stack_.top();
        value_stack_.pop();
        left_value_ = value_stack_.top();
        value_stack_.pop();

        result_ = left_value_ - right_value_;
        value_stack_.push(result_);
}

void Eval_Visitor::visit_multiplication_node (Multiplication_Node & node)
{
	node.get_left_child()->accept(this);
        node.get_right_child()->accept(this);

        right_value_ = value_stack_.top();
        value_stack_.pop();
        left_value_ = value_stack_.top();
        value_stack_.pop();

        result_ = left_value_ * right_value_;
        value_stack_.push(result_);
}

void Eval_Visitor::visit_division_node (Division_Node & node) 
{
	node.get_left_child()->accept(this);
        node.get_right_child()->accept(this);

        right_value_ = value_stack_.top();
        value_stack_.pop();
        left_value_ = value_stack_.top();
        value_stack_.pop();

        if(right_value_ == 0) {
                std::cerr<<"Error: Dividie by zero exception" << std::endl;
                return;
        }
        else {
                result_ = left_value_ / right_value_;
                value_stack_.push(result_);
        }
}

void Eval_Visitor::visit_modulus_node (Modulus_Node & node)
{
	node.get_left_child()->accept(this);
        node.get_right_child()->accept(this);

        right_value_ = value_stack_.top();
        value_stack_.pop();
        left_value_ = value_stack_.top();
        value_stack_.pop();

        result_ = left_value_ % right_value_;
        value_stack_.push(result_);
}

void Eval_Visitor::visit_number_node (Number_Node & node) 
{	
	//All visited number nodes will return their number
	//value and be pushed onto the stack. 
	value_stack_.push(node.eval());
}

int Eval_Visitor::result (void) 
{
	return result_;
}
