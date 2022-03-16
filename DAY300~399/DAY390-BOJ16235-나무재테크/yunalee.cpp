#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 12;

int N, M, K;
vector<int> arr[MAX][MAX];
int nutrient[MAX][MAX];
int map[MAX][MAX];

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

void solution() {
    // 봄, 여름
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j].size() == 0) continue;
            sort(arr[i][j].begin(), arr[i][j].end());

            int death = 0;
            for (int k = 0; k < arr[i][j].size(); k++) {
                int nt = arr[i][j][k];

                if (nutrient[i][j] >= nt) {
                    arr[i][j][k] = nt + 1;
                    nutrient[i][j] -= nt;
                }
                else {
                    arr[i][j].erase(arr[i][j].begin() + k);
                    k -= 1;
                    death += nt / 2;
                }
            }

            nutrient[i][j] += death;

        }
    }


    // 가을
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j].size() == 0) continue;
            for (int k = 0; k < arr[i][j].size(); k++) {
                if (arr[i][j][k] % 5 == 0) {
                    int ny, nx;
                    for (int p = 0; p < 8; p++) {
                        ny = i + dy[p];
                        nx = j + dx[p];
                        if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                            arr[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
    }

    // 겨울
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            nutrient[i][j] += map[i][j];
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            nutrient[i][j] = 5;
        }
    }

    int y, x, age;
    for (int i = 0; i < M; i++) {
        cin >> y >> x >> age;
        arr[y - 1][x - 1].push_back(age);
    }

    for (int i = 0; i < K; i++) {
        solution();
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer += arr[i][j].size();
        }
    }

    cout << answer << "\n";


    return 0;
}
