const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

function repeat(fn, point) {
    return function () {
        if (!point) return
        return repeat(fn, fn(point))
    }
}

function fnCheckAndRunner(fn) {
    while (typeof fn === 'function') {
        fn = fn()
    }
}

const starter = function (fn, point) {
    fnCheckAndRunner(function () {
        return repeat(fn, point)
    })
}

let cnt, M = 0, n, m, ln = 0, board = [], vis = []
let di = [0, 1, 0, -1], dj = [-1, 0, 1, 0]
let stack = []

const dfs = point => {
    const [[i, j], ii] = point
    // console.log('currPoint', [i, j], ii)
    for (let idx = ii; idx < 4; ++idx) {
        const ni = i + di[idx]
        const nj = j + dj[idx]
        if (0 <= ni && ni < n && 0 <= nj && nj < m && !vis[ni][nj] && board[ni][nj]) {
            vis[ni][nj] = 1
            cnt++
            if (idx < 3) stack.push([[i, j], idx + 1])
            return [[ni, nj], 0]
        }
    }
}

const solve = _ => {
    let complexCnt = 0
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            if (!vis[i][j] && board[i][j]) {
                vis[i][j] = 1
                complexCnt++
                cnt = 1
                starter(dfs, [[i, j], 0])
                while (stack.length) starter(dfs, stack.pop())
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
        [n, m] = line
            .split(' ')
            .map(e => parseInt(e))

        for (let i = 0; i < n; ++i) {
            let temp = []
            for (let j = 0; j < m; ++j)temp.push(0)
            vis.push(temp)
        }
    } else {
        board.push(line
            .split(' ')
            .map(e => parseInt(e))
        )
    }
    ln++
    if (ln > n) solve()
}).on('close', function () {
    process.exit();
});
