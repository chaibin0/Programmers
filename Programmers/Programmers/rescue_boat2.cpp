/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int i=0,j = 0;
	sort(people.begin(), people.end());
	vector<bool> visit;
	visit.assign(people.size(), 0);
	for (j = people.size()-1; j > i; j--) {
		if (people[j] + people[i] <= limit) {
			i++;
			answer++;
		}
		else {
			answer++;
		}
				
	}
	if (i == j)
		answer++;
	return answer;
}

int main(void) {
	vector<int> people = { 70,80,50 };
	int limit = 100;
	cout << solution(people, limit) << endl;
}

*/