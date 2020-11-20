class Solution {
private:
    vector<vector<int> > dp;
    int sLen, pLen;
    string S, P;
public:
    bool isMatch(string s, string p) {
        S = s, P = p;
        sLen = s.length(), pLen = p.length();

        dp.resize(sLen + 1);
        for (int i = 0; i <= sLen; i++)
            dp[i].resize(pLen + 1, -1);

        return compare(0, 0);
    }

    bool compare(int si, int pi)
    {
        if (si > sLen)
            return false;

        bool ret = dp[si][pi];
        if (dp[si][pi] != -1)
            return ret;

        if (pi == pLen)
            return (si == sLen);

        bool match = (si < sLen && (P[pi] == S[si] || P[pi] == '.'));

        if (pi + 1 < pLen && P[pi + 1] == '*')
            return ret = compare(si, pi + 2) || (match && compare(si + 1, pi));

        return ret = compare(si + 1, pi + 1) && match;
    }
};