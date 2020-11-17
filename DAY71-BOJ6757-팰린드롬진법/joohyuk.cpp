#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
int x,nums[30],sq;

bool isPalindrome(int x,int b){
    int pos=0;
    while(x){
        nums[pos++]=x%b;x/=b;        
    }
    for(int i=0;i<pos/2;++i)if(nums[i]!=nums[pos-1-i])return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>x;sq=sqrt(x);
    for(int i=2;i<=sq;++i)if(isPalindrome(x,i))cout<<i<<endl;
    if(x!=4)if(x%(sq+1)==x/(sq+1))cout<<sq+1<<endl;
    for (int i=sq-1;i>0;i--)if(!(x%i))cout<<x/i-1<<endl;
    return 0;
}
