#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long arr[360000];

int getSeconds(string time){ // 문자열을 파싱해서 초로 구해준다.
    string hour = time.substr(0,2);
    string minute = time.substr(3,2);
    string second = time.substr(6,2);
    
    return stoi(hour) * 60 * 60 + stoi(minute) * 60 + stoi(second);
}

string timeToStr(int time){ // 정수를 문자열 시:분:초로 표현
    int hour = time / 3600;
    time %= 3600;
    int minute = time / 60;
    time %= 60;
    int second = time;
    
    string ret = "";
    if(hour < 10)
        ret += "0";
    ret += to_string(hour);
    ret += ":";
    if(minute < 10)
        ret += "0";
    ret += to_string(minute);
    ret += ":";
    if(second < 10)
        ret += "0";
    ret += to_string(second);
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playSeconds = getSeconds(play_time);
    int advSeconds = getSeconds(adv_time);
    
    // 각 재생시간의 구간에 대해 시청자의 수 count
    for(auto log : logs) {
        int start = getSeconds(log.substr(0,8));
        int end = getSeconds(log.substr(9,8));
        for(int i = start; i < end; i++){
            arr[i] ++;
        }
    }
    
    // 구간 시청자수에 대한 누적합 구함
    for(int i = 0; i < playSeconds; i++){
        arr[i + 1] += arr[i];
    }
    
    long long mx = arr[advSeconds] - arr[0];
    int mxIdx = 0;
    // 광고 재생시간동안 누적합이 가장 큰 시간을 찾는다.
    for(int i = 0; i < playSeconds - advSeconds + 1; i++){
        if(mx < arr[i + advSeconds] - arr[i]){
            mx = arr[i + advSeconds] - arr[i];
            mxIdx = i + 1;
        }
        
    }

    answer = timeToStr(mxIdx);
    return answer;
}
