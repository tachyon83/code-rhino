#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int a[5]={1,2,3,4,5};
int b[8]={2,1,2,3,2,4,2,5};
int c[10]={3,3,1,1,2,2,4,4,5,5};
 
vector<int> solution(vector<int> answers) {
    int acnt=0,bcnt=0,ccnt=0;
    int aidx=0,bidx=0,cidx=0;
    for(int i=0;i<answers.size();i++){
        if(aidx>=5) aidx=0;
        if(answers[i]==a[aidx]) acnt++;
        aidx++;     
        
        if(bidx>=8) bidx=0;
        if(answers[i]==b[bidx]) bcnt++;
        bidx++;
        
        if(cidx>=10) cidx=0;
        if(answers[i]==c[cidx]) ccnt++;
        cidx++;
    }
    vector<int> ans;
    int maxResult=max({acnt,bcnt,ccnt});
    if(maxResult==acnt) ans.push_back(1);
    if(maxResult==bcnt) ans.push_back(2);
    if(maxResult==ccnt) ans.push_back(3);
     
    return ans;
}
