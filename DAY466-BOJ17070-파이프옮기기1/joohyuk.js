const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const n = parseInt(input[0])
const board = []
const dp = []
for (let i = 0; i < n; ++i) {
  board.push(input[i + 1].split(' ').map(e => parseInt(e)))
  let temp = []
  for (let j = 0; j < n; ++j) temp.push([ 0, 0, 0 ])
  dp.push(temp)
}

const solve = _ => {
  dp[0][1][0] = 1

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < n; ++j) {
      if (!i && !j) continue
      try {
        if (!board[i][j + 1]) dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2]
      } catch (e) {}
      try {
        if (!board[i][j + 1] && !board[i + 1][j] && !board[i + 1][j + 1])
          dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]
      } catch (e) {}
      try {
        if (!board[i + 1][j]) dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2]
      } catch (e) {}
    }
  }
  console.log(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2])
}
solve()
