#include <iostream>
#include <cstdlib>
int func(int q, int r)
{
	return q + r;
}
int main(int argc, char** argv) {
	int item1, item2, sum;
	std::cout << "Enter first integer: ";
	std::cin >> item1;
	std::cout << "Enter second integer: ";
	std::cin >> item2;
	std::cout << "The sum is: " << func(item1, item2) << std::endl;
	return 0;
}