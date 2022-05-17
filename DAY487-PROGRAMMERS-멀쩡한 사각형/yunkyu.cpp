using namespace std;

int calcGcd(int a, int b) {
    if(b == 0) return a;
    else return calcGcd(b, a % b);
}

long long solution(int w,int h) {
    long long answer = w * h;
    int gcd = calcGcd(w, h); // 최대 공약수
    // 최대공약수 개수만큼 동일한 패턴, 각 패턴별 사각형 개수 더함
    // 잘린 종이의 사각형 = (가로 / 최대공약수 + 세로 / 최대공약수 - 1) * 최대공약수
    long long cutted = gcd * (w / gcd + h / gcd - 1); 
    return answer - cutted;
}
