// 1-Two-Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		map<int, int> map_nums;
		for (unsigned int i = 0U; i < nums.size(); ++i) {
			int complement = target - nums[i];
			if (map_nums.find(complement) != map_nums.end()) {
				result.push_back(i);
				result.push_back(map_nums[complement]);
				break;
			}
			else {
				map_nums.insert(make_pair(nums[i], i));
			}
		}
		return result;
	}
};

int main()
{
	vector<int> input = { 2, 7, 11, 15 };
	Solution solution;
	vector<int> result = solution.twoSum(input, 9);
	cout << result[0] << "," << result[1] << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
