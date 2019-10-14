#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int min_r = m;
		int min_c = n;
		for (int i = 0; i < ops.size(); i++) {
			if (ops[i][0] < min_r) {
				min_r = ops[i][0];
			}
			if (ops[i][1] < min_c) {
				min_c = ops[i][1];
			}
		}
		return min_r * min_c;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
