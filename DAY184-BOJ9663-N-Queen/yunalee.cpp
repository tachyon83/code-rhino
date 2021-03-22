#include <iostream>
#define MAX 156
using namespace std;

int arrX[MAX];
int arrY[MAX];
int n;

int solution(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		if (x == arrX[i]) {
			return 0;
		}
		if (y == arrY[i]) {
			return 0;
		}
		if (abs(x - arrX[i]) == abs(y - arrY[i]))
		{
			return 0;
		}
	}

	if (y == n - 1)
	{
		return 1;
	}

	arrX[y] = x;
	arrY[y] = y;

	int r = 0;
	for (int i = 0; i < n; i++)
	{
		r += solution(i, y + 1);
	}
	return r;
}
int main()
{
	cin >> n;

	int r = 0;
	for (int i = 0; i < n; i++)
	{
		r += solution(i, 0);
	}
	cout << r << "\n";

	return 0;
}
