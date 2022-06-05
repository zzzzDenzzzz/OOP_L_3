#include"Set.h"

int main()
{
	int a[]{ 10, 20, 30 };
	Set s1, s2{ 5 }, s3{ 3, a };
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;

	return 0;
}