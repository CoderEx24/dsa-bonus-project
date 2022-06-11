#include "skiplist.hpp"

int main()
{
	SkipList<int> skiplist;
	skiplist.insert(1);
	skiplist.insert(2);
	skiplist.insert(3);
	skiplist.search(0); // return false
	skiplist.insert(4);
	skiplist.search(1); // return true
	skiplist.remove(0); // return false, 0 is not in skiplist
	skiplist.remove(1); // return true
	skiplist.search(1); // return false, 1 has already been deleted
}

