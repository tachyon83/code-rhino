#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int> > tree;
void quadtree(int row, int col, int n)
{
	if (n == 1)
	{
		cout << tree[row][col];
		return;
	}

	int color = tree[row][col];
	bool check = false;
	for (int i = 0; i < n && !check; i++)
		for (int j = 0; j < n && !check; j++)
			if (color != tree[row + i][col + j])
				check = true;

	if (!check)
		cout << color;
	else
	{
		cout << "(";
		quadtree(row, col, n / 2);
		quadtree(row, col + n / 2, n / 2);
		quadtree(row + n / 2, col, n / 2);
		quadtree(row + n / 2, col + n / 2, n / 2);
		cout << ")";
	}
}
int main(void)
{
	int n;
	cin >> n;
	vector<string> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];

	for (int i = 0; i < n; i++)
	{
		tree.push_back(vector<int>(n, 0));
		for (int j = 0; j < n; j++)
			tree[i][j] = (int)(input[i][j] - '0');
	}
	quadtree(0, 0, n);
}