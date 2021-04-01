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
    constructor(comparator = (a, b) => {
        if (a[0] == b[0]) return a[1] > b[1]
        return a[0] < b[0]
    }) {
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

let ln = 0, n, m, g = [], hist = [], a, b, c, p, q, w, cost = []
let pq = new PriorityQueue()

const input = line => {
    if (!ln) {
        [n, m, a, b, c] = line.split(' ').map(e => parseInt(e))
        for (let i = 0; i < n + 1; ++i) {
            let temp = []
            for (let j = 0; j < 1000 + 1; ++j)temp.push(-1)
            cost.push(temp)
            g.push([])
            hist.push(new Set())
        }
    } else {
        [p, q, w] = line.split(' ').map(e => parseInt(e))
        g[p].push([q, w])
        g[q].push([p, w])
    }
    ln++
}

const dijkstra = _ => {
    for (let np of g[a]) {
        [nx, w] = np
        cost[a][w] = c - w
    }
    pq.push([0, c, a])
    while (!pq.isEmpty()) {
        [v, hold, curr] = pq.pop()
        if (curr == b) break
        if (cost[curr][v] > hold) continue;
        for (let np of g[curr]) {
            [nx, w] = np
            if (hold - w < 0) continue
            let temp = Math.max(v, w)
            if (cost[nx][temp] < hold - w) {
                cost[nx][temp] = hold - w
                hist[nx].add(temp)
                pq.push([temp, hold - w, nx])
            }
        }
    }
}

const solve = v => {
    dijkstra()
    console.log(Array.from(hist[b]).sort()[0] || -1)
}

rl
    .on('line', input)
    .on('close', solve)
