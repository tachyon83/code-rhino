#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> sumUm;   //key:장르, value: 장르별 play수 누적합
    unordered_map<string, vector<pair<int, int>>> um;   //key: 장르, value: (play수, 고유번호i)
    unordered_map<string, int>::iterator iter;
    for(int i = 0; i < genres.size(); i++){
        um[genres[i]].push_back(make_pair(plays[i], i));
        iter = sumUm.find(genres[i]);
        if(iter == sumUm.end()){
            sumUm[genres[i]] = plays[i];
        }else{
            sumUm[genres[i]] += plays[i];
        }
    }
    
    vector<pair<string, int>> vc;
    for(iter = sumUm.begin(); iter != sumUm.end(); iter++){
        vc.push_back(make_pair(iter->first, iter->second));
    }
    sort(vc.begin(), vc.end(), cmp);    //장르별 총 play수를 기준으로 내림차순 정렬
    
    
    for(int i = 0; i < vc.size(); i++){
        string key = vc[i].first;
        sort(um[key].begin(), um[key].end(), cmp2);  //해당 장르에서 play수를 기준으로 내림차순 정렬
        
        for(int i = 0; i < um[key].size(); i++){
            if(i >= 2){ //상위 2곡만 베스트 앨범이므로 이후 순위를 가리킬 경우 종료
                break;
            }
            answer.push_back(um[key][i].second);
        }
    }
    
    
    
    return answer;
}
