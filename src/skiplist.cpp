#include "skiplist.hpp"

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
