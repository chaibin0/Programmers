/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct T {
	int length;
	int donation;
};


int solution(int K, vector<vector<int>> travel) {
	int answer = 0;
	vector<vector<T>> temp(travel.size());
	T t1 = { travel[0][0],travel[0][1] };
	T t2 = { travel[0][2],travel[0][3] };
	temp[0].push_back(t1);
	temp[0].push_back(t2);
	for (int i = 0; i<travel.size() - 1; i++) {
		for (int j = 0; j<temp[i].size(); j++) {
			if (temp[i][j].length + travel[i + 1][0] <= K) {
				t1.length = temp[i][j].length + travel[i + 1][0];
				t1.donation = temp[i][j].donation + travel[i + 1][1];
				temp[i + 1].push_back(t1);
			}
			if (temp[i][j].length + travel[i + 1][2] <= K) {
				t2.length = temp[i][j].length + travel[i + 1][2];
				t2.donation = temp[i][j].donation + travel[i + 1][3];
				temp[i + 1].push_back(t2);
			}
		}
	}

	for (int i = 0; i<temp[travel.size()-1].size(); i++) {
		if (temp[travel.size()-1][i].length <= K)
			answer = max(answer, temp[travel.size()-1][i].donation);
	}
	return answer;
}


int main(void) {
	vector<vector<int>> travel = { {500, 200, 200, 100},{800, 370, 300, 120},{700, 250, 300, 90} };
	int K = 1650;
	cout << solution(K, travel) << endl;
}

*/