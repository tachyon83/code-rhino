const fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const dr = [ -1, 0, 1, 0 ],dc = [ 0, -1, 0, 1 ]
let [ R, C, N ] = input[0].split(' ').map(e => parseInt(e))
const board = []
for (let i = 0; i < R; ++i)board.push(input[1 + i].split('').map(e => (e === '.' ? 3 : 1)))

while (N--) {
  let flag = false
  const bombs = new Set()
  for (let i = 0; i < R; ++i) {
    for (let j = 0; j < C; ++j) {
      if (board[i][j] === 1) {
        flag = true
        bombs.add([ i, j ])
        for (let k = 0; k < 4; ++k) {
          const nr = i + dr[k]
          const nc = j + dc[k]
          if (0 <= nr && nr < R && 0 <= nc && nc < C) bombs.add([ nr, nc ])
        }
      } else board[i][j]--
    }
  }

  while (bombs.size) {
    bombs.forEach(ep => {
      board[ep[0]][ep[1]] = 0
      bombs.delete(ep)
    })
  }

  if (!flag) {
    for (let i = 0; i < R; ++i) {
      for (let j = 0; j < C; ++j) {
        if (board[i][j] <= 0) board[i][j] = 3
      }
    }
  }
}

for (let i = 0; i < R; ++i) {
  for (let j = 0; j < C; ++j) {
    if (board[i][j] > 0) board[i][j] = 'O'
    else board[i][j] = '.'
  }
  console.log(board[i].join(''))
}
