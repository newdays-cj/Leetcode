#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int __findBottomLeftVaule(TreeNode* root, int& deep) {
        int rval, lval, rdeep = 0, ldeep = 0;

        if (root->right == NULL && root->left == NULL) {
            deep = 1;
            return root->val;
        }

        if (root->right != NULL) {
            rval = __findBottomLeftVaule(root->right, rdeep);
        }

        if (root->left != NULL) {
            lval = __findBottomLeftVaule(root->left, ldeep);
        }

        if (ldeep >= rdeep) {
            deep = ldeep + 1;
            return lval;
        } else {
            deep = rdeep + 1;
            return rval;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        int deep;
        return __findBottomLeftVaule(root, deep);
    }
};

int main(void)
{
	return 0;
}
