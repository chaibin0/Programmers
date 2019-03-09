#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

namespace find_path_game {
	struct Tree {
		int x;
		int y;
		int index;
		Tree * left;
		Tree * right;

	};

	vector<int> postcircuit(const Tree *tree, vector<int> &post) {
		if (tree->left != NULL)
			postcircuit(tree->left, post);
		if (tree->right != NULL)
			postcircuit(tree->right, post);
		post.push_back(tree->index);

		return post;
	}

	vector<int> precircuit(const Tree *tree, vector<int> &pre) {
		pre.push_back(tree->index);
		if (tree->left != NULL)
			postcircuit(tree->left, pre);
		if (tree->right != NULL)
			postcircuit(tree->right, pre);
		return pre;
	}

	
	//기존 데이터 정렬 y축은 큰순, x축은 작은 순
	bool pred(vector<int> a, vector<int> b) {
		if (a[1] == b[1])
			return a[0] < b[0];
		else
			return a[1] > b[1];
	}
	vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
		vector<vector<int>> answer;

		//인덱스 번호 추가
		for (int i = 0; i < nodeinfo.size(); i++) {
			nodeinfo[i].push_back(i + 1);
		}
		sort(nodeinfo.begin(), nodeinfo.end(), pred);

		for (int i = 0; i < nodeinfo.size(); i++) {
			for (int j = 0; j < nodeinfo[i].size(); j++) {
				cout << nodeinfo[i][j] << " ";
			}
			cout << endl;
		}

		int height = nodeinfo[0][1];

		//root tree
		Tree tree = { nodeinfo[0][0] ,nodeinfo[0][1],nodeinfo[0][2],NULL,NULL };
		Tree * iterator;
		for (int i = 1; i < nodeinfo.size(); i++) {
			iterator = &tree;

			while (1) {
				if (iterator->x > nodeinfo[i][0]) {		//왼쪽 노드
					if (iterator->left == NULL) {
						iterator->left = new Tree{ nodeinfo[i][0],nodeinfo[i][1] ,nodeinfo[i][2],NULL,NULL };
						break;
					}
					else
						iterator = iterator->left;
				}
				else {
					if (iterator->right == NULL) {
						iterator->right = new Tree{ nodeinfo[i][0],nodeinfo[i][1] ,nodeinfo[i][2],NULL,NULL };
						break;
					}
					else
						iterator = iterator->right;
				}
			}
		}
		vector<int> pre;
		vector<int> post;
		answer.push_back(precircuit(&tree,pre));
		answer.push_back(postcircuit(&tree,post));

		return answer;
	}

	
};

/*
int main(void) {
	vector<vector<int>> nodeinfo = { {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };
	vector<vector<int>> result = find_path_game::solution(nodeinfo);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
*/
