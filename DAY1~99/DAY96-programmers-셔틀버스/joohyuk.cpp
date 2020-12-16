#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

string numToTimestamp(int n){
    int hh=n/60;
    int mm=n%60;
    string ret="";
    if(hh<10)ret+='0';
    ret+=to_string(hh)+':';
    if(mm<10)ret+='0';
    ret+=to_string(mm);
    return ret;
}
int timestampToNum(string st){
    int hh=stoi(st.substr(0,2));
    int mm=stoi(st.substr(3,2));
    return hh*60+mm;
}

string solution(int n, int t, int m, vector<string> timetable) {

    string answer = "";
    sort(timetable.begin(),timetable.end());
    int bustime=9*60;
    int ans=-1,busn=1,cnt=0;
    bool flag=0;

    for(int i=0;i<timetable.size();++i){
        auto curr=timestampToNum(timetable[i]);
        if(curr<=bustime){
            if(cnt<m-1)cnt++;
            else{
                if(busn<n){
                    busn++;
                    bustime+=t;
                    cnt=0;
                }else{
                    ans=curr-1;
                    flag=1;
                    break;
                }
            }
        }else{
            while(curr>bustime && busn<n){
                bustime+=t;
                busn++;
                cnt=0;
            }
            if(curr>bustime){
                ans=bustime;
                flag=1;
                break;
            }else i--;
        } 
    }
    if(!flag)ans=bustime;
    answer=numToTimestamp(ans);
    return answer;
}
