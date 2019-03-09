/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> graph(n, vector<bool>(n));
	queue<int> temp;
	vector<int> visit(n);
	vector<int> rank(n);

	//그래프화
	for (int i = 0; i < results.size(); i++) {
		graph[results[i][0]-1][results[i][1]-1] = true;
		visit[results[i][0]-1]++;
	}

	for (int i = 0; i < visit.size(); i++) {
		if (visit[i] == 0) {
			temp.push(i);
		}
	}
	
	rank.assign(n, n);

	while (!temp.empty()) {
		int j = temp.front();
		temp.pop();
		cout << j << "를 뽑을 때"<<endl;
		for (int i = 0; i < results.size(); i++) {
			if (graph[i][j] == true) {
				temp.push(i);
				if (rank[i] == n)
					rank[i] = rank[j] - 1;
				else
					rank[i]--;
			}
		}
	}
	rank.push_back(n + 1);
	rank.push_back(0);

	
	sort(rank.begin(), rank.end());
	for (int i = 0; i < rank.size(); i++)
		cout << rank[i] << " ";
	cout << endl;
	for (int k = 1; k < rank.size()-1; k++) {
		if (rank[k] == k) {
			if(rank[k-1]!=rank[k]&&rank[k]!=rank[k+1])
				answer++;	
		}
	}

	return answer;
}

int main(void) {
	int n = 5;
	vector<vector<int>> results = { {4,3}, {4,2},{3,2},{1,2},{2,5} };
	//vector<vector<int>> results = { {1,3},{2,3},{3,4},{3,5},{4,6},{5,6} };
	cout << solution(n, results) << endl;
}


*/