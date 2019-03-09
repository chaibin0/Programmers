#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
	int answer = 0;
	int cmax = 0;
	int temp = 0;
	vector<int> result(money.size() + 2);

	//1번째 경우
	result[2] = money[0];
	for (int i = 1; i < money.size()-1; i++) {
		if (result[i] + money[i] > result[i-1] + money[i]) {
			result[i + 2] = money[i] + result[i];
		}
		else {
			result[i + 2] = money[i] + result[i-1];
		}
		cmax = max(cmax, result[i + 2]);
	}
	//2번째 경우
	result.clear();
	result.assign(money.size() + 2, 0);
	result[3] = money[1];
	for (int i = 2; i < money.size(); i++) {
		if (result[i] + money[i] > result[i - 1] + money[i]) {
			result[i + 2] = money[i] + result[i];
		}
		else {
			result[i + 2] = money[i] + result[i-1];
		}
		cmax = max(cmax, result[i + 2]);
	}
	return cmax;
}
/*
int main(void) {
	vector<int> money = { 1,2,3};
	cout<<solution(money)<<endl;
}
*/