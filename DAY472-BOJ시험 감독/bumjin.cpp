#include <iostream>
// 여유 있게 1을 붙여서 최대 숫자를 정의합니다.
#define max_int 1000001

/*
    정수 범위를 넘어가기 때문에 long long 을 사용합니다.
    int의 최대값은 2147483647 (20억)
    리듬감있게 외우면 외워집니다. 이일 사칠 사팔 삼육사칠~
 */

// long long을 편하게 쓰기 위해서 lld로 정의
#define lld long long

using namespace  std;

/*
    시간 복잡도: O(n)
    공간 복잡도: O(n)
    사용한 자료구조: 배열
    사용한 알고리즘: 반복문
 */

int n, a[max_int], b, c;
// 전체 감독관의 수는 정수 범위를 초과할 수 있기 때문에 long long으로 선언합니다.
lld result;

int main(){
    // 1. 입력
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d %d", &b, &c);

    // 2. 계산
    for(int i=1; i<=n; i++){
        // 1) 총 감독관의 수
        // 총 감독관은 한반에 한명씩 꼭 들어갑니다.
        a[i] = a[i] - b;
        result++;

        // 2) 부 감독관의 수
        // 남은 응시생이 있어야 부 감독관이 들어갑니다.
        if(a[i] > 0) {
            // 나눗셈을 통해 부 감독관의 수를 계산합니다.
            result += a[i] / c;

            // 나머지가 있으면 부 감독관을 한명더 늘려줍니다.
            if(a[i] % c > 0) result++;
        }
    }

    // 3. 출력
    printf("%lld\n", result);
}
