// N-Queen
// https://www.acmicpc.net/problem/9663

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n;

const input = (line) => {
  n = parseInt(line);
};

const solve = () => {
  const arr = new Array(n).fill(0); // n행의 퀸 index 저장
  let cnt = 0;

  const check = (row, n) => {
    // 이전 행의 퀸들과 대각선, 세로로 공격할 수 있는지 확인
    for (let i = 0; i < row; i++) {
      if (n === arr[i] || Math.abs(n - arr[i]) === row - i) return false;
    }
    return true;
  };

  const DFS = (idx) => {
    if (idx === n) {
      // 퀸을 모두 놓았다면
      cnt++;
      return;
    }

    for (let i = 0; i < n; i++) {
      if (!check(idx, i)) continue;
      arr[idx] = i;
      DFS(idx + 1);
    }
  };

  DFS(0);

  console.log(cnt);
};

rl.on('line', (line) => input(line)).on('close', solve);
