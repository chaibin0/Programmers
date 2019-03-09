#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
namespace autocomplate1 {
	struct Tree {
		int count;
		bool flag;
		Tree * next[26];

	};
	bool Pred(string a, string b) {
		return a.length() < b.length();
	}
	int solution(vector<string> words) {
		int answer = 0;
		int i;
		Tree tree[26] = { 0,false,NULL };
		sort(words.begin(), words.end(), Pred);

		for (i = 0; i < words.size(); i++) {
			Tree * iterator = &tree[words[i][0] - 'a'];
			for (int j = 0; j < words[i].size(); j++) {
				if (iterator->count == 1)
					answer++;
				
				iterator->count++;
				
				if (iterator->count > 1) 
					answer++;	

				if (iterator->flag == true) {
					answer--;
					iterator->flag = false;
				}

				if (j == words[i].size() - 1) {
					iterator->flag = true;
					break;
				}
				if (iterator->next[words[i][j+1] - 'a'] == NULL) {
					iterator->next[words[i][j+1] - 'a'] = new Tree({ 0,false,NULL });
				}
				iterator = iterator->next[words[i][j+1] - 'a'];
			}
		}
		return answer+words.size();
	}
};
/*
int main(void) {
	//vector<string> words = { "go", "gone", "guild" };
	//vector<string> words = { "word", "war", "warrior", "world" };
	vector<string> words = {"abcdefg","ab","abc"};
	cout << autocomplate1::solution(words) << endl;
}

*/