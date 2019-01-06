#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>,less<int>> temp;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int j = 0;
	for (int i = 0; i < k; i++) {
		if (dates[j] == i) {
			temp.push(supplies[j]);
			if (j != supplies.size() - 1)
				j++;
		}
		if (stock == 0)
		{
			stock += temp.top();
			temp.pop();
			answer++;
		}
		stock--;

	}
	return answer;



}

/*
int main(void) {
int stock = 4;
vector<int> datas = { 4,10,15 };
vector<int> supplies = { 20,5,10 };
int k = 30;
cout << solution(stock, datas, supplies, k) << endl;

}
*/


