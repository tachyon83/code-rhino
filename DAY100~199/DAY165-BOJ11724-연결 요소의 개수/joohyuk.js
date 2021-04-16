const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n
let m = -1
let ln = 0
let vis = []
let g = []

const dfs = n => {
    vis[n] = 1
    for (let nx of g[n]) if (!vis[nx]) dfs(nx)
}
const solve = _ => {
    let cnt = 0
    for (let i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt++
            dfs(i)
        }
    }
    console.log(cnt)
    process.exit();
}

rl.on('line', function (line) {
    if (!ln) {
        line = line.split(' ')
        line = line.map(e => parseInt(e))
        n = line[0]
        m = line[1]
        for (let i = 0; i <= n; ++i) {
            vis.push(0)
            g.push([])
        }
    } else {
        line = line.split(' ')
        line = line.map(e => parseInt(e))
        g[line[0]].push(line[1])
        g[line[1]].push(line[0])
    }
    ln++
    if (ln > m) solve()
}).on('close', function () {
    process.exit();
});
