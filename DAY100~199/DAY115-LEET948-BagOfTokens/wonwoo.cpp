class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int size = tokens.size();
        int end = size - 1;
        int ans = 0;
        int point = 0;

        sort(tokens.begin(), tokens.end());
        for (int i = 0; i < min(size, end + 1); i++) {
            if (tokens[i] > P && 0 < point) {
                point--;
                P += tokens[end--];
            }
            if (tokens[i] > P) {
                break;
            }

            point++;
            P -= tokens[i];
            ans = max(ans, point);
        }
        return ans;
    }
};