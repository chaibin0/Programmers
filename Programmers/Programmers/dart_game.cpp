#include <string>
#include <iostream>
#include <vector>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	bool flag = false;
	string number = "";
	int inumber = 0;
	vector<int> vnumber;
	for (int i = 0; i < dartResult.length(); i++) {
		if (dartResult[i] >= '0'&&dartResult[i] <= '9') {
			number += dartResult[i];
		}
		else if(dartResult[i] == 'D' || dartResult[i] == 'S' ||dartResult[i]=='T') {
			inumber = stoi(number);
			number = "";
			if (dartResult[i + 1] == '*') {			//스타상
				if (dartResult[i] == 'S') {
					if (flag == false) {
						vnumber.push_back(inumber*2);
						flag = true;
					}
					else {
						vnumber[vnumber.size() - 1] *= 2;
						vnumber.push_back(inumber*2);
					}
				}
				else if (dartResult[i] == 'D') {
					if (flag == false) {
						vnumber.push_back(inumber*inumber*2);
						flag = true;
					}
					else {
						vnumber[vnumber.size() - 1] *= 2;
						vnumber.push_back(inumber*inumber*2);
					}

				}
				else if (dartResult[i] == 'T') {
					if (flag == false) {
						vnumber.push_back(inumber*inumber*inumber*2);
						flag = true;
					}
					else {
						vnumber[vnumber.size() - 1] *= 2;
						vnumber.push_back(inumber*inumber*inumber*2);
					}
				}
				i++;
			}
			else if (dartResult[i + 1] == '#') {	//아차상
				if (dartResult[i] == 'S') {
					if (flag == false) {
						vnumber.push_back(inumber*(-1));
						flag = true;
					}
					else {
						vnumber.push_back(inumber*(-1));
					}
				}
				else if (dartResult[i] == 'D') {
					if (flag == false) {
						vnumber.push_back(inumber*inumber*(-1));
						flag = true;
					}
					else {
						vnumber.push_back(inumber*inumber*(-1));
					}

				}
				else if (dartResult[i] == 'T') {
					if (flag == false) {
						vnumber.push_back(inumber*inumber*inumber*(-1));
						flag = true;
					}
					else {
						vnumber.push_back(inumber*inumber*inumber*(-1));
					}
				}
				i++;
			}
			else {
				if (dartResult[i] == 'S') {
					if (flag == false) {
						vnumber.push_back(inumber);
						flag = true;
					}
					else {
						vnumber.push_back(inumber);
					}
				}
				else if (dartResult[i] == 'D') {
					if (flag == false) {
						vnumber.push_back(inumber*inumber);
						flag = true;
					}
					else {
						vnumber.push_back(inumber*inumber);
					}

				}
				else if (dartResult[i] == 'T') {
					if (flag == false) {
						vnumber.push_back(inumber*inumber*inumber);
						flag = true;
					}
					else {
						vnumber.push_back(inumber*inumber*inumber);
					}
				}
			}
		}
	}

	for (int i = 0; i < vnumber.size(); i++) {
		answer += vnumber[i];
	}
	return answer;
}


/*
int main(void) {

	string test1 = "1S2D*3T";
	string test2 = "1D2S#10S";
	string test3 = "1D2S0T";
	string test4 = "1S*2T*3S";
	string test5 = "1D#2S*3S";
	string test6 = "1T2D3D#";
	string test7 = "1D2S3T*";
	
	cout << "test1 :" << solution(test1) << "\t"<<"answer : 37"<<endl;
	cout << "test2 :" << solution(test2) << "\t" << "answer : 9" << endl;
	cout << "test3 :" << solution(test3) << "\t" << "answer : 3" << endl;
	cout << "test4 :" << solution(test4) << "\t" << "answer : 23" << endl;
	cout << "test5 :" << solution(test5) << "\t" << "answer : 5" << endl;
	cout << "test6 :" << solution(test6) << "\t" << "answer : -4" << endl;
	cout << "test7 :" << solution(test7) << "\t" << "answer : 59" << endl;
}
*/