#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int hArr[9];	//난쟁이 9명 키를 담을 배열
	int totHeight = 0;	//난쟁이 키 총합

	for (int i = 0; i < 9; i++) {
		cin >> hArr[i];
		totHeight += hArr[i];
	}

	sort(hArr, hArr + 9);	//오름차순 출력을 위한 정렬

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			//두명의 키를 뺐을 때의 총합이 100인 경우
			if ((totHeight - hArr[i] - hArr[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					//두명을 제외한 다른 난쟁이 키 출력
					if (k == i || k == j) {
						continue;
					}
					cout << hArr[k] << '\n';
				}
				i = j = 9;
				break;
			}
		}
	}

	return 0;
}
