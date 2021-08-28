#include <iostream>
using namespace std;

int arr[10001] = { 0, };
int main() {
    int N, M;
    int usableAlphabets = 0;

    cin >> N >> M;

    for (int i = 0; i < 26; i++)
        usableAlphabets += (1 << i);

    string word;
    for (int i = 0; i < N; i++) {
        cin >> word;

        for (int j = 0; j < word.size(); j++)
            arr[i] |= (1 << (word[j] - 'a'));
    }

    char o,x;
    for (int i = 0; i < M; i++) {
        cin >> o >> x;

        if (o == '1')
            usableAlphabets -= (1 << (x - 'a'));
        else
            usableAlphabets += (1 << (x - 'a'));

        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if ((arr[j] & usableAlphabets) == arr[j])
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}