#include <iostream>
#include <vector>
using namespace std;

int hanoiCount(int num)
{
	if (num == 1)
	{
		return 1;
	}

	return hanoiCount(num - 1) * 2 + 1;
}

void hanoiRoot(int num, int from, int by, int to)
{
	if (num == 1)
	{
		cout << from << " " << to << '\n';
	}
	else
	{
		hanoiRoot(num - 1, from, to, by);
		cout << from << " " << to << '\n';
		hanoiRoot(num - 1, by, from, to);
	}
}

int main()
{
	int num, totalCnt;
	cin >> num;

	totalCnt = hanoiCount(num);
	cout << totalCnt << '\n';

	hanoiRoot(num, 1, 2, 3);
}
