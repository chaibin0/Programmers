#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
namespace mukbang1 {	
	int solution(vector<int> food_times, long long k) {
		long long answer = 0;		
		priority_queue<int, deque<int>, greater<int>> data;			//처음 갯수 확인
		int max_index = 0;
		long long previous=0,current = 0;
		int remain = food_times.size();
		int height = 1;
		for (int j = 0; j < food_times.size(); j++) {
			if (food_times[j] > food_times[max_index])
				max_index = j;				
		}
		
		for (int i = 0; i < max_index; i++) {
			if (food_times[i] - 1 == 0)
				remain--;
			else 
				data.push(food_times[i] - 1);
		}
		
		for (int i = max_index + 1; i < food_times.size(); i++) 
			data.push(food_times[i]);
			
		current = max_index;
		
		for (long long i = food_times[max_index]; (k-1)/food_times.size() >= 0&&k>=current; i--) {
			previous = current;
			current += remain;
			while (!data.empty()&&height == data.top()) {
				remain--;
				data.pop();
			}
			height++;		
		}

		//이전 위치
		for (int i = max_index; i < food_times.size()&&height-1>0; i++) {
			if (food_times[i] >= height - 1) {
				if (previous == k)
					return i + 1;
				previous++;
			}

		}

		//현재 위치
		for (int i = 0; i <= max_index; i++) {
			if (food_times[i] >= height) {
				if (previous == k)
					return i + 1;
				previous++;
			}
		}
		return -1;
	}
};
/*
int main(void) {
	vector<int> food_times = { 3,1,2 };
	int k = 5;
	int l = 6;
	for(int i=1;i<=10;i++)
		cout << mukbang1::solution(food_times, i) << endl;
	
}
*/