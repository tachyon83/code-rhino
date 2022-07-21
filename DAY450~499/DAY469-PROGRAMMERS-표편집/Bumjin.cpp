#include <string>
#include <vector>
#include <stack>
using namespace std;

int cur;
stack<int> st;

// 연결 리스트 node
struct Node {
    int num;
    Node* prev;
    Node* next;
    Node(int num):num(num),prev(NULL),next(NULL){};
};

vector<Node*> v;

void solve(vector<string>& cmd){
    for(string s:cmd){
        if(s[0]=='D' || s[0]=='U'){
            int x = stoi(s.substr(2));
            if(s[0]=='D') while(x--) cur = v[cur]->next->num;
            else while(x--) cur = v[cur]->prev->num;
        }
        else if(s[0]=='C'){
            st.push(cur);
            if(v[cur]->prev != NULL)
                v[cur]->prev->next = v[cur]->next;
            if(v[cur]->next != NULL){
                v[cur]->next->prev = v[cur]->prev;
                cur = v[cur]->next->num;
            }
            else cur = v[cur]->prev->num;
        }
        else if(s[0]=='Z'){
            int r = st.top(); st.pop();
            if(v[r]->prev != NULL)
                v[r]->prev->next = v[r];
            if(v[r]->next != NULL)
            v[r]->next->prev = v[r];
        }
        else return; //oops
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    
    // 연결리스트 생성 및 연결
    v = vector<Node*>(n);
    
    for(int i=0;i<n;i++)
        v[i] = new Node(i);
    
    v[0]->next = v[1];
    v[n-1]->prev = v[n-2];
    
    for(int i=1;i<n-1;i++){
        v[i]->next = v[i+1];
        v[i]->prev = v[i-1];
    }
    
    // cmd 수행
    cur = k;
    solve(cmd);
    
    // 삭제 여부 체크
    int leftCheck, rightCheck;
    leftCheck = rightCheck = cur;
    
    answer[cur] = 'O';
    
    // 현재 커서 기준 왼쪽 체크
    while(v[leftCheck]->prev != NULL){
        leftCheck = v[leftCheck]->prev->num;
        answer[leftCheck] = 'O';
    }
    
    // 현재 커서 기준 오른쪽 체크
    while(v[rightCheck]->next != NULL){
        rightCheck = v[rightCheck]->next->num;
        answer[rightCheck] = 'O';
    }

    return answer;
}
