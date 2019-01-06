#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct Pred {
	bool operator()(vector<int> a, vector<int> b) {
		return a[0] < b[0];
	}
};
struct Pred1 {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int solution(vector<vector<int>> routes) {
	int answer = 0;
	int current;
	int i = 1;
	sort(routes.begin(), routes.end(), Pred());
	priority_queue<int, deque<int>,Pred1> prique;
	current = routes[0][0];
	prique.push(routes[0][1]);
	while (!prique.empty()) {
		while (i!=routes.size()) {
			if (routes[i][0] == current) {
				prique.push(routes[i][1]);
				i++;
			}
			else
				break;
		}
		if (current == prique.top()) {
			while (!prique.empty()) {
				prique.pop();
			}
			if (i != routes.size()) {
				prique.push(routes[i][1]);
				current = routes[i][0];
			}
			else {
				answer++;
				break;
			}
			answer++;
		}
		else current++;
	}
	return answer;
}
/*
int main(void) {
	
	vector<vector<int>> routes = { {-20,15},{-14,-5},{-18,-13},{-5,-3} };
	cout<<solution(routes)<<endl;

}
*/