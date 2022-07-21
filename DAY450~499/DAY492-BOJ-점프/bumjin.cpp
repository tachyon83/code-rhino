#include<iostream> typedef long long ll;
#define endl "\n"
#define MAX 100
using namespace std; 
int N;
int MAP[MAX][MAX];
ll DP[MAX][MAX];
void Input(){
  cin >> N;   
  for (int i = 0; i < N; i++){        
    for (int j = 0; j < N; j++){           
      cin >> MAP[i][j];       
      }    
      }   
      DP[0][0] = 1;}
  void Solution(){ 
    for (int i = 0; i < N; i++){       
      for (int j = 0; j < N; j++){           
        if (DP[i][j] == 0 || (i == N - 1 && j == N - 1)) continue; 
        int Value = MAP[i][j];         
        int Down = Value + i;        
        int Right = Value + j;            
        if (Down < N) DP[Down][j] = DP[Down][j] + DP[i][j]; 
        if (Right < N) DP[i][Right] = DP[i][Right] + DP[i][j];  
        } 
        }  
        cout << DP[N - 1][N - 1] << endl;} 
        void Solve(){
        Input();  
        Solution();}
        int main(void){ 
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        //    freopen("Input.txt", "r", stdin);  
        Solve();    
        return 0;
        }
