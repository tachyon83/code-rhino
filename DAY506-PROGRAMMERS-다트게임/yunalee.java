class Solution {
    private static final int NEXT = 1;
    private static final int MAX_SCORE = 10;
    
    public int solution(String dartResult) {
        int answer = 0;
        double[] scoreBoard = new double[dartResult.length()];
        
        int index = 0;
        for(int i = 0; i < dartResult.length(); i++) {
            int score = getScore(dartResult, i);
            i += NEXT;
            
            if(score == MAX_SCORE) {
                i += NEXT;
            }
            
            scoreBoard[index++] = calculateByArea(dartResult, score, i);
            
            if(i + 1 < dartResult.length()) {
                i = calculateByOption(dartResult, scoreBoard, i, index);
            }
        }
        
        for(int i = 0; i < index; i++) {
            answer += scoreBoard[i];
        }
        return answer;
    }
    
    private int getScore(String dartResult, int index) {
        if(index + NEXT < dartResult.length() 
               && dartResult.charAt(index) == '1' 
               && dartResult.charAt(index + NEXT) == '0') {
            return 10;
        }
        
        return dartResult.charAt(index) - '0';
    }
    
    private double calculateByArea(String dartResult, int score, int index) {
        char area = dartResult.charAt(index);
        
        if(area == 'D') {
            return Math.pow(score, 2);
        }
        
        if(area == 'T') {
            return Math.pow(score, 3);
        }
        
        return score;
    }
    
    private int calculateByOption(String dartResult, double[] scoreBoard, int index, int scoreBoardIndex) {
        char option = dartResult.charAt(index + 1);
                
        if(option == '*') {
            calculateScoreDouble(scoreBoard, scoreBoardIndex);
            return index + NEXT;
        }
        
        if(option == '#') {
            scoreBoard[scoreBoardIndex - 1] *= -1;
            return index + NEXT;
        }
        
        return index;
    }
    
    private void calculateScoreDouble(double[] scoreBoard, int index) {
        for(int j = index - 1; j >= index - 2 && j >= 0; j--) {
            scoreBoard[j] *= 2;
        }
    }
}
