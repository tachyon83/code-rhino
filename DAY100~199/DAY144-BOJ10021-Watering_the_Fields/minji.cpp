#include <bits/stdc++.h>

int p[2001];

using namespace std;

struct A {
    int from, to, dist;
    bool operator<(const A obj) {
        return dist < obj.dist;
    }
};

int Find(int x){
    if (x==p[x])
        return x;
    else
        return p[x] = Find(p[x]);
}

void Union_(int x, int y)
{
    x = Find(x);
    y = Find(y);
    p[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> v;
    vector<A> a;
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

	
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = (v[i].first - v[j].first) * (v[i].first - v[j].first);
            d += (v[i].second - v[j].second) * (v[i].second - v[j].second);
            if (d >= c)
                a.push_back({i + 1, j + 1, d});
        }
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
	sort(a.begin(), a.end());
	long long ans = 0;
	int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (Find(a[i].from) != Find(a[i].to)) {
	        Union_(a[i].from, a[i].to);
	        cnt += 1;
	        ans += (long long)a[i].dist;
	    }
	}
	(cnt == n -1 ) ? std::cout << ans << '\n' : std::cout << -1 << '\n';
}
