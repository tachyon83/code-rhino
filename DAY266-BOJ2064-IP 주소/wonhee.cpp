#include<iostream>
#include<algorithm>
using namespace std;
string in[1001], s[1001];//2진수로 변환

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	int ip_address;
	for (int i = 0; i < N; i++)
	{
		cin >> in[i];

		//2진수로 변환
		int num = 0;
		for (int j = 0; j < in[i].size(); j++)
		{
			if (in[i][j] == '.')
			{
				string temp;
				for (int k = 0; k < 8; k++)
				{
					int n = num % 2; num /= 2;
					temp += '0' + n;
				}
				reverse(temp.begin(), temp.end());
				s[i] += temp;
			}
			else
			{
				num *= 10;
				num += in[i][j] - '0';
			}
		}
		string temp;
		for (int k = 0; k < 8; k++)
		{
			int n = num % 2; num /= 2;
			temp += '0' + n;
		}
		reverse(temp.begin(), temp.end());
		s[i] += temp;
	}

	//각 자릿수마다 모든 주소에 대해서 다 같은지 체크
	bool c[32];
	for (int i = 0; i < 32; i++) c[i] = 1;
	for (int j = 0; j < 32; j++)
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (s[i][j] != s[i + 1][j])
			{
				c[j] = 0;
				break;
			}
		}
	}

	string net_address, net_mask;
	int num = 32;
	for (int i = 0; i < 32; i++)
	{
		if (!c[i])
		{
			num = i;
			break;
		}
	}

	for (int i = 0; i < num; i++)
	{
		net_address += s[0][i];
		net_mask += '1';
	}
	for (int i = num; i < 32; i++)
	{
		net_address += '0';
		net_mask += '0';
	}
	num = 0;
	for (int i = 0; i < 8; i++)
	{
		num *= 2;
		num += net_address[i] - '0';
	}
	cout << num;
	for (int i = 8; i < 32; i += 8)
	{
		int num = 0;
		for (int j = i; j < i + 8; j++)
		{
			num *= 2;
			num += net_address[j] - '0';
		}
		cout << '.' << num;
	}
	cout << '\n';

	num = 0;
	for (int i = 0; i < 8; i++)
	{
		num *= 2;
		num += net_mask[i] - '0';
	}
	cout << num;
	for (int i = 8; i < 32; i += 8)
	{
		int num = 0;
		for (int j = i; j < i + 8; j++)
		{
			num *= 2;
			num += net_mask[j] - '0';
		}
		cout << '.' << num;
	}
	cout << '\n';

	return 0;
}