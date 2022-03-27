#include <bits/stdc++.h>
using namespace std;
 
void findMajority(int arr[], int size)
{
    unordered_map<int, int> m;
    for(int i = 0; i < size; i++)
        m[arr[i]]++;
    for(auto i : m)
    {
        if(i.second > size / 2)
        {
            cout << "Majority found : " << i.first<<endl;
            break;
        }
    }
}
 
int main() 
{ 
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    findMajority(arr, n); 
    return 0; 
} 
