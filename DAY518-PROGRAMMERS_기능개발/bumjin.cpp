#include <string>
#include <vector>
#include <queue> 


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    int max_day=((100-progresses[0])-1)/speeds[0]+1;
    int count=0; 
    int param=0;
    queue<int> q;
    vector<int> answer;
    int show=0;
    
    for(int i=0;i<progresses.size();i++){
        param=((100-progresses[i])-1)/speeds[i]+1;
        q.push(param);
    }
    
    
 show=q.size();
 printf("q.size()is %d",show);
    
   while(!q.empty())
   {
       printf("q is %d\n",q.front());
      if(q.front()<=max_day){
          count++;
          printf("q popped %d\n",q.front());
          q.pop();
      }
       else{
           printf("count is %d\n",count);
           answer.push_back(count);
           count=0;
           max_day=q.front();
           printf("max_day is %d\n",max_day);
       }
   
        
  }
    answer.push_back(count);

    return answer;

}
