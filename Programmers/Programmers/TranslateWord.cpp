/* 2018-11-17 프로그래머스 단어 변환 */
#include <string>
#include <iostream>
/* 2018-11-19 프로그래머스 단어 변환 */

#include <vector>
#include <queue>
using namespace std;
bool compstr(string first, string last);

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<vector<string>> temp;
	vector<bool> visit(words.size());
	visit.assign(words.size(), false);

	vector<string> next;
	next.push_back(begin);

	temp.push(next);
	while (!temp.empty()) {
		vector<string> a=temp.back();
		temp.pop();
		answer++;
		for (int i = 0; i < words.size(); i++) {
			if (compstr(a[a.size() - 1], words[i]) && target == words[i])
				return answer;
			else if ((a.end() == find(a.begin(), a.end(), words[i])) && compstr(a[a.size() - 1], words[i])){
				vector<string> b = a;
				b.push_back(words[i]);
				temp.push(b);
			}
		}
	}

		return 0;
}

bool compstr(string first, string last) {
	int temp = 0;
	for (int i = 0; i < first.length(); i++) {
		if (first[i] != last[i])
			temp++;		
		if (temp >= 2)
			return false;
	}
	if (temp == 1)
		return true;
	else
		return false;
}
/*
int main(void) {
	
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot","dot","dog","lot","log","cog" };
	cout << solution(begin, target, words) << endl;
	
	
	//string begin = "hit";
	//string target = "cog";
	//vector<string> words = { "hot","dot","dog","lot","log"};
	//cout << solution(begin, target, words) << endl;
	
}
*/