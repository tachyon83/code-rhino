function solution(n)
{
    let ans = 0;
    while(n > 0) { 
        if(n % 2 === 0) { // 순간이동 할수 있다면 순간이동
           n /= 2;
        }
        else { // 불가능하다면 1만큼 점프
            n -= 1;
            ans++;
        }
    }

    return ans;
}
