#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<char>>::iterator iter;
	vector<vector<string>> answer;
	vector <vector<char>> standard;
	for (int i = 0; i < strs.size(); i++) {
		vector<char> tmp;
		for (int j = 0; j < strs[i].size(); j++) {
			tmp.push_back((strs[i][j]));
		}
		sort(tmp.begin(), tmp.end());
		iter = find(standard.begin(), standard.end(), tmp);
		//존재하면 그쪽에 삽입
		if (iter != standard.end()) {
			answer[distance(standard.begin(),iter)].push_back(strs[i]);
		}
		//존재하지않으면 새로운곳 삽입
		else {
			vector<string> tmp2;
			tmp2.push_back(strs[i]);
			answer.push_back(tmp2);
			standard.push_back(tmp);
		}

	}
	return answer;
    }
};
