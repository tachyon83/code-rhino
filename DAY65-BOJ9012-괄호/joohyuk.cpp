#include <iostream>
#define endl '\n'
using namespace std;
const int cSize=52;

class CharStack
{
private:
    int pos,cap;
    char* arr;

    void init()
    {
        pos=0;
        cap=cSize;
        arr=new char[cSize];
    }
public:
    CharStack(){ init();}
    void terminate() { delete[] arr; }
    void clear()
    {
        terminate();
        init();
    }
    int empty() { return (pos==0); }
    void pop() { pos--; }
    bool push(char c)
    {
        if (c==')' && empty()) return 1;
        else if (c==')') pop();
        else if (c=='(') arr[pos++]=c;
        return 0;
    }  
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,flag;
    char* arr;
    CharStack s;
    cin>>n;
    while(n--)
    {
        arr=new char[cSize];
        cin>>arr;
        flag=0;i=0;
        while(1)
        {
            flag=s.push(arr[i++]);
            if (flag) break;
        }
        if (flag || !s.empty()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        s.clear();
    }
    s.terminate();
    return 0;
}
