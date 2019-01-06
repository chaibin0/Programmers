/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int first,second;
	priority_queue<int,vector<int>,less<int>> temp;
	
	for(int i=0;i<scoville.size();i++)
		temp.push(scoville[i]);
	
	while (temp.top() < K && temp.size()>1) {
		answer++;
		first = temp.top();
		temp.pop();
		second = temp.top();
		temp.pop();
		temp.push(first + second * 2);
	}
	if (temp.top() < K)
		return -1;
	return answer;
}

int main(void) {
	vector<int> scoville = { 1,2,3,9,10,12 };
	int K = 7;
	cout << solution(scoville,K) << endl;
}
*/
