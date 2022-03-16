/*6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(*/
/*NO
NO
YES
NO
YES
NO*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;
  cin >> n;
  cin.ignore();
  
  while(n--){
    string str;
    getline(cin, str);
    
    stack<char> st;
    bool chk = true;
    for(char ch : str){
      if(ch == '('){
        st.push(ch);
      }else if(ch == ')'){
        if(st.empty()){
          cout << "NO\n";
          chk = false;
          break;
        }
        st.pop();
      }
    }
    if(chk){
      if(!st.empty()){
        cout << "NO\n";
      }else{
        cout << "YES\n";
      }
    }
  }
}
