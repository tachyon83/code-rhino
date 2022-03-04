const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N,
  M,
  K,
  arr = [],
  visited = [],
  res = [];

const dy = [0, -1, 1, 0, 0],
  dx = [0, 0, 0, -1, 1];

rl.on('line', (line) => {
  if (!N) [N, M, K] = line.split(' ').map((a) => parseInt(a));
  else {
    arr.push(line.split(' ').map((a) => parseInt(a)));
    visited.push(new Array(M).fill(false));
  }
}).on('close', () => {
  const v = [];
  // 배열에 격자판의 좌표와 정수를 모두 집어넣는다
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      v.push([i, j, arr[i][j]]);
    }
  }

  // 현재 좌표와 인접한 칸에 대하여 방문했는지 확인
  const checkAround = (y, x) => {
    for (let i = 0; i < 5; i++) {
      const ny = y + dy[i],
        nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
      if (visited[ny][nx]) return true;
    }

    return false;
  };

  const dfs = (curr, sum, cnt) => {
    if (cnt === K) {
      // 칸 K개를 모두 골랐을때
      res.push(sum);
      return;
    }

    for (let i = curr + 1; i < v.length; i++) {
      const [y, x, value] = v[i];
      if (!checkAround(y, x)) {
        // 고를수 있는 칸이라면
        visited[y][x] = true;
        dfs(i, sum + value, cnt + 1);
        visited[y][x] = false;
      }
    }
  };

  // 격자판에서 고를수 있는 모든 조합을 탐색
  for (let i = 0; i < v.length; i++) {
    const [y, x, value] = v[i];
    visited[y][x] = true;
    dfs(i, value, 1);
    visited[y][x] = false;
  }

  res.sort((a, b) => b - a);
  // 정렬후 최댓값 출력
  console.log(res[0]);
});
