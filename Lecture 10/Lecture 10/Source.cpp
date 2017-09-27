#include <iostream>

int highest;

void checkHighest(int val)
{
	if (val > highest) highest = val;
}


int main()
{
	int a = 1, b = 2, c = 3, d = 4;

	checkHighest(a);
	checkHighest(b);
	checkHighest(c);
	checkHighest(d);

	std::cout << highest << std::endl;
	std::cin.get();
	
	return 0;
}