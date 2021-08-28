#include<iostream>
#include<queue>
using namespace std;
queue<int> q[101];
int arr[101];
bool c[101] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K; cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		q[arr[i]].push(i);
	}

	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < K; i++)
	{
		if (cnt != N) //아직 멀티탭에 빈칸이 남는 경우
		{
			if (!c[arr[i]])
			{
				c[arr[i]] = 1;
				++cnt;
			}
		}
		else //멀티탭에서 하나를 빼야하는 경우
		{
			if (!c[arr[i]])
			{
				//빼야할것 찾기 - 해당 수의 다음 위치가 가장 가까운것. 
				//만약 다음에 안나오면 0순위
				int num, temp = 0;
				for (int j = 1; j < 101; j++)
				{
					if (c[j])
					{
						if (q[j].empty())
						{
							num = j;
							break;
						}
						else if (temp < q[j].front())
						{
							temp = q[j].front();
							num = j;
						}
					}
				}
				c[num] = 0;
				c[arr[i]] = 1;
				++ret;
			}
		}
		q[arr[i]].pop();
	}
	cout << ret;
	return 0;
}