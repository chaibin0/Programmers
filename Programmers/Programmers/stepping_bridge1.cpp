#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int a = 0;
	int b = distance;


	sort(rocks.begin(), rocks.end());

	while (a < b) {
		int c = (a + b) / 2;

		int p = 0;
		int hits = 0;
		for (int i = 0; i < rocks.size(); ++i) {
			if (rocks[i] - p < c) {
				++hits;
			}
			else {
				p = rocks[i];
			}
		}

		if (hits <n) {
			a = c + 1;
		}
		else {
			b = c;
		}
		cout << "a : " << a << "\t" << "b : " << b << "\t";
		cout << "c :" << c << endl;
	}

	return a;
}
/*
int main(void) {
	int distance = 25;
	vector<int> rocks = { 2,14,11,21,17 };
	int n = 2;
	cout << solution(distance, rocks, n) << endl;
}
*/