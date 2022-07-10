#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Pos {
    int r;
    int c;
};

string solution(int m, int n, vector<string> board) {
    string answer = "";
    // 인덱스는 알파벳에 대응. 알파벳 별로 위치 저장. 
    // pos_record[i][0], pos_record[i][1]  i 번쨰 알파벳인 두 글자의 위치
    vector<vector<Pos>> pos_record(26); 

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '*' || board[i][j] == '.')
                continue;
            pos_record[board[i][j] - 'A'].push_back({ i, j });
        }
    }  

    vector<char> v; // "최종 제거 순서"  
    int v_index = -1; // v 의 인덱스. 이 인덱스가 가리키는 v 의 알파벳이 이번에 제거할 알파벳이다. 이 인덱스가 가리키는 v내의 알파벳 뒤에 있는 것들에서 알파벳 정렬 순서에 맞게 새로운 알파벳이 추가 될 것이다. 
    while (true) {
        set<char> remove; // "제거 후보." while문의 반복마다 현재의 board 에서 제거 가능한 알파벳 정렬된 순서대로 차례대로 여기에 추가할 것.
        for (int k = 0; k < 26; ++k) {
            if (pos_record[k].empty()) continue; // board에 없는 알파벳이라면 넘어감
            
            bool OK = true;
            
            // 경로 0 번 꺾기 (같은 행 사이에 장애물 있는지 검사)
            if (pos_record[k][0].r == pos_record[k][1].r) { // 짝꿍인 두 알파벳끼리 같은 행이라면 두 열의 사이에 장애물(* 혹은 다른 알파벳)이 있는지 검사한다.
                // ㅡ 모양의 경로
                OK = true;
                int i = pos_record[k][0].r;
                for (int j = pos_record[k][0].c + 1; j < pos_record[k][1].c; ++j) {
                    if (board[i][j] == '*') { OK = false; break; }
                    if (board[i][j] >= 'A' && board[i][j] <= 'Z') { OK = false; break; }
                }
                if (OK) { // 장애물이 없다면 remove 에 추가
                    remove.insert(k + 'A');
                    continue;
                }
            }

            // 경로 0 번 꺾기 (같은 열 사이에 장애물 있는지 검사)
            if (pos_record[k][0].c == pos_record[k][1].c) { // 짝꿍인 두 알파벳끼리 같은 열이라면 두 행의 사이에 장애물(* 혹은 다른 알파벳)이 있는지 검사한다.
                // │ 모양의 경로
                OK = true;
                int j = pos_record[k][0].c;
                for (int i = pos_record[k][0].r + 1; i < pos_record[k][1].r; ++i) {
                    if (board[i][j] == '*') { OK = false; break; }
                    if (board[i][j] >= 'A' && board[i][j] <= 'Z') { OK = false; break; }
                }
                if (OK) { // 장애물이 없다면 remove 에 추가
                    remove.insert(k + 'A');
                    continue;
                }
            }

            // 경로 1 번 꺾기 
            if (pos_record[k][0].c < pos_record[k][1].c) {  // ㄴ, ㄱ. 
                // ㄴ 모양의 경로 (ㄴ 의 왼쪽 위가 pos_record[k][0], 오른쪽 아래가 pos_record[k][1])
                OK = true;
                // (point_r, point_c) 는 꺾이는 위치
                int point_r = pos_record[k][1].r;
                int point_c = pos_record[k][0].c;
                
                // ㄴ의 │ 
                for (int i = pos_record[k][0].r + 1; i <= point_r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                // ㄴ의 ㅡ
                for (int j = point_c; j < pos_record[k][1].c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }

                // ㄱ 모양의 경로 (ㄱ 의 왼쪽 위가 pos_record[k][0], 오른쪽 아래가 pos_record[k][1])
                OK = true;
                // (point_r, point_c) 는 꺾이는 위치
                point_r = pos_record[k][0].r;
                point_c = pos_record[k][1].c;

                // ㄱ 의 ㅡ
                for (int j = pos_record[k][0].c + 1; j <= point_c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                // ㄱ 의 │
                for (int i = point_r; i < pos_record[k][1].r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }
            }
            if (pos_record[k][0].c > pos_record[k][1].c) { // ┌ , ┘
                // ┘ 모양의 경로 ( ┘ 의 오른쪽 위가 pos_record[k][0], 왼쪽 아래가 pos_record[k][1])
                OK = true;
                // (point_r, point_c) 는 꺾이는 위치
                int point_r = pos_record[k][1].r;
                int point_c = pos_record[k][0].c;

                // ┘ 의 │
                for (int i = pos_record[k][0].r + 1; i <= point_r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                // ┘ 의 ㅡ
                for (int j = pos_record[k][1].c + 1; j <= point_c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }

                // ┌ 모양의 경로 ( ┌ 의 오른쪽 위가 pos_record[k][0], 왼쪽 아래가 pos_record[k][1])
                OK = true;
                // (point_r, point_c) 는 꺾이는 위치
                point_r = pos_record[k][0].r;
                point_c = pos_record[k][1].c;

                // ┌ 의 ㅡ
                for (int j = point_c; j < pos_record[k][0].c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                // ┌ 의 │
                for (int i = point_r; i < pos_record[k][1].r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }
            }
        }

        if (remove.empty()) break; // 현재 board 에서 하나도 제거할 수 있는게 없었다면 while문 종료

        // 현재 board 에서 제거 가능한 알파벳들을 v 에 "알파벳 순서"에 맞춰 추가 (단, v_index 가 가리키는 알파벳 뒤에 추가. v_index는 이번 턴에 제거한 알파벳의 포인터이기 때문)
        for (auto& ele : remove) {
            int i = 0;
            // 이미 v 에 있다면 추가하지 않음
            if (find(v.begin(), v.end(), ele) != v.end())
                continue;

            // 추가되야할 위치 찾기 (v_index 뒤, 정렬된 순서 유지)
            for (i = v_index + 1; i < v.size(); ++i) 
                if (ele < v[i])
                    break;
            
            if (v.empty()) v.push_back(ele); // v 가 비어있는 처음 턴에선 그냥 바로 추가
            else v.insert(v.begin() + i, ele); // 위에서 찾은 위치 i 자리에 추가
        }

        v_index++;

        // v[v_index] 알파벳 2 개 제거하기
        char next_remove_char = v[v_index];
        Pos pos_next_remove_char1{ pos_record[next_remove_char - 'A'][0].r, pos_record[next_remove_char - 'A'][0].c }; // 위치
        Pos pos_next_remove_char2{ pos_record[next_remove_char - 'A'][1].r, pos_record[next_remove_char - 'A'][1].c }; // 위치
        board[pos_next_remove_char1.r][pos_next_remove_char1.c] = '.'; // 제거
        board[pos_next_remove_char2.r][pos_next_remove_char2.c] = '.'; // 제거
        pos_record[next_remove_char - 'A'].clear(); // pos_record 에서도 두 위치 담은 벡터 지우기 
    }

    // 더 이상 제거할게 없어서 while문 종료 후 빠져나왔는데 알파벳이 아직 남아있다면 제거 불가능한 알파벳이 있다는 뜻이므로 "IMPOSSIBLE" 리턴
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                return "IMPOSSIBLE";

    // 알파벳이 모두 제거되었다면 v 에 차례로 담긴 알파벳이 답이 된다.
    for (int i = 0; i < v.size(); ++i)
        answer += v[i];

    return answer;
}
