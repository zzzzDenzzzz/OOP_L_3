#pragma once

#include<iostream>
#include<ostream>
#include<istream>

class Set
{
	int size;
	int *set;
	void sort();
	friend std::ostream &operator<<(std::ostream &out, const Set &s);
	friend std::istream &operator>>(std::istream &in, Set &s);
	friend bool operator==(Set &s1, Set &s2);
	friend Set operator+(const Set &s, const int &element);
	friend Set operator+=(Set &s, int const &element);
	friend Set operator-(const Set &s, const int &element);
	friend Set operator-=(Set &s, const int &element);
	friend Set operator+(const Set &s1, const Set &s2);
	friend Set operator+=(Set &s1, const Set &s2);
	friend Set operator-(const Set &s1, const Set &s2);
	friend Set operator-=(Set &s1, const Set &s2);
	friend Set operator*(const Set &s1, const Set &s2);
	friend Set operator*=(Set &s1, const Set &s2);
public:
	Set();
	Set(int size, int *set);
	Set(int size);
	Set(const Set &s);
	~Set();
	void printSet();
	bool elementMembershipCheck(const int &element);
	Set &addElement(const int &element);
	Set &deleteElement(const int &element);
	Set &operator=(const Set &s);
};