function solution(people, limit) {
    let answer = 0;
    people.sort((a,b) => a - b); // 몸무게 오름차순으로 정렬
    let i = 0, j = people.length - 1;
    
    while(i < j) {
        if(people[i] + people[j] <= limit) { // 양쪽 사람들의 무게합이 limit 이하일때 둘다 태운다
            i++;
            j--;
        }else { // 초과하면 무거운 사람 혼자 태운다
            j--;
        }
        answer++;
    }
    if(i === j) answer += 1; // 사람한명이 남았다면 태워보낸다
    
    return answer;
}
