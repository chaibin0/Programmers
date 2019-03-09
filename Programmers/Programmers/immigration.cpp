#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
/*
int solution(int n, vector<int> times) {
	long answer = LONG_MAX;
	long min = 1;
	long max = LONG_MAX-1L;
	long mid = 0;
	bool flag = false;
	long count;
	sort(times.begin(), times.end());
	while (1) {
		count = 0;
		mid = (min + max) / 2;
		flag = false;
		for (int i = 0; i < times.size(); i++) {
			if (mid % times[i] == 0) {
				count += (mid / times[i]);
				if (count == n) {
					answer = (mid < answer) ? mid : answer;
					break;
				}
			}
			else
				count += (mid / times[i]);
			

			if (count < 0) {		//범위 초과
				flag = true;
			}
		}

		if (flag == true) {
			max = mid;
			continue;
		}


		if (mid == min)
			break;

		if (n <= count) {
			max = mid;
			answer = (mid < answer) ? mid : answer;
		}
		if (n > count) {
			min = mid;
		}
	}
	return answer;
}



int main(void) {
	int n = 14;
	vector<int> times = {3,2};
	cout << solution(n, times) << endl;
}

*/