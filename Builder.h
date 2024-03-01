//Builder.h

#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "Expr_Node.h"

class Builder {
public: 
  //
  //start_expression
  //
  virtual void start_expression (void) = 0;
  
  //
  //build_left_parenthesis_node
  //
  virtual void build_left_parenthesis_node (void) = 0;
  
  //
  //build_right_parenthesis_node
  //
  virtual void build_right_parentheis_node (void) = 0;
  
  //
  //build_number_node
  //
  virtual void build_number_node (int number) = 0;
  
  //
  //build_addition_node
  //
  virtual void build_addition_node (void) = 0;
  
  //
  //build_subtraction_node
  //
  virtual void build_subtraction_node (void) = 0;
  
  //
  //build_multiplication_node
  //
  virtual void build_multiplication_node (void) = 0;
  
  //
  //build_division_node
  //
  virtual void build_division_node (void) = 0;
  
  //
  //build_modulus_node
  //
  virtual void build_modulus_node (void) = 0;
  
  //
  //get_expression
  //
  virtual Expr_Node * get_expression (void) = 0;
  
  //
  //build_tree
  //
  virtual void build_tree (void) = 0;
};

#endif
