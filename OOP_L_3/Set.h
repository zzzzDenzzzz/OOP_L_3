#pragma once

#include<ostream>
#include<iostream>

class Set
{
	int size_set;
	int *set;
	friend std::ostream &operator<<(std::ostream &out, Set &s);
public:
	Set();
	Set(int size_set);
	Set(int size_set, int *set);
	~Set();
};