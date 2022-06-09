#include"Set.h"

Set &Set::operator=(const Set &s)
{
	if (this == &s)
	{
		return *this;
	}
	if (set != nullptr)
	{
		delete[]set;
	}
	size = s.size;
	set = new int[size];
	for (int i = 0; i < size; i++)
	{
		set[i] = s.set[i];
	}

	return *this;
}

void Set::sort()
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && set[j - 1] > set[j]; j--)
		{
			int tmp = set[j - 1];
			set[j - 1] = set[j];
			set[j] = tmp;
		}
	}
}

Set::Set()
{
	size = 0;
	set = nullptr;
}

Set::Set(int size, int *set)
{
	this->size = size;
	this->set = set;
	this->set = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->set[i] = set[i];
	}
}

Set::Set(int size)
{
	this->size = size;
	set = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->set[i] = i;
	}
}

Set::Set(const Set &s)
{
	this->size = s.size;
	this->set = s.set;
	set = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->set[i] = s.set[i];
	}
}

Set::~Set()
{
	delete[]set;
}

void Set::printSet()
{
	std::cout << "size = " << size << std::endl;
	std::cout << "{";
	for (int i = 0; i < size; i++)
	{
		std::cout << set[i];
		if (i == size - 1)
		{
			break;
		}
		else
		{
			std::cout << ", ";
		}
	}
	std::cout << "}" << std::endl << std::endl;
}

bool Set::elementMembershipCheck(const int &element)
{
	for (int i = 0; i < size; i++)
	{
		if (element == set[i])
		{
			return true;
		}
	}
	return false;
}

Set &Set::addElement(const int &element)
{
	if (!this->elementMembershipCheck(element))
	{
		int *_set = new int[++size];
		for (int i = 0; i < size - 1; i++)
		{
			_set[i] = set[i];
		}
		_set[size - 1] = element;
		delete[]set;
		set = _set;
	}
	
	return *this;
}

Set &Set::deleteElement(const int &element)
{
	if (this->elementMembershipCheck(element))
	{
		int *_set = new int[--size];
		for (int i = 0, j = 0; i <= size; i++)
		{
			if (element != set[i])
			{
				_set[j] = set[i];
				j++;
			}
		}

		delete[]set;
		set = _set;
	}
	
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Set &s)
{
	out << "size = " << s.size << std::endl;
	if (s.set == nullptr)
	{
		out << "*set = nullptr" << std::endl << std::endl;
		return out;
	}
	else
	{
		out << "{";
		for (int i = 0; i < s.size; i++)
		{
			out << s.set[i];
			if (i == s.size - 1)
			{
				break;
			}
			else
			{
				out << ", ";
			}
		}
		out << "}" << std::endl << std::endl;
	}
	return out;
}

std::istream &operator>>(std::istream &in, Set &s)
{
	int element;
	in >> element;
	s.addElement(element);

	return in;
}

bool operator==(Set &s1, Set &s2)
{
	if (s1.size == s2.size)
	{
		Set _s1(s1);
		Set _s2(s2);
		_s1.sort();
		_s2.sort();
		for (int i = 0; i < _s1.size; i++)
		{
			if (_s1.set[i] == _s2.set[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

Set operator+(const Set &s, const int &element)
{
	Set _s;
	return _s.addElement(element);
}

Set operator+=(Set &s, int const &element)
{
	return s.addElement(element);
}

Set operator-(const Set &s, const int &element)
{
	Set _s(s);
	return _s.deleteElement(element);
}

Set operator-=(Set &s, const int &element)
{
	return s.deleteElement(element);
}

Set operator+(const Set &s1, const Set &s2)
{
	Set _s(s1);
	for (int i = 0; i < s2.size; i++)
	{
		_s.addElement(s2.set[i]);
	}

	return _s;
}

Set operator+=(Set &s1, const Set &s2)
{
	for (int i = 0; i < s2.size; i++)
	{
		s1.addElement(s2.set[i]);
	}

	return s1;
}

Set operator-(const Set &s1, const Set &s2)
{
	Set _s(s1);
	for (int i = 0; i < s2.size; i++)
	{
		_s.deleteElement(s2.set[i]);
	}

	return _s;
}

Set operator-=(Set &s1, const Set &s2)
{
	for (int i = 0; i < s2.size; i++)
	{
		s1.deleteElement(s2.set[i]);
	}

	return s1;
}

Set operator*(const Set &s1, const Set &s2)
{
	Set _s(s1);
	Set __s;
	for (int i = 0; i < s2.size; i++)
	{
		if (_s.elementMembershipCheck(s2.set[i]))
		{
			__s.addElement(s2.set[i]);
		}
	}
	return __s;
}

Set operator*=(Set &s1, const Set &s2)
{
	Set _s;
	for (int i = 0; i < s2.size; i++)
	{
		if (s1.elementMembershipCheck(s2.set[i]))
		{
			_s.addElement(s2.set[i]);
		}
	}
	return s1 = _s;
}
