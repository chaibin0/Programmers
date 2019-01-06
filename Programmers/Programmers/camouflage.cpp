#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int solution(vector<vector<string>> clothes) {
	int answer = 0;
	int value = 0;
	vector<int> temp;
	map<string, int> hash;
	for (int i = 0; i < clothes.size(); i++) {
			hash[clothes[i][1]]++;		
	}
	map<string, int>::iterator ihash=hash.begin();
	answer = hash.begin()->second;
	for (ihash++; ihash != hash.end(); ++ihash) {
		answer=answer+(answer+1)*ihash->second;
	}


	return answer;
}
/*
int main(void) {
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
	cout << solution(clothes) << endl;

}
*/