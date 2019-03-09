#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	string value = "0";
	vector<string> number = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
	bool flag = true;
	int i = 1;
	int count= 1;
	while(count<t*m){		
		flag = true;
		string temp = "";
		int num = i;
		while (flag) {
			if (num / n == 0)
				flag = false;
			temp.insert(0,number[num%n]);
			num /= n;
		}
		cout << temp << endl;
		count += temp.size();
		value += temp;
		i++;
	}
	int j = 0;
	for(int i=0;i<count&&j<t;i++){
		if (i%m == p - 1) {
			answer += value[i];
			j++;
		}
	}
	cout << value << endl;
	return answer;
}
/*
int main(void) {
	int n = 2, t = 4, m = 2, p = 1;
	cout << solution(16,16, 2, 2) << endl;
}
*/