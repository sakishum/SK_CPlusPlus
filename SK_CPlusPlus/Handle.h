//
//  Handle.h
//  SK_CPlusPlus
//
//  Created by shum saki on 12-12-11.
//  Copyright (c) 2012年 招商局物流集团. All rights reserved.
//

#ifndef __SK_CPlusPlus__Handle__
#define __SK_CPlusPlus__Handle__

#include <iostream>
using namespace std;

class CPoint {
private:
    int xval, yval;
    
public:
    CPoint():xval(0), yval(0) {}
    CPoint(int x, int y):xval(x), yval(y) {}
    int x() const { return xval;}
    int y() const { return yval;}
    CPoint& x(int xv) { xval = xv; return *this; }
    CPoint& y(int yv) { yval = yv; return *this; }
    /// p.x(24).y(24);
};

/// 引用计数类
class CUPoint {
    /// all member are private
    friend class CHandle;
    CPoint p;
    int u;              /// 引用计数变量
    CUPoint(): u(1) {}  /// 引用计数初始化为1
    CUPoint(int x, int y): p(x, y), u(1) {}
    CUPoint(const CPoint& p0): p(p0), u(1) {}
};

/*
 从效果上来说，handle就是一种只包含单个对象的容器，它通过允许多个handle
 对象指向同一个对象来避免复制。定义句柄类，我们还需要新定义一个类来容
 纳被引用类对象的引用计数和被引用类对象本身。
 
 这里的引用计数为0时删除p的意思应该是由handle创建的p
 handle的构造函数中有一种是跟p有关的，在这类构造函数中
 创建了p并初始化了p的计数，当这个计数为0时删除的是由handle创建
 的p，如果Point自身不实例化对象的话，这样就真的实现了删除p对象了
 
 可见，handle需要提供hanle(const handle &) , hanle(const Point &)和hanle(int x, int y)
 三类构造函数的必要性，都是为了创建Point对象，而且这样创建的Point对象可以与handle关联
 */
/// 句柄类
class CHandle {
private:
    CUPoint * up;   /// 和间接层UPoint打交道了
    // ...
    
public:
    CHandle();
    CHandle(int, int);
    CHandle(const CPoint&);
    CHandle(const CHandle&);
    CHandle& operator=(const CHandle&);
    ~CHandle();

    int x() const;
    int y() const;
    CHandle& x(int);
    CHandle& y(int);
    
    int OutputU(){return up->u;};   /// 输出引用个数
};

#endif /* defined(__SK_CPlusPlus__Handle__) */
