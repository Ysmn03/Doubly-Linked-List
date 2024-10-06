#include "DLL.h"
#include<iostream>
using namespace std;
/*int main()
{
	DoublyList l;
	l.add_begin(3);
	l.add_begin(5);
	l.add_begin(100);
	l.add_begin(99);
	l.add_begin(7);
	l.add_pos(55, 4);
	cout << l.size() << endl;
	//l.del_end();
	//l.del_pos(2);
	//l.del_begin();
	l.del_el(100);
	l.print_forward();
}*/
/*void f(DoublyList x)
{
	cout << "begin of f" << endl;
	x.print_forward();
	x.add_begin(100);
	x.del_end();
	x.print_forward();
	cout << "end of f" << endl;
}
void main()
{
	DoublyList l;
	l.add_end(3);
	l.add_end(4);
	l.add_end(5);
	l.print_forward();
	f(l);
	l.print_forward();
}*/
void main()
{
	DoublyList l1, l2;
	l1.add_end(1);
	l1.add_end(2);
	l2.add_end(5);
	l2.add_end(6);
	l2.add_end(7);
	l1.print_forward();
	l1.print_forward();
	l1 = l2;
	l2.add_end(100);
	l1.print_forward();
	l2.print_forward();
}