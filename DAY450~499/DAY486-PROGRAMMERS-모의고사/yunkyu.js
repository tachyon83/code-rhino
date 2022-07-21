function solution(answers) {
    let answer = [];
    const a1 = [1,2,3,4,5];
    const a2 = [2,1,2,3,2,4,2,5];
    const a3 = [3,3,1,1,2,2,4,4,5,5];
    
    let scores = [0,0,0];
    
    for(let i = 0; i < answers.length; i++){
        // 각 수포자의 점수를 누적
        if(a1[i % 5] === answers[i]) scores[0]++;
        if(a2[i % 8] === answers[i]) scores[1]++;
        if(a3[i % 10] === answers[i]) scores[2]++;
    }
    
    let maxScore = Math.max(...scores); // 가장 높은 점수
    
    return scores.reduce((acc, curr, index) => {
        if(curr === maxScore) acc.push(index + 1); // 가장 높은 점수를 받은 사람 push
        return acc;
    }, answer);
}
