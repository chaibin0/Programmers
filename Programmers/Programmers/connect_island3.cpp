/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool checkVisit(vector<bool> visit);

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<bool> visit(n);
	vector<vector<int>> temp(n,vector<int>(n));
	int min = costs[0][2];
	int minnode1=costs[0][0], minnode2=costs[0][1];
	for (int i = 0; i < costs.size(); i++) {		//그래프화
		temp[costs[i][0]][costs[i][1]] = costs[i][2];
		temp[costs[i][1]][costs[i][0]] = costs[i][2];
		if (costs[i][2] < min) {
			min = costs[i][2];
			minnode1 = costs[i][0];
			minnode2 = costs[i][1];
		}
	}
	answer += min;
	visit[minnode1] = true;
	visit[minnode2] = true;
	min = -1;
	
	while (checkVisit(visit)) {
		for (int i = 0; i < visit.size(); i++) {
			if (visit[i] != true)
				continue;
			for (int j = 0; j < visit.size(); j++) {
				if ((min == -1 || min > temp[i][j]) && visit[j] != true && temp[i][j] != 0) {
					min = temp[i][j];
					minnode1 = i;
					minnode2 = j;
				}
			}
		}
		visit[minnode1] = true;
		visit[minnode2] = true;
		answer += min;
		min = -1;
	}
	return answer;
}

bool checkVisit(vector<bool> visit) {
	for (int i = 0; i < visit.size(); i++) {
		if (visit[i] == false) {
			return true;
		}
	}
	return false;
}

int main(void) {
int n = 4;
//vector<vector<int>> costs = { { 0,1,1 },{ 0,2,2 },{ 1,2,5 },{ 1,3,1 },{ 2,3,8 } };
vector<vector<int>> costs = { { 0,1,1 },{ 0,2,2 },{ 2,3,1 } };
cout << solution(n, costs) << endl;
}

*/
