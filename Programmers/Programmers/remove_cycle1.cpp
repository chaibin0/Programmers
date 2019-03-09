
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace remove_cycle1 {
	bool check(const vector<int> temp,int i);
	void remove(vector<vector<int>> graph, vector<int> &temp, int i,int n);

	int solution(int n, vector<vector<int>> edges) {
		vector<vector<int>> graph(n);
		vector<int> value(n);
		vector<int> temp;
		bool cycle = false;
		bool flag = true;

		int answer = 0;
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0] - 1].push_back(edges[i][1] - 1);
			graph[edges[i][1] - 1].push_back(edges[i][0] - 1);

			value[edges[i][0] - 1]++;
			value[edges[i][1] - 1]++;
		}
		for (int i = 0; i < n; i++) {
			if (value[i] == 1) {
				remove(graph, value, i, i);
				continue;
			}
		}
		for (int i = 0; i < n; i++) {
			if (value[i] <= 0)
				continue;
			cout << "i=" << i << "일 때" << endl;
			temp = value;
			cycle = true;
			temp[i] = 0;
			remove(graph, temp, i,i);
			cout << i << "번째 제거" << endl;
			for (int i = 0; i < n; i++) {
				cout << temp[i] << " ";
			}
			cout << endl;

			while (flag) {
				for (int j = 0; j < n; j++) {
					if (j == i)
						continue;
					if (temp[j] == 1) {
						flag = true;
						remove(graph, temp, i,j);
						cout << j << "번째 제거" << endl;
						for (int i = 0; i < n; i++) {
							cout << temp[i] << " ";
						}
						cout << endl;
					}
					else 
						flag = false;
				}
			}

			if (check(temp,i)) {			
				answer += i + 1;
			}
			
		}
		
		return answer;
	}
	bool check(const vector<int> temp,int n) {
		cout << endl << "검사" << endl;
		for (int i = 0; i < temp.size(); i++) {
			cout << temp[i] << " ";
		}
		cout << endl << endl;
		for (int i = 0; i < temp.size(); i++) {

			if (i == n)
				continue;
			if (temp[i] > 0)
				return false;
		}
		return true;
	}
	void remove(vector<vector<int>> graph,vector<int> &temp,int i,int n) {
		for (int j = 0; j < graph[n].size(); j++) {
			if (graph[n][j] == i)
				continue;
			temp[graph[n][j]]--;
			if (temp[graph[n][j]] == 1) {
				temp[graph[n][j]] = 0;
				remove(graph, temp, i, graph[n][j]);
				cout << j << "번째 제거" << endl;
				for (int i = 0; i < graph.size(); i++) {
					cout << temp[i] << " ";
				}
			}
			cout << endl;		
		}
	}
}
/*
void main(void) {
	//vector<vector<int>> edges = { { 1, 2 },{ 1, 3 },{ 2, 3 },{ 2, 4 },{ 3, 4 } };
	vector<vector<int>> edges = { {1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7},{7, 8},{8, 1},{2, 7},{3, 6} };
	//vector<vector<int>> edges = { { 1, 2 },{ 2, 3 },{ 3, 1 },{ 3, 4 },{ 4, 5 },{ 2, 5 },{2,4} };
	cout << remove_cycle1::solution(8, edges) << endl;
}

*/