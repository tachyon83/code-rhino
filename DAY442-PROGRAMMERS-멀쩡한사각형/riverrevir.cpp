using namespace std;
int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);
}
long long solution(int w,int h) {
    long long answer=1;
    answer=((long long)w*h)-(w+h)+GCD(w,h);
    return answer;
}

