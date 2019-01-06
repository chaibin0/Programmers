/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int maxnumber;
	sort(people.begin(), people.end());
	vector<bool> visit;
	visit.assign(people.size(), 0);
	for (int i = 0; i < people.size(); i++) {
		maxnumber = i;
		if (visit[i] == 1)
			continue;
		for (int j = i+1; j < people.size(); j++) {
			if (visit[j] == 1)
				continue;
			else if (visit[j] == 0 && people[i] + people[j] > limit)
				break; 
			else if (visit[j] == 0 && people[i] + people[j] <= limit) {
				maxnumber = j;
			}
		}
		answer++;
		visit[i] = 1;
		visit[maxnumber] = 1;
	}
	return answer;
}

int main(void) {
	vector<int> people = { 70,80,50 };
	int limit = 100;
	cout << solution(people, limit) << endl;
}
*/