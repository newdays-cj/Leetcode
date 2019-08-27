// 2-Add-Two-Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* p3 = new ListNode(0);
		ListNode* r = p3;
		int carry = 0;

		while (p1 != NULL && p2 != NULL) {
			int temp = p1->val + p2->val + carry;
			carry = temp / 10;
			p3->next = new ListNode(temp % 10);
			p3 = p3->next;
			p1 = p1->next;
			p2 = p2->next;
		}

		if (p1 == NULL) {
			p1 = p2;
		}

		while (p1 != NULL) {
			int temp = p1->val + carry;
			carry = temp / 10;
			p3->next = new ListNode(temp % 10);
			p3 = p3->next;
			p1 = p1->next;
		}

		if (carry != 0) {
			p3->next = new ListNode(carry);
		}

		p3 = r;
		r = r->next;
		delete p3;
		return r;
	}
};


int main()
{
	ListNode* parm1 = new ListNode(2);
	parm1->next = new ListNode(4);
	parm1->next->next = new ListNode(3);

	ListNode* parm2 = new ListNode(5);
	parm2->next = new ListNode(6);
	parm2->next->next = new ListNode(4);

	Solution solution;
	solution.addTwoNumbers(parm1, parm2);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
