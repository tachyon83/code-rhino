#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void tracking(vector<char> alpa, vector<char> result,int mo,int ja,int index);
int L, C;

int main() {

	vector<char> alpa;
	vector<char> result;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char x;
		cin >> x;
		alpa.push_back(x);
	}
	sort(alpa.begin(), alpa.end());
	for (int i = 0; i < alpa.size(); i++) {
		tracking(alpa, result, 0, 0, i);
	}
	
}

void tracking(vector<char> alpa, vector<char> result, int mo, int ja,int index) {

	//넣기
	if (alpa[index] == 'a' || alpa[index] == 'e' || alpa[index] == 'i' || alpa[index] == 'o' || alpa[index] == 'u') {
		mo++;
	}
	else {
		ja++;
	}
	result.push_back(alpa[index]);
	//넣은후 길이가 L이면 출력
	if ((result.size() == L)) {
		if ((mo >= 1) && (ja >= 2)) {
			for (int i = 0; i < result.size(); i++) {
				printf("%c", result[i]);
			}
			printf("\n");
		}
		else {
			return;
		}
	}
	//아니면 더넣기
	else {
		for (int i = index+1; i < alpa.size(); i++) {
			tracking(alpa, result, mo, ja, i);
		}
	}
}
