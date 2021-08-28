const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n=0, g= [],a,b,cand=[],mn=50,big=50

const input = line => {
    if (!n) {
        n= parseInt(line)
        for (let i = 0; i < n + 1; ++i) {
            let temp = []
            for (let j = 0; j < n + 1; ++j){
                if(i==j)temp.push(0)
                else temp.push(big)
            }
            g.push(temp)
        }
    } else {
        [a,b] = line.split(' ').map(e => parseInt(e))
        if(a==-1)fw()
        else{
            g[a][b] =g[b][a]= 1
        }
    }
}

const cnt = _ => {
    for (let i = 1; i < n + 1; ++i) {
        let temp=0
        for (let j = 1; j < n + 1; ++j) {
            if(g[i][j]>temp)temp=g[i][j]
        }
        if (mn>=temp){
            if(mn>temp)cand=[]
            mn=temp
            cand.push(i)
        }
    }
    console.log(mn,cand.length)
    ans=''
    for(let e of cand)ans+=e+' '
    console.log(ans)
}

const fw = _ => {
    for (let k = 1; k < n + 1; ++k) {
        for (let i = 1; i < n + 1; ++i) {
            for (let j = 1; j < n + 1; ++j) {
                g[i][j] =g[j][i]= Math.min(g[i][j],g[i][k] + g[k][j])
            }
        }
    }
    cnt()
}

rl
    .on('line', input)
    // .on('close', fw)
