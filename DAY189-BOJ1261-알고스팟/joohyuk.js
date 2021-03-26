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

let ln = 0, ncrush, crush, n, m, nr, nc, r, c, board = [], big
let dr = [0, 1, 0, -1], dc = [-1, 0, 1, 0]
let pq = new PriorityQueue()

const input = line => {
    if (!ln) {
        [m, n] = line.split(' ').map(e => parseInt(e))
        big = n * m + 1
        for (let i = 0; i < n; ++i) {
            let temp = []
            for (let j = 0; j < m; ++j)temp.push(0)
            board.push(temp)
        }
    } else line.split('').forEach((e, i) => {
        e = parseInt(e)
        if (e) board[ln - 1][i] = [big, 1]
        else board[ln - 1][i] = [big, 0]
    })
    ln++
}

const dijkstra = _ => {
    board[0][0] = [0, 0]
    pq.push([board[0][0][0], [0, 0]])
    while (!pq.isEmpty()) {
        [crush, [r, c]] = pq.pop()
        if (crush > board[r][c][0]) continue;
        for (let i = 0; i < 4; ++i) {
            nr = r + dr[i], nc = c + dc[i]
            if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                ncrush = crush
                if (board[nr][nc][1]) ncrush++
                if (board[nr][nc][0] > ncrush) {
                    board[nr][nc][0] = ncrush
                    pq.push([ncrush, [nr, nc]])
                }
            }
        }
    }
}

const solve = _ => {
    dijkstra()
    console.log(board[n - 1][m - 1][0])
}

rl
    .on('line', input)
    .on('close', solve)
