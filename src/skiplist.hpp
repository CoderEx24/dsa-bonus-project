#ifndef   SKIPLIST_H
#define   SKIPLIST_H

#include <random>
template<class T_>
struct SkipListNode
{
	T_ data;
	SkipListNode **next;	
};


template<class T>
class SkipList
{
	SkipListNode<T> sentinel;
	int h;

	SkipListNode<T>* find_pred_node(T x);
	unsigned int pick_height();
	
public:
	SkipList<T>(): h(0) {}

	void insert(T x);
	bool search(T x);
	bool remove(T x);

};

#endif // SKIPLIST_H 

