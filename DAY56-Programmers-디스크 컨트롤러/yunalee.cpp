#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int workCnt = jobs.size();
    vector<pair<int, int>> readyQ;
    sort(jobs.begin(), jobs.end()); //job이 들어온 시간 오름차순 중, 작업 소요시간 오름차순 정렬

    int startTime = 0;
    int endTime = 0;
    while (readyQ.size() > 0 || jobs.size() > 0) {
        //
        if (readyQ.size() == 0) {
            readyQ.push_back(make_pair(jobs[0][0], jobs[0][1]));    //최초 작업 적재
            jobs.erase(jobs.begin());  //적재된 작업 삭제 
        }
        //수행할 작업의 시작,종료시간 계산
        if (endTime >= readyQ[0].first) {
            startTime = endTime;
        }
        else {
            startTime = readyQ[0].first;
        }
        endTime = startTime + readyQ[0].second;

        //작업 수행 중, 들어오는 job 적재
        while (jobs.size() > 0 && jobs[0][0] <= endTime) {
            if (endTime >= jobs[0][0]) {    //작업 수행중 적재가 가능한 job 체크
                readyQ.push_back(make_pair(jobs[0][0], jobs[0][1]));
                jobs.erase(jobs.begin());
            }
        }

        answer = answer + (endTime - readyQ[0].first);
        readyQ.erase(readyQ.begin());   //종료된 작업 삭제
        sort(readyQ.begin(), readyQ.end(), comp);   //수행 가능한 작업중 가장 짧은 작업순으로 정렬
    }

    return answer / workCnt;
}
