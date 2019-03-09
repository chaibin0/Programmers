#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
namespace mukbang {
	int solution(vector<int> food_times, long long k) {
		long long answer = 0;
		queue<int> visit;
		int j = 0;
		for (int j = 0; j < food_times.size() && j <= k; j++) {
			food_times[j]--;
			if(food_times[j]!=0)
				visit.push(j);
		}
		if (j == food_times.size() - 1) {

			if (j == k)
				return -1;
			else
				return j;
		}
			

		int i;
		for (int i = food_times.size(); i <= k; i++) {
			if (visit.empty())  return (long long)-1;	

			food_times[visit.front()]--;
			
			if(food_times[visit.front()]!=0)
				visit.push(visit.front());
			
			if(i!=k)
			visit.pop();

				
		}
		return (visit.front()%food_times.size())+1;
	}	
};
/*
int main(void) {
	vector<int> food_times = { 3,1,2 };
	int k = 5;
	int l = 6;

	cout << mukbang::solution(food_times,k) << endl;
	cout << mukbang::solution(food_times, l) << endl;
}
*/