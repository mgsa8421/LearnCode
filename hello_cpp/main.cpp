#include <iostream>
using namespace std;
 
class A
{
public:
    virtual void Debug(){cout<<"base"<<endl;}
	void fun1(){cout<<"base fun1"<<endl;}
	void add(){cout<<"1+1"<<endl;}
 
};
 
class B:public A
{
public:
   void Debug(){cout<<"child"<<endl;}
   void fun1(){cout<<"child fun1"<<endl;}
   void fun2(){cout<<"child fun2"<<endl;}
};
 
int main()
{
    A* a;//声明一个基类指针a
	a=new B;//这里将基类指针强制转换为了子类指针类型
	a->Debug();//输出child,这里指针指向了虚函数 Debug，实际调用的就是其在子类B中的实现。
	a->fun1();//输出base fun1,这里指针指向了基类的函数fun1,因为基类的fun1不是虚函数，所以就不会指向子类中的同名函数fun1
	//a->fun2();//这样写就是错误的，基类指针能指向的函数只能是基类中存在的函数，基类不存在fun2，所以这样写就是错误的
 
 
	B* b1=new B;//声明一个子类指针b1并初始化	
	b1->add();//输出1+1，可以看到子类指针可以指向基类中的函数add()，这个函数在子类B中并没有
	b1->fun1();//输出child fun1,这里指针指向了基类的函数fun1,因为基类的fun1不是虚函数，所以就不会指向子类中的同名函数fun1
	
    return 0;
}