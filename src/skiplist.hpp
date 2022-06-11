#ifndef   SKIPLIST_H
#define   SKIPLIST_H

#define MAX_LIST_SIZE 10
#define MAX_LEVEL     10

#include <random>

struct SkipListNode
{
	SkipListNode()
	{
		this->data = 0;
		this->next = new SkipListNode* [MAX_LEVEL];
		
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
	SkipList(): h(0)
	{
		this->sentinel = new SkipListNode;
	}
	
	SkipListNode* find_pred_node(int x)
	{
		auto u = this->sentinel;

		for (int i = this->h; i >= 0; i --)
			while(u->next[i] && u->next[i]->data < x)
				u = u->next[i];

		return u;
	}

	unsigned int pick_height();

public:
	void insert(int x);
	bool search(int x);
	bool remove(int x);
};

#endif // SKIPLIST_H

