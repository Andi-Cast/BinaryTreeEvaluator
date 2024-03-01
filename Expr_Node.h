//Expr_Node.h

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

class Visitor;

class Expr_Node {
public:
	virtual void accept (Visitor * v) = 0;
};

#endif
