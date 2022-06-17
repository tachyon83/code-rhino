#include <string>
#include <cmath>
#include <vector>
using namespace std;
 
int solution(string dartResult) {
    int answer = 0;
    int index=0;
    vector<int> score;
    int n=dartResult.size();
    for(int i=0;i<n;i++){
        if(dartResult[i]=='S'){}
        else if(dartResult[i]=='D'){
            score[index-1]=pow(score[index-1],2);
        }
        else if(dartResult[i]=='T'){
            score[index-1]=pow(score[index-1],3);
        }
        else if(dartResult[i]=='*'){
            score[index-1]*=2;
            if(index>1){
                score[index-2]*=2;
            }
        }
        else if(dartResult[i]=='#'){
            score[index-1]*=(-1);
        }
        else{
            if(dartResult[i+1]=='0'){
                score.push_back(10);
                i++;
            }
            else{
                score.push_back(dartResult[i]-'0');
            }
            index++;
        }
    }
    for(int i=0;i<score.size();i++){
        answer+=score[i];
    }
    return answer;
}
