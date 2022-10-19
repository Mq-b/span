## 参考MSVC源码和cppref的平凡实现span

经测试在MSVC C++11通过编译

只需要将`span.hpp`包含即可使用

```
#include"span.hpp"
#include<iostream>
void print(span<int>sp) {
	for (auto i : sp)
		std::cout << i << ' ';
	std::cout << '\n';
}
int main() {
	int array[]{ 6,6,6,6 };
	print(array);
}

```C++