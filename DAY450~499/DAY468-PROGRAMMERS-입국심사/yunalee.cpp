#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    /**
     * 맨앞의 고객은 비어있는 입국심사대로 간다
     * 비어있는 입국심사대를 가서 업무처리 하는 것보다 다른 곳이 더 빠르다면 대기한다
     */
    
    sort(times.begin(), times.end());
    
    //최소 = n이 1이고 심사시간이 1분
    //최대 = n명이 최대 소요 심사시간을 갖을때
    long long start = 1;
    long long end = (long long)times[times.size() - 1] * n;
    long long mid;
    
    while(start <= end){
        mid = (start + end)/2;
        
        long long cnt = 0;
        
        for(int i = 0; i < times.size(); i++){
            cnt += mid/times[i];
        }
        
        if(cnt < n){
            start = mid + 1;
        }else{
            if(mid <= end){
                answer = mid;
            }
            end = mid - 1;
        }
    }
    
    return answer;
}
