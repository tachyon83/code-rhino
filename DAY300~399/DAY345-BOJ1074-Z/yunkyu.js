const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs, n, r, c;
const dy = [0, 0, 1, 0];
const dx = [0, 1, -1, 1];
let cnt = -1;

const solve = (y, x, N) => {
  const l = Math.pow(2, N); // 가로 세로 길이
  // (r,c)가 현재 범위보다 큰범위에 있을때
  if (y + l < r || x + l < c) {
    cnt += l * l;
    return;
  }
  //(r,c)가 현재 구간보다 이전에 있을때
  if (y > r && x > c) return;
  if (N === 1) {
    // 가로 세로가 2일때는 Z모양 순으로 수를 센다
    for (let i = 0; i < 4; i++) {
      ++cnt;
      y += dy[i];
      x += dx[i];
      if (y === r && x === c) {
        // (r,c)라면 출력
        console.log(cnt);
        return;
      }
    }
    return;
  }

  // N이 1보다 크다면 4등분
  solve(y, x, N - 1);
  solve(y, x + l / 2, N - 1);
  solve(y + l / 2, x, N - 1);
  solve(y + l / 2, x + l / 2, N - 1);
};

rl.on('line', (line) => {
  inputs = line.split(' ').map((a) => parseInt(a));
  rl.close();
}).on('close', () => {
  (n = inputs[0]), (r = inputs[1]), (c = inputs[2]);
  solve(0, 0, n);
});
