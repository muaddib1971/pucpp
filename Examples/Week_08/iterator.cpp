#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct List
{
	struct ListNode
	{
		int i;
		ListNode *next;

		ListNode(int i = 0, ListNode *next = nullptr):i(i),next(next) {}
		~ListNode() { delete next; }
	};

	// forward
	struct iterator
	{
		ListNode *curr;
		iterator(ListNode *curr = nullptr) : curr(curr) {}
		bool operator != (const iterator &it)
		{
			return it.curr != curr;
		}
		int operator * () { return curr->i; }

		// pre
		iterator &operator ++ () { curr = curr->next; return *this; }
		// post
		iterator &operator ++ (int) { curr = curr->next; return *this;}
	};

	ListNode *head;
	ListNode *tail;

	List() : head(nullptr), tail(nullptr) {}
	~List() { delete head; }

	List(const initializer_list<int> &l) : head(nullptr), tail(nullptr)
	{
		for (auto i : l)
			push_back(i);
	}

	void push_back(int i)
	{
		if (!head)
		{
			head = new ListNode(i);
			tail = head;
		}
		else
		{
			tail->next = new ListNode(i);
			tail = tail->next;
		}
	}

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
};

struct A
{
	int i;

	bool operator < (const A &a) { return i > a.i; }
};

bool comp(int i, int j) { return i > j; }

// Functor
struct Comp
{
	bool operator () (int i, int j) { return i > j; }
};


typedef set<int, Comp> Type;

int main(int argc, char **argv)
{
	Type v = {10, 5, 20};

	/*auto loc = find(v.begin(), v.end(), 50);
	if (loc == v.end())
		cout << "Not found\n";
	else
		v.erase(loc);*/

	//sort(v.begin(), v.end());

#if 0
	v.insert({"Hello" ,10});
	v.insert({"World", 5});
	v.insert({"Foo", 20});
#endif

	//for (int i = 0; i < 1000000; i++)
	//	cout << v[i] << " ";

	for (Type::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	//for (int i : v)
	//	cout << i << " ";
	cout << "\n";

	return 0;
}

