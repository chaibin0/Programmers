#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int solution(string str1, string str2) {

	multiset<string> sstr1;
	multiset<string> sstr2;
	for (int i = 0; i < str1.length()-1; i++) {
		string data;
		data.assign(" ", 2);
		if ((str1[i] >= 'a'&&str1[i] <= 'z')||(str1[i]>='A'&&str1[i]<='Z')) {
			if ((str1[i+1] >= 'a'&&str1[i+1] <= 'z') || (str1[i+1] >= 'A'&&str1[i+1] <= 'Z')) {
				data[0]=toupper(str1[i]);
				data[1]=toupper(str1[i + 1]);

				sstr1.insert(data);
			}
		}
	}

	for (int j = 0; j < str2.length()-1; j++) {
		string data;
		data.assign(" ", 2);
		if ((str2[j] >= 'a'&&str2[j] <= 'z') || (str2[j]>='A'&&str2[j]<='Z')) {
			if ((str2[j + 1] >= 'a'&&str2[j + 1] <= 'z') || (str2[j + 1] >= 'A'&&str2[j + 1] <= 'Z')) {
				data[0] = toupper(str2[j]);
				data[1] = toupper(str2[j + 1]);
				sstr2.insert(data);
			}
		}
	}
	if (sstr1.size() == 0 || sstr2.size() == 0)
		return 65536;
	set<string>::iterator iter;
	set<string>::iterator iter2;
	int sunion = sstr1.size();
	int sintersaction = 0;

	for (iter=sstr2.begin(); iter!=sstr2.end(); ++iter) {
		iter2 = find(sstr1.begin(), sstr1.end(), *iter);
		if (iter2 != sstr1.end()) {
			sstr1.erase(iter2);
			sintersaction++;
		}
		else
			sunion++;
	}

	double answer = (double)sintersaction / sunion;
	answer *= 65536;
	return (int)answer;
}
/*
int main(void) {
	string str1 = "FRANCE";
	string str2 = "french";

	cout << solution(str1, str2);
}

*/