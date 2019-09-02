// 47-Permutations-II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
	static void __permuteUnique(vector<vector<int>>& result, vector<int>& pro_nums,
		map<int, int>& num_count, int count)
	{
		if (count == 0) {
			result.push_back(pro_nums);
			return;
		}

		for (auto iter = num_count.begin(); iter != num_count.end(); iter++)
		{
			if (iter->second == 0) {
				continue;
			}
			else {
				pro_nums.push_back(iter->first);
				iter->second -= 1;
				__permuteUnique(result, pro_nums, num_count, count - 1);
				iter->second += 1;
				pro_nums.pop_back();
			}
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		map<int, int> num_count;
		vector<vector<int>> result;
		vector<int> pro_nums;

		for (auto iter = nums.begin(); iter != nums.end(); iter++) {
			num_count[*iter] += 1;
		}

		__permuteUnique(result, pro_nums, num_count, nums.size());

		return result;
	}
};

int main()
{
	Solution solution;
	vector<int> input = { 1, 1, 2 };
	solution.permuteUnique(input);
	return 0;
}
