#include <iostream>

using namespace std;

int N;
int arr[1001][10];
int result = 0;

void solved(){
    for(int i = 0; i < 10; i++){
        arr[1][i] = 1;
    }

    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++){
                arr[i][j] = arr[i][j] + arr[i - 1][k];
                arr[i][j] = arr[i][j] % 10007;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        result = result + arr[N][i];
    }
    result = result % 10007;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    solved();

    cout << result << '\n';

    return 0;
}
