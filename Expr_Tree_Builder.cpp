//Expr_Tree_Builder.cpp

#include "Expr_Tree_Builder.h"
#include <iostream>

Expr_Tree_Builder::Expr_Tree_Builder (void) 
:tree_(nullptr)
{

}
    
void Expr_Tree_Builder::build_left_parenthesis_node (void) 
{
	//This design uses a nullptr to represent the 'left parenthesis'.
	operatorStack_.push (nullptr);
}
    
void Expr_Tree_Builder::build_right_parentheis_node (void) 
{
	//This while loop will build the subtree that is inside the parenthesis
	//and push the root onto the number stack to be used to build the rest of the tree.
	while (!operatorStack_.is_empty() && operatorStack_.top() != nullptr) {
		tree_ = operatorStack_.top();
		operatorStack_.pop();
		tree_->set_right_child (numberStack_.top());
		numberStack_.pop();
		tree_->set_left_child (numberStack_.top());
		numberStack_.pop();
		numberStack_.push (tree_);
	}
	//This removes the 'left parenthesis' which is represented by a nullprt.
	operatorStack_.pop();
}
    
void Expr_Tree_Builder::start_expression (void) 
{
	//If tree_ does not equal nullptr, it will be reset everything for the 
	//next expression.
	if (tree_ != nullptr) {
		tree_ = nullptr;
		numberStack_.clear();
		operatorStack_.clear();
	}
}
    
void Expr_Tree_Builder::build_number_node (int number) 
{
	Number_Node * number_node = new Number_Node(number);
	numberStack_.push(number_node);
}
    
void Expr_Tree_Builder::build_addition_node (void) 
{
	Addition_Node * addition = new Addition_Node();
        
	//If the operator stack is empty or there is a nullptr on top, the node will
	//be added to the operator stack. 
	if (operatorStack_.is_empty() == true || operatorStack_.top() == nullptr) {
		operatorStack_.push(addition);
  	}
	//This will first check for precedence and if the incoming operator node is less than
	//or equal to the precedence of the top operator node. If is this is true then
	//it will trigger the build_tree() method that builds the subtree with the operator 
	//on top of the stack. Finally the incoming operator node is pushed unto the operator
	//stack.
  	else if (operatorStack_.top()->precedence() >= addition->precedence()) {
    		build_tree();
    		operatorStack_.push(addition);
  	}
	//If precedence of incoming operator node is greater than the operator precedence
	//of the node at the top of the operator stack, the incoming node is added to the 
	//stack. 
  	else {
    		operatorStack_.push(addition);
  	}
}
    
void Expr_Tree_Builder::build_subtraction_node (void) 
{
	Subtraction_Node * subtraction = new Subtraction_Node();

	if (operatorStack_.is_empty() == true || operatorStack_.top() == nullptr) {
		operatorStack_.push(subtraction);
  	}
  	else if (operatorStack_.top()->precedence() >= subtraction->precedence()) {
    		build_tree();
    		operatorStack_.push(subtraction);
  	}
  	else {
    		operatorStack_.push(subtraction);
  	}
}
    
void Expr_Tree_Builder::build_multiplication_node (void) 
{
	Multiplication_Node * multiplication = new Multiplication_Node();
        
	if (operatorStack_.is_empty() == true || operatorStack_.top() == nullptr) {
    		operatorStack_.push(multiplication);
  	}
  	else if (operatorStack_.top()->precedence() >= multiplication->precedence()) {
    		build_tree();
    		operatorStack_.push(multiplication);
  	}
  	else {
    		operatorStack_.push(multiplication);
  	}
} 
    
void  Expr_Tree_Builder::build_division_node (void) 
{
	Division_Node * division = new Division_Node();
        
	if (operatorStack_.is_empty() == true || operatorStack_.top() == nullptr) {
    		operatorStack_.push(division);
  	}
  	else if (operatorStack_.top()->precedence() >= division->precedence()) {
    		build_tree();
    		operatorStack_.push(division);
  	}
  	else {
    		operatorStack_.push(division);
  	}
}
    
void Expr_Tree_Builder::build_modulus_node (void) 
{
	Modulus_Node * modulus = new Modulus_Node();
        
  	if (operatorStack_.is_empty() == true || operatorStack_.top() == nullptr) {
    		operatorStack_.push(modulus);
  	}
  	else if (operatorStack_.top()->precedence() >= modulus->precedence()) {
    		build_tree();
    		operatorStack_.push(modulus);
  	}
  	else {
    		operatorStack_.push(modulus);
  	}
}
    
Binary_Expr_Node * Expr_Tree_Builder::get_expression (void) 
{
	//This returnst the root node of the expreesion tree.
  	return tree_;
}
    
void Expr_Tree_Builder::build_tree (void) 
{
	//Throws error is if there is an attempt to build a tree
	//when there isn't any operators on the stack. 
	if (tree_ == nullptr && operatorStack_.is_empty()) {
    		std::cout<<"error with building tree"<<std::endl;
  	}
  	else { 
		//This while loop will construct the expression subtree with
		//the operators present in the operator stack. It will first 
		//set the root (tree_) as the top of the operator stack and add
		//the leaf nodes to it. It finally pushes the root of the tree
		//onto the number stack if there are more incoming parts.
		//It also checks to see if the top is a nullptr to stop building 
		//the tree since the ')' is in charge of building any subtrees
		//inside the parenthesis.
    		while(!operatorStack_.is_empty() && operatorStack_.top() != nullptr) {
      			tree_ = operatorStack_.top();
      			operatorStack_.pop();
      			tree_->set_right_child(numberStack_.top());
      			numberStack_.pop();
      			tree_->set_left_child(numberStack_.top());
      			numberStack_.pop();
      			numberStack_.push(tree_);
    		}
  	}
}
