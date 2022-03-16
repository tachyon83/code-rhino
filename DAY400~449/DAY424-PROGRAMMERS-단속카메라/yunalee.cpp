#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int, int>> vc;
    
    sort(routes.begin(), routes.end());
    vc.push_back(make_pair(routes[0][0], routes[0][1]));
    for(int i = 1; i < routes.size(); i++){
        int a = routes[i][0];
        int b = routes[i][1];
        bool flag = false;
        for(int j = 0; j < vc.size(); j++){
            flag = false;
            if(vc[j].first <= a && a <= vc[j].second){
                vc[j].first = a;
                flag = true;
            }
            if(vc[j].first <= b && b <= vc[j].second){
                vc[j].second = b;
                flag = true;
            }
            
            if(flag){
                break;
            }
        }
        if(!flag){
            vc.push_back(make_pair(a, b));
        }
    }
    
    answer = vc.size();
    
    return answer;
}
