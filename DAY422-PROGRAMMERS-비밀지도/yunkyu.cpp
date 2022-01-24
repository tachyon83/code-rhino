#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++){
        int num1 = arr1[i];
        int num2 = arr2[i];
        string str = "";
        // arr1과 arr2의 i번째 줄에 대해 각각 비트마스크를 이용해서 비트 확인
        for(int j = n - 1; j >= 0; j--){
            if((num1 & 1 << j) || (num2 & 1 << j)) str += '#'; // j번째에 둘중 하나라도 벽이 있다면 (이진수에서 1 이라면)
            else str += ' ';
        }
        answer.push_back(str);
    }
    return answer;
}
