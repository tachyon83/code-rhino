// Trie로 푸는 문제라 생각하고 접근했는데 잘 풀리지 않네요ㅠㅠ
import java.util.HashMap;
import java.util.Map;

class TrieNode {
    Map<Character, TrieNode> childNodes = new HashMap<>();
    boolean endPoint;
    
    public Map<Character, TrieNode> getChildNodes() {
        return childNodes;
    }
    
    public boolean isLast() {
        return endPoint;
    }
    
    public void setLast(boolean last) {
        endPoint = last;
    }
}

class Trie {
    private TrieNode rootNode;

    Trie(){
        rootNode = new TrieNode();
    }

    void insert(String word){
        TrieNode node = this.rootNode;
        for(int i=0; i<word.length(); i++) {
            node = node.getChildNodes().computeIfAbsent(word.charAt(i), c -> new TrieNode());
        }
        node.setLast(true);
    }

    boolean contains(String word){
        TrieNode node = this.rootNode;
        char cur;
        for(int i=0; i<word.length(); i++){
            cur = word.charAt(i);
            
            if(node.getChildNodes().containsKey('*')) {
                node = node.getChildNodes().get('*');
                continue;
            }
            
            if(!node.getChildNodes().containsKey(cur)) {
                return false;
            }
            node = node.getChildNodes().get(cur);
        }
        return node.isLast();
    }

    void delete(String word){
        delete(this.rootNode, word, 0);
    }
    
    private void delete(TrieNode node, String word, int index){
        if(index == word.length()){
            if(!node.isLast()) {
                throw new Error("not exist");
            }
            
            node.setLast(false);
            return;
        }
        
        char cur = word.charAt(index);
        if(!node.getChildNodes().containsKey(cur)) {
            throw new Error("not exist");
        }
        
        TrieNode child = node.getChildNodes().get(cur);
        delete(node.getChildNodes().get(cur), word, index+1);
        if(child.getChildNodes().isEmpty()) {
            if(!child.isLast()) {
                node.getChildNodes().remove(cur, child);
            }
        }
    }
}

class Solution {  
    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        Trie trie = new Trie();
        
        for(int i = 0; i < banned_id.length; i++) {
            trie.insert(banned_id[i]);
            
            boolean[] checked = new boolean[user_id.length];
            
            for(int i = 0; i < user_id.length; i++) {
                if(!checked[i] && trie.contains(user_id[i])) {
                    checked[i] = true;
                    trie.delete(user_id[i]);
                }
            }
        }
        
        
        
        return answer;
    }
}
