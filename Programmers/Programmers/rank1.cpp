/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
int solution(int n, vector<vector<int>> results) {
	map<int, queue<int>> nmap;
	vector<vector<bool>> barr(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++) {
		barr[i][i] = true;
	}
	for (auto x : results) {
		nmap[x[0]].push(x[1]);
	}

	for (auto x : nmap) {
		int start = x.first;
		queue<int> q = x.second;
		while (!q.empty()) {
			int cvalue = q.front();
			q.pop();
			if (barr[start][cvalue] == false) {
				barr[start][cvalue] = true;
				barr[cvalue][start] = true;
				queue<int> tq = nmap[cvalue];
				while (!tq.empty()) {
					q.push(tq.front());
					tq.pop();
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (barr[i][j] == false) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cnt++;
		}
	}

	return cnt;
}

int main(void) {
	int n = 5;
	vector<vector<int>> results = { { 4,3 },{ 4,2 },{ 3,2 },{ 1,2 },{ 2,5 } };
	//vector<vector<int>> results = { {1,3},{2,3},{3,4},{3,5},{4,6},{5,6} };
	cout << solution(n, results) << endl;
}
*/