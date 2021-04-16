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

let ln = 0, n, m, g = [], big = 5e7 + 1, p, q, w, cost = []
let pq = new PriorityQueue()

const input = line => {
    if (!ln) {
        [n, m] = line.split(' ').map(e => parseInt(e))
        for (let i = 0; i < n + 1; ++i) {
            cost.push(big)
            g.push([])
        }
    } else {
        [p, q, w] = line.split(' ').map(e => parseInt(e))
        g[p].push([q, w])
        g[q].push([p, w])
    }
    ln++
}

const dijkstra = _ => {
    cost[1] = 0
    pq.push([cost[1], 1])
    while (!pq.isEmpty()) {
        [hold, curr] = pq.pop()
        if (cost[curr] < hold) continue;
        for (let np of g[curr]) {
            [nx, w] = np
            if (cost[nx] > hold + w) {
                cost[nx] = hold + w
                pq.push([cost[nx], nx])
            }
        }
    }
    console.log(cost[n])
}

rl
    .on('line', input)
    .on('close', dijkstra)
