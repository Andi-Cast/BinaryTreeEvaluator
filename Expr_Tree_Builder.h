//Expr_Tree_Builder.h

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Builder.h"
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Stack.h"
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"

class Expr_Tree_Builder : public Builder {
public:
	//
  	//Constructor
  	//
  	Expr_Tree_Builder (void);

  	//
  	//start_expression
  	//
  	void start_expression (void);
  
  	//
 	//build_left_parenthesis_node
  	//
  	void build_left_parenthesis_node (void);
  
  	//
  	//build_right_parenthesis_node
  	//
  	void build_right_parentheis_node (void);
  
  	//
  	//build_number_node
 	//
  	void build_number_node (int number);
  
  	//
  	//build_addition_node
  	//
  	void build_addition_node (void);
  
  	//
  	//build_subtraction_node
  	//
  	void build_subtraction_node (void);
  
  	//
  	//build_multiplication_node
  	//
  	void build_multiplication_node (void);
  
  	//
  	//build_division_node
  	//
  	void build_division_node (void);
  
  	//
  	//build_modulus_node
  	//
  	void build_modulus_node (void);
  
  	//
  	//get_expression
  	//
  	Binary_Expr_Node * get_expression (void);
  
  	//
  	//build_tree
  	//
  	void build_tree (void);

private:
  	Binary_Expr_Node * tree_;
  	Stack<Expr_Node *> numberStack_;
  	Stack<Binary_Expr_Node *> operatorStack_;
};

#endif
