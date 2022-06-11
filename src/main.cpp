#include "skiplist.hpp"

int main()
{
	SkipList<int> skiplist(100);
	for (auto i : {21, 32, 43, 64, 75, 64, 37, 48, 59, 100})
	{	
		skiplist.insert(i);
	}
	skiplist.print();
	//	skiplist.search(0); // return false
//	skiplist.insert(4);
//	skiplist.search(1); // return true
//	skiplist.remove(0); // return false, 0 is not in skiplist
//	skiplist.remove(1); // return true
//	skiplist.search(1); // return false, 1 has already been deleted
}

