// 1160-Find-Words-That-Can-Be-Formed-by-Characters.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	static void convert(string word, map<int, int>& chars)
	{
		chars.clear();
		for (auto iter = word.begin(); iter != word.end(); ++iter) {
			chars[*iter]++;
		}
	}

	static bool canForm(map<int, int>& word, map<int, int>& chars)
	{
		for (auto iter = word.begin(); iter != word.end(); ++iter) {
			if (iter->second > chars[iter->first]) {
				return false;
			}
		}
		return true;
	}

public:
	int countCharacters(vector<string>& words, string chars)
	{
		int ret = 0;
		map<int, int> map_chars;
		convert(chars, map_chars);

		for (auto iter = words.begin(); iter != words.end(); ++iter)
		{
			map<int, int> map_word;
			convert(*iter, map_word);
			if (canForm(map_word, map_chars)) {
				ret += iter->size();
			}
		}

		return ret;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
