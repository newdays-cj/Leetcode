#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        int num[3] = {0, 1, 1};

        for (int i = 2; i <= n; i++) {
            num[i % 3] = num [(i - 1) % 3] + num [(i - 2) % 3];
        }
        
        return num[n % 3];
    }
};

int main(void)
{
	Solution s;
	for (int i = 0; i < 10; i++) {
		cout << s.fib(i) << endl;
	}
	
	return 0;
}
