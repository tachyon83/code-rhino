const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

class Queue {
  constructor() {
    this.array = [];
  }
  enqueue(data) {
    this.array.push(data);
  }
  dequeue() {
    return this.array.shift();
  }
  head() {
    return this.array[0];
  }
  empty() {
    if (this.array.length === 0) {
      return true;
    } else return false;
  }
}

let n,
  arr = [],
  visit = [],
  mn = 200,
  mx = 0;

const dy = [-1, 1, 0, 0],
  dx = [0, 0, -1, 1];

const init = () => {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      visit[i][j] = true;
    }
  }
};

const BFS = (diff) => {
  const q = new Queue();

  for (let i = mn; i <= mx - diff; i++) {
    init(); // visit 초기화

    for (let j = 0; j < n; j++) {
      for (let k = 0; k < n; k++) {
        if (i <= arr[j][k] && arr[j][k] <= i + diff) {
          // (i ~ i + diff)범위안의 값들만 이동가능하게 정함
          visit[j][k] = false;
        }
      }
    }

    q.enqueue([0, 0]);
    while (!q.empty()) {
      const fr = q.head();
      const y = fr[0];
      const x = fr[1];
      q.dequeue();

      if (visit[y][x] === true) continue; // 방문했거나 갈수없는곳이라면
      visit[y][x] = true;
      if (y === n - 1 && x === n - 1) return true; // 도착

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];
        if (0 <= ny && ny < n && 0 <= nx && nx < n) {
          // 범위안이라면 이동
          q.enqueue([ny, nx]);
        }
      }
    }
  }

  return false;
};

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else arr.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      // 배열의 최대 최소값 구함
      mn = Math.min(mn, arr[i][j]);
      mx = Math.max(mx, arr[i][j]);
    }
  }

  for (let i = 0; i < n; i++) {
    visit.push(new Array(n).fill(true));
  }

  let start = 0,
    end = mx - mn; // 수의 차이가 가장클때

  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (BFS(mid)) {
      // diff가 mid값일때 도착할수있다면 더 작은 구간에서 diff값 탐색
      end = mid - 1;
    } else {
      // 도착하지 못한다면 더 큰 구간에서 diff값 탐색
      start = mid + 1;
    }
  }

  console.log(end + 1);
});
