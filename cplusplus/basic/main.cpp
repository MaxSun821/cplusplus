// c++基础

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
	int repeatedNTimes(vector<int>& nums) {
		unordered_map<int, int> un_map;
		size_t len = nums.size();
		for(auto e : nums)
		{
			un_map[e]++;
		}

		for(auto e : un_map)
		{
			if(un_map.count(e.first) == len / 2)
			{
				return e.first;
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> v = {1,2,3,3};
	int ret = s.repeatedNTimes(v);

	cout << ret << endl;
	return 0;
}

