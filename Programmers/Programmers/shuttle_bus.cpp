#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int lastbus = n;
	int currentbus = 1;
	int start_time = 540;		//9시 
	int result = 0;

	priority_queue<int, deque<int>, greater<int>> int_time;
	
	for (int i = 0; i < timetable.size(); i++) {
		string hour;
		string minute;
		hour += timetable[i][0];
		hour += timetable[i][1];
		minute += timetable[i][3];
		minute += timetable[i][4];
		int_time.push(stoi(hour) * 60 + stoi(minute));
	}

	int i=0;
	while (currentbus <= lastbus) {		
		if (!int_time.empty()){
			if (int_time.top() <= start_time) {
				if (i == m - 1 && currentbus == lastbus) {
					result = int_time.top() - 1;
					break;
				}
				int_time.pop();
				i++;
			}
			else {
				if (currentbus == lastbus) {
					result = 540 + t*(n - 1);
					break;
				}
				currentbus++;
				start_time += t;
				i = 0;
			}
		}
		else {		//사람이 없다.
			result = 540 + t*(n - 1);
			break;
		}

		if (i == m) {
			currentbus++;
			start_time += t;
			i = 0;
		}
	}

	if (result / 60 >= 10) {		//시
		answer += to_string(result / 60);
		answer += ":";
	}
	else {
		answer += "0";
		answer += to_string(result / 60);
		answer += ":";
	}

	if (result % 60 >= 10) {		//분
		answer += to_string(result %60);
	}
	else {
		answer += "0";
		answer += to_string(result % 60);
	}
	
	return answer;
	
}
/*
int main(void) {
	
	int n = 10;
	int t = 60;
	int m = 45;
	vector<string> timetable = { "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" };
	cout << solution(n, t, m, timetable) << endl;
}

*/