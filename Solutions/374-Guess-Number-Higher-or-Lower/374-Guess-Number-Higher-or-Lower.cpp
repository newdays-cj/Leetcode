// 374-Guess-Number-Higher-or-Lower.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
extern int guess(int num)
{
	if (num > 6)
		return -1;
	if (num == 6)
		return 0;
	if (num < 6)
		return 1;
}

class Solution {
public:
	int guessNumber(int n)
	{
		int left, right, mid;
		left = 1;
		right = n;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			switch (guess(mid)) {
			case 0:
				return mid;
			case 1:
				left = mid + 1;
				break;
			case -1:
				right = mid - 1;
				break;
			default:
				return -1;
			}
		}
		return -1;
	}
};
int main()
{
	Solution solution;
	solution.guessNumber(10);
}
