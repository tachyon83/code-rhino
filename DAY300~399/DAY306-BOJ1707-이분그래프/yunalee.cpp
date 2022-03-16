#include <iostream>
#include <vector>

using namespace std;

vector<int> vc[20000];
int colors[20000];
bool flag ;

/*
 * -1 : red
 * 0 : 없음
 * 1 : blue 
 */
void solution(int start, int color){
    colors[start] = color;  // 시작색 결정

    // 시작 노드에 연결된 노드의 수만큼 반복
    for(int i = 0; i < vc[start].size(); i++){

        // 시작노드의 인접한 노드와의 색이 같은 경우, 이분그래프가 아닌 경우 이다
        if(colors[vc[start][i]] == color){
            flag = false;
            return;
        }

        // 인접한 노드가 아직 방문하지 않은 노드인 경우
        // 인접노드 색을 시작노드와 다른 색으로 결정
        if(colors[vc[start][i]] == 0){
            solution(vc[start][i], -color);
        }
    }
}

void init(int v){
    for(int i = 0; i <= v; i++){
        vc[i].clear();
        colors[i] = 0;
    }
}

int  main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while(tc--){
        int V, E;
        cin >> V >> E;

        for(int i = 0; i < V + 1; i++){
            colors[i] = 0;   // 방문하지 않은 노드에 대해서는 0으로 초기화
        }

        // 그래프 정보 입력
        for(int i = 0; i < E; i++){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;

            vc[tmp1].push_back(tmp2);
            vc[tmp2].push_back(tmp1);
        }

        flag = true;
        for(int i = 1; i < V + 1; i++){
            // 이분그래프가 아닌경우
            if(!flag){
                break;
            }

            // 방문하지 않은 노드에 대해 탐색
            if(colors[i] == 0){
                solution(i, -1);
            }
        }

        if(flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

        // 초기화
        init(V);
    }

    return 0;
}
