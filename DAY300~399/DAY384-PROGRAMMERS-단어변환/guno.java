import java.util.*;

class Solution {

    class Word {
        String s;
        List<Word> child = new ArrayList<>();

        public Word(String s) {
            this.s = s;
        }
    }

    class Node {
        Word word;
        int cnt;

        public Node(Word word, int cnt) {
            this.word = word;
            this.cnt = cnt;
        }
    }

    public int solution(String begin, String target, String[] words) {
        int ans = 0;
        Word root = new Word(begin);
        List<Word> list = new ArrayList<>();
        Map<Word, Boolean> map = new HashMap<>();

        list.add(root);
        map.put(root, false);

        Arrays.stream(words).forEach(s -> {
            Word word = new Word(s);
            list.add(word);
            map.put(word, false);
        });

        for (int i = 0; i < list.size(); i++) {
            Word w1 = list.get(i);
            for (int j = 0; j < list.size(); j++) {
                if (i == j) {
                    continue;
                }
                Word w2 = list.get(j);
                if (check(w1.s,w2.s)) {
                    w2.child.add(w1);
                }
            }
        }
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(root, 0));
        while (!q.isEmpty()) {
            Node poll = q.poll();
            Word word = poll.word;
            int cnt = poll.cnt;
            map.put(word, true);
            if (word.s.equals(target)) {
                ans = cnt;
                break;
            }
            for (Word c : word.child) {
                if (!map.get(c))
                    q.add(new Node(c, cnt + 1));
            }
        }

        return ans;
    }


    boolean check(String a, String b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                cnt++;
            }
        }
        if (cnt == 1)
            return true;
        else
            return false;
    }

}
