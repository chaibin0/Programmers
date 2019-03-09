
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace remove_cycle {
	void dfs(vector<vector<bool>> graph, vector<bool> visit, vector<bool> visit1, vector<int> current, int want, int previous, int position);

	vector<vector<int>> all_cycle;
	vector<int> count;
	int length = 0;

	int solution(int n, vector<vector<int>> edges) {
		vector<vector<bool>> graph(n, vector<bool>(n));
		vector<bool> visit(n);
		vector<bool> visit1(n);
		count.assign(n,0);
		int answer = 0;
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0] - 1][edges[i][1] - 1] = 1;
			graph[edges[i][1] - 1][edges[i][0] - 1] = 1;
		}

		for (int i = 0; i < n; i++) {
			visit[i] = true;
			for (int j = 0; j < n; j++) {
				vector<int> current;
				current.push_back(i);
				if(j!=i&&graph[i][j])
					dfs(graph, visit, visit1,current, i, i,j);

				
			}
			visit[i] = false;
			visit1[i] = true;
		}
		bool flag;
	
		
		for (int i = 0; i < n; i++) {
			if (count[i] == length)
				answer += i + 1;
		}
		return answer;
	}

	void dfs(vector<vector<bool>> graph, vector<bool> visit, vector<bool> visit1, vector<int> current,int want,int previous, int position) {
		visit[position] = true;
		current.push_back(position);

		for (int j = 0; j < graph.size(); j++) {
			if (j != previous&&graph[position][j]&&!visit1[j] && j == want) {
				for (int k = 0; k < current.size(); k++) 
					count[current[k]]++;
				length++;
			}
			if (!visit[j]&& !visit1[j] && j!=previous&&graph[position][j])
				dfs(graph, visit,visit1, current, want, position,j);
		}
		visit[position] = false;
	}
}

/*
void main(void) {
	vector<vector<int>> edges = { {1, 2},{1, 3},{2, 3},{2, 4},{3, 4} };
	//vector<vector<int>> edges = { {1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7},{7, 8},{8, 1},{2, 7},{3, 6} };
	cout<<remove_cycle::solution(8, edges)<<endl;
}

*/