#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
namespace block_game {
	bool checkgaro(vector<int> &count, vector<int> &possible, vector<vector<int>> &board, int i, int j, int &answer);
	bool checksero(vector<int> &count, vector<int> &possible, vector<vector<int>> &board, int i, int j, int &answer);
	void checkline(vector<int> &possible, vector<vector<int>> board, int i);
	
	vector<vector<vector<int>>> garo = {
		{{1,0,0},
		{1,1,1}},

		{{0,1,0},
		{1,1,1}},

		{{0,0,1},
		{1,1,1}}
	};

	vector<vector<vector<int>>> sero = {
		{{1,0},
		{1,0},
		{1,1}},

		{{0,1},
		{0,1},
		{1,1}}
	};

	int solution(vector<vector<int>> board) {
		int answer = 0;
		vector<int> possible(board[0].size());
		vector<int> count(board[0].size());

		for (int i = 0; i < board.size()-1; i++) {
			checkline(possible, board, i);
			for (int j = 0; j < board[0].size() - 1; j++) {

				if (i< board.size() - 2) //세로 불가능할때는 실행 불가
					if (checksero(count, possible, board, i, j,answer))
						j = -1;
				if (j < board[0].size() - 2)  //가로 불가능할 때는 실행 불가
					if (checkgaro(count, possible, board, i, j,answer))
						j = -1;
			}
		}
		return answer;
	}

	//가장 위에 있는 블록 인덱스 구하는 함수
	void checkline(vector<int> &possible, vector<vector<int>> board, int i) {		
		for (int a = 0; a < board[0].size(); a++) {
			if (possible[a] != 0) continue;
			for (int i = 0; i<board.size(); i++) {
				if (possible[a]==0 && (board[i][a]!=0)) {
					possible[a] = board[i][a];
				}
			}
		}
	}

	bool checkgaro(vector<int> &count, vector<int> &possible, vector<vector<int>> &board, int i, int j,int &answer) {
		bool check = false;
		int a = 0;
		int block = 0;
		for (a = 0; a < garo.size(); a++) {
			int temp = 0;		//일치율
			for (int c = 0, j_ = j; c < 3; c++, j_++) {
				int qqq = 0;
				for (int b = 0, i_ = i; b < 2; b++, i_++) {
					if (garo[a][b][c] == board[i_][j_] || (garo[a][b][c]>0 && board[i_][j_]>0)) {
						if (garo[a][b][c] == 0) {
							temp++;
							continue;
						}
						if (block == 0 || board[i_][j_] == block) {
							block = board[i_][j_];
							if (possible[j_] != board[i_][j_]) {
								qqq++;
								continue;
							}
							temp++;				
						}
					}
				}
				if (qqq == 2) temp += 2;
			}
			if (temp==6) {	//적중한게 있다
				answer++;
				for (int b = 0, i_ = i; b < 2; b++,i_++) {
					for (int c = 0, j_ = j; c < 3; c++,j_++) {
						possible[j_] = 0;
						if (board[i_][j_] != 0) board[i_][j_] = 0;						
					}
				}
				checkline(possible, board, i);
				return true;
			}
		}
		return false;
	}

	bool checksero(vector<int> &count, vector<int> &possible, vector<vector<int>> &board, int i, int j, int &answer) {
		for (int a = 0; a < sero.size(); a++) {
			int temp = 0;		//일치율
			int block = 0;
			for (int c = 0, j_ = j; c < 2; c++, j_++) {
				int qqq = 0;
				for (int b = 0, i_ = i; b < 3; b++, i_++) {
					if (sero[a][b][c] == board[i_][j_] || (sero[a][b][c]>0 && board[i_][j_]>0)) {
						if (sero[a][b][c] == 0) {
							temp++;
							continue;
						}
						if (block == 0 || board[i_][j_] == block) {
							block = board[i_][j_];
							if (possible[j_] != board[i_][j_]) {
								qqq++;
								continue;
							}
							temp++;
						}
					}
				}
				if (qqq == 3)
					temp += 3;
			}

			if (temp == 6) {	//적중한게 있다
				answer++;
				for (int b = 0,i_=i; b < 3; b++, i_++) {					
					for (int c = 0,j_=j; c < 2; c++, j_++) {
						possible[j_] = 0;
						if (board[i_][j_] != 0) board[i_][j_] = 0;
					}
				}
				checkline(possible, board, i);
				return true;
			}
		}
		return false;
	}
}

int main(void) {
	/*
	vector<vector<int>> board =
	{ 
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
	{0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
	{0, 0, 0, 0, 3, 0, 4, 0, 0, 0},
	{0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
	{1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 5} };
	*/
	/*
	vector<vector<int>> board =
	{
		{ 0, 0,  0, 0, 0, 0, 0, 7, 0, 6 },
		{ 0, 0,  0, 0, 8, 0, 7, 7, 7, 6 },
		{ 9,10, 10, 8, 8, 8, 0, 0, 6, 6 },
		{ 9, 0, 10, 4, 0, 0, 3, 5, 0, 0 },
		{ 9, 9, 10, 4, 3, 3, 3, 5, 0, 0 },
		{ 0, 0,  0, 4, 4, 0, 5, 5, 0, 0 },
		{ 0, 0,  0, 0, 0, 0, 0, 0, 2, 0 },
		{ 0, 0,  0, 0, 0, 0, 0, 0, 2, 0 },
		{ 6, 0,  0, 0, 0, 0, 0, 2, 2, 1 },
		{ 6, 6,  6, 0, 0, 0, 0, 1, 1, 1 } };
	*/
	
	vector<vector<int>> board =
	{
		{ 0, 0,  0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0,  0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0,  0, 0, 0, 0, 0, 0, 0, 0 },
		{ 2, 2,  0, 0, 4, 4, 4, 0, 0, 0 },
		{ 2, 1,  0, 0, 3, 6, 4, 0, 0, 0 },
		{ 2, 1,  1, 1, 3, 6, 0, 0, 0, 0 },
		{ 0, 0,  0, 3, 3, 6, 6, 0, 8, 0 },
		{ 0, 0,  0, 5, 0, 0, 7, 8, 8,8 },
		{ 0, 5,  5, 5, 0, 0, 7, 7, 7, 0 },
		{ 0, 0,  0, 0, 0, 0, 0, 0, 0, 0 } };
	
	/*
	vector<vector<int>> board =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
		{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 }, 
		{ 0, 1, 0, 2, 0, 0, 0, 0, 0, 0 }, 
		{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 }, 
		{ 0, 0, 3, 2, 2, 0, 0, 0, 0, 0 }, 
		{ 0, 0, 3, 3, 3, 0, 0, 0, 0, 0 }};
		*/
	/*
	vector<vector<int>> board = {
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 }
	};
	*/
	cout << block_game::solution(board) << endl;
}
