class Solution {
    static int[][] map;
    static int n,m;

    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = true;
        m = key.length;
        n = lock.length;
        map = new int[2 * m + n - 2][2 * m + n - 2];
        rollback(lock);

        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < m+n-1; i++) {
                for (int j = 0; j < m+n-1; j++) {
                    setKey(key, i, j);
                    if(check())
                        return true;
                    else
                        rollback(lock);
                }
            }
            key = rotate(key);
        }

        return false;
    }

    static void setKey(int[][] key, int x, int y) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                map[x + i][y + j] += key[i][j];
            }
        }
    }
    static void rollback(int[][] lock) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i + m - 1][j + m - 1] = lock[i][j];
            }
        }
    }

    static int[][] rotate(int[][] key) {
        int[][] temp = new int[m][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                temp[j][m - i - 1] = key[i][j];
            }
        }
        return temp;
    }

    static boolean check() {
        for (int i = m-1; i < m+n-1; i++) {
            for (int j = m-1; j < m+n-1; j++) {
                if(map[i][j]!=1)
                    return false;
            }
        }
        return true;
    }

}
