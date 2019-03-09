
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	bool flag = false;
	vector<vector<int>> temp(left.size() + 1, vector<int>(right.size() + 1));
	for (int i = 1; i < left.size() + 1; i++) {
		for (int j = 1; j < right.size() + 1; j++) {
			 temp[i][j] = max(temp[i - 1][j], temp[i - 1][j - 1]);
			 if (left[i - 1] > right[j - 1]) {
				 temp[i][j] = max(temp[i][j] , temp[i][j - 1]+right[j-1]);
			 }
			 cout << temp[i][j] << "  ";
		}
		cout << endl;
	}

	answer = temp[left.size()][right.size()];
	return answer;
}
/*
int main(void) {
	vector<int> left = { 5,2,2,2,2,2};
	vector<int> right = { 5,5,7,2,5,5 };
	//vector<int> left = { 3,2,5};
	//vector<int> right = { 2,4,1 };

	cout << solution(left, right) << endl;

}
*/

