/*

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int K, vector<vector<int>> travel) {
	vector<vector<int>> dp(travel.size() + 1, vector<int>(K + 1));
	int i, j;
	int answer = 0;
	for (i = 1; i < travel.size() + 1; i++) {
		for (j = 1; j <= K; j++) {
			if (j - travel[i - 1][0] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - travel[i - 1][0]] + travel[i - 1][1]);

			if (j - travel[i - 1][2] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - travel[i - 1][2]] + travel[i - 1][3]);

			answer = max(answer, dp[i][j]);
		}
	}
	return answer;
}


int main(void) {
//vector<vector<int>> travel = { {500, 200, 200, 100},{800, 370, 300, 120},{700, 250, 300, 90} };
vector<vector<int>> travel = { {1100, 1900, 400, 900},{  300, 700,1000, 2000},{400, 700,900, 1800 },{1200, 2300, 500, 1200} };
int K = 3000;
cout << solution(K, travel) << endl;
}

*/

