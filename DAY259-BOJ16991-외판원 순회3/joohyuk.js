const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n=0, g=[],dp=[],big=80000

const input = line => {
    if (!n) {
        n= parseInt(line)
        for(let j=0;j<n;++j){
            temp=[]
            for(let i=0;i<(1<<n);++i)temp.push(-1)
            dp.push(temp)
        }
    } else g.push(line.split(' ').map(e => parseInt(e)))
}

const dist=(a,b)=>{
    const dx=g[a][0]-g[b][0]
    const dy=g[a][1]-g[b][1]
    return Math.sqrt(dx**2+dy**2)
}

const tsp=(s,mask)=>{
    if(dp[s][mask]!=-1)return dp[s][mask]
    if(mask==(1<<n)-1)return dp[s][mask]=dist(s,0)
    dp[s][mask]=big
    for(let i=0;i<n;++i){
        if(i==s || mask&(1<<i))continue
        dp[s][mask]=Math.min(dp[s][mask],dist(i,s)+tsp(i,mask|(1<<i)))
    }
    return dp[s][mask]
}

const solve = _ => {
    console.log(tsp(0,1))
}

rl
    .on('line', input)
    .on('close', solve)
