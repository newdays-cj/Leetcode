#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> index = vector<int>(nums.size(), -1);
        stack<int> stack;

        for (int i = 0; i < nums.size() * 2; ) {
            int __index = i % nums.size();
            if (stack.empty() && (index[__index] == -1)) {
                stack.push(__index);
                i++;
            } else {
                if (nums[stack.top()] < nums[__index]) {
                    index[stack.top()] = __index;
                    stack.pop();
                } else {
                    if (index[__index] == -1) {
                        stack.push(__index);
                    }
		    i++;
                }
            }
        }

        for (int i = 0; i < index.size(); ++i) {
            if (index[i] != -1) {
                index[i] =nums[index[i]];
            }
        }

        return index;
    }
};

int main(void)
{
	vector<int> result;
	vector<int> nums = {1,2,1};

	Solution s;
	result = s.nextGreaterElements(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}
