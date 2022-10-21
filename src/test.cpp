#include"span.hpp"
#include<iostream>
#include<vector>
#include<array>

template<typename T>
void print(span<T> arr) {
	for (auto i : arr)
		std::cout << i << ' ';
	std::cout << '\n';
}

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
		for (auto j : i) {
			std::cout << j << ' ';
		}
	}

	std::cout << '\n';

	for (auto i = sp2.begin(); i != sp2.end(); i++) {
		std::cout << *i << ' ';
	}

	span<int>sp4(sp2);
	std::cout << sp4.data() << ' ' << sp2.data() << '\n';
	
	auto i =sp = sp;
	std::cout << sp.data() << ' ' << sp.data()<< ' ' << i.data() << '\n';

	std::cout << sp.size_types() << ' ' << sp2.size_types() << ' ' << sp3.size_types() << '\n';

	std::cout << sp2[2] << ' ' << sp2.front() << ' ' << sp2.back() << std::endl;

	auto n = sp2.first();
	for (auto i : n) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	n = sp2.first(4);
	std::cout << n.size() << std::endl;
	for (auto i : n) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	n = sp2.last(3);
	for (auto i : n) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	std::array<int, 10>arr{ 1,2,3,4,5,6,7,8,9,10 };
	span<int>sp5(arr);
	for (auto i : sp5) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	for (auto i : sp5.subspan(2, 7))
		std::cout << i << ' ';

	print<int>(v);
	
	std::cout << *(arr.begin() + 5) << std::endl;
	std::cout << *(arr.end() - 5) << std::endl;

}