#include "Header.h"
#include <iostream>

int main() {

	Vector vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(8);
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.push_back(11);

	std::cout << vec[0];
}
