function solution(w, h) {
    let answer = w * h;
    const getGcd = (a,b) => { // a와 b의 최대공약수를 구한다
        if(b === 0) return a;
        else return getGcd(b,a % b);
    }
    const gcd = getGcd(w,h); // 최대공약수
    // 최대 공약수의 개수만큼 대각선으로 잘리는 사각형의 동일한 패턴이 생긴다.
    // 또한 각 패턴에 가로 세로는 각각 w, h 에 최대공약수(패턴의 수) 만큼 나눈 값이고
    // 잘리는 사각형은 즉, 패턴의 가로 세로를 더한것에 1을 뺀 값과 같다. 1을 빼는 이유는(가로와 세로가 시작할때 중복되기 때문)
    const cutted = gcd * (w / gcd + h / gcd - 1); 
    
    return answer - cutted;
}
