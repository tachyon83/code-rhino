#include <iostream>
#define endl '\n'
using namespace std;
const int sz=20+1;
bool flag,slopecheck;
int curr,cases,prv,cnt,t,n,x,land[sz][sz];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
    cin>>t;
    for(int test_case = 1; test_case <= t; ++test_case){
        cin>>n>>x;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>land[i][j];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                curr=land[i][j];
                if(!slopecheck){
                    if(!prv){
                        prv=land[i][j];
                        cnt=1;
                    }else if(prv==land[i][j])cnt++;
                    // different height
                    else{
                        // left or right
 
                        // left
                        if(prv+1==land[i][j]){
                            if(cnt>=x){
                                prv=land[i][j];
                                cnt=1;
                            }else{
                                flag=1;
                                break;
                            }
                        // right
                        }else if(prv==land[i][j]+1){
                            slopecheck=1;
                            prv=land[i][j];
                            cnt=1;
                        }else{
                            flag=1;
                            break;
                        }
                    }
                // slopecheck=1
                }else{
                    if(cnt>=x){
                        if(j<n && prv<land[i][j]){
                            flag=1;
                            break;
                        }else if(j<n && prv>land[i][j]){
                            if(prv>land[i][j]+1){
                                flag=1;
                                break;
                            }
                            prv=land[i][j];
                            cnt=1;
                        }else{
                            slopecheck=0;
                            prv=land[i][j];
                            cnt=1;
                        }
                    }else{
                        if(prv!=land[i][j]){
                            flag=1;
                            break;
                        }
                        cnt++;
                    }
                }
            }
            if(slopecheck && cnt<x)flag=1;
            if(!flag)cases++;
            flag=0;cnt=0;prv=0;slopecheck=0;
        }
 
        for(int j=0;j<n;++j){
            for(int i=0;i<n;++i){
                curr=land[i][j];
                if(!slopecheck){
                    if(!prv){
                        prv=land[i][j];
                        cnt=1;
                    }else if(prv==land[i][j])cnt++;
                    // different height
                    else{
                        // left or right
 
                        // left
                        if(prv+1==land[i][j]){
                            if(cnt>=x){
                                prv=land[i][j];
                                cnt=1;
                            }else{
                                flag=1;
                                break;
                            }
                        // right
                        }else if(prv==land[i][j]+1){
                            slopecheck=1;
                            prv=land[i][j];
                            cnt=1;
                        }else{
                            flag=1;
                            break;
                        }
                    }
                // slopecheck=1
                }else{
                    if(cnt>=x){
                        if(i<n && prv<land[i][j]){
                            flag=1;
                            break;
                        }else if(i<n && prv>land[i][j]){
                            if(prv>land[i][j]+1){
                                flag=1;
                                break;
                            }
                            prv=land[i][j];
                            cnt=1;
                        }else{
                            slopecheck=0;
                            prv=land[i][j];
                            cnt=1;
                        }
                    }else{
                        if(prv!=land[i][j]){
                            flag=1;
                            break;
                        }
                        cnt++;
                    }
                }
            }
            if(slopecheck && cnt<x)flag=1;
            if(!flag)cases++;
            flag=0;cnt=0;prv=0;slopecheck=0;
        }
        cout<<'#'<<test_case<<' '<<cases<<endl;
        cases=0;
    }
    return 0;
}
