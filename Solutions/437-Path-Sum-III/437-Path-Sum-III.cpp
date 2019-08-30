// 437-Path-Sum-III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
	int __pathSum(TreeNode* root, int sum) {
		int ret = 0;
		if (root != NULL) {
			if (sum == root->val) {
				ret += 1;
			}
			ret += __pathSum(root->left, sum - root->val);
			ret += __pathSum(root->right, sum - root->val);
		}
		return ret;
	}
public:
	int pathSum(TreeNode* root, int sum) {
		int ret = 0;
		ret += __pathSum(root, sum);
		if (root != NULL) {
			ret += pathSum(root->left, sum);
			ret += pathSum(root->right, sum);
		}
		return ret;
	}
};

int main()
{
}
