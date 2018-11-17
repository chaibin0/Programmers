/* 2018-11-17 프로그래머스 타겟 넘버 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;
int dfs(vector<int> numbers, int number, int target, int value);
int TargetNumber(vector<int> numbers, int target);

int TargetNumber(vector<int> numbers, int target) {
	int answer = 0;
	answer = dfs(numbers, 1, target, numbers[0]) + dfs(numbers, 1, target, -(numbers[0]));
	return answer;
}

int dfs(vector<int> numbers, int number, int target,int value) {
	if (number < numbers.size())
		return dfs(numbers, number + 1, target, value+numbers[number])+dfs(numbers, number + 1, target, value-numbers[number]);

	if (number == numbers.size() && target == value)
		return 1;
	else 
		return 0;

}
/*
int main(void) {
	vector<int > numbers {1, 1, 1, 1, 1};
	int target = 3;
	cout << TargetNumber(numbers, target) << endl;
}
*/