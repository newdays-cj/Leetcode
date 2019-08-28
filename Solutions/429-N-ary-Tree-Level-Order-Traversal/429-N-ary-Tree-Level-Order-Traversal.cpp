// 429-N-ary-Tree-Level-Order-Traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
private:
	static vector<int> __levelOrder(queue<Node*> *current_queue, queue<Node*>  *next_queue)
	{
		vector<int> ret;
		/* next_queue should be empty */
		while (!next_queue->empty()) {
			next_queue->pop();
		}

		while (!current_queue->empty()) {
			Node* tmp = current_queue->front();
			current_queue->pop();;

			ret.push_back(tmp->val);

			for (auto iter = tmp->children.begin(); iter != tmp->children.end(); iter++) {
				next_queue->push(*iter);
			}
		}

		return ret;
	}
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ret;
		queue<Node*> *current_queue = new queue<Node*>; /* use pointer to swap queue better */
		queue<Node*> *next_queue = new queue<Node*>;

		if (root == NULL) {
			return ret;
		}

		current_queue->push(root);
		while (!current_queue->empty()) {
			vector<int> layer = __levelOrder(current_queue, next_queue); /* current_queue will be empty */
			ret.push_back(layer);

			queue<Node*>* tmp = current_queue; /* swap current queue and next queue */
			current_queue = next_queue;
			next_queue = tmp;
		}

		delete current_queue;
		delete next_queue;
		return ret;
	}
};


int main()
{
}