#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000][10000];
int n;
int arr[1000];
int max_result=0;

void input(){
    cin >>n;
    for(int i=0;i<n;i++){
            cin>>arr[i];
            dp[i][i]=arr[i];
    }
   

}

void solution(){
    for(int s=0;s<n;s++){
        for(int e=0;e<n;e++){
            if(e>s){
                dp[s][e]=arr[e]+dp[s][e-1];
                if(dp[s][e]>max_result){
                     max_result=dp[s][e];        
                }
            }
        }    
    }
    printf("result is %d",max_result);
}

int main() {
    input();
    solution();
    }


