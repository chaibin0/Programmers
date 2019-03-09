#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
namespace treffic {
	int solution(vector<string> lines) {
		int answer = 0;
		int count = 0;
		string hour, minute, second, micro, process_time;
		int end_bar, start_bar;

		priority_queue<int, vector<int>, greater<int>> start_process, end_process;
		int value1, value2;
		for (int i = 0; i < lines.size(); i++) {
			process_time = "";
			hour.assign(lines[i], 11, 2);
			minute.assign(lines[i], 14, 2);
			second.assign(lines[i], 17, 2);
			micro.assign(lines[i], 20, 3);
			int j;
			for (j = 24; j < lines[i].size(); j++) {
				if (lines[i][j] == '.') {
					j++;
					break;
				}
				if (lines[i][j] == 's') {
					process_time += "000";
					j++;
					break;
				}
				process_time += lines[i][j];
			}
			if (j != lines[i].size()) {
				int k = 0;
				for (int k = 0; k < 3; k++) {
					if (lines[i][j] == 's') {
						process_time += "0";
					}
					else {
						process_time += lines[i][j++];
					}
				}
			}

			value1 = 60 * 60 * stoi(hour) * 1000 + 60 * stoi(minute) * 1000 + stoi(second) * 1000 + stoi(micro);
			value2 = stoi(process_time);
			start_process.push(value1 - value2 + 1);

			end_process.push(value1);
		}

		end_bar = end_process.top();
		start_process.pop();
		count++;
		answer = max(answer, count);
		start_bar = end_bar - 999;
		cout << "value1 : " << value1 << endl;
		cout << "start : " << start_bar << endl;
		cout << "end : " << end_bar << endl;

		while (end_bar != value1) {
			while (!start_process.empty() && start_process.top() <= end_bar) {
				cout << start_process.top() << ": count1증가" << endl;
				start_process.pop();
				count++;

			}
			answer = max(answer, count);

			while (!end_process.empty() && end_process.top() <= start_bar) {
				cout << end_process.top() << ": count1감소" << endl;
				end_process.pop();
				count--;
			}
			start_bar++;
			end_bar++;

		}

		return answer;
	}
};
/*
int main(void) {

	//vector<string> time = { "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" };
	//vector<string> time={"2016-09-15 00:00:00.000 3s"};
	//vector<string> time={"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"};
	//vector<string> time={"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};
	vector<string> time = { "2016-09-15 00:00:00.000 2.3s", "2016-09-15 23:59:59.999 0.1s" };

	std::cout << solution(time) << endl;


}
*/