#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Result {
	int number;
	double fail;
};

bool pred(Result a, Result b) {
	return a.fail < b.fail;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<Result> result;
	vector<int> pass(N);
	vector<int> fail(N);
	
	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] > N) {
			for (int j = 0; j < N; j++)
				pass[j]++;
		}
		else {
			for (int j = 0; j < stages[i]; j++) {
				pass[j]++;
			}

			fail[stages[i] - 1]++;
		}		
	}

	for (int i = 0; i < pass.size(); i++) {
		result.push_back({ i + 1,(double)pass[i] / fail[i] });
	}

	stable_sort(result.begin(), result.end(), pred);
	for (int i = 0; i < pass.size(); i++) {
		answer.push_back(result[i].number);
	}
	return answer;
}
/*
int main(void) {
	vector<int> stages = { 2,1,2,6,2,4,3,3 };
	vector<int> result=solution(5, stages);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	cout << endl;
}
*/