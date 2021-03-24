const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const top = 0;
const parent = i => ((i + 1) >>> 1) - 1;
const left = i => (i << 1) + 1;
const right = i => (i + 1) << 1;

class PriorityQueue {
    constructor(comparator = (a, b) => a[0] < b[0]) {
        this._heap = [];
        this._comparator = comparator;
    }
    size() {
        return this._heap.length;
    }
    isEmpty() {
        return this.size() == 0;
    }
    peek() {
        return this._heap[top];
    }
    push(...values) {
        values.forEach(value => {
            this._heap.push(value);
            this._shiftUp();
        });
    }
    pop() {
        const poppedValue = this.peek();
        const bottom = this.size() - 1;
        if (bottom > top) {
            this._swap(top, bottom);
        }
        this._heap.pop();
        this._shiftDown();
        return poppedValue;
    }
    _greater(i, j) {
        return this._comparator(this._heap[i], this._heap[j]);
    }
    _swap(i, j) {
        [this._heap[i], this._heap[j]] = [this._heap[j], this._heap[i]];
    }
    _shiftUp() {
        let node = this.size() - 1;
        while (node > top && this._greater(node, parent(node))) {
            this._swap(node, parent(node));
            node = parent(node);
        }
    }
    _shiftDown() {
        let node = top;
        while (
            (left(node) < this.size() && this._greater(left(node), node)) ||
            (right(node) < this.size() && this._greater(right(node), node))
        ) {
            let maxChild = (right(node) < this.size() && this._greater(right(node), left(node))) ? right(node) : left(node);
            this._swap(node, maxChild);
            node = maxChild;
        }
    }
}


const big = 10000 * 200 + 1
let ln = 0, n, e, temp, g = [], board = [], cost = []
let prv = [], a, b, c, pq = new PriorityQueue()

const input = line => {
    if (!ln) {
        [n, e] = line.split(' ').map(e => parseInt(e))
        for (let i = 0; i <= n; ++i) {
            g.push([])
            prv.push(0)
            temp = []
            if (i) {
                for (let j = 0; j < n; ++j)temp.push(0)
                board.push(temp)
            }
        }
    } else {
        [a, b, c] = line.split(' ').map(e => parseInt(e))
        g[a].push([b, c])
        g[b].push([a, c])
    }
    ln++
}

const reset = _ => {
    for (let i = 0; i <= n; ++i)cost[i] = big
}

const record = s => {
    for (let e = 1; e <= n; ++e) {
        if (e == s) {
            board[s - 1][e - 1] = '-'
            continue
        }
        let m = e
        while (prv[m] != s) m = prv[m]
        board[s - 1][e - 1] = m
    }
}

const print = _ => {
    for (let i = 0; i < n; ++i)console.log(board[i].join(' '))
}

const dijkstra = s => {
    reset()
    let curr, d
    cost[s] = 0
    pq.push([cost[s], s])
    while (!pq.isEmpty()) {
        [d, curr] = pq.pop()
        if (cost[curr] < d) continue;
        for (let np of g[curr]) {
            if (cost[np[0]] > d + np[1]) {
                cost[np[0]] = d + np[1]
                prv[np[0]] = curr
                pq.push([cost[np[0]], np[0]])
            }
        }
    }
}

const solve = _ => {
    for (let i = 1; i <= n; ++i) {
        dijkstra(i)
        record(i)
    }
    print()
}

rl
    .on('line', input)
    .on('close', solve)
