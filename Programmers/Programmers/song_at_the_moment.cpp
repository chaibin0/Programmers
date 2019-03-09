#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Data {
	string value;
	int index;
	int play_time;
};

bool pred(Data a, Data b) {
	if (a.play_time == b.play_time)
		return a.index < b.index;
	else
		return a.play_time > b.play_time;
}
void change_rhythm(vector<bool> &shap, const string &value, string &value_) {
	for (int i = 0; i < value.length(); i++) {
		value_.push_back(value[i]);
		if (value[i + 1] == '#') {
			shap.push_back(true);
			i++;
		}
		else
			shap.push_back(false);
	}
}

bool compare_song(const string &rhythm, const vector<bool> &rhythm_shap, const string &m, const vector<bool> &m_shap, int position) {
	for (int i = 0; i < m.length(); i++, position++) {
		if (rhythm[position] != m[i] || rhythm_shap[position] != m_shap[i])
			return false;
	}
	return true;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	string m_;
	vector<bool> m_shap;
	vector<Data> result;
	int start_time;
	int end_time;
	bool flag = false;
	int max = -1;
	change_rhythm(m_shap, m, m_);

	for (int i = 0; i < musicinfos.size(); i++) {
		string music,title;
		string rhythm,rhythm_;
		vector<bool> rhythm_shap;

		int j = 12;

		start_time = 600 *musicinfos[i][0]+ 60 *musicinfos[i][1] + 10 * musicinfos[i][3]  + musicinfos[i][4]-671*'0';
		end_time= 600 * musicinfos[i][6] + 60 *  musicinfos[i][7]+ 10 * musicinfos[i][9] + musicinfos[i][10] - 671 * '0';

		while (!flag) {
			if (musicinfos[i][j] == ',') {
				j++;
				break;
			}
			else {
				title += musicinfos[i][j];
				j++;
			}
		}

		while (j < musicinfos[i].size()) {
			rhythm += musicinfos[i][j];
			j++;
		}

		change_rhythm(rhythm_shap, rhythm, rhythm_);

		int length = rhythm_.size();
		for (int j = rhythm_.size(); j <= end_time- start_time; j++) {
			rhythm_.push_back(rhythm_[j%length]);
			rhythm_shap.push_back(rhythm_shap[j%length]);
		}
		cout << rhythm_ << endl;

		int position = 0;
		if (rhythm_.length() < m_.length())
			continue;

		for (int j = 0; j <= rhythm_.length()-m_.length(); j++) {
			if (rhythm_[j] == m_[0]) {
				/*
				if (max < end_time - start_time && compare_song(rhythm_, rhythm_shap, m_, m_shap, j)) {
					max = end_time - start_time;
					answer = title;
					break;
				}
				*/
				if (compare_song(rhythm_, rhythm_shap, m_, m_shap, j)) {
					Data data;
					data.index = i;
					data.value = title;
					data.play_time = end_time - start_time;
					result.push_back(data);
					break;
				}
			}
		}
	}
	sort(result.begin(), result.end(), pred);
	
	if (result.size() == 0)
		return "(None)";
	else
		return result[0].value;
}


/*
int main(void) {
	//string m = "ABCDEFG";
	//vector<string> musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "12:00,12:14,HELL1,CDEFGAB" };

	//string m = 	"CC#BCC#BCC#BCC#B";
	//vector<string> musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };

	
	string m = "ABC";
	vector<string> musicinfos = { "12:00,12:14,HELLO,C#DEFGAB#", "13:00,13:05,WORLD,ABCDEF" };

	
	cout << solution(m, musicinfos) << endl;
}

*/