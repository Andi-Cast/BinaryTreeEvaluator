//Number_Node.h

#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expr_Node.h"
class Visitor;

class Number_Node : public Expr_Node {
public:
	//
	//constructor
	//
	Number_Node (int number);

	//
	//eval
	//
	int eval (void);

	//
	//accept
	//
	void accept (Visitor * v);

private:
	int number_;
};

#endif



