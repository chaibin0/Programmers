/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool checkVisit(vector<bool> visit);

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<bool> visit(n);
	vector<bool> cost(costs.size());
	int key = 0;
	int min = 0;
	while (checkVisit(visit)) {
		key = 0;
		for (int i = 0; i < costs.size(); i++) {
			if (visit[costs[i][0]] != true || visit[costs[i][1]] != true) {
				if (min > costs[i][2] || key == 0) {
					key = i;
					min = costs[i][2];
				}
			}
		}

		answer += min;
		visit[costs[key][0]] = true;
		visit[costs[key][1]] = true;
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
	vector<vector<int>> costs = { { 0,1,1 },{ 0,2,2 },{ 1,2,5 },{ 1,3,1 },{ 2,3,8 } };
	cout << solution(n, costs) << endl;
}
*/