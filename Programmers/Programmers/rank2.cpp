#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 105;

int N, M;
bool reach[MAXN][MAXN];
int total = 0;
int solution(int n, vector<vector<int>> results) {
	//그래프화
	for (int i = 0; i < results.size(); i++)
		reach[i][i] = true;

	for (int i = 0; i < results.size(); i++) {
		reach[results[i][0] - 1][results[i][1] - 1] = true;
	}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			if (reach[i][k])
				for (int j = 0; j < N; j++)
					if (reach[k][j])
						reach[i][j] = true;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << reach[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++)
	{
		bool good = true;

		// we can find the rank of a cow if all other cows are connected to it
		for (int j = 0; j < N; j++)
			if (!reach[i][j] && !reach[j][i])
			{
				good = false;
				break;
			}

		if (good)
			total++;
	}
	return total;
}

/*
int main()
{
	int n = 5;
	//vector<vector<int>> results = { { 4,3 },{ 4,2 },{ 3,2 },{ 1,2 },{ 2,5 } };
	vector<vector<int>> results = { { 5,5 },{ 4,3 },{ 4,2 },{ 3,2 },{ 1,2 },{2,5} };
	//vector<vector<int>> results = { {1,3},{2,3},{3,4},{3,5},{4,6},{5,6} };
	cout << solution(n, results) << endl;
	return 0;
}

*/
