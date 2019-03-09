#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace secret_map {
	vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
		
		vector<string> answer(n);

		for (int i = 0; i < n; i++) {
			int k = arr1[i] | arr2[i];
			answer[i].assign(" ",n);
			for (int j = n - 1; j >= 0; j--) {
				if (k % 2 == 0)
					answer[i][j] = ' ';
				else
					answer[i][j] = '#';
				k /= 2;
				
			}
		}
		return answer;
	}
}
/*
int main(void) {
	int n = 5;
	vector<int> arr1 = { 9,20,28,18,11 };
	vector<int> arr2 = {30,1,21,17,28 };
	
	vector<string> result = secret_map::solution(n, arr1, arr2);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}

*/