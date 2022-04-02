#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
 
long long Answer;
bool Select[3];
vector<char> Operator, Priority;
vector<long long> Number;
map<int, char> Oper_Type;
 
long long Max(long long A, long long B) { return A > B ? A : B; }
 
void Setting(string Str)
{
    Oper_Type[0] = '*';
    Oper_Type[1] = '+';
    Oper_Type[2] = '-';
 
    string Num = "";
    for (int i = 0; i < Str.length(); i++)
    {
        if (isdigit(Str[i]) == 0)
        {
            Number.push_back(stoll(Num));
            Operator.push_back(Str[i]);
            Num = "";
        }
        else Num += Str[i];
    }
    Number.push_back(stoll(Num));
}
 
long long Calculate(long long N1, long long N2, char Op)
{
    if (Op == '*') return N1 * N2;
    if (Op == '+') return N1 + N2;
    if (Op == '-') return N1 - N2;
}
 
long long Find_Result()
{
    vector<char> Temp_Operator = Operator;
    vector<long long> Temp_Number = Number;
    for (int i = 0; i < 3; i++)
    {
        char C = Priority[i];
        for (int j = 0; j < Temp_Operator.size(); j++)
        {
            if (Temp_Operator[j] == C)
            {
                long long Result = Calculate(Temp_Number[j], Temp_Number[j + 1], C);
                Temp_Number[j] = Result;
                Temp_Number.erase(Temp_Number.begin() + j + 1);
                Temp_Operator.erase(Temp_Operator.begin() + j);
                j--;
            }
        }
    }
    return abs(Temp_Number[0]);
}
 
void DFS(int Cnt)
{
    if (Cnt == 3)
    {
        long long Result = Find_Result();
        Answer = Max(Answer, Result);
        return;
    }
 
    for (int i = 0; i < 3; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        Priority.push_back(Oper_Type[i]);
        DFS(Cnt + 1);
        Priority.pop_back();
        Select[i] = false;
    }
}
 
long long solution(string expression)
{
    Setting(expression);
    DFS(0);
    return Answer;
}
