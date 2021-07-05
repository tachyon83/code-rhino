const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const dr = [-1, 0, 1, 0, -1, -1, 1, 1], dc = [0, 1, 0, -1, -1, 1, -1, 1, -1]
let w = 0, h, board = [], vis = [], ln

const input = line => {
    if (!w) {
        ln = 0
        board = []
        line = line.split(' ').map(e => parseInt(e))
        w = line[0], h = line[1]
    } else {
        board.push(line.split(' ').map(e => parseInt(e)))
        ln++
        if (ln == h) {
            vis = []
            for (let j = 0; j < h; ++j) {
                let temp = []
                for (let i = 0; i < w; ++i)temp.push(false)
                vis.push(temp)
            }
            solve()
            w = 0
        }
    }
}

const explore = (r, c) => {
    vis[r][c] = true
    let q = []
    q.push([r, c])
    while (q.length) {
        [cr, cc] = q.shift()
        for (let i = 0; i < 8; ++i) {
            let nr = cr + dr[i], nc = cc + dc[i]
            if (0 <= nr && nr < h && 0 <= nc && nc < w && board[nr][nc] && !vis[nr][nc]) {
                vis[nr][nc] = true
                q.push([nr, nc])
            }
        }
    }
}

const solve = _ => {
    let cnt = 0
    for (let i = 0; i < h; ++i) {
        for (let j = 0; j < w; ++j) {
            if (board[i][j] && !vis[i][j]) {
                cnt++
                explore(i, j)
            }
        }
    }
    console.log(cnt)
}

rl
    .on('line', input)
    // .on('close', solve)
