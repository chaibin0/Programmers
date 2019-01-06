#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int firstx = (brown - 2) / 2;
	int firsty = 3;
	int firstbrown = brown;
	int firstred = firstx-2;
	int lastred= firstx - 2;
	int i = 0;
	while (1) {
		if (lastred == red)
			break;
		i++;
		firstx -= 1;
		firsty += 1;
		lastred = (firstred-i)*(i+1);
	}

	answer.push_back(firstx);
	answer.push_back(firsty);

	return answer;
	
}
/*
int main(void) {
	int brown = 24;
	int red = 24;
	vector<int> result = solution(brown, red);
	cout << result[0] << "   " << result[1] << endl;
}

*/