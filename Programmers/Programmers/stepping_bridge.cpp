/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	int count = 0;
	int left = 1;
	int right = distance;
	int mid = 0;
	int temp=0;
	bool flag = false;
	int i, j;
	rocks.push_back(0);
	rocks.push_back(distance);
	sort(rocks.begin(), rocks.end());
	while (1) {		
		count = 0;
		mid = (left + right) / 2;
		
		for (i = 0; i < rocks.size()-1; i++) {		//mid값을 찾는 과정
			for (j = i + 1; j < rocks.size(); j++) {
				if (rocks[j] - rocks[i] > mid)
					break;

				if (rocks[j] - rocks[i] == mid) {
					flag = true;
					count = i - j-1;
				}
			}
			if (flag == true) {
				if (i == 1 && mid > rocks[i])
					count = n + 1;
				break;
			}

			if (i!=0 && rocks[i + 1] - rocks[i] < mid) {
				count++;
				if (count > n)
					break;
			}
		}

		if (flag == true) {		//mid값이 존재할 경우
			for (i = j+1; i < rocks.size(); i++) {
				if (rocks[i] - rocks[i - 1] < mid) {
					if (i == j + 1) {
						count = n + 1;
						break;
					}

					count++;
				}

				if (count > n)
					break;
			}
		}
		

		if (left==mid)
			break;
		if (count > n)
			right = mid-1;
		if (count < n)
			left = mid + 1;
	}

	return mid;
}

int main(void) {
	int distance = 25;
	vector<int> rocks = { 2,14,11,21,17 };
	int n = 2;
	cout << solution(distance, rocks, n) << endl;
}

*/