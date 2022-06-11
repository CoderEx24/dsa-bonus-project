#include "skiplist.hpp"

void print(bool b, int x)
{
	std::cout << x << " is" << (b ? "" : " not") << " in the list\n";
}

int main()
{
	SkipList skiplist;
	for (auto i : {21, 32, 43, 64, 75, 64, 37, 48, 59, 100})
	{	
		skiplist.insert(i);
	}
	skiplist.print();
	print(skiplist.search(10), 10); // return false
	skiplist.insert(4);
	print(skiplist.search(1), 1); // return true
	skiplist.remove(0); // return false, 0 is not in skiplist
	skiplist.remove(75); // return true
	print(skiplist.search(75), 75);	// return false, 1 has already been deleted

	skiplist.print();
}

