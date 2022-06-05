#include "Set.h"

Set::Set()
{
	this->size_set = 0;
	this->set = nullptr;
}

Set::Set(int size_set)
{
	this->size_set = size_set;
	set = new int[size_set];
	for (int i = 0; i < size_set; i++)
	{
		this->set[i] = i;
	}
}

Set::Set(int size_set, int *set)
{
	this->size_set = size_set;
	this->set = set;
	this->set = new int[size_set];
	for (int i = 0; i < size_set; i++)
	{
		this->set[i] = set[i];
	}
}

Set::~Set()
{
	delete[]set;
}

std::ostream &operator<<(std::ostream &out, Set &s)
{
	if (s.set != nullptr)
	{
		for (int i = 0; i < s.size_set; i++)
		{
			out << s.set[i] << " ";
		}
	}
	else
	{
		out << "Error";
	}
	
	return out;
}