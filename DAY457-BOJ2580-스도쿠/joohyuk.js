const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')
const rows = []
const cols = []
const grs = []
const zs = []

for (let i = 0; i < 9; ++i) {
  rows.push(new Set())
  cols.push(new Set())
  grs.push(new Set())
}

for (let i = 0; i < 9; ++i) {
  input[i] = input[i].split(' ').map(e => parseInt(e, 10))
  for (let j = 0; j < 9; ++j) {
    if (input[i][j] === 0) zs.push([ i, j ])
    rows[i].add(input[i][j])
    cols[j].add(input[i][j])
    grs[parseInt(i / 3, 10) * 3 + parseInt(j / 3, 10)].add(input[i][j])
  }
}

const print = _ => {
  for (let i = 0; i < 9; ++i) console.log(input[i].join(' '))
}
const process = n => {
  if (n === zs.length) return true

  const i = zs[n][0]
  const j = zs[n][1]
  const grn = parseInt(i / 3, 10) * 3 + parseInt(j / 3, 10)

  for (let k = 1; k <= 9; ++k) {
    if (rows[i].has(k) || cols[j].has(k) || grs[grn].has(k)) continue

    rows[i].add(k)
    cols[j].add(k)
    grs[grn].add(k)
    input[i][j] = k
    if (process(n + 1)) return true
    rows[i].delete(k)
    cols[j].delete(k)
    grs[grn].delete(k)
  }
  return false
}
if (zs.length) process(0)
print()
