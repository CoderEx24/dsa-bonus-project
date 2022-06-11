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
	       while (u->next[i] != nullptr && u->next[i]->data < x)
		       u = u->next[i];
	
	return u;
}
