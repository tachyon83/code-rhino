const fs = require('fs')
let input
try {
    input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')
} catch (_) {}

const n = parseInt(input), board = []

for (let i = 0; i < n; ++i) {
    const temp = []
    for (let j = 0; j < 2 * n - 1; ++j)temp.push(' ')
    board.push(temp)
}

const dnc = (r, c, sz) => {
    r = parseInt(r), c = parseInt(c), sz = parseInt(sz)

    if (sz === 3) {
        board[r][c - 1] = '*'
        for (let i = -1; i <= 1; i = i + 2)board[r + 1][c - 1 + i] = '*'
        for (let i = -2; i <= 2; ++i)board[r + 2][c - 1 + i] = '*'
        return
    }
    dnc(r, c, sz / 2)
    dnc(r + sz / 2, c - sz / 2, sz / 2)
    dnc(r + sz / 2, c + sz / 2, sz / 2)
}
dnc(0, n, n)

for (let i = 0; i < n; i++)console.log(board[i].join(''));
