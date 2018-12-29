#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> que;
	string temp;

	for (int i = 0; i < operations.size(); i++) {
		sort(que.begin(), que.end());

		if (operations[i][0] == 'I') {
			temp = operations[i].substr(2, string::npos);
			int a = stoi(temp);
		//	if(find(que.begin(),que.end(),a)!=que.end())
			que.push_back(a);
		}
		else if (operations[i][0] == 'D') {
			temp = operations[i].substr(2, string::npos);
			int a = stoi(temp);
			if(!que.empty())
				if (a == -1) {
					que.pop_front();
				}
				else if(a == 1) {
					que.pop_back();
				}
		}
	}
	sort(que.begin(), que.end());

	if (que.empty())
		return { 0,0 };
	answer.push_back(que[que.size() - 1]);
	answer.push_back(que[0]);

	return answer;
}

/*
int main(void) {
	//vector<string> operation = { "I 16","D 1" };
	vector<string> operation = { "I 16","I 16","I 3","D 1" };
	//vector<string> operation = { "I 7","I 5","I -5","D -1" };
	vector<int> a = solution(operation);
	cout << a[0] << " " << a[1] << endl;
}

*/