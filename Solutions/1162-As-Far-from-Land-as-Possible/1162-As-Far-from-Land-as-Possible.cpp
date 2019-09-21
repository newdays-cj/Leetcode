// 1162-As-Far-from-Land-as-Possible.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
	class Node
	{
	public:
		int x, y;

		Node(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};

	void in_queue(queue<class Node>& queue, vector<vector<int>>& grid, int x, int y, int val)
	{
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0) {
			grid[x][y] = val;
			queue.push(Node(x, y));
		}
	}

public:
	int maxDistance(vector<vector<int>>& grid) {
		queue<class Node> queue;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					queue.push(Node(i, j));
				}
			}
		}

		while (!queue.empty()) {
			class Node node = queue.front();
			queue.pop();

			in_queue(queue, grid, node.x + 1, node.y, grid[node.x][node.y] + 1);
			in_queue(queue, grid, node.x - 1, node.y, grid[node.x][node.y] + 1);
			in_queue(queue, grid, node.x, node.y + 1, grid[node.x][node.y] + 1);
			in_queue(queue, grid, node.x, node.y - 1, grid[node.x][node.y] + 1);
		}

		int ret = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (ret < grid[i][j]) {
					ret = grid[i][j];
				}
			}
		}

		if (ret <= 1) {
			ret = 0;
		}

		return ret - 1;
	}
};

int main()
{
	vector<vector<int>> input;
	input.push_back(vector<int>({ 1, 0, 1 }));
	input.push_back(vector<int>({ 0, 0, 0 }));
	input.push_back(vector<int>({ 1, 0, 1 }));
	Solution solution;
	int ret = solution.maxDistance(input);
	std::cout << ret;
}
