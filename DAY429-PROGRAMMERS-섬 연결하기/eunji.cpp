#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> parent;

bool cmp(vector<int> a, vector<int> b)
{
    return (a[2] < b[2]);
}
int find(int p)
{
    if (p == parent[p])
        return p;
    parent[p] = find(parent[p]);
    return parent[p];
}
bool isCycle(vector<int> cost)
{
    int start = cost[0];
    int end = cost[1];
    int startP = find(parent[start]);
    int endP = find(parent[end]);
    if (startP != endP)
    {
        parent[endP] = startP;
        return false;
    }
    return true;
}
int solution(int n, vector<vector<int>> costs)
{
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
    }
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0; i < costs.size(); i++)
    {
        if (!isCycle(costs[i]))
        {
            answer += costs[i][2];
        }
    }
    return answer;
}
