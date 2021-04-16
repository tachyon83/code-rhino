#include <queue>
#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 99999 + 1;
bool visited[maxN];
class Button
{
private:
    int T, G;
    queue<int> Q;
    bool A(){
        int n = Q.front();
        n++;
        if (n == G)return 0;
        else if (n < maxN && !visited[n]){
            Q.push(n);
            visited[n] = 1;
        }
        return 1;
    }
    bool B(){
        int n = Q.front();
        if (!n){
            if (!visited[0])Q.push(0);
        }else if (n * 2 < maxN){
            int m = n * 2;
            int p = 1;
            while (m >= 10)
            { m /= 10; p *= 10;}
            n = n * 2 - p;
            if (n == G)return 0;
            else if (n < maxN && !visited[n]){
                Q.push(n);
                visited[n] = 1;
            }
        }
        return 1;
    }

public:
    Button() { T = 0; G = 0;}
    Button(int t, int g) { T = t; G = g; }
    int solve(int n){
        int Qs, t = 0;
        if (n == G)return t;
        Q.push(n);

        while (!Q.empty() && t < T){
            t++;
            Qs = Q.size();
            for (int i = 0; i < Qs; ++i){
                if (!A())return t;
                if (!B())return t;
                Q.pop();
            }
        }
        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, g, res;
    cin >> n >> t >> g;
    Button B(t, g);
    res = B.solve(n);
    if (res == -1)cout << "ANG" << endl;
    else cout << res << endl;
    return 0;
}
