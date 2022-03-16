#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long solution(int n, vector<int> times);
long long doCount(long long minutes, vector<int> times);

long long solution(int n, vector<int> times) {
    long long start = (long long)(*min_element(times.begin(), times.end()));
    long long end = (long long)(*min_element(times.begin(), times.end())) * (long long)n;
    long long mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (doCount(mid,times) >= (long long)n) {
            end = mid;
        }
        else {
            start = mid+1;
        }
    }
    return end;

}

long long doCount(long long minutes,vector<int> times ) {
    long long days = 0;
    for (int i = 0; i < times.size(); i++) {
        days += (minutes/(long long)times[i]);
    }
    return days;
}
