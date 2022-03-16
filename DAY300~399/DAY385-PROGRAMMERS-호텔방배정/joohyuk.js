function solution(k, room_number) {
    const root={}
    const find=a=>{
        if(!(a in root))return a
        return root[a]=find(root[a])
    }
    
    var answer = [];
    for(const num of room_number){
        const temp=find(num)
        answer.push(temp)
        if(!(temp in root))root[temp]=temp+1
    }
    return answer;
}
