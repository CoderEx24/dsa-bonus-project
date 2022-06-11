#include "skiplist.hpp"

#include <random>
#include <vector>

template<class T>
unsigned int SkipList<T>::pick_height()
{
	int z = random();
	int k = 0;

	while(z | 1)
	{
		k++;
		z /= 2;
	}
	return k;
}

template<class T>
SkipListNode<T>* SkipList<T>::find_pred_node(T x)
{
	SkipList<T>* u = this->sentinel;

	for (int i = this->h; i >= 0; i--)
	       while (u->next[i] && u->next[i]->data < x)
		       u = u->next[i];
	
	return u;
}

template<class T>
bool SkipList<T>::search(T x)
{
	auto u = find_pred_node(x);
	
	return u.next[0];
}

template<class T>
void SkipList<T>::insert(T x)
{
	auto u = this->sentinel;
	std::vector<SkipListNode<T>*> stack;

	for (int i = this->h; i >= 0; i --)
	{
		while (u.next[i] && u.next[i].data < x)
			u = u.next[i];
		
		if (u.next[i] && u.next[i].data == x)
			return;	
		
		stack.push_back(u);
	}
	
	unsigned int h = this->pick_height();
	auto new_node = new SkipListNode<T>* {x, new SkipListNode<T>* [h] };
	
	while (this->h < h)
	{
		this->h++;
		stack.push_back(this->sentinel);
	}

	for (int i = 0; i < h; i ++)
	{
		new_node->next[i] = stack[i].next[i];
		stack[i].next[i] = new_node;	
	}

	return;
	
}

