#include <iostream>
#include <string>
using namespace std;

int n;
string ans;
char sDet(string *s, int n);
void sDiv(string *s, int n);
void DnC(string *s, int n);

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        char sAns;
        cin >> sAns;
        cout << sAns << '\n';
        return 0;
    }
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    char temp = sDet(s, n);
    if (temp == '-')
        DnC(s, n);
    else
        ans += temp;
    cout << ans << '\n';
    return 0;
}

char sDet(string *s, int n)
{
    char t = s[0].at(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i].at(j) != t)
                return '-';
        }
    }
    return t;
}
void sDiv(string *s, int n)
{
    n /= 2;
    string s1[n];
    string s2[n];
    string s3[n];
    string s4[n];
    for (int i = 0; i < n; i++)
    {
        s1[i] = s[i].substr(0, n);
        s2[i] = s[i].substr(n, n);
        s3[i] = s[n + i].substr(0, n);
        s4[i] = s[n + i].substr(n, n);
    }
    char d = '-';
    char s1ans = sDet(s1, n);
    char s2ans = sDet(s2, n);
    char s3ans = sDet(s3, n);
    char s4ans = sDet(s4, n);
    if (s1ans == d)
        DnC(s1, n);
    else
        ans += s1ans;
    if (s2ans == d)
        DnC(s2, n);
    else
        ans += s2ans;
    if (s3ans == d)
        DnC(s3, n);
    else
        ans += s3ans;
    if (s4ans == d)
        DnC(s4, n);
    else
        ans += s4ans;
}
void DnC(string *s, int n)
{
    ans += "(";
    sDiv(s, n);
    ans += ")";
}
