#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long  ll;

vector<ll> getPi(string s) {
	int i;
	// s의 i인덱스까지의 부분 문자열의 겹치는 접미사, 접두사 배열의 최대 길이
	vector<ll> pi(s.size(), 0);
	int j = 0;
	for (i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) 
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}

	return pi;
}

int main() {
	string s;
	ll n;

	cin >> s >> n;
	vector<ll> pi = getPi(s);
	cout << s.size() + (n - 1) * (s.size() - pi[s.size() - 1]);
	return 0;
}
