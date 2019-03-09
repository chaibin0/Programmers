/*
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<bool> visit(n);
	queue<int> temp;
	
	vector<vector<int>> graph(n, vector<int>(n));
	
	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0] - 1][edge[i][1] - 1] = 1;
		graph[edge[i][1] - 1][edge[i][0] - 1] = 1;
	}
	visit[0] = true;
	temp.push(0);
	int count;
	int temp_size;
	while (!temp.empty()) {
		count = 0;
		temp_size = temp.size();
		while(count<temp_size){
			int i = temp.front();
			temp.pop();
			for (int j = 0; j < visit.size(); j++) {
					if (graph[i][j] == 1 && visit[j] == false) {
						temp.push(j);
						visit[j] = true;
					}			
			}
			count++;
		}
	}
	return temp_size;
}


int main(void) {
	int n = 6;
	vector<vector<int>> vertex = { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} };
	cout << solution(n, vertex) << endl;
}
*/