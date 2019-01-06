#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer =true;
	int k;
	vector<vector<string>> hash(10);

	for (int i = 0; i < phone_book.size(); i++) {
		k = phone_book[i][0] - '0';
		hash[k].push_back(phone_book[i]);
		for (int j = 0; j < hash[k].size() - 1; j++) {
			if (hash[k][j].compare(0,hash[k][hash[k].size() - 1].size(), hash[k][hash[k].size() - 1])==0)
				return false;			
			else if (hash[k][hash[k].size() - 1].compare(0, hash[k][j].size(),hash[k][j]) == 0)
				return false;			
		}
	}
	return answer;


}
/*
int main(void) {
	//vector<string> phone_book = { "119", "97674223", "1195524421" };
	
	vector<string> phone_book = { "123", "97674223", "1195524421" };
	//vector<string> phone_book = { "113", "12340", "123440", "12345", "98346" };

	cout << solution(phone_book) << endl;
}
*/