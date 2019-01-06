/*
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(string number, int k) {
	vector<int> temp;
	vector<int> temp1;
	int num = stoi(number);
	int a = (int)pow(10,number.length()-1);
	for (int i = 0; i < number.length(); i++) {
		temp.push_back(num / a);
		num = num%a;
		a /= 10;
	}
	int x = 0;
	for (int i = 0; i < number.length() - 1; i++) {
		
		
	}
	string answer = "";

	return answer;
}

int main(void) {
	string number = "1924";
}
*/