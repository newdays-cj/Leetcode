// 617-Merge-Two-Binary-Trees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 /*
class Solution {
private:
	static void __mergeTrees(TreeNode* t1, TreeNode* t2, TreeNode* &root)
	{
		if (t1 == NULL && t2 == NULL) {
			return;
		}

		root = new TreeNode((t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val));
		__mergeTrees((t1 == NULL ? NULL : t1->left), (t2 == NULL ? NULL : t2->left), root->left);
		__mergeTrees((t1 == NULL ? NULL : t1->right), (t2 == NULL ? NULL : t2->right), root->right);
	}
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* root = NULL;
		__mergeTrees(t1, t2, root);
		return root;
	}
};
*/

class Solution {
private:
	static void __mergeTrees(TreeNode* t1, TreeNode* t2, TreeNode*& root)
	{
		if (t1 == NULL && t2 != NULL) {
			root = t2;
		}

		if (t1 != NULL && t2 == NULL) {
			root = t1;
		}

		if (t1 != NULL && t2 != NULL) {
			root->val = t1->val + t2->val;
			__mergeTrees((t1->left), t2->left, t1->left);
			__mergeTrees((t1->right), t2->right, t1->right);
		}
	}
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		__mergeTrees(t1, t2, t1);
		return t1;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
