/*
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
struct result {
	vector<int> k;
	int work;
};

struct Pred {
	bool operator()(result a, result b) {
		return a.work > b.work;
	}
};


bool Pred1(vector<int> a, vector<int> b) {
	if (a[1] == b[1])
		return a[0] < b[0];
	return a[1] < b[1];
}


int solution(vector<vector<int>> jobs) {
	priority_queue<int, vector<result>, Pred> temp;
	sort(jobs.begin(), jobs.end(), Pred1);
	result res1;
	int answer = 0;
	int total = 0;
	int work = 0;
	for (int i = 0; i < jobs.size(); i++) {
		if (temp.empty()) {
			res1.k = jobs[i];
			res1.work = jobs[i][1] + jobs[i][0];
			temp.push(res1);
		}
		else {
			if (work >= jobs[i][0]) {
				res1.k = jobs[i];
				res1.work = jobs[i][1] + work;
				temp.push(res1);
			}
			else{
				while (!temp.empty()) {
					result t = temp.top();
					if (work > t.k[0]) {
						total += t.k[1] + work - t.k[0];
						work += t.k[1];
						temp.pop();
					}
					else {
						total += t.k[1];
						work = t.k[1] + t.k[0];
						temp.pop();
					}
				}
				if (work < jobs[i][0]) {
					res1.k = jobs[i];
					res1.work = jobs[i][1]+jobs[i][0];
					temp.push(res1);
				}
				else {
					res1.k = jobs[i];
					res1.work = jobs[i][1]+work;
					temp.push(res1);
				}
			}
		}
	}
	while (!temp.empty()) {
		result t = temp.top();
		if (work > t.k[0]) {
			total += t.k[1] + work - t.k[0];
			work += t.k[1];
			temp.pop();
		}
		else {
			total += t.k[1];
			work = t.k[1]+t.k[0];
			temp.pop();
		}
	}
	answer = total / jobs.size();
	return answer;
}

int main(void) {
	//vector<vector<int>> jobs = { {0, 9},{0, 4},{0, 5},{0, 7},{0, 3} };
	vector<vector<int>> jobs = { {0,3},{2,6},{ 1,9 } };
	//vector<vector<int>> jobs = { { 0, 4 },{ 6, 5 },{ 13, 17 }};
	//vector<vector<int>> jobs = { { 2, 9 },{ 3, 4 },{6,3} };
	cout << solution(jobs) << endl;
}
*/