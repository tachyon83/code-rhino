const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const [ n, m ] = input[0].split(' ').map(e => parseInt(e))
const g = new Array(n + 1).fill(0).map(e => [])
const cost = new Array(n + 1).fill(100 * n + 1)

class PriorityQueue {
  curr = 0
  parent = i => ((i + 1) >>> 1) - 1
  left = i => (i << 1) + 1
  right = i => (i + 1) << 1

  constructor(minHeap) {
    this._heap = []
    this._comparator = minHeap ? (a, b) => cost[a] < cost[b] : (a, b) => b < a
  }
  size() {
    return this._heap.length
  }
  isEmpty() {
    return this.size() == 0
  }
  top() {
    return this._heap[this.curr]
  }
  push(...values) {
    values.forEach(value => {
      this._heap.push(value)
      this._shiftUp()
    })
  }
  pop() {
    const poppedValue = this.top()
    const bottom = this.size() - 1
    if (bottom > this.curr) this._swap(this.curr, bottom)
    this._heap.pop()
    this._shiftDown()
    return poppedValue
  }
  _greater(i, j) {
    return this._comparator(this._heap[i], this._heap[j])
  }
  _swap(i, j) {
    ;[ this._heap[i], this._heap[j] ] = [ this._heap[j], this._heap[i] ]
  }
  _shiftUp() {
    let node = this.size() - 1
    while (node > this.curr && this._greater(node, this.parent(node))) {
      this._swap(node, this.parent(node))
      node = this.parent(node)
    }
  }
  _shiftDown() {
    let node = this.curr
    while (
      (this.left(node) < this.size() && this._greater(this.left(node), node)) ||
      (this.right(node) < this.size() && this._greater(this.right(node), node))
    ) {
      let maxChild =
        this.right(node) < this.size() &&
        this._greater(this.right(node), this.left(node))
          ? this.right(node)
          : this.left(node)
      this._swap(node, maxChild)
      node = maxChild
    }
  }
}

const solve = (s, t) => {
  const pq = new PriorityQueue(true)
  cost[s] = 0
  pq.push(s)

  while (!pq.isEmpty()) {
    const curr = pq.pop()
    if (curr === t) {
      console.log(cost[curr])
      break
    }

    for (const [ nx, w ] of g[curr]) {
      if (nx === s) continue
      const nc = cost[curr] + w
      if (nc < cost[nx]) {
        cost[nx] = nc
        pq.push(nx)
      }
    }
  }
}

for (let i = 0; i < m; ++i) {
  const [ a, b, c ] = input[1 + i].split(' ').map(e => parseInt(e))
  g[a].push([ b, c ])
  g[b].push([ a, c ])
}
const [ s, t ] = input[m + 1].split(' ').map(e => parseInt(e))

solve(s, t)
