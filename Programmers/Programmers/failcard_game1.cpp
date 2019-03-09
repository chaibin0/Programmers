/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	int leftmax = *max_element(left.begin(), left.end());

	vector<vector<int>> temp(left.size() + 1, vector<int>(right.size() + 1));
	int i = 1, j = 1;

	while (i < left.size() + 1 && j<right.size() + 1) {
		if (left[i - 1] > right[j - 1]) {
			temp[i][j] = temp[i][j - 1] + right[j - 1];
			answer = max(answer, temp[i][j]);
			j++;
		}
		else if (right[j - 1] >= leftmax) {
			if (i == left.size())
				break;
			temp[i + 1][j] = temp[i][j - 1];
			i++;
			j++;
			leftmax = *max_element(left.begin() + i-1, left.end());
		}
		else {
			temp[i + 1][j - 1] = temp[i][j - 1];
			i++;
		}
	}

	return answer;
}

int main(void) {
	vector<int> left = { 5,5,5,6 };
	vector<int> right = { 5,5,7,2,5,5,5,5 };

	cout << solution(left, right) << endl;
}
*/
