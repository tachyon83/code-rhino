#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <stack>
#include <limits.h>
#include <queue>
#include <memory.h>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    int ret = 0;
    string s,temp="";
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n-1; i++) {
        temp += "OI";
    }
    for (int i = 0; i < m-3; i++) {
        if (s.substr(i, 3) == "IOI") {
            if (n == 1) {
                ret++;
            }
            else if (s.substr(i + 3, 2*n-2)==temp && i+3<m&&i+3+2*n-2<m) {
                ret++;
            }
        }
    }
    cout << ret;
}
