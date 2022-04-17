#include <string>
#include <vector>
 
using namespace std;
 
long long Binary_Search(long long Mid, vector<int> T)
{
    long long Result = 0;
    for (int i = 0; i < T.size(); i++)
    {
        Result = Result + (Mid / T[i]);
    }
    return Result;
}
 
long long solution(int n, vector<int> times) 
{
    long long Start = 1;
    long long End = 0;
    long long Temp = 0;
    for (int i = 0; i < times.size(); i++)
    {
        if (Temp < times[i]) Temp = times[i];
    }
    End = Temp * n;
    while(Start <= End)    
    { 
        long long Mid = (Start + End) / 2;
        if (Binary_Search(Mid, times) < n) Start = Mid + 1;
        else End = Mid - 1;
        
    }
    return Start;
}
