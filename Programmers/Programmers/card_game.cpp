/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	
	bool flag = false;
	vector<vector<int>> temp(left.size() + 1, vector<int>(right.size() + 1));
	
	int i = 1, j = 1;
	temp[0].assign(right.size() + 1, -1);
	temp[0][0] = 0;

	for (i = 1; i < left.size() + 1; i++) {
		flag = false;
		for (j = 1; j<right.size() + 1; j++) {
			//왼쪽 값이 오른쪽 값보다 작은 경우
			if (left[i - 1] > right[j - 1]) {
				if (flag == true) {
					if (temp[i][j-1]!=-1) {
						flag = false;
						temp[i][j] = temp[i][j-1] + right[j - 1];
					}
					else
						temp[i][j] = -1;
				}
				else {
					temp[i][j] = max(temp[i][j - 1] + right[j - 1], temp[i - 1][j - 1] + right[j - 1]);
				}
			}
			else {
				if (flag == false) {
					if (temp[i - 1][j] != -1)
						temp[i][j] = temp[i - 1][j - 1];
					else
						temp[i][j] = 0;
					flag = true;
				}
				else
					temp[i][j] = -1;

			}
			answer = max(answer, temp[i][j]);


		}
	}
	return answer;
}

int main(void) {
	vector<int> left = { 3,2,5 };
	vector<int> right = { 2,4,1};

	vector<int> left1 = { 2,5,4 };
	vector<int> right1 = { 3,2,5,1,2,2 };
	
	vector<int> left2 = { 5,5,5,6 };
	vector<int> right2 = { 5,5,7,2,5,5,5,5 };
	
	vector<int> left3 = { 3,2,5 };
	vector<int> right3 = { 6,6,5,4 };

	vector<int> left4 = { 3,2,5,5,4,8,6,13 };
	vector<int> right4 = { 14,10};

	cout << solution(left, right) << "   7" << endl;
	cout << solution(left1, right1) << "   10"<<endl;
	cout << solution(left2, right2) << "   22" << endl;
	cout << solution(left3, right3) << "   0" << endl;
	cout << solution(left4, right4) << "   2" << endl;
}
*/