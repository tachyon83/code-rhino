#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
   
    for(int i=0; i<s.size(); i++){
        if((isalpha(s[i]) && s[i-1] == ' ')  || (isalpha(s[i]) && i==0)){
            s[i]=(toupper(s[i]));
        }else{
          s[i] = tolower(s[i]);  
        }
        
    }
    
    return s;
}
