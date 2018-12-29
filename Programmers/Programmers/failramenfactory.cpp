/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <functional>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int j = 0;
	for (int i = 0; i<k; i++) {
		if (dates[j] == i) {
			make_heap(supplies.begin(), supplies.begin() + j+1, greater<int>());
			if(j!=supplies.size()-1)
				j++;
		}
		if (stock == 0)
		{
			stock += supplies[0];
			supplies[0] = 0;
			make_heap(supplies.begin(), supplies.begin() + j + 1, greater<int>());
			answer++;
		}
		stock--;

	}
	return answer;
}

int main(void) {
	int stock = 4;
	vector<int> datas = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;
	cout << solution(stock, datas, supplies, k) << endl;
	
}
*/