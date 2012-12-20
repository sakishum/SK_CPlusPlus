//
//  main.cpp
//  SK_CPlusPlus
//
//  Created by saki shum on 12-1-18.
//  Copyright (c) 2012年 招商局物流集团. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

#include "Surrogate.h"
#include "Handle.h"
#include "Expr.h"

using namespace std;

class C_USER {
    int uid;
    
public:
    void reset(const string& data);
};

void C_USER::reset(const string& data)
{
    if (data.empty()) {
        cout << "empty" << endl;
        return;
    }
    static string token = string("");
    if (token.empty()) {
        cout << "reset" << endl;
        token = data;
    } else if (token == data)
    {
        cout << "Quit" << endl;
        return;
    }
}

int main (int argc, const char * argv[])
{
#if 0
    string cmd, url;
    stack<string> s1, s2; //定义了两个栈
    //栈1用作存储操作队列，而栈2则用作临时保存栈1出栈的数据
    s1.push("http://www.acm.org/"); //首页压栈
    while(cin >> cmd)
    {
        if(cmd == "VISIT")  //访问操作
        {
            cin >> url;
            s1.push(url);   //把访问的地址压入栈1
            while(!s2.empty()) s2.pop();    //清空栈2
            //想一想，为什么要清空栈2
            cout << s1.top() << endl;
        }
        else if(cmd == "BACK")  //返回操作
        {
            if(s1.size() > 1)    //如果此次弹出后不会使得栈变空
            {
                s2.push(s1.top());  //把栈1顶元素压入栈2
                s1.pop();
                cout << s1.top() << endl;
            }
            else
                cout << "Ignored" << endl;
        }
        else if(cmd == "FORWARD")   //前进操作
        {
            if(!s2.empty()) //栈2有元素，意味着可以前进
            {
                s1.push(s2.top());  //把栈2的顶端元素压入栈1
                cout << s2.top() << endl;
                s2.pop();   //弹出栈2的顶端元素
            }
            else
                cout << "Ignored" << endl;
        }
        else break;
    }
    cout << "END, LUA!\n";
#endif
    string test = string("saki");
    C_USER user;
    cout << "Once, LUA!\n";
    user.reset(test);
    cout << "Twice, LUA!\n";
    user.reset(test);
    
    ///    ======SURROGATE TEST======
    int num_vehicles = 0;
    VehicleSurrogate Parking_lot[100];
    Automobile x;
    Parking_lot[num_vehicles++] = VehicleSurrogate(x);
    
    Parking_lot[0].start();
    cout<<Parking_lot[0].weight()<<endl;
    
    ///    ======HANDLE TEST======
    //Point *p = new Point(8,9);
    CPoint p(8,9);
    //Point p1 = p.x(88);
    //Point *pp = &p;
    CHandle h1(1,2);
    CHandle h2 = h1;        /// 此处调用的是构造函数Handle(const Handle& h)
    h2.x(3).y(4);           /// 此处的特殊写法是因为写xy函数内返回了对象
    CHandle h3(5,6);        /// 此处调用Handle的赋值运算符重载函数Handle& operator=(const Handle& h)
    h1 = h3;
    CHandle h4(p);
    CHandle h5(h4);
    h4.x(7).y(8);
    //Handle h5(p1);
    //Handle h5 = h4;
    cout <<"h1(" << h1.x() <<":"<< h1.y() << "):" << h1.OutputU() <<endl;
    cout <<"h2(" << h2.x() <<":"<< h2.y() << "):" << h2.OutputU() <<endl;
    cout <<"h3(" << h3.x() <<":"<< h3.y() << "):" << h3.OutputU() <<endl;
    cout <<"h4(" << h4.x() <<":"<< h4.y() << "):" << h4.OutputU() <<endl;
    cout <<"h5(" << h5.x() <<":"<< h5.y() << "):" << h5.OutputU() <<endl;
    //delete pp; //不能这样，不是用new分配的空间
    //cout <<"h5(" << h5.x() <<":"<< h5.y() << "):" << h5.OutputU() <<endl;
    cout<<p.x()<<" "<<p.y()<<endl;
    //cout<<&p1<<endl;
    
    /// ============== Memset array
    int *pNum = new int[100];
    memset(pNum,0,sizeof(int)*(100));
    pNum[19] = 20;
    cout<<pNum[19]<<endl;
    cout<<pNum[20]<<endl;
    if (pNum != NULL) {
        delete []pNum;
        pNum = NULL;
    }
    cout<<"Start"<<endl;
    /// =============== A example of OOP
    Expr t = Expr("*", Expr("-",5), Expr("+", 3, 4));
    cout <<t<<"="<<t.eval()<<endl;
    
    return 0;
}

