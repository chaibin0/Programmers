/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int N) {
	long long answer = 0;
	
	int height=2;
	int width =1;
	int temp1 = 1;
	int temp2 = 1;
	int temp3 = 0;
	if (N == 1) {
		return 4;
	}
	else 
		for (int i = 2; i < N+1; i++) {
			temp1 = temp2 + temp3;
			temp3 = temp2;
			temp2 = temp1;
		}
	answer = temp1 * 4 + 2 * temp3;
	return answer;
}

int main(void) {
	for(int i=1;i<20;i++)
		cout << "i= "<<i<<"ÀÏ ¶§ °ª : "<<solution(i) << endl;
}

*/