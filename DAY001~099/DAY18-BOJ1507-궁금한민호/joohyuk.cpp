#include <iostream>
#define endl '\n'
using namespace std;
const int sz=20;
struct info{
    int value;
    bool tf;
};
int n;
info routes[sz][sz];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>routes[i][j].value;
        }
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(i!=j && j!=k && k!=i){
                    int temp=routes[i][k].value+routes[k][j].value;
                    if(temp==routes[i][j].value){
                        routes[i][j].tf=1;
                    }else if(temp<routes[i][j].value){
                        cout<<-1<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            if(!routes[i][j].tf)
                res+=routes[i][j].value;
        }
    }
    cout<<res<<endl;
    return 0;
}
