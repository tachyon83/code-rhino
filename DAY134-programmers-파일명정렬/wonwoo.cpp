#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct FILES {
    vector<string> subArr;
    int idx;
};
bool compare(const struct FILES& a, const struct FILES& b) {
    int ret = a.subArr[0].compare(b.subArr[0]);
    if (ret == 0) {
        return stoi(a.subArr[1]) < stoi(b.subArr[1]);
    }
    else {
        return ret < 0;
    }
}
vector<string> solution(vector<string> files) {
    int size = files.size();
    vector<string> copyFiles(size);
    for (int i = 0; i < size; i++) {
        copyFiles[i] = files[i];
    }

    vector<struct FILES> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i].idx = i;
        arr[i].subArr.resize(3);
        int len = files[i].length();
        int numStart = -1, numEnd = -1;
        transform(files[i].begin(), files[i].end(), files[i].begin(), ::toupper);
        for (int j = 0; j < len; j++) {
            if (numStart == -1 && files[i][j] >= '0' && files[i][j] <= '9') {
                numStart = j;
            }
            else if (numStart >= 0 && (files[i][j] < '0' || files[i][j] > '9')) {
                numEnd = j;
                break;
            }
        }
        numEnd = numEnd == -1 ? len : numEnd;
        arr[i].subArr[0] = files[i].substr(0, numStart);
        arr[i].subArr[1] = files[i].substr(numStart, numEnd - numStart);
        if (numEnd < len) {
            arr[i].subArr[2] = files[i].substr(numEnd, len - numEnd);
        }
    }

    stable_sort(arr.begin(), arr.end(), compare);

    vector<string> answer(size);
    for (int i = 0; i < size; i++) {
        answer[i] = copyFiles[arr[i].idx];
    }
    return answer;
}