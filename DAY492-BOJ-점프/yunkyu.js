// 점프
// https://www.acmicpc.net/problem/1890
// 배운점: Javascript에서 Number 자료형의 최대 크기는 2^53 - 1으로 경로의 개수가 2^63 - 1
// 이므로 BigInt 자료형을 사용해야 한다. BigInt 사용시 BigInt간 끼리만 연산이 가능하고
// .toString()을 통해 맨 뒤에 붙어있는 BigInt를 표시하는 n을 제거 가능하다.

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  board = [];

const input = (line) => {
  if (!n) n = parseInt(line);
  else board.push(line.split(' ').map((i) => parseInt(i)));
};

const solve = () => {
  const dp = Array.from(Array(n), () => new Array(n).fill(BigInt(0))); // BigInt자료형으로 초기화
  const dy = [0, 1];
  const dx = [1, 0];

  const DFS = (y, x) => {
    if (y === n - 1 && x === n - 1) return 1; // 목표지점 도착시
    if (board[y][x] === 0) return 0; // 이동 불가능
    if (dp[y][x]) return dp[y][x];

    // 오른쪽과 아래로 각각 이동
    for (let i = 0; i < 2; i++) {
      const ny = y + dy[i] * board[y][x];
      const nx = x + dx[i] * board[y][x];
      if (ny >= n || nx >= n) continue; // 보드를 넘어가지 않는다면
      dp[y][x] += BigInt(DFS(ny, nx)); // 가능한 경로의 수 누적
    }

    return dp[y][x];
  };

  console.log(DFS(0, 0).toString());
};

rl.on('line', (line) => input(line)).on('close', solve);
