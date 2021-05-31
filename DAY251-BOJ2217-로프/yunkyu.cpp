#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;

bool compare(int a , int b){
    return a > b;
}
int main(){
    int rope[N];
    int num;
    
    scanf("%d",&num);
    
    for(int i=0; i<num; i++){
        scanf("%d",&rope[i]);
    }
    
    sort(rope,rope+num,compare); // 큰 중량을 들수 있는 로프순으로 정렬
    
    int max=-1;
    int weight;
    
    for(int i=1; i<=num; i++){
        weight = rope[i] * i; // 강한 로프 i개를 썼을때 들수 있는 중량 구하며 갱신
        if( max < weight )
            max = weight;
    }
    
    printf("%d\n",max);
    return 0;
}
