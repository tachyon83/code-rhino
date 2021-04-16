#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
  sort(people.begin(), people.end());
  int sum = 0;
    for (int i = people.size()-1, j=0; j<=i; i--,sum++) {
        if (people[i] + people[j] <= limit) j++;
    }
    return sum;
}
