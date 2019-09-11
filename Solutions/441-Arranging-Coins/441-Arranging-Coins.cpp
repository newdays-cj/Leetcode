// 441-Arranging-Coins.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>

class Solution {
public:
	int arrangeCoins(int n) {
		long __n = n;
		if (__n <= 0) {
			return 0;
		}

		long k = pow(2 * (double)__n, 0.5) - 1;
		/* (k + 1) * k / 2 <= n < (k + 2) * (k + 1) / 2 */
		while ((k + 2) * (k + 1) <= 2 * __n) {
			k++;
		}
		return k;
	}
};

int main()
{
	Solution solution;
	solution.arrangeCoins(2147483647);
}
