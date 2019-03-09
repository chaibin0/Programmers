#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;
namespace open_chatting{
/*
	void find_data(vector<string> &vuser, vector<string> &vname, const string &user, const string &name) {
		vector<string>::iterator iter = find(vuser.begin(), vuser.end(), user);
		if (iter == vuser.end()){
			vuser.push_back(user);
			vname.push_back(name);
		}
	}

	string search_data(vector<string> &vuser, vector<string> &vname, const string &user, const string &name)	{
		vector<string>::iterator iter = find(vuser.begin(), vuser.end(), user);
		return vname[iter - vuser.begin()];
	}

*/
	vector<string> solution(vector<string> record) {
		vector<string> answer;
		vector<vector<string>> log(record.size(),vector<string>(3));
		map<string,string> user;
		
		for (int i = 0; i < record.size(); i++) {
			istringstream iss(record[i]);
			iss >> log[i][0];
			iss >> log[i][1];
			iss >> log[i][2];
			if (log[i][0]=="Enter" || log[i][0]=="Change"){
				user[log[i][1]]=log[i][2];
			}
		}

		for (int i = 0; i < log.size(); i++) {
			if (log[i][0] == "Enter") {
				answer.push_back(user[log[i][1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
			}
			else if (log[i][0] == "Leave") {
				answer.push_back(user[log[i][1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
			}
		}
		return answer;
	}
};

/*
int main(void) {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
	vector<string> value = open_chatting::solution(record);
	for (int i = 0; i < value.size(); i++) {
		cout << value[i] << endl;
	}
}
*/