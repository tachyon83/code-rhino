#include <iostream>
#include <vector>

using namespace std;

vector<int> vc[300001];
long result[2];
int visited[300001];
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmpA, tmpB;
        cin >> tmpA >> tmpB;
        vc[tmpA].push_back(tmpB);
        vc[tmpB].push_back(tmpA);
    }

    for(int i = 1; i <= N; i++){
      long long int tmp = vc[i].size();

      result[0] += tmp * (tmp - 1) * (tmp - 2) / 6;

      for(int j = 0; j < tmp; j++){
        int tmp2 = vc[i][j];
        result[1] += (tmp - 1) * (vc[tmp2].size() - 1);
      }
    }

    if(result[0] * 3 < result[1]){
      cout << "D\n";
    }else if(result[0] * 3 > result[1]){
      cout << "G\n";
    }else{
      cout << "DUDUDUNGA\n";
    }

    return 0;
}
