#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    
    int num;
    int time[1000]={0};
    int total = 0;
    
    scanf("%d",&num);
    for(int i=0; i<num; i++){
        scanf("%d",&time[i]);
    }
    
    sort(time,time+num); // 작은 시간이 걸리는 순으로 정렬
    
    for(int i=0; i<num; i++){
        for(int j=i; j>=0; j--){
            total += time[j]; // 누적합 구함
        }
    }
    
    printf("%d",total);
    
    return 0;
}
