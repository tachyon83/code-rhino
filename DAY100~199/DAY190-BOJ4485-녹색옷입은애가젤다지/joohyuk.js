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

let cnt = 0, ln = 0, n, nr, nc, r, c, board, cost, big
let dr = [0, 1, 0, -1], dc = [-1, 0, 1, 0]
let pq = new PriorityQueue()

const reset = _ => {
    board = [], cost = []
    big = n * n * 9 + 1
    for (let i = 0; i < n; ++i) {
        let temp = []
        for (let j = 0; j < n; ++j)temp.push(big)
        cost.push(temp)
    }
}

const input = line => {
    if (!ln) {
        n = parseInt(line)
        if (n) reset()
    } else if (ln <= n) {
        board.push(line.split(' ').map(e => parseInt(e)))
        if (ln == n) {
            ln = -1
            solve(++cnt)
        }
    }
    ln++
}

const dijkstra = _ => {
    cost[0][0] = board[0][0]
    pq.push([cost[0][0], [0, 0]])
    while (!pq.isEmpty()) {
        [crush, [r, c]] = pq.pop()
        if (crush > cost[r][c]) continue;
        for (let i = 0; i < 4; ++i) {
            nr = r + dr[i], nc = c + dc[i]
            if (0 <= nr && nr < n && 0 <= nc && nc < n) {
                if (cost[nr][nc] > crush + board[nr][nc]) {
                    cost[nr][nc] = crush + board[nr][nc]
                    pq.push([cost[nr][nc], [nr, nc]])
                }
            }
        }
    }
}

const solve = v => {
    dijkstra()
    console.log(`Problem ${v}:`, cost[n - 1][n - 1])
}

rl
    .on('line', input)
    // .on('close', solve)
