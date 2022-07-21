const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')
const n = input[0]
const inOrder = input[1].split(' ').map(e => parseInt(e))
const postOrder = input[2].split(' ').map(e => parseInt(e))

const indexes = []
inOrder.forEach((e, i) => { indexes[e] = i })
const preOrder = []
const process = (s, e) => {
  if (s >= e || !postOrder.length) return
  const node = postOrder.pop()
  process(indexes[node] + 1, e)
  process(s, indexes[node])
  preOrder.push(node)
}
process(0, n)
console.log(preOrder.reverse().join(' '))
