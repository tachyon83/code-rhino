#include <stack>
#include <string>
#include <iostream>
#define endl '\n'
using namespace std;
const int sz=1e6+1;
char s[sz];
string ex;
stack<char>st,hold;
bool flag;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>s>>ex;
    int i=0,exEnd=(int)ex.size()-1;
    int j=exEnd;
    while(s[i]){
        st.push(s[i]);
        if(s[i]==ex[exEnd]){
            while(!st.empty() && st.top()==ex[j]){
                hold.push(st.top());st.pop();
                j--;
                if(j<0){
                    flag=1;
                    break;
                }
            }
            if(flag)while(!hold.empty())hold.pop();
            else while(!hold.empty()){st.push(hold.top());hold.pop();}
            j=exEnd;
            flag=0;
        }
        i++;
    }
    if(st.empty()){
        cout<<"FRULA";
        return 0;
    }
    while(!st.empty()){hold.push(st.top());st.pop();}
    while(!hold.empty()){cout<<hold.top();hold.pop();}
    return 0;
}
