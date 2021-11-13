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

function solution(n, s, a, b, fares) {
    const dp = [], weight = [], big = 200 * 1e5 + 1, g = []
    for (let i = 0; i <= n; ++i) {
        dp.push(0)
        weight.push(big)
        g.push([])
    }
    const reset = _ => {
        for (let i = 0; i <= n; ++i)weight[i] = big
    }
    for (const fare of fares) {
        const [from, to, cost] = fare
        g[from].push([to, cost])
        g[to].push([from, cost])
    }
    const add = _ => {
        for (let i = 1; i <= n; ++i)dp[i] += weight[i]
    }
    const djk = start => {
        reset()
        const pq = new PriorityQueue()
        pq.push([0, start])
        weight[start] = 0
        while (!pq.isEmpty()) {
            const [cc, here] = pq.pop()
            for (const np of g[here]) {
                const [nx, nc] = np
                if (weight[nx] > nc + cc) {
                    weight[nx] = nc + cc
                    pq.push([weight[nx], nx])
                }
            }
        }
        add()
    }

    djk(s)
    djk(a)
    djk(b)

    let answer = big;
    for (let i = 1; i <= n; ++i) {
        if (dp[i] < answer) answer = dp[i]
    }
    return answer;
}
