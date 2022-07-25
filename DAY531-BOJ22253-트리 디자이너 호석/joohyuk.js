const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

class PriorityQueue {
  curr = 0
  parent = i => ((i + 1) >>> 1) - 1
  left = i => (i << 1) + 1
  right = i => (i + 1) << 1

  constructor(minHeap) {
    this._heap = []
    this._comparator = minHeap ? (a, b) => a < b : (a, b) => b[1] < a[1]
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

class Queue {
  constructor() {
    this.queue = []
    this.head = 0
    this.tail = 0
  }
  push(element) {
    this.queue.push(element)
    this.tail++
  }
  pop() {
    return this.queue[this.head++]
  }
  front() {
    return this.queue[this.head]
  }
  isEmpty() {
    return this.length === 0
  }

  get length() {
    return this.tail - this.head
  }
}

const n = Number(input[0])
const mod = 1e9 + 7
const nums = [ 0 ].concat(input[1].split(' ').map(e => Number(e)))

const g = []
const roots = []
const cases = []
const vis = []

for (let i = 0; i < n + 1; ++i) {
  g.push([])
  roots.push(0)
  vis.push(false)

  const temp = []
  for (let j = 0; j < 10; ++j) temp.push(0)
  cases.push(temp)
}

for (let i = 0; i < n - 1; ++i) {
  const [ a, b ] = input[2 + i].split(' ').map(e => Number(e))
  g[a].push(b)
  g[b].push(a)
}

const q = new Queue()
const pq = new PriorityQueue(0)

q.push([ 1, 0, 0 ])
while (!q.isEmpty()) {
  const [ curr, p, depth ] = q.pop()
  roots[curr] = p

  for (const nx of g[curr]) {
    if (nx !== p) q.push([ nx, curr, depth + 1 ])
  }

  if (g[curr].length === 1 && curr !== 1) pq.push([ curr, depth ])
}

while (!pq.isEmpty()) {
  const [ curr, depth ] = pq.pop()

  if (vis[curr]) continue
  vis[curr] = true

  const root = roots[curr]
  if (curr === 0) continue

  const num = nums[curr]

  let s = 0
  for (let i = 0; i < 10; ++i) {
    cases[root][i] = (cases[root][i] + cases[curr][i]) % mod
    s = (s + (i >= num ? cases[curr][i] : 0)) % mod
  }
  cases[curr][num] += s + 1
  cases[curr][num] %= mod
  cases[root][num] += s + 1
  cases[root][num] %= mod

  pq.push([ root, depth - 1 ])
}

let sum = 0
cases[1].forEach(e => (sum += e))
console.log(sum % mod)
