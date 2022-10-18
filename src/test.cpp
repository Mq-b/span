#include"span.hpp"
#include<iostream>
#include<vector>
int main() {
	int array[1024]{};
	span<int> sp(array);
	std::cout << sp.size() << std::endl;

	std::vector<int>v{ 1,2,3,4,5,6 };
	span<int>sp2(v);
	std::cout << sp2.size() << std::endl;

	std::vector<int> v2[10]{ std::vector{1,2,3,4,5,6,7,8},std::vector{6,6,6,6,6,6} };
	span<std::vector<int>>sp3(v2);
	std::cout << sp3.size() << std::endl;
	

	for (auto i : sp3) {
		endl(std::cout);
		for (auto j : i) {
			std::cout << j << ' ';
		}
	}
	
}