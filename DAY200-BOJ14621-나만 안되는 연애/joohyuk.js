const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let ln = 0, n, m, routes = [], roots = [], ans = 0, mw = []

const find = a => {
    if (roots[a] == a) return a
    roots[a] = find(roots[a])
    return roots[a]
}

const union = (a, b) => {
    a = find(a)
    b = find(b)
    roots[a] = b
}

const input = line => {
    if (!ln) {
        [n, m] = line.split(' ').map(e => parseInt(e))
        for (let i = 0; i <= n; ++i)roots.push(i)
    } else if (ln == 1) mw = line.split(' ')
    else {
        let temp = line.split(' ').map(e => parseInt(e))
        routes.push([temp[2], temp[0], temp[1]])
    }
    ln++
}

const conn = _ => {
    let hold = find(1)
    for (let i = 1; i <= n; ++i)if (find(i) != hold) return false
    return true
}

const mst = _ => {
    routes.sort(function (a, b) { return a[0] > b[0] ? 1 : -1 })
    for (let route of routes) {
        [w, p, q] = route
        if (find(p) != find(q) && mw[p - 1] != mw[q - 1]) {
            ans += w
            union(p, q)
        }
    }
    console.log(conn() ? ans : -1)
}

rl
    .on('line', input)
    .on('close', mst)
