//
//  Expr.h
//  SK_CPlusPlus
//
//  Created by shum saki on 12-12-18.
//  Copyright (c) 2012年 招商局物流集团. All rights reserved.
//

/*
 * 这个例子很好的展示了面向对象的三个要素，这样设计出的类具有很好的扩展性，
 * 比如再增加有多个子节点的节点，只要添加个新类，然后在Expr中添加个新构造
 * 函数就行了。用户完全不必知道底层的代码是怎么实现的。以后面对问题的时候要
 * 好好的借鉴这种思想！
 */

#ifndef __SK_CPlusPlus__Expr__
#define __SK_CPlusPlus__Expr__

#include <iostream>
using namespace std;

class Expr_node;
class Int_node;
class Unary_node;
class Binary_node;

/// handle class
class Expr {
    friend ostream& operator<<(ostream&, const Expr&);
    Expr_node* p;
    
public:
    Expr(int);                              /// create a Int_node
    Expr(const string&, Expr);              /// create a Unary_node
    Expr(const string&, Expr, Expr);        /// create a Binary_node
    Expr(const string&, Expr, Expr ,Expr);  /// create a Ternary_node
    Expr(const Expr&);
    ~Expr();
    Expr& operator=(const Expr&);
    int eval() const;
}; 

class Expr_node
{
    friend ostream& operator<<(ostream&, const Expr_node&);
    friend class Expr;  /// friend classes are not inherite!
    int use;            /// ref count
    
    virtual void print(ostream&) const = 0;
    virtual int eval() const = 0;
public:
    Expr_node(): use(1) {}
    virtual ~Expr_node() {}
    
};

class Int_node : public Expr_node {
    friend class Expr;
    int n;
    
    Int_node(int k): n(k) {}
    virtual void print(ostream& o) const { o<< n; }
    virtual int eval() const { return n; }
};

class Unary_node: public Expr_node {
    friend class Expr;
    Unary_node(const string& a, Expr b): op(a), opnd(b) {}
    virtual void print(ostream& o) const { o<<"("<<op<<opnd<<")"; }
    virtual int eval() const;
private:
    string op;
    Expr opnd;
};

class Binary_node: public Expr_node {
    friend class Expr;
    string op;
    Expr left;
    Expr right;
    Binary_node(const string& a, Expr b, Expr c): op(a), left(b), right(c) {}
    virtual void print(ostream& o) const { o<<"("<<left<<op<<right<<")"; }
    virtual int eval() const;
};

class Ternary_node: public Expr_node {
    friend class Expr;
    
    string op;
    Expr left;
    Expr middle;
    Expr right;
    
    Ternary_node(const string& a, Expr b, Expr c, Expr d): op(a), left(b), middle(c), right(d) {}
    virtual void print(ostream& o) const { o<<"("<<left<<"?"<<middle<<":"<<right<<")"; }
    virtual int eval() const;
};

#endif /* defined(__SK_CPlusPlus__Expr__) */
