#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    getline(cin, S);

    bool chk = false;
    vector<char> vc;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == '<'){    //태그 시작부분
            if(vc.size() > 0){  //태그 이전에 입력된 문자열이 있으면 역순 출력 후 초기화
                for(int j = vc.size() - 1; j >= 0; j--){
                    cout << vc[j];
                }
                vc.clear();
            }
            chk = true;
        }

        if(chk){    //종료태그를 만날때까지 입력순으로 출력
            cout << S[i];
            if(S[i] == '>'){
                chk = false;
            }
            continue;
        }

        if(S[i] == ' '){    //스페이스 입력 인식 시, 현재까지 입력된 문자열 역순 출력
            for(int j = vc.size() - 1; j >= 0; j--){
                cout << vc[j];
            }
            vc.clear();
            cout << S[i];
            continue;
        }

        vc.push_back(S[i]); //입력된 문자열 저장
    }

    //벡터에 남아있는 문자열 역순 출력
    for(int j = vc.size() - 1; j >= 0; j--){
        cout << vc[j];
    }

    return 0;
}
