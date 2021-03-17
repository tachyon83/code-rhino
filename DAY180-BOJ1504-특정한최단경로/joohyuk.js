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


const big = 1000 * 800 + 1
let ln = 0, n, E, g = [], cost = [], v1, v2, a, b, c, pq = new PriorityQueue()
let sv1, sv2, v1n, v2n, v1v2, v2v1

const input = line => {
    if (!ln) {
        [n, E] = line.split(' ').map(e => parseInt(e))
        for (let i = 0; i <= n; ++i)g.push([])
    } else if (ln <= E) {
        [a, b, c] = line.split(' ').map(e => parseInt(e))
        g[a].push([b, c])
        g[b].push([a, c])
    } else[v1, v2] = line.split(' ').map(e => parseInt(e))
    ln++
}

const reset = _ => {
    for (let i = 0; i <= n; ++i)cost[i] = big
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
                pq.push([cost[np[0]], np[0]])
            }
        }
    }
}

const solve = _ => {
    dijkstra(1)
    sv1 = cost[v1]
    sv2 = cost[v2]

    dijkstra(v1)
    v1n = cost[n]
    v1v2 = cost[v2]

    dijkstra(v2)
    v2n = cost[n]
    v2v1 = cost[v1]

    let ans = Math.min(sv1 + v1v2 + v2n, sv2 + v2v1 + v1n)
    if (ans >= big) console.log(-1)
    else console.log(ans)
}

rl
    .on('line', input)
    .on('close', solve)
