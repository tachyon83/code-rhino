const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

function repeat(fn, arr) {
    return function () {
        if (!arr.length) return
        return repeat(fn, fn(arr))
    }
}

function fnCheckAndRunner(fn) {
    while (typeof fn === 'function') {
        fn = fn()
    }
}

const starter = function (fn, arr) {
    fnCheckAndRunner(function () {
        return repeat(fn, arr)
    })
}

let cnt, M = 0, n, m, ln = 0, board = [], vis = [], di = [0, 1, 0, -1], dj = [-1, 0, 1, 0]

const dfs = arr => {
    let ret = []
    arr.map(e => {
        i = e[0], j = e[1]
        cnt++
        for (let idx = 0; idx < 4; ++idx) {
            let ni = i + di[idx]
            let nj = j + dj[idx]
            if (0 <= ni && ni < n && 0 <= nj && nj < m && !vis[ni][nj] && board[ni][nj]) {
                vis[ni][nj] = 1
                ret.push([ni, nj])
            }
        }
    })
    return ret
}
const solve = _ => {
    let complexCnt = 0
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            if (!vis[i][j] && board[i][j]) {
                vis[i][j] = 1
                complexCnt++
                cnt = 0
                starter(dfs, [[i, j]])
                M = Math.max(M, cnt)
            }
        }
    }
    console.log(complexCnt)
    console.log(M)
    process.exit();
}

rl.on('line', function (line) {
    if (!ln) {
        line = line.split(' ')
        line = line.map(e => parseInt(e))
        n = line[0]
        m = line[1]
        for (let i = 0; i < n; ++i) {
            let temp = []
            for (let j = 0; j < m; ++j)temp.push(0)
            vis.push(temp)
        }

    } else {
        line = line.split(' ')
        line = line.map(e => parseInt(e))
        board.push(line)
    }
    ln++
    if (ln > n) solve()
}).on('close', function () {
    process.exit();
});
