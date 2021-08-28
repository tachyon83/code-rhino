const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n=0, g=[],vis=[],q=[],cost=[],start,mx=0

const input = line => {
    if (!n) {
        n= parseInt(line)
        for(let i=0;i<n+1;++i){
            g.push([])
            vis.push(0)
            cost.push(0)
        }
    } else {
        const row = line.split(' ').map(e => parseInt(e))
        g[row[0]].push([row[1],row[2]])
        g[row[1]].push([row[0],row[2]])
    }
}

const bfs=i=>{
    vis[i]=1
    q.push(i)
    while(q.length){
        curr=q.pop()
        for(np of g[curr]){
            if(!vis[np[0]]){
                vis[np[0]]=1
                cost[np[0]]=cost[curr]+np[1]
                if(cost[np[0]]>mx){
                    mx=cost[np[0]]
                    start=np[0]
                }
                q.push(np[0])
            }
        }
    }
}

const solve = _ => {
    start=1
    bfs(start)

    vis=[],cost=[]
    for(let i=0;i<n+1;++i){
        vis.push(0)
        cost.push(0)
    }
    bfs(start)
    console.log(mx)
}

rl
    .on('line', input)
    .on('close', solve)
