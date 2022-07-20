#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for(int i=0;i<s.size();i++){
        if(i==0&&islower(s[i])){
            s[i]=toupper(s[i]);
        }
       // if(s[i]==' ')printf("it is null\n");
        if(i!=0&&isupper(s[i])){
            s[i]=tolower(s[i]);
        }
        
        if(i>0 && s[i-1]==' '&& islower(s[i])){
            s[i]=toupper(s[i]);
        }
       
           
      printf("%c",s[i]);    
    }
    string answer = s;
    return answer;
}
