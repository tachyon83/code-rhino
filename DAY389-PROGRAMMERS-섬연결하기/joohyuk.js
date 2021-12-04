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
    constructor(comparator = (a, b) => a[2] < b[2]) {
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

function solution(n, costs) {
    const root = []
    for (let i = 0; i < n; ++i)root.push(i)

    const find = a => {
        if (root[a] === a) return a
        return root[a] = find(root[a])
    }
    
    const pq = new PriorityQueue()
    for (const cost of costs) pq.push(cost)

    var answer = 0;
    while (!pq.isEmpty()) {
        const [a, b, c] = pq.pop()
        console.log(83,a,b,c)
        if (find(a) !== find(b)) {
            answer += c
            root[find(a)]=root[find(b)]
        }
    }
    return answer;
}
