#include <iostream>
#include <vector>

#define MAX 2000000
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	bool arr[MAX];
	vector<int> v;
	fill_n(arr, MAX, true);
	arr[0] = false;
	arr[1] = false; 
	
	for(int i = 2; i < MAX; i++) {
			if(arr[i]) {
				for(int j = i+i; j < MAX; j+=i)
					arr[j] = false;
			}			
		}
	
	for(int i = 2; i < MAX; i++) {
		int a = i;
		if(arr[i]) {
			while(a / 10 != 0) {
				v.push_back(a % 10);
				a = a / 10;
			}
			v.push_back(a);
			int len = v.size();
			for(int j = 0; j < len; j++) {
				if(j == len-j-1)
					break;
				if(v[j] == v[len-j -1])
					continue;
				else {
					arr[i] = false;
					break;
				}
			}
		}
		v.clear();
	}
	
	for(int i = N; i < MAX; i++)
		if(arr[i]) {
			cout<<i;
			break;
		}

	return 0;
}
