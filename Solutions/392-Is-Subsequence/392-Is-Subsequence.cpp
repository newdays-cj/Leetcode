// 392-Is-Subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		auto iter_s = s.begin();
		if (iter_s == s.end()) { //s is ""
			return true;
		}
		for (auto iter_t = t.begin(); iter_t != t.end(); iter_t++)
		{
			if (*iter_s == *iter_t) {
				iter_s++;
				if (iter_s == s.end()) {
					return true;
				}
			}

		}
		return false;
	}
};

int main()
{
	Solution solution;
	solution.isSubsequence("axc", "ahbgdc");
	solution.isSubsequence("abc", "ahbgdc");
}