const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N,
  M,
  X,
  weight = [];

class PriorityQueue {
  constructor(minHeap) {
    this.heap = [];
    this.minHeap = minHeap;
  }
  _compare(a, b) {
    if (this.minHeap) {
      return a < b;
    } else {
      return a > b;
    }
  }
  _getParentIndex(n) {
    return Math.ceil(n / 2) - 1;
  }
  _getLeftChildIndex(n) {
    return 2 * n + 1;
  }
  _getRightChildIndex(n) {
    return 2 * n + 2;
  }
  size() {
    return this.heap.length;
  }
  isEmpty() {
    return this.size() === 0;
  }
  push(cost, item) {
    this.heap.push([cost, item]);
    let currIndex = this.size() - 1;
    while (
      0 < currIndex &&
      this._compare(
        this.heap[currIndex][0],
        this.heap[this._getParentIndex(currIndex)][0]
      )
    ) {
      this.heap[currIndex] = this.heap[this._getParentIndex(currIndex)];
      this.heap[this._getParentIndex(currIndex)] = [cost, item];
      currIndex = this._getParentIndex(currIndex);
    }
  }
  pop() {
    if (this.isEmpty()) return null;
    if (this.size() === 1) return this.heap.pop();
    const top = this.heap[0];
    const lastItem = this.heap.pop();
    this.heap[0] = lastItem;
    let currIndex = 0;
    while (this._getLeftChildIndex(currIndex) < this.size()) {
      if (this._getRightChildIndex(currIndex) < this.size()) {
        const compareIndex = this._compare(
          this.heap[this._getLeftChildIndex(currIndex)][0],
          this.heap[this._getRightChildIndex(currIndex)][0]
        )
          ? this._getLeftChildIndex(currIndex)
          : this._getRightChildIndex(currIndex);

        this.heap[currIndex] = this.heap[compareIndex];
        this.heap[compareIndex] = lastItem;
        currIndex = compareIndex;
      } else if (
        this._compare(
          this.heap[this._getLeftChildIndex(currIndex)][0],
          this.heap[currIndex][0]
        )
      ) {
        this.heap[currIndex] = this.heap[this._getLeftChildIndex(currIndex)];
        this.heap[this._getLeftChildIndex(currIndex)] = lastItem;
        currIndex = this._getLeftChildIndex(currIndex);
      } else break;
    }
    return top;
  }
}

const input = (line) => {
  if (!N) [N, M, X] = line.split(' ').map((i) => parseInt(i));
  else weight.push(line.split(' ').map((i) => parseInt(i)));
};

const dijkstra = (start, graph, ans) => {
  const dist = new Array(N + 1).fill(100 * N + 1);
  const pq = new PriorityQueue(true); // 우선순위큐 이용
  dist[start] = 0;
  pq.push(dist[start], start);

  while (!pq.isEmpty()) {
    const [currCost, curr] = pq.pop();
    if (currCost > dist[curr]) continue; // 이미 갱신된 지점은 스킵

    for (const [next, cost] of graph[curr]) {
      if (dist[next] > currCost + cost) {
        // 더 짧은 거리로 갱신 가능할 때
        dist[next] = currCost + cost;
        pq.push(dist[next], next);
      }
    }
  }

  for (let i = 1; i <= N; i++) {
    ans[i] += dist[i];
  }
};

const solve = () => {
  const graph1 = new Array(N + 1).fill(0).map((i) => []);
  const graph2 = new Array(N + 1).fill(0).map((i) => []);
  const ans = new Array(N + 1).fill(0);

  for (let i = 0; i < M; i++) {
    const [start, end, cost] = weight[i];
    // 2개의 단방향 그래프 생성
    graph1[start].push([end, cost]);
    graph2[end].push([start, cost]);
  }

  dijkstra(X, graph1, ans); // 가는 길에 대한 최단시간
  dijkstra(X, graph2, ans); // 오는 길에 대한 최단시간

  let result = 0;
  // 가는길과 오는길에 대한 최단 시간의 합중 가장 큰 것을 취한다
  for (let i = 1; i <= N; i++) {
    result = Math.max(result, ans[i]);
  }

  console.log(result);
};

rl.on('line', (line) => input(line)).on('close', solve);
