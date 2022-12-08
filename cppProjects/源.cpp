#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec = { 1,2,3,4,5 };
	std::ranges::for_each(vec, [](auto item) {cout << item << endl; });
	return 0;
}