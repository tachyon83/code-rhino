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
        this.q = []
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

let gears = [[]],
    q = new Queue(),
    dg = [-1, 1],
    k = 0, n = -1, ret,
    info = new Queue()

const rotate = (s, d) => {
    if (d > 0) return s[s.length - 1] + s.substring(0, s.length - 1)
    return s.substring(1, s.length) + s[0]
}

const sum = _ => {
    let ret = 0
    for (let i = 1; i < 4 + 1; ++i)ret += parseInt(gears[i][0]) * (2 ** (i - 1))
    return ret
}

const input = line => {
    n++
    if (n < 4) gears.push(line)
    else if (!k) k = parseInt(line)
    else info.push(line.split(' ').map(e => parseInt(e)))
}

const solve = _ => {
    while (k--) {
        let vis = new Array(4 + 1).fill(false),
            rdr = new Array(4 + 1).fill(0)

        let [n, d] = info.pop()
        vis[n] = true, rdr[n] = d

        q.push([n, d])
        while (!q.isEmpty()) {
            let [cg, cdr] = q.pop(), ndr = 1
            if (cdr === 1) ndr = -1

            for (let i = 0; i < 2; ++i) {
                let ng = cg + dg[i]
                if (0 < ng && ng < 5 && !vis[ng]) {
                    if (i) {
                        if (gears[cg][2] !== gears[ng][6]) {
                            vis[ng] = true, rdr[ng] = ndr
                            q.push([ng, ndr])
                        }
                    } else {
                        if (gears[cg][6] !== gears[ng][2]) {
                            vis[ng] = true, rdr[ng] = ndr
                            q.push([ng, ndr])
                        }
                    }
                }
            }
        }
        for (let i = 0; i < 4 + 1; ++i)if (vis[i]) gears[i] = rotate(gears[i], rdr[i])
        ret = sum()
    }
    console.log(ret)
}

rl
    .on('line', input)
    .on('close', solve)
