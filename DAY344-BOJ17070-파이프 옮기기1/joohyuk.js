const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, board = [], dp = []

const input = line => {
    if (!n) n = parseInt(line)
    else {
        board.push(line.split(' ').map(e => parseInt(e)))
        let temp = []
        for (let i = 0; i < n; ++i)temp.push([0, 0, 0])
        dp.push(temp)
    }
}

const solve = _ => {
    dp[0][1][0] = 1

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (!i && !j) continue
            try {if (!board[i][j + 1]) dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2]} catch (e) { }
            try {if (!board[i][j + 1] && !board[i + 1][j] && !board[i + 1][j + 1]) dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]} catch (e) { }
            try {if (!board[i + 1][j]) dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2]} catch (e) { }
        }
    }
    console.log(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2])
}

rl
    .on('line', input)
    .on('close', solve)
