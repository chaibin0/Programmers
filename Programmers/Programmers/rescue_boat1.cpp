/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int nextnumber;
	vector<int>::iterator iter,iter1;
	sort(people.begin(), people.end());
	while (!people.empty()){
		iter = people.begin();
		iter1 = iter;
		nextnumber = *iter;
		if (people.size() == 1) {
			answer++;
			people.erase(people.begin());
			break;
		}
		while((++iter)!=people.end()){
			if (nextnumber + *iter <= limit) {
				iter1 = iter;
			}
			if (nextnumber + *iter > limit)
				break;
		}
		answer++;
		if (iter1 == people.begin()) {
			people.erase(people.begin());
		}
		else {
			people.erase(iter1);
			people.erase(people.begin());
		}
	}

	return answer;
}

int main(void) {
	vector<int> people = { 70,50,80,50 };
	int limit = 100;
	cout << solution(people, limit) << endl;
}

*/