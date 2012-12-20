//
//  Expr.cpp
//  SK_CPlusPlus
//
//  Created by shum saki on 12-12-18.
//  Copyright (c) 2012年 招商局物流集团. All rights reserved.
//

#include "Expr.h"

ostream& operator<<(ostream& o, const Expr_node& e)
{
    e.print(o);
    return o;
}

ostream&
operator<<(ostream& o, const Expr& t)
{
    t.p->print(o);
    return o;
}

Expr&
Expr::operator=(const Expr& rhs)
{
    rhs.p->use++;
    if (--p->use == 0) {
        delete p;
    }
    p = rhs.p;
    return *this;
}

Expr::Expr(int n)
{
    p = new Int_node(n);
}

Expr::Expr(const string& op, Expr t)
{
    p = new Unary_node(op, t);
}

Expr::Expr(const string& op, Expr left, Expr right)
{
    p = new Binary_node(op, left, right);
}

Expr::Expr(const string& op, Expr left, Expr middle ,Expr right)
{
    p = new Ternary_node(op, left, middle, right);
}

Expr::Expr(const Expr& t)
{
    p = t.p;
    ++p->use;
}

Expr::~Expr()
{
    if ( --p->use == 0)
    {
        delete p;
        p = NULL;
    }
}

int Expr::eval() const
{
    return p->eval();
}

int Unary_node::eval() const
{
    if (op == "-") {
        return -opnd.eval();
    }
    throw "error, bad op" + op + "int UnaryNode";
}

int Binary_node::eval() const
{
    int op1 = left.eval();
    int op2 = right.eval();
    if (op == "+" ) return op1 + op2;
    if (op == "-" ) return op1 - op2;
    if (op == "*" ) return op1 * op2;
    if (op == "/" && op2 != 0) return op1 / op2;
    throw "error, bad op" + op + "int UnaryNode";
}

int Ternary_node::eval() const
{
    if(left.eval())
        return middle.eval();
    else return right.eval();
}
