#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class queue_node {
public:
    string word;
    int distance;
    queue_node(string word, int distance) {
        this->word = word;
        this->distance = distance;
    }
};

class Solution {
private:
    int reach(string &word1, string &word2)
    {
        int diff = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) {
                diff++;
                if (diff > 1) {
                    break;
                }
            }
        }

        return diff == 1;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<queue_node> queue;

        queue.push(queue_node(beginWord,1));

        while(queue.size()) {
            for (auto iter = wordList.begin(); iter != wordList.end(); ) {
                auto current = queue.front();
                if (reach(current.word, *iter)) {
                    if (*iter == endWord) {
                        return current.distance + 1;
                    }
                    queue.push(queue_node(*iter, current.distance + 1));
                    iter = wordList.erase(iter);
                } else {
                    iter++;
                }
            }

            queue.pop();
        }

        return 0;
    }
};

int main(void)
{
	Solution s;
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
	cout << s.ladderLength(beginWord, endWord, wordList);

	return 0;
}
