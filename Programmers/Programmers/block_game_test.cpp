
#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check = false;
/*
int main(void){
	vector<vector<int>> garo = { {0,0,1},{1,1,1} };
	vector<vector<int>> board = { {0,0,2},{2,2,2} };
	vector<int> possible = { 2,2,2 };
	vector<int> count = { 0,0,0 };
	int temp = 0;		//일치율
	for (int b = 0, i_ =0; b < 2; b++, i_++) {
		for (int c = 0, j_ = 0; c < 3; c++, j_++) {
			if (garo[b][c] == board[i_][j_] || (garo[b][c]>0 && board[i_][j_]>0)) {
				if (garo[b][c] == 0) {
					temp++;
				}
				if (possible[j_] == board[i_][j_]) {
					temp++;
				}
			}

		}
	}
	if (temp == 6) {	//적중한게 있다
		for (int b = 0, i_ = 0; b < 2; b++) {
			for (int c = 0, j_ = 0; c < 3; c++) {
				cout << board[i_][j_] << " ";
				possible[j_] = 0;
				if (board[i_][j_] != 0) {
					board[i_][j_] = 0;
				}
				else
					count[j_] = max(count[j_], 1);
			}
			cout << endl;
		}
	}

	for (int i = 0; i < count.size(); i++)
		cout << count[i] << " ";
	cout << endl;
}
*/