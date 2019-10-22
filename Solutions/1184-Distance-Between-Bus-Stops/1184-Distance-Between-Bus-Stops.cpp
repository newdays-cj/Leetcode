#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		int all = 0;
		for (int i = 0; i < distance.size(); i++) {
			all += distance[i];
		}

		int tmp = 0;
		if (start > destination) {
			destination = destination + distance.size();
		}

		for (int i = start; i < destination; i++) {
			tmp += distance[i % distance.size()];
		}

		return tmp > all - tmp ? all - tmp : tmp;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
