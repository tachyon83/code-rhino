#define ll long long
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
ll solution(int w,int h) {
    long long p=(ll)w*(ll)h;
    return p-(w+h-gcd(w,h));
}
