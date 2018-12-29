#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
	string a = "A";
	string temp;
	string temp1;
	int answer = 0;
	int countA = 0;
	int offset = 0;
	bool flag = false;
	
	temp.assign(name.length(), 'A');
	if (temp.compare(name) == 0)
		return 0;

	for (int i = name.length()-1; i >0; i--) {
		//temp.replace(0, i, "A");
		temp.assign(i, 'A');
		for (int j = 0; j < i + 2 && j + i != name.length(); j++){
			temp1 = name.substr(j, i);
			if (temp.compare(temp1) == 0) {
				flag = true;
				offset = j;
				countA = i;
			}
		}
		if (flag == true) {
			break;
		}
	}
	if (flag == true)
		answer += 2 * offset - 2 + name.length() - temp.size() - offset;
	else
		answer += name.length() - 1;
	
	for (int i = 0; i < name.size(); i++) {
		if (name[i] >= 'O')
			answer += 'Z' - name[i] + 1;
		else
			answer += name[i] - 'A';
	}
	return answer;
}

int main(void) {
	string name = "JAZ";
	cout << solution(name) << endl;
}
