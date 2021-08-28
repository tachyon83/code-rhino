const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const big = 10000 + 1
const dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]
let n = 0, cn = 0, mn = big, board = [], border = [], vis = []

const input = line => {
    if (!n) {
        n = parseInt(line)
        for (let i = 0; i < n; ++i) {
            let temp = []
            for (let j = 0; j < n; ++j)temp.push([0, 0])
            vis.push(temp)
        }
    } else board.push(line.split(' ').map(e => parseInt(e)))
}

const explore = (r, c, cn) => {
    let q = []
    q.push([r, c])
    while (q.length) {
        [cr, cc] = q.shift()
        let cnt = 0
        for (let i = 0; i < 4; ++i) {
            let nr = cr + dr[i], nc = cc + dc[i]
            if (0 <= nr && nr < n && 0 <= nc && nc < n) {
                if (board[nr][nc]) {
                    if (!vis[nr][nc][1]) {
                        vis[nr][nc][1] = cn
                        q.push([nr, nc])
                    }
                } else cnt++
            }
        }
        if (cnt) border.push([cr, cc])
    }
}

const bfs = (r, c, idx, ccn) => {
    idx++
    let q = []
    q.push([r, c])
    let cost = 0
    while (q.length) {
        let qs = q.length
        cost++
        for (let k = 0; k < qs; k++) {
            [cr, cc] = q.shift()
            for (let i = 0; i < 4; ++i) {
                let nr = cr + dr[i], nc = cc + dc[i]
                if (0 <= nr && nr < n && 0 <= nc && nc < n && vis[nr][nc][0] != idx && vis[nr][nc][1] != ccn) {
                    if (vis[nr][nc][1]) return cost - 1
                    vis[nr][nc][0] = idx
                    q.push([nr, nc])
                }
            }
        }
    }
    return big
}

const solve = _ => {
    let num = 0
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] && !vis[i][j][1]) {
                num++
                vis[i][j][1] = num
                explore(i, j, num)
            }
        }
    }

    border.forEach((ep, idx) => {
        [cr, cc] = ep
        mn = Math.min(mn, bfs(cr, cc, idx, vis[cr][cc][1]))
    })
    console.log(mn)
}

rl
    .on('line', input)
    .on('close', solve)
