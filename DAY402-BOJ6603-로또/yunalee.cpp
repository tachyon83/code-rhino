#include <bits/stdc++.h>
using namespace std;

int k;
int arr[15];
int arr2[15];
bool visited[15];

void solution(int idx) {
    if (idx == 6) {
        int minVal = -1;
        bool flag = true;
        for (int i = 0; i < 6; i++) {
            if (minVal > arr2[i]) {
                flag = false;
                break;
            }
            minVal = arr2[i];
        }

        if (flag) {
            for (int i = 0; i < 6; i++) {
                cout << arr2[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }

    for (int i = 0; i < k; i++) {
        if (!visited[i]) {
            arr2[idx] = arr[i];
            visited[i] = true;
            solution(idx + 1);
            visited[i] = false;
        }
    }
}

void Print() {
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    for (int i = 0; i < 15; i++) {
        cout << arr2[i] << ' ';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        cin >> k;
        if (k == 0) {
            break;
        }

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        solution(0);
        cout << "\n";

        for (int i = 0; i < 15; i++) {
            arr[i] = 0;
            arr2[i] = 0;
        }
    }
}
