/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> weight) {
	int answer = 0;
	int temp;
	vector<int> possible;
	for (int i = 0; i<weight.size(); i++) {
		temp = possible.size();
		for (int j = 0; j<temp; j++) {
			possible.push_back(possible[j] + weight[i]);
		}
		possible.push_back(weight[i]);
	}
	int i = 1;
	while (1) {
		if (find(possible.begin(), possible.end(), i) == possible.end()) {
			return i;
		}
		i++;
	}
	return answer;
}

int main(void) {
	vector<int> weight = { 3,1,6,2,7,30,1 };
	cout << solution(weight) << endl;
}
*/