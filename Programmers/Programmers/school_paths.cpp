#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int i, j;
	vector<vector<long>> temp(n + 2, vector<long>(m + 2));
	for (int i = 0; i < puddles.size(); i++) {
		temp[puddles[i][1]][puddles[i][0]] = -1;
	}

	for (i = 1; i<n + 1; i++) {
		for (j = 1; j<m + 1; j++) {
			if (((i == 1 && j == 2) || (i == 2 && j == 1)) && temp[i][j] != -1) {
				temp[i][j] = 1;
				continue;
			}
			if (temp[i][j] == -1)
				temp[i][j] == 0;
			else if (temp[i][j - 1] == -1 && temp[i - 1][j] == -1)
				temp[i][j] = 0;
			else if (temp[i][j - 1] == -1)
				temp[i][j] = temp[i - 1][j];
			else if (temp[i - 1][j] == -1)
				temp[i][j] = temp[i][j - 1];
			else
				temp[i][j] = (temp[i - 1][j] + temp[i][j - 1]) % 1000000007;
		}
	}
	answer = temp[i - 1][j - 1];
	return answer;
}
/*
int main(void) {
	int m = 4;
	int n = 3;
	vector<vector<int>> puddles = { {2,1},{1,2}};
	cout << solution(m, n, puddles) << endl;
}

*/