import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// 트라이 알고리즘
// 휴대폰 자판 
public class p5670 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String str = br.readLine();
		
		while(!str.equals("")) {
			int tc = Integer.valueOf(str);
			List<String> list = new ArrayList<String>();
			Trie5670 trie = new Trie5670();
			
			// 입력 받기 
			for(int i = 0; i < tc; i++) {
				String word = br.readLine();
				list.add(word);
				trie.insert(word);
			}
			
			// 정답 찾기
			double sum = 0;
			for(String ele : list) {
				sum += trie.contains(ele);
			}
			
			// 평균 출력
			double avg = sum / tc;
			sb.append(String.format("%.2f", avg));
			sb.append("\n");
			
			str = br.readLine();
		}
		
		System.out.println(sb.toString());
	}
}

//트라이 알고리즘에 사용되는 노드 
class TrieNode5670 {
	private Map<Character, TrieNode5670> childNode = new HashMap<>();
	private boolean isLastChar;

	// 해당 문자가 마지막 문자인지
	public boolean isLastChar() {
		return this.isLastChar;
	}

	public void setLastChar(boolean isLastChar) {
		this.isLastChar = isLastChar;
	}

	public Map<Character, TrieNode5670> getChildNodes() {
		return this.childNode;
	}
}

//트라이 알고리즘 
class Trie5670 {
	public TrieNode5670 rootTemp;

	// 생성자 생성
	Trie5670() {
		this.rootTemp = new TrieNode5670();
	}

	// 삽입
	public void insert(String word) {
		TrieNode5670 tempNode = this.rootTemp;
   
    for(int i = 0; i < word.length(); i++) {
    	// 즉, childNode의 Key가 charAt(i) 이면 c(value = TrieNode) 리턴, 없으면 -> 다음에 작성한 { new TrieNode() } 함수를 실행하고, 그 결과값을 리턴해준다. 
    	tempNode = tempNode.getChildNodes().computeIfAbsent(word.charAt(i), c -> new TrieNode5670());   // 두 값(단어의 문자와 현재 노드의 KEY값) 이 다르면 새로운 Node 생성
    }
   
	tempNode.setLastChar(true);
	}

	 // 존재 여부
	 public int contains(String word) {
		 TrieNode5670 tempNode = this.rootTemp;
		 int count = 1;
		 // 첫 글자는 무조건 입력해야 하므로 첫 글자 설정 
		 tempNode = tempNode.getChildNodes().get(word.charAt(0));
		 
		 for(int i = 1; i < word.length(); i++) {
			 if(tempNode.getChildNodes().size() >= 2) {
				 count++;
			 }
			 // 만약 해당 문자가 어느 문자열의 마지막인데, 이후 다른 단어들이 줄줄이 뒤에 있는 경우
			 else if(tempNode.getChildNodes().size() == 1 && tempNode.isLastChar()) {
				 count++;
			 }
			 
			 char ch = word.charAt(i);
			 TrieNode5670 node = tempNode.getChildNodes().get(ch);
			 
			 tempNode = node;
	    }
	   
	    return count;
	 }
}
