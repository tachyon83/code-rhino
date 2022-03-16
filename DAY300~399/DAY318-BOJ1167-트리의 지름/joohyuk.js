const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

class Queue {
    constructor() {
        this.q = []
        this.s = 0
        this.e = 0
        this.sz = 0
    }
    size() {
        return this.sz
    }
    isEmpty() {
        if (this.sz !== 0) return false
        this.s = 0
        this.e = 0
        return true
    }
    push(...values) {
        values.forEach(value => {
            this.q.push(value);
            this.e++
            this.sz++
        });
    }
    pop() {
        this.sz--
        return this.q[this.s++]
    }
}


let n = 0, g = [], vis = []

const input = line => {
    if (!n) {
        n = parseInt(line)
        for (let i = 0; i < n + 1; ++i) {
            g.push([])
            vis.push(false)
        }
    } else {
        line = line.split(' ').map(e => parseInt(e))
        for (let i = 1; i < line.length - 1; i += 2)g[line[0]].push([line[i], line[i + 1]])
    }
}

const reset = _ => {
    for (let i = 0; i < n + 1; ++i)vis[i] = false
}

const bfs = start => {
    let mx = 0
    vis[start] = true
    let qc = new Queue()
    qc.push([start, 0])
    while (!qc.isEmpty()) {
        [curr, cost] = qc.pop()
        g[curr].forEach(np => {
            [nx, nc] = np
            if (!vis[nx]) {
                vis[nx] = true
                if (nc + cost > mx) {
                    start = nx
                    mx = nc + cost
                }
                qc.push([nx, nc + cost])
            }
        })
    }
    reset()
    return [start, mx]
}

const solve = _ => {
    console.log(bfs(bfs(1)[0])[1])
}

rl
    .on('line', input)
    .on('close', solve)
