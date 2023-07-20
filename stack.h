#pragma once

#include <deque>
#include <initializer_list>

namespace my_stack {

template<typename T, typename C = std::deque<T>>
class stack {
public:
	typedef typename C::value_type value_type;
	typedef typename C::size_type size_type;
	typedef typename C::const_reference const_reference;
	typedef typename C::reference reference;
	typedef C container_type;

	stack() = default;
	stack(std::initializer_list<T> initList) : c{ initList } {}
	template<typename InitIter>
	stack(InitIter begin, InitIter end) : c{ begin,end } {};
	stack& operator=(const stack& other) 
	{
		if (c != other.c()) {
			c = other.c();
		}
		return *this;
		
	};
	stack& operator=(stack&& other)
	{
		c = std::move(other);
	};
	~stack() = default;

	reference top()
	{
		c.back();
	}

	const_reference top()const
	{
		c.back();
	}

	bool empty()const
	{
		return c.empty();
	}

	size_type size()const
	{
		return c.size();
	}

	void push(const value_type& value)
	{
		c.push_back(value);
	}

	void push(value_type&& value)
	{
		c.push_back(std::move(value));
	}

	template<typename ...Args>
	void emplace(Args&&... args)
	{
		c.emplace_back(std::forward<Args>(args)...);
	}

	void pop()
	{
		c.pop_back();
	}

	void swap(stack& other)
	{
		std::swap(c, other.c);
	}

	template<typename T, typename C>
	friend bool operator==(const stack<T, C>& x, const stack<T, C>& y);

	template<typename T, typename C>
	friend bool operator!=(const stack<T, C>& x, const stack<T, C>& y);

	template<typename T, typename C>
	friend bool operator<(const stack<T, C>& x, const stack<T, C>& y);

	template<typename T, typename C>
	friend bool operator<=(const stack<T, C>& x, const stack<T, C>& y);

	template<typename T, typename C>
	friend bool operator>(const stack<T, C>& x, const stack<T, C>& y);

	template<typename T, typename C>
	friend bool operator>=(const stack<T, C>& x, const stack<T, C>& y);
	
protected:
	C c;
};


template<typename T, typename C>
bool operator==(const stack<T, C>& x, const stack<T, C>& y)
{
	return x.c == y.c;
}

template<typename T, typename C>
bool operator!=(const stack<T, C>& x, const stack<T, C>& y)
{
	return !(x == y);
}

template<typename T, typename C>
bool operator<(const stack<T, C>& x, const stack<T, C>& y)
{
	return x.c < y.c;
}

template<typename T, typename C>
bool operator<=(const stack<T, C>& x, const stack<T, C>& y)
{
	return (x < y) && (x == y);
}

template<typename T, typename C>
bool operator>(const stack<T, C>& x, const stack<T, C>& y)
{
	return !(x < y);
}

template<typename T, typename C>
bool operator>=(const stack<T, C>& x, const stack<T, C>& y)
{
	return (x > y) && (x == y);
}

}