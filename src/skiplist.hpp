#ifndef   SKIPLIST_H
#define   SKIPLIST_H

#define MAX_LIST_SIZE 10
#define MAX_LEVEL     10

#include <random>

struct SkipListNode
{
	SkipListNode(int x, int l)
	{
		this->data = x;
		this->next = new SkipListNode* [l];
		
		for (int i = 0; i < MAX_LIST_SIZE; i ++)
			this->next = nullptr;
	}

	int data;
	SkipListNode **next;
};

class SkipList
{
	int h;
	SkipListNode *sentinel;

public:
	SkipList(): h(MAX_LEVEL)
	{
		this->sentinel = new SkipListNode(0, MAX_LEVEL);
	}
	
	SkipListNode* find_pred_node(int x)
	{
		auto u = this->sentinel;

		for (int i = this->h; i >= 0; i --)
			while(u->next[i] && u->next[i]->data < x)
				u = u->next[i];

		return u;
	}

	unsigned int pick_height()
	{
		return random() % MAX_LEVEL;
	}

public:
	void insert(int x)
	{
		auto u = this->sentinel;
		auto stack = new SkipListNode* [MAX_LEVEL + MAX_LIST_SIZE];

		for (int i = this->h; i >= 0; i --)
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
	}

	bool search(int x)
	{
		return this->find_pred_node(x)->next[0];
	}

	bool remove(int x);
};

#endif // SKIPLIST_H

