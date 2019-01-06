#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int need = number.length() - k;
	int cmax = 0;
	int ccount = 0;
	int j;
	vector<int> temp;
	for (int i = need; i>0; i--) {
		cmax = 0;
		ccount = 0;
		for (j = 0; j<number.length() - i+1&&j<number.length(); j++) {
			if (cmax<number[j]) {
				cmax = number[j];
				ccount = j;
			}
		}
		number.replace(0,ccount+1," ");
		
		temp.push_back(cmax);
	}
	for (int i = 0; i<temp.size(); i++)
		answer += temp[i];
	return answer;
}
/*
int main(void){
	string number = "1924";
	string number1 = "1231234";
	string number2 = "4177252841";

	cout << solution(number,2) << endl;
	cout << solution(number1,3) << endl;
	cout << solution(number2,4) << endl;

}

*/