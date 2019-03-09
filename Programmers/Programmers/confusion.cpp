/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
	vector<string> index = { "0","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	vector<int> answer;
	
	bool flag = true;
	vector<string>::iterator iter;
	int j;
	for (int i = 0; i < msg.size(); i++) {
		flag = true;
		string temp="";
		while (flag) {
			temp += msg[i];
			iter = find(index.begin(), index.end(), temp);
			if (iter != index.end()) {
				j = iter-index.begin();
				i++;
			}
			else {
				flag = false;
				answer.push_back(j);
				index.push_back(temp);
				i--;
			}
		}
	}
	return answer;
}
int main(void) {
	string msg ="KAKAO";
	vector<int> answer;
	answer = solution(msg);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
		cout << endl;
	}
}
*/