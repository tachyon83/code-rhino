#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> v;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        if (v.empty() ||v[v.size()-1]<num)
            v.push_back(num);
        else {
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
        }
    }
    cout << n - v.size() << '\n';
    return 0;
}