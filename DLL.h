struct node
{
	int data;
	node* next,*prev;
	node(int d, node* n = 0, node* p = 0)
	{
		next = n;
		data = d;
		prev = p;
	}
};

class DoublyList
{
	node* head;
public:
	DoublyList();
	bool empty();
	void print_forward();
	void print_backward();
	void add_begin(int el);
	void add_end(int el);
	bool add_pos(int el, int pos);
	int size();
	bool del_end();
	bool del_pos(int pos);
	bool del_begin();
	bool del_el(int el);
	int search(int el);
	DoublyList(DoublyList& o);
	void operator=(DoublyList& o);
	~DoublyList();
};