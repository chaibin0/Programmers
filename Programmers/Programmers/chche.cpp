#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <locale>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int recent = 0;
	int count = 0;
	bool flag = false;
	locale loc;
	vector<string> cash(cacheSize);
	vector<int> cash_recent(cacheSize);
	
	if (cacheSize == 0)
		return cities.size() * 5;
	for (int i = 0; i<cities.size(); i++) {
		for(int j=0;j<cities[i].length();j++)
			cities[i][j] = toupper(cities[i][j]);
		recent = 0;
		flag = false;
		if (find(cash.begin(), cash.end(), cities[i]) != cash.end()) {
			for (int j = 0; j<cash.size(); j++) {
				if (cash[j] == cities[i]) {
					cash[j] = cities[i];
					cash_recent[j] = count++;
				}
			}
			answer++;
		}
		else {
			for (int j = 0; j<cash.size(); j++) {
				if (cash[j] == "")
				{
					answer += 5;
					cash[j] = cities[i];
					cash_recent[j] = count++;
					flag = true;
					break;
				}
				else {
					if (cash_recent[recent] >= cash_recent[j]) {
						recent = j;

					}
				}
			}
			if (flag == false) {
				cash[recent] = cities[i];
				cash_recent[recent] = count++;
				answer += 5;
			}
		}
	}
	return answer;
}
/*
int main(void) {
	
	//vector<string> cities = { "Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork","LA" };
	//vector<string> cities = { "Jeju","Pangyo","Seoul","Jeju","Pangyo","Seoul","Jeju","Pangyo","Seoul" };


	//vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	int n = 2;

	//vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
	vector<string> cities = { "Jeju", "Pangyo", "NewYork", "newyork" };
	cout << solution(n, cities) << endl;

}
*/