#ifndef   SKIPLIST_H
#define   SKIPLIST_H

#define MAX_LIST_SIZE 10
#define MAX_LEVEL     10

#include <random>
#include <iostream>

struct SkipListNode
{
	SkipListNode(int x, int l)
	{
		this->data = x;
		this->next = new SkipListNode* [l];
		
		for (int i = 0; i < l; i ++)
			this->next[i] = nullptr;
	}

	int data;
	SkipListNode **next;
};

class SkipList
{
	int h;
	SkipListNode *sentinel;

public:
	SkipListNode* find_pred_node(int x)
	{
		auto u = this->sentinel;

		for (int i = this->h - 1; i >= 0; i --)
			while(u->next[i] && u->next[i]->data < x)
				u = u->next[i];

		return u;
	}

	unsigned int pick_height()
	{
		return random() % MAX_LEVEL;
	}

public:
	SkipList(): h(MAX_LEVEL)
	{
		this->sentinel = new SkipListNode(0, MAX_LEVEL);
	}
	
	void print()
	{
		for (int i = 0; i < this->h; i ++)
		{
			auto node = this->sentinel;
			if (!node)
				std::cout << "NULL";
			
			while (node)
			{
				std::cout << node->data << "->";
				node = node->next[i];
			}
			std::cout << '\n';
		}
	}

	void insert(int x)
	{
		auto u = this->sentinel;
		auto stack = new SkipListNode* [MAX_LEVEL + MAX_LIST_SIZE];

		for (int i = this->h - 1; i >= 0; i --)
		{
			while (u->next[i] && u->next[i]->data < x)
				u = u->next[i];
			
			if (u->next[i] && u->next[i]->data == x)
				return;

			stack[i] = u;
		}

		unsigned int h = this->pick_height();
		auto new_node = new SkipListNode(x, h); 

		for (int i = 0; i < h; i ++)
		{
			new_node->next[i] = stack[i]->next[i];
			stack[i]->next[i] = new_node;
		}
		delete[] stack;
	}

	bool search(int x)
	{
		auto u = this->find_pred_node(x);
		return u->next[0] && u->next[0]->data == x;
	}

	bool remove(int x)
	{
		bool removed = false;
		auto u = this->sentinel;
		for (int i = this->h - 1; i >= 0; i --)
		{
			while(u->next[i] && u->next[i]->data < x)
				u = u->next[i];
			
			if (u->next[i] && u->next[i]->data == x)
			{	
				removed = true;

				u->next[i] = u->next[i]->next[i];
				
				if (u == this->sentinel && !u->next[i])
					this->h--;
			}
		}
		return removed;

	}
};

#endif // SKIPLIST_H

