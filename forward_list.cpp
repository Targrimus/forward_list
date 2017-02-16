#include <iostream>
#include "forward_list.h"

int main(int argc, char ** argv)
{
	forward_list<int> numbers;

	numbers.push_back(10).push_back(22).push_back(55);
	std::cout << "is empty: " << std::boolalpha << numbers.empty() << std::endl;
	numbers.pop_front();
	std::cout << "front: " << numbers.front() << std::endl;
	std::cout << "back: " << numbers.back() << std::endl;

	return 0;
}
