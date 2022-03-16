// 오답

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  m,
  arr = [],
  dp = [],
  visited = [];

const dy = [0, 0, 1];
const dx = [-1, 1, 0];
const INF = -987654321;

const dfs = (y, x, dir) => {
  if (y === n - 1 && x === m - 1) return arr[y][x]; // 도착시 도착점의 가치 반환
  if (dp[y][x][dir] !== INF) return dp[y][x][dir]; // 이미 구한값은 바로 반환

  let maxV = INF;
  for (let i = 0; i < 3; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
      if (visited[ny][nx] === false) {
        visited[ny][nx] = true;
        maxV = Math.max(maxV, dfs(ny, nx, i)); // 3가지 방향중 가장 큰 가치를 얻을수 있는 방향
        visited[ny][nx] = false;
      }
    }
  }

  dp[y][x][dir] = maxV + arr[y][x]; // 현재 가치를 더해준다
  return dp[y][x][dir];
};

rl.on('line', (line) => {
  if (!n) [n, m] = line.split(' ').map((a) => parseInt(a));
  else {
    arr.push(line.split(' ').map((a) => parseInt(a)));
    dp.push(new Array(m).fill(new Array(3).fill(INF)));
    visited.push(new Array(m).fill(false));
  }
}).on('close', () => {
  visited[0][0] = true;
  console.log(dfs(0, 0, 0));
  console.log(dp);
});
