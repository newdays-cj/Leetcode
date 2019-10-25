#include <vector>

using namespace std;

class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> ret = vector<int>(num_people, 0);
		int total = 0;
		int i = 0;
		while (1) {
			for (int j = 0; j < num_people; j++) {
				int tmp = i * num_people + j + 1;
				if (candies - total > tmp) {
					ret[j] += tmp;
					total += tmp;
				}
				else {
					ret[j] += candies - total;
					return ret;
				}
			}
			i++;
		}
	}
};