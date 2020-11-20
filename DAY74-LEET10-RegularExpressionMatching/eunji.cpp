class Solution {
//수정중
public:
    bool isMatch(string s, string p) {
        //같을때는 break해서 넘김
        //다를때는...
            //'*'일때
                //그전문자가 '.'일때
                //그전문자가 문자일때
                    //그다음문자가 그전문자와 같을때
                    //그다음문자가 그전문자와 다를때
            //'.'일때
            //문자일때
                //다음문자가'*'일때
	int i = 0, j = 0;
	while(1) {
		if (i >= s.size() || j>=p.size()) return false;
		if (s[i] != p[j]) {
			if (p[j] != '.') {
				if (p[j] == '*') {
					if (s[i++] != p[j - 1] && p[j - 1] != '.') return false;
				}
				else {
					if (p[++j] != '*') {
						return false;
					}
				}
			}
			else {
				i++;
			}
		}else{
			i++;
		}
		j++;
	}
	return true;
    }
};
