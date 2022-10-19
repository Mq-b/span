## 参考MSVC源码和cppref的平凡实现span

经测试在MSVC C++11通过编译

只需要将`span.hpp`包含即可使用

```C++
#include"span.hpp"
#include<iostream>
#include<string>
#include<vector>

template<class T>
void print(span<T>sp) {
	for (auto i : sp)
		std::cout << i << ' ';
	std::cout << '\n';
}
int main() {
	char str[]{ "abcdefg" };
	std::vector<std::string>v{ "*","*","^","^" };
	print<char>(str);
	print<std::string>(v);
}
```