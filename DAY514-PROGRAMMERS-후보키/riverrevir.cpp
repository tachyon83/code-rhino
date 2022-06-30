#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int Answer, Attribute_Size;
vector<bool> Select;
vector<int> V;
vector<vector<int>> Candidate;
vector<vector<string>> Relation;
 
void Make_Attribute()
{
    Select.resize(Relation[0].size(), false);
    Attribute_Size = Relation[0].size();
}
 
bool Check_Uniqueness()
{
    vector<string> Temp;
    for (int i = 0; i < Relation.size(); i++)
    {
        string Result = "";
        for (int k = 0; k < V.size(); k++)
        {
            int Idx = V[k];
            Result += Relation[i][Idx];
        }
 
        if (find(Temp.begin(), Temp.end(), Result) != Temp.end()) return false;
        else Temp.push_back(Result);
    }
 
    return true;
}
 
bool Check_Minimality()
{
    if (V.size() == 1) return true;
 
    // V에는 후보키로 사용할 Attribute들의 조합이 들어있다.
    // "12"가 후보키일떄, "012"가 삽입되면 ?
    // "12"가 후보키일떄, "134"가 삽입되면 ?
    // "01"이 후보키일때, "134"가 삽입되면 ?
    for (int i = 0; i < Candidate.size(); i++)
    {
        bool Flag = false;
        for (int j = 0; j < Candidate[i].size(); j++)
        {
            int Key = Candidate[i][j];
            if (find(V.begin(), V.end(), Key) == V.end())
            {
                Flag = true;
                break;
            }
        }
        if (Flag == false) return false;
    }
    return true;
}
 
bool Check()
{
    if (Check_Uniqueness() == true && Check_Minimality() == true)
    {
        Candidate.push_back(V);
        return true;
    }
    return false;
}
 
void DFS(int Idx, int Cnt, int Total_Cnt)
{
    if (Cnt == Total_Cnt)
    {
        if (Check() == true) Answer++;
        return;
    }
 
    for (int i = Idx; i < Attribute_Size; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        V.push_back(i);
        DFS(i, Cnt + 1, Total_Cnt);
        V.pop_back();
        Select[i] = false;
    }
}
 
void Make_Combination()
{
    for (int i = 1; i <= Relation[0].size(); i++)
    {
        DFS(0, 0, i);
    }
}
 
int solution(vector<vector<string>> relation)
{
    Relation = relation;
    Make_Attribute();
    Make_Combination();
    return Answer;
}
