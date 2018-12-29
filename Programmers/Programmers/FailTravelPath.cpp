#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
//error code
vector<string> solution1(vector<vector<string>> tickets) {
	vector<string> answer;
	map<string, deque<string>> m;
	map<string, deque<string>>::iterator iter;

	for (int i = 0; i < tickets.size(); i++) {
		iter = m.find(tickets[i][0]);
		if (m.find(tickets[i][0]) == m.end())
		{
			deque<string> temp;
			temp.push_back(tickets[i][1]);
			m.insert({tickets[i][0], temp });
		}
		else {
			deque<string> temp = iter->second;
			temp.push_back(tickets[i][1]);
			m[tickets[i][0]]=temp;
		}
	}	

	for (iter = m.begin(); iter != m.end(); ++iter)
		sort((iter->second).begin(),(iter->second).end());
		
	string first = "ICN";
	answer.push_back(first);
	string second;
	for (int i = 0; i < tickets.size(); i++) {
		second = m[first].front();
		if(!m[first].empty())
			m[first].pop_front();
		answer.push_back(second);
		first = second;
	}
	
	return answer;
}
/*
int main(void) {
	//ctor<vector<string>> tickets = { {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} };
//	vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} };
	vector<vector<string>> tickets = { { "ABD", "ATL" } ,{ "ICN", "ATL" },{ "ICN", "ABD" },{ "ATL", "ICN" },{ "ATL", "ABD" } };
	//vector<vector<string>> tickets = { { "ICN", "SFO" } };

	//vector<vector<string>> tickets = { { "SFO", "ICN" }, {"ICN", "SFO" } };
	/*
	vector<string> temp = solution(tickets);

	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i]<<" ";
	}
	cout << endl;
	
}
*/