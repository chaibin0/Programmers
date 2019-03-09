#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
namespace candidate_key {
	void combination(vector<vector<int>> &combinations, vector<int> order, vector<int> value, int current_length, int position, int length, bool flag);
	bool Union(set<int> a, set<int> b);
	bool pred(vector<int> a, vector<int> b) {
		return a.size() < b.size();
	}

	struct relation_data {
		bool flag;
		map<string, relation_data> link;
	};
	int solution(vector<vector<string>> relation) {
		int answer = 0;
		int length = relation[0].size();
		vector<bool> visit(relation.size());
		vector<int> order, value;
		vector<vector<int>> combinations;
		vector<set<int>> result;


		for (int i = 0; i < relation[0].size(); i++)		//조합을 위한 column 번호
			order.push_back(i);

		combination(combinations, order, value, 0, 0, length, true);		//조합 설정
		combination(combinations, order, value, 0, 0, length, false);

		sort(combinations.begin(), combinations.end(), pred);			//개수대로 정렬

		int i, j, k;
		for (i = 0; i < combinations.size(); i++) {
			bool flag = false;
			map<vector<string>, bool> result3;
			set<int> temp;
			for (k = 0; k < relation.size(); k++) {
				vector<string> result3_data;

				for (j = 0; j < combinations[i].size(); j++) {
					result3_data.push_back(relation[k][combinations[i][j]]);
				}
				if (result3[result3_data] == true) {
					flag = true;
					break;
				}
				else {
					result3[result3_data] = true;
				}

			}
			if (result3.size() == relation.size() || !flag) {
				for (int p = 0; p < combinations[i].size(); p++) {
					temp.insert(combinations[i][p]);
				}
				result.push_back(temp);
			}

		}

		for (int i = 0; i < result.size(); i++) {
			int count = 0;
			vector<int> a;
			answer++;
			for (int j = i + 1; j < result.size(); j++) {
				if (Union(result[i], result[j])) {
					result.erase(result.begin() + j);
					j--;
				}
			}
		}
		return answer;
	}

	void combination(vector<vector<int>> &combinations, vector<int> order, vector<int> value, int current_length, int position, int length, bool flag) {
		if (current_length > length - 1)
			return;
		if (flag == true) {
			value.push_back(order[position]);
			combinations.push_back(value);
		}
		combination(combinations, order, value, current_length + 1, position + 1, length, false);
		combination(combinations, order, value, current_length + 1, position + 1, length, true);
	}

	bool Union(set<int> a, set<int> b) {
		int count = 0;
		set<int>::iterator iter = a.begin();
		for (iter = a.begin(); iter != a.end(); ++iter) {
			if (b.find(*iter) != b.end())
				count++;
		}
		if (count == a.size())
			return true;
		else
			return false;
	}
}
/*
int main(void) {
	vector<vector<string>> relation = { {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} };
	//vector<vector<string>> relation = { { "a","b"} ,{  "a","a" }, {  "a","c"}, { "b","a"} };

	//vector<vector<string>> relation = { { "50","100"}};
	cout << candidate_key::solution(relation) << endl;
}

*/
