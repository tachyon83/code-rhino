const check = (skill_tree,skills) => {
    const sts = skill_tree.split("");
    let idx = 0;
    for(const st of sts){
        if(skills.find(sk => sk === st)){ // 선행관계가 있는 스킬이라면
            if(skills[idx] !== st) return false; // 선행스킬을 배우지 않았다면 불가능
            else idx++; 
        }
    }
    
    return true;
}

function solution(skill, skill_trees) {
    let answer = 0;
    const skills = skill.split(""); 
    for(const st of skill_trees){ 
        if(check(st,skills)) answer ++; // 가능한 스킬트리인지 확인 
    }
    
    return answer;
}
