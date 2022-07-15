#include <string>
#include <vector>
#include <map>
using namespace std;
int arr[500500];

void Outside(int original_size,int triangle_size,int start,int start_value,int depth){
    if(triangle_size<=0){
        return;
    }
    arr[start]=start_value;
  //  printf("depth %d\n",depth);
    //printf("i:%d %d\n",start_value,arr[start]);
    for(int i=start+1;i<start+1+triangle_size-1;i++){
        arr[i]=arr[i-1]+(1+2*(depth-1))+i-(start+1);
       // printf("i:%d %d ",i+1,arr[i]);
    }
 //   printf("\n");
    for(int i=start+1+triangle_size-1;i<start+1+2*(triangle_size-1);i++){
        arr[i]=arr[i-1]+1;
        //printf("i:%d %d ",i+1,arr[i]);
    }
   // printf("\n");
    for(int i=start+1+2*(triangle_size-1);i<start+3*(triangle_size-1);i++){
        arr[i]=arr[i-1]-((original_size-depth+1)-(i-(start+1+2*(triangle_size-1))));
       // printf("i:%d %d ",i+1,arr[i]);
    }
    //printf("\n");
    Outside(original_size,triangle_size-3,start+3*(triangle_size-1),arr[start]+4*(depth),depth+1);
}
vector<int> solution(int n){ 
    vector<int> answer;
    map<int,int> m;
    arr[500500]={0,};
    //n=9;
    Outside(n,n,0,1,1);
    
    for(int i=0;i<500500;i++){
        if(arr[i]==0){
           break ;
        }
      //  printf("i:%d %d ",i+1,arr[i]);
        m.insert({arr[i],i+1});
    }
    for(int i=0;i<m.size();i++){
        if(m[i]==0)continue;
        answer.push_back(m[i]);
     //  printf("%d ",m[i]);
    }
    return answer;
}



/*
삼각형 9->1(1+2*(depth-1)),2,3,4순으로 증가 ->오른쪽으로 가면서 1씩 증가->9(9-depth+1) 8 7 6 5 순으로 감소 depth=1
삼각형 6->3(1+2*(depth-1)),4,5,6 순으로 증가->오른쪽으로 가면서 1씩 증가->8(9-depth+1) 7 6 5 순으로 감소 depth=2
삼각형 3->5(1+2*(depth-1)),6,7,8 순으로 증가->오른쪽으로 가면서 1씩 증가->7(n_real-depth+1) 6 5 순으로 감소 depth=3

                          1(1)
             2(2)                   24(3)
          3(4)            25(5)            23(6)
        4(7)      26(8)            39(9)          22(10)   
      5(11)       27(12)   40(13)          38(14)           21(15)   
   6(16)     28(17)   41(18)      45(19)        37(20)             20(21)
  7(22)  29(23)    42(24)    43(25)        44(26)        36(27)         19(28)
 8(29) 30(30) 31(31)      32(32)    33(33)         34(34)         35(35)     18(36)  
9(37) 10(38)11(39) 12(40)       13(41)      14(42)        15(43)        16(44)     17(45)

*/
