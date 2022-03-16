const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  n,
  arr,
  limit,
  psum,
  dp = [];

rl.on('line', (line) => {
  inputs.push(line);
}).on('close', () => {
  n = parseInt(inputs[0]);
  arr = inputs[1].split(' ').map((a) => parseInt(a));
  limit = parseInt(inputs[2]);

  psum = new Array(n + 1).fill(0);
  // 손님 수의 누적합을 구한다.
  for (let i = 1; i <= n; i++) {
    psum[i] = arr[i - 1];
    psum[i] += psum[i - 1];
  }

  for (let i = 0; i < 4; i++) {
    dp.push(new Array(n + 1).fill(0));
  }

  // dp[i][j] => i번째 기관차가 j칸까지 끌고갈때 최대 손님수
  for (let i = 1; i <= 3; i++) {
    for (let j = i * limit; j <= n; j++) {
      /* 
      현재 기관차가 j칸까지 끌수 있는 손님의 수 + i-1 번째 기관차가 현재 기관차가 끄는 객차 이전까지 끈 손님수 
      와 현재 기관차가 j-1칸까지 끌수 있는 손님의 수 중 큰 값을 취한다.
      */
      dp[i][j] = Math.max(
        dp[i][j - 1],
        dp[i - 1][j - limit] + psum[j] - psum[j - limit]
      );
    }
  }

  console.log(dp[3][n]);
});
