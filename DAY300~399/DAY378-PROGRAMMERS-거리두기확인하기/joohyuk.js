function solution(places) {
    let board
    const dr=[0,1,0,-1],dc=[1,0,-1,0]
    const check=(d,ccoord,pcoord)=>{
        console.log(5,d)
        if(d===2)return false
        let [cr,cc]=ccoord
        for(let i=0;i<4;++i){
            let nr=cr+dr[i],nc=cc+dc[i]
            if([nr,nc]===pcoord)continue
            if(0<=nr&&nr<5&&0<=nc&&nc<5&&places[nr][nc]!=='X'){
                if(places[nr][nc]==='P')return true
                return check(d+1,[nr,nc],ccoord)
            }
        }
        return false
    }
    
    var answer = [];
    for(const place of places){
        board=place
        let flag=false
        for(let i=0;i<5;++i){
            for(let j=0;j<5;++j){
                if(board[i][j]==='P')flag|=check(0,[i,j],[-1,-1])
            }
        }
        answer.push(flag?0:1)
    }
    return answer;
}
