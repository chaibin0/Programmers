/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int i = 0;
	int sum = 0;
	int temp = 0;
	int min;
	int max;
	int mid;

	sort(budgets.begin(), budgets.end());
	min = 0;
	max = 100000;

	for (int i = 0; i<budgets.size(); i++) {
		sum += budgets[i];
	}
	if (sum<M)
		return budgets[budgets.size() - 1];
	while (1) {
		sum = 0;
		mid = (max + min) / 2;
		for (int i = 0; i < budgets.size(); i++) {
			if (budgets[i] < mid)
				sum += budgets[i];
			else {
				sum += mid*(budgets.size() - 1 - (i - 1));
				break;
			}

		}

		if (mid == temp) {
			cout << "max : " << max << endl;
			cout << "min : " << min << endl;
			return mid;

		}
		if (sum > M)
			max = mid;
		else
			min = mid;
		cout << "min : " << min;
		cout << "\tmax : " << max;
		cout << "\tmid : " << (double)mid<<endl;
		temp = mid;
	}
	return answer;
}

int main(void) {
	vector<int> budgets = { 120,110,140,150 };
	int M = 486;
	solution(budgets, M);
}
*/