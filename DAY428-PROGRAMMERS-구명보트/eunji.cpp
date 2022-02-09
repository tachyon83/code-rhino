#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit)
{
    int groupNum = 0;
    int small = 0;
    int big = people.size() - 1;
    sort(people.begin(), people.end());

    while (small <= big)
    {
        if (people[small] + people[big] <= limit)
            small++;
        groupNum++;
        big--;
    }
    return groupNum;
}
