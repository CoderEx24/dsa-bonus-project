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
		this->next = new SkipListNode* [MAX_LIST_SIZE];
		
		for (int i = 0; i < MAX_LIST_SIZE; i ++)
			this->next = nullptr;
	}

	int data;
	SkipListNode **next;
};

#endif // SKIPLIST_H

