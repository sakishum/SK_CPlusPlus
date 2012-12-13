//
//  Handle.cpp
//  SK_CPlusPlus
//
//  Created by shum saki on 12-12-11.
//  Copyright (c) 2012年 招商局物流集团. All rights reserved.
//

#include "Handle.h"

CHandle::CHandle()
: up(new CUPoint)
{
    
}

/// 按创建Point的方式构造handle，handle->UPoint->Point
CHandle::CHandle(int x, int y)
:up(new CUPoint(x, y))
{

}

/// 创建Point的副本
CHandle::CHandle(const CPoint& p)
:up(new  CUPoint(p))
{

}

/// 此处复制的是handle，但是底层的point对象并未复制，只是引用计数加1
CHandle::CHandle(const CHandle & h)
:up(h.up)
{
    ++up->u;
}

/// 右边的对象引用计数加1，左边的减1
CHandle& CHandle::operator=(const CHandle & h)
{
    ++h.up->u;
    if (--up->u == 0) {
        delete up;
    }
    up = h.up;
    return *this;
}

int CHandle::x() const
{
    return up->p.x();
}

int CHandle::y() const
{
    return up->p.y();
}

/// 指针语义，不必复制 CUPoint 对象
CHandle& CHandle::x(int x0)
{
    up->p.x(x0);
    return *this;
}

/// 指针语义，不必复制 CUPoint 对象
CHandle& CHandle::y(int y0)
{
    up->p.y(y0);
    return *this;
}

CHandle::~CHandle()
{
    if (--up->u == 0) {
        delete up;
    }
}