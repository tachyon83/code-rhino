const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  cnt = 0,
  inputs,
  dp;

const input = (line) => {
  if (!n) {
    n = parseInt(line);
    inputs = new Array(n);
  } else {
    inputs[cnt] = line.split(' ').map((num) => parseInt(num));
    cnt++;
  }
};

const solve = () => {
  // dp 배열 초기화
  dp = new Array(n);
  for (let i = 0; i < n; i++) {
    dp[i] = new Array(3).fill(0);
  }

  let ans = 1000001;
  for (let i = 0; i < 3; i++) {
    dp[0][0] = 1000001;
    dp[0][1] = 1000001;
    dp[0][2] = 1000001;
    dp[0][i] = inputs[0][i]; // i번째 color를 첫번째 집으로 설정 나머지 color는 고를수 없게 큰 값으로 초기화
    for (let j = 1; j < n; j++) {
      // 이전의 color와 다른 color로 칠한다
      dp[j][0] = Math.min(dp[j - 1][1], dp[j - 1][2]) + inputs[j][0];
      dp[j][1] = Math.min(dp[j - 1][0], dp[j - 1][2]) + inputs[j][1];
      dp[j][2] = Math.min(dp[j - 1][0], dp[j - 1][1]) + inputs[j][2];
    }

    for (let j = 0; j < 3; j++) {
      if (i == j) continue; // 첫번쨰 집의 color는 불가능
      ans = Math.min(ans, dp[n - 1][j]);
    }
  }
  console.log(ans);
  process.exit();
};

rl.on('line', input).on('close', solve);
