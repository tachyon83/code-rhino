#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct Meeting
{
    int time[2];
};

int cmp(const void *p1, const void *p2)
{
    Meeting *a = (Meeting *)p1;
    Meeting *b = (Meeting *)p2;
    int diff = a->time[1] - b->time[1];
    if (diff)
        return diff;
    return a->time[0] - b->time[0];
}

int n, temp0, temp1;
Meeting givenTime[100000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)cin>>givenTime[i].time[0]>>givenTime[i].time[1];
    qsort(givenTime, n, sizeof(Meeting), cmp);
    int prevMtEnd = 0;
    int count = 0;
    int i = 0;

    while (i < n)
    {
        if (givenTime[i].time[0] >= prevMtEnd)
        {
            count++;
            prevMtEnd = givenTime[i].time[1];
        }
        i++;
    }
    cout << count << endl;
}
