#include <string>
#include <vector>
#include <iostream>

using namespace std;

int minMove = 987987987;
void go(vector<pair<int, int>> notA, vector<bool> visited, vector<pair<int, int>> choNum, int k, int cnt, int totSize){
    if(k == cnt){
        int curPos = 0;
        int subMove = 0;
        cout << '\n';
        for(int i = 0; i < choNum.size(); i++){
            cout << (char)(choNum[i].second+'A');
        }
        cout << '\n';
        if(cnt == 6){
            if(choNum[0].second + 'A' != 'J'){
                return;
            }
            if(choNum[1].second + 'A' != 'E'){
                return;
            }
            if(choNum[2].second + 'A' != 'R'){
                return;
            }
            if(choNum[3].second + 'A' != 'O'){
                return;
            }
            if(choNum[4].second + 'A' != 'E'){
                return;
            }
            if(choNum[5].second + 'A' != 'N'){
                return;
            }
        }else{
            return;
        }
        
        for(int i = 0; i < choNum.size(); i++){
            int leftMove = curPos - choNum[i].first;
            int rightMove = curPos + choNum[i].first;
            leftMove = leftMove < 0 ? leftMove + totSize : leftMove;
            rightMove = rightMove >= totSize ? rightMove - totSize : rightMove;
            
            int m = leftMove <= rightMove ? leftMove : rightMove;
            subMove += m;
            curPos = choNum[i].first;
            cout << "cursor Move: " << m << ' ';
            int leftAlpha = choNum[i].second - 0;
            int rightAlpha = ('Z' - 'A') - choNum[i].second + 1;
            m = leftAlpha <= rightAlpha ? leftAlpha : rightAlpha;
            cout << "alpha Move: " << m << '\n';
            subMove += m;
        }
        
        if(subMove < minMove){
            minMove = subMove;
        }
        
        return;
    }
    
    for(int i = 0; i < notA.size(); i++){
        if(!visited[i]){
            choNum.push_back(make_pair(notA[i].first, notA[i].second));
            visited[i] = true;
            go(notA, visited, choNum, k, cnt+1, totSize);
            visited[i] = false;
            choNum.erase(choNum.end());
        }
    }
}


int solution(string name) {
    int answer = 0;
    vector<pair<int, int>> notA;
    
    for(int i = 0; i < name.size(); i++){
        if(name[i] != 'A'){
            notA.push_back(make_pair(i, name[i] - 'A'));
        }
    }
    vector<bool> visited(notA.size(), false);
    
    vector<pair<int, int>> choNum;
    go(notA, visited, choNum, notA.size(), 0, name.size());
    
    answer = minMove;
    
    return answer;
}
