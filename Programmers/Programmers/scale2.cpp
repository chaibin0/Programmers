/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> weight) {
	int ans = 1;
	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++) {
		if (ans < weight[i])
			break;
		ans += weight[i];
		cout << ans<<endl;
	}

	return ans;
}


int main(void) {
vector<int> weight = { 3,1,6,2,7,30,1 };
//vector<int> weight = { 3,1};
cout << solution(weight) << endl;
}

*/
