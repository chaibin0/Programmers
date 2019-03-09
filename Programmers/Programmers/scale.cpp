/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool dfs(vector<int> weight, int number, int i, int n);
int solution(vector<int> weight) {
	int answer = 0;
	int number = 1;
	int k = 0;
	int i = 1;
	sort(weight.begin(), weight.end());
	while (1) {
		if (!(dfs(weight, number, k + weight[0], 0) || dfs(weight, number, k, 0)))
			return number;
		else
			number++;

	}
	return answer;
}

bool dfs(vector<int> weight, int number,int i,int n) {
	if (number == i)
		return 1;
	if (n+1 == weight.size())
		return 0;
	if (i + weight[n+1] > number)
		return 0;
	return dfs(weight, number, i + weight[n + 1], n + 1) || dfs(weight, number, i , n + 1);
}

int main(void) {
	vector<int> weight = { 3,1,6,2,7,30,1 };
	//vector<int> weight = { 3,1};
	cout << solution(weight) << endl;
}

*/