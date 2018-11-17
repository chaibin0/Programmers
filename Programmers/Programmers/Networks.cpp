/* 2018-11-17 프로그래머스 네트워크 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> computers);
void checknetwork(vector<vector<int>> computers, vector<bool> &people, int num);

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool> people(n);	//방문 확인 용도
	people.assign(n,false);	//방문 안한걸로 초기화

	for (int i = 0; i<computers.size(); i++) {
		if (people[i] == true)
			continue;
		people[i] = true;
		for (int j = 0; j < computers[0].size(); j++) {
			if (i == j) continue;
			else if (people[j] == false && computers[i][j] == 1){
				checknetwork(computers,people,j);
			}
		}
		answer++;
	}
	return answer;
}

void checknetwork(vector<vector<int>> computers, vector<bool> &people, int num) {
	people[num] = true;
	for (int i = 0; i < computers[num].size(); i++) {
		if (i == num) continue;
		else if (people[i] == false && computers[num][i] == 1) {
			checknetwork(computers, people, i);
		}
	}
}

/*
int main(void) {
	//vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };
	vector<vector<int>> computers = { {1,1,0},{1,1,1},{0,1,1} };
	int n = 3;
	cout<<solution(n, computers)<<endl;
}
*/