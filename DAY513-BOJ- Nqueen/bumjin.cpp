#include <string>
#include <vector>
#include <cmath>
using namespace std;
int row[12];
int answer;
int N;

bool check(int r){
    for(int i=0;i<r;i++){
        if(row[r]==row[i]){
            return false;        
        }
        else if(abs(row[i]-row[r])==abs(r-i)){
            return false;
        }    
    }
    return true;
}


void Dfs(int r){
    if(r==N){
        ++answer;
        return;
    }
    
    for(int i=0;i<N;i++){
        row[r]=i;
        if(check(r)){
            Dfs(r+1);
        }
        row[r]=0;
    }
    return;
}

int solution(int n) {
    int r=0;
    N=n;    
    answer=0;
    for(int i=0;i<12;i++){
        row[i]=0;
    }
    Dfs(0); 
    return answer;
}
