class Solution {
    public boolean isSubsequence(String s, String t) {
        int checked = 0;
        int tidx = 0;
        for(int i = 0; i < s.length(); i++) {
            for(int j = tidx; j < t.length(); j++) {
                if(s.charAt(i) == t.charAt(j)) {
                    checked++;
                    tidx = j + 1;
                    break;
                }
            }
        }
        
        if(checked == s.length()) {
            return true;
        }
        return false;
    }
}
