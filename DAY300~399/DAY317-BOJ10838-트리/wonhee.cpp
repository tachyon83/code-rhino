#include <iostream>
#include <vector>
#include <set>
using namespace std;
int check[100000], parent[100000];
int paint_up[100000];

int findCommonParent(int a, int b, int chk)
{
    if (a == b)
        return a;

    int cnt = 0;
    while (cnt <= 1000)
    {
        if (a >= 0)
        {
            if (check[a] == chk)
                return a;
            check[a] = chk;
        }
        if (b >= 0)
        {
            if (check[b] == chk)
                return b;
            check[b] = chk;
        }

        if (a >= 0)
            a = parent[a];
        if (b >= 0)
            b = parent[b];
        cnt++;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;

    parent[0] = -1;
    for (int i = 1; i < N; i++)
    {
        paint_up[i] = 0;
        parent[i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int opt, a, b;
        cin >> opt >> a >> b;

        int commonParent;
        switch (opt)
        {
        case 1:
        {
            int paint; cin >> paint;
            commonParent = findCommonParent(a, b, i + 1);

            while (a != commonParent)
            {
                paint_up[a] = paint;
                a = parent[a];
            }

            while (b != commonParent)
            {
                paint_up[b] = paint;
                b = parent[b];
            }
            break;
        }
        case 2:
        {
            parent[a] = b;
            break;
        }
        default:
        {
            set <int> checkSet;
            commonParent = findCommonParent(a, b, i + 1);

            while (a != commonParent)
            {
                checkSet.insert(paint_up[a]);
                a = parent[a];
            }

            while (b != commonParent)
            {
                checkSet.insert(paint_up[b]);
                b = parent[b];
            }
            cout << checkSet.size() << '\n';
        }
        }
    }

    return 0;
}