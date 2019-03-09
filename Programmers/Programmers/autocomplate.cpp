
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

namespace autocomplate{
int solution(vector<string> words) {
	int answer = 0;
	bool flag = true;
	int count;
	int size;
	int i;
	for (i = 0; i < words.size(); i++) {
		deque<string> check;
		count = 0;
		for (int j = 0; j < words.size(); j++) {
			if (i == j)
				continue;
			if (words[i][count] == words[j][count]) {
				check.push_back(words[j]);
			}
		}
		count++;
		while (!check.empty()) {
			if (count >= words[i].length())
				break;
			size = check.size();
			for (int j = 0; j < size; j++) {
				string temp = check.front();
				if (words[i][count] == temp[count]) {
					check.push_back(temp);
				}
				check.pop_front();
			}
			count++;
			
		}
		answer += count;
	}
	return answer;
}
}
/*
int main(void) {
	//vector<string> words = { "go", "gone", "guild" };
	vector<string> words = { "word", "war", "warrior", "world" };
	cout << solution(words) << endl;
}
*/
