#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int indexsum = list1.size() + list2.size();
		string tmp;
		vector<string> ret;
		for (int i = 0; i < list1.size(); i++) {
			for (int j = 0; j < list2.size(); j++) {
				if (list1[i] == list2[j]) {
					if (i + j == indexsum) {
						ret.push_back(list1[i]);
					}
					if (i + j < indexsum) {
						ret.clear();
						ret.push_back(list1[i]);
						indexsum = i + j;
					}
				}
			}
		}

		return  ret;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
