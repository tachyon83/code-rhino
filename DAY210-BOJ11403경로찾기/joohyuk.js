const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n=0, g= []

const input = line => {
    if (!n) {
        n= parseInt(line)
    } else {
        const row = line.split(' ').map(e => parseInt(e))
        g.push(row)
    }
}

const printer = _ => {
    for (let i = 0; i < n; ++i) {
        let temp=''
        for (let j = 0; j < n; ++j)temp+=g[i][j]+' '
        console.log(temp)
    }
}

const fw = _ => {
    for (let k = 0; k < n; ++k) {
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                let temp=g[i][k] + g[k][j]
                if(temp>1)g[i][j]=1
            }
        }
    }
    printer()
}

rl
    .on('line', input)
    .on('close', fw)
