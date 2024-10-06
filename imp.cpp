#include "DLL.h"
#include<iostream>
using namespace std;
DoublyList::DoublyList()
{
	head = NULL;
}
bool DoublyList::empty()
{
	return (head == 0);
}
void DoublyList::print_forward()
{
	node* t=head;
	for (; t != 0; t = t->next)
		cout << t->data<<" ";
	cout << endl;
}
void DoublyList::print_backward()
{
	if (head != 0)
	{
		for (; head->next != 0; head = head->next);
		for (; head->prev != 0; head = head->prev)
			cout << head->data << " ";
		cout << head->data<<endl;
	}
}
void DoublyList::add_begin(int el)
{
	if (head == 0)
		head = new node(el);
	else
	{
		head->prev = new node(el, head);
		head = head->prev;
	}

}
void DoublyList::add_end(int el)
{
	if (head == 0)
		head = new node(el);
	else
	{
		node* t = head;
		for (; t->next != 0; t = t->next);
		t->next= new node(el);
		t->next->prev=t;
	}
}
bool DoublyList::add_pos(int el, int pos)
{
	if (pos<1 || pos>size() + 1)
		return false;
	else if (pos == 1)
		head = new node(el);
	else if (pos == size() + 1)
		add_end(el);
	else
	{
		node* t=head;
		for (int c = 1; c < pos; ++c, t = t->next);
		t->prev=t->prev->next = new node(el,t,t->prev);
		return true;
	}
}
int DoublyList::size()
{
	if (empty())
		return -1;
	node* t = head;
	int count = 0;
	for (; t != 0; t = t->next, ++count);
	return count;
}
bool DoublyList::del_end()
{
	if (head == 0)
		return false;
	if (size()==1)
	{
		delete head;
		head = 0;
		return true;
	}
	node* t = head;
	for (; t->next->next!= 0; t = t->next);
	delete t->next;
	t->next = 0;
	return true;
}
bool DoublyList::del_begin()
{
	if (head == 0)
		return false;
	else if (head->next == 0)
	{
		delete head;
		head = 0;
		return true;
	}
	node* t = head;
	head = head->next;
	delete t;
	return true;
}
bool DoublyList::del_pos(int pos)
{
	if (pos<1 || pos>size())
		return false;
	else if (pos == size())
	{
		del_end();
		return true;
	}
	else if (pos == 1)
		del_begin();
	node* t1 = head,*t2;
	for (int i = 1; i < pos - 1; ++i, t1 = t1->next);
	t2 = t1 -> next->next;
	delete t1->next;
	t1->next = t2->next->prev;
	return true;
}
bool DoublyList::del_el(int el)
{
	int index = search(el);
	if (index != -1)
	{
		del_pos(index);
		return true;
	}
	else
		return false;
}
int DoublyList::search(int el)
{
	node* t = head;
	int index = 0;
	for (; t != 0; t = t->next, ++index)
		if (t->data == el)
			return index + 1;
	return -1;
}
DoublyList::DoublyList(DoublyList& o)
{
	if (!o.empty())
	{
		node* t1 = o.head, * t2;
		t2 = head = new node(t1->data);
		t1 = t1->next;
		for (; t1 != 0; t1 = t1->next)
			t2=t2->next = new node(t1->data);
	}
	else
		head = 0;
}
void DoublyList::operator=(DoublyList& o)
{
	while (!empty())
		del_end();
	if (!o.empty())
	{
		node* t1 = o.head,*t2;
		t2 = head = new node(t1->data);
		while (t1->next != 0)
		{
			t1 = t1->next;
			t2 =t2->next= new node(t1->data);
		}
	}
	else
		head = 0;
}
DoublyList::~DoublyList()
{
	while (!empty())
			del_end();
	cout << "deleted\n";
}