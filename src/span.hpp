#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include<type_traits>
#include<iterator>

template<typename Ty>
struct span_iterator {
	using value_type = std::remove_cv_t<Ty>;
	using pointer = Ty*;
	using reference = Ty&;

	constexpr reference operator*()const noexcept {
		return *_ptr;
	}

	constexpr pointer operator->()const noexcept {
		return _ptr;
	}

	constexpr span_iterator& operator++()noexcept {
		++_ptr;
		return *this;
	}

	constexpr span_iterator& operator++(int)noexcept {
		span_iterator tmp{ *this };
		++*this;
		return tmp;
	}

	constexpr span_iterator operator--()noexcept {
		--_ptr;
		return *this;
	}

	constexpr span_iterator operator--(int)noexcept {
		span_iterator tmp{ *this };
		--* this;
		return tmp;
	}

	friend constexpr bool operator==(const span_iterator& v1, const span_iterator& v2) {
		return v1._ptr == v2._ptr;
	}

	pointer _ptr   = nullptr;
	pointer _begin = nullptr;
	pointer _end   = nullptr;
};

template<typename Ty>
class span {
public:

	using element_type = Ty;
	using pointer = Ty*;
	using const_pointer = const Ty*;
	using reference = Ty&;
	using iterator = span_iterator<Ty>;

	template<typename T>
	constexpr span(T &v)noexcept :_ptr{ std::data(v)}, _size{std::size(v)} {}

	constexpr size_t size()const noexcept { 
		return _size; 
	}

	constexpr bool empty()const noexcept {
		return _size == 0;
	}

	constexpr const_pointer data()const noexcept {
		return _ptr;
	}

	constexpr iterator begin()const noexcept {
		return { _ptr,_ptr,_ptr + _size};
	}

	constexpr iterator end()const noexcept {
		const auto End = _ptr + _size;
		return { End,_ptr,End};
	}


private:
	pointer _ptr;
	size_t _size;
};

#endif // __SPAN_HPP
