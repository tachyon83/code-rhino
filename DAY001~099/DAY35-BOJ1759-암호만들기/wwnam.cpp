#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> arr;
int L, C;
bool checkVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}
void makePass(int idx, string str, int cons, int vowel)
{
	if (cons + vowel == L)
	{
		if (cons >= 2 && vowel >= 1)
			cout << str << '\n';
		return;
	}

	for (int i = idx; i < C; i++)
	{
		string tmp = str + arr[i];
		if (checkVowel(arr[i]))
			makePass(i + 1, tmp, cons, vowel + 1);
		else
			makePass(i + 1, tmp, cons + 1, vowel);
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> L >> C;
	arr = vector<char>(C);
	for (int i = 0; i < C; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	makePass(0, "", 0, 0);
}
