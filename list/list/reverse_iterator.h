#pragma once

template <class Iterator>
class reverse_iterator
{
	typedef reverse_iterator<Iterator> self;
public:
	reverse_iterator(Iterator it)
		:_it(it)
	{}

	operator*()
	{
		Iterator prev = it;
		return *--prev;
	}

	self& operator++()
	{
		--_it;
		return *this;
	}
	self& operator--()
	{
		++_it;
		return *this;
	}	
	bool operator!=(const self& rit) const
	{
		return _it != rit._it;
	}
 
private:
	Iterator _it;
};