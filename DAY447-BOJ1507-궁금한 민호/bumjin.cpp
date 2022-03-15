#include <stdio.h>

int arr[]={1,2,3};
bool visited[4]={0,};
int result=0;
int max=0;
void permutation(int cnt){
    if(cnt==3){
        return ;
    }

    for(int i=0;i<3;i++){
        if(visited[i]==false){
            visited[i]=true;
            cnt++;
            result=result+arr[i];
            permutation(cnt);
            if(result>max){
                max=result;
            }
            result=result-arr[i];
            cnt--;
            visited[i]=false;
        }
    }

}


int main(){
    permutation(0);
    printf("max is %d",max);
}
