/*
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
bool checkNumber(int i, string numbers);
int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end(), greater<int>());
	vector<bool> temp(stoi(numbers)+1);
	for (int i = 2; i <= stoi(numbers); i++) {
		if (temp[i]==false && checkNumber(i,numbers)) {
			answer++;
		}
		if (temp[i] == false) {
			for (int j = i; j <= stoi(numbers); j += i) {
				temp[j] = true;
			}
		}
	}
	
	return answer;
}

bool checkNumber(int i,string numbers) {
	bool flag = false;
	vector<bool> visit(numbers.length());
	while (i != 0) {
		flag = false;
		int temp = i % 10;
		for (int j = 0; j <= numbers.length(); j++) {
			if (temp == numbers[j]-'0'&&visit[j]==0) {
				flag = true;
				visit[j] = 1;
				break;
			}
		}
		if (flag == false)
			return false;

		i /= 10;
	}

	return true;
}

int main(void) {
	cout<<solution("011")<<endl;
}
*/

