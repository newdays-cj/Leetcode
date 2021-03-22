#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int tmp = 1;

        if (num == 1) {
            return false;
        }

        for (int i = 2; i * i < num; i++) {
            if (num % i == 0) {
                tmp += i + num / i;
                if (tmp > num) {
                    return false;
                }
            }
        } 

        if (tmp == num) {
            return true;
        }

        return false;
    }
};

int main(void)
{
	Solution s;
	for (int i = 1; i < 10; i++) {
		cout << s.checkPerfectNumber(i) << endl;
	}
}
