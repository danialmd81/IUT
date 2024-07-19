#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	vector<int> vec2{10, 11, 12, 13};
	vector<int> vec3;
	merge(vec.end(), vec.begin(), vec2.begin(), vec2.end(), back_inserter(vec3));
	for (auto x : vec3)
	{
		cout << x << " ";
	}
}
