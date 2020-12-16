#include <iostream>
#include <vector>
// #include <pair>
#include <algorithm> //sort
#include <cstring>   //memset
#define endl '\n'
using namespace std;
char abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char vw[5] = {'a', 'e', 'i', 'o', 'u'};
vector<pair<int, char>> vec;
char ans[16];
int vwFlag = 0, cnt = 0, l, c, cntCs = 0, cntVw = 0;
bool cmp(pair<int, char> a, pair<int, char> b)
{
    if (a.first < b.first)
        return true;
    else
        return false;
}
void pass(int pos)
{
    for (int i = pos; i < c - l + 1 + cnt; i++)
    {
        ans[cnt] = vec[i].second;
        if (cnt == l - 1)
        {
            for (int j = 0; j < l; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (ans[j] == vw[k])
                    {
                        cntVw++;
                        vwFlag = 1;
                        break;
                    }
                }
                if (!vwFlag)
                    cntCs++;
                vwFlag = 0;
            }
            if (cntCs >= 2 && cntVw >= 1)
            {
                for (int j = 0; j < l; j++)
                {
                    cout << ans[j];
                }
                cout << endl;
                        }
            cntCs = 0;
            cntVw = 0;
        }
        else
        {
            cnt++;
            pass(i + 1);
        }
    }
    cnt--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char ch;
    cin >> l >> c;
    for (int i = 0; i < c; ++i)
    {
        cin >> ch;
        for (int j = 0; j < 26; j++)
        {
            if (ch == abc[j])
            {
                vec.emplace_back(make_pair(j, ch));
                break;
            }
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    pass(0);

    return 0;
}
