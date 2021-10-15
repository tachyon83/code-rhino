const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  inputs = [],
  dp,
  max = 0;

const solve = () => {
  for (let i = 0; i < n; i++) {
    const [t, p] = inputs[i];

    max = Math.max(dp[i], max); // i일 전 까지 번 최대 금액
    if (i + t - 1 < n) {
      // n일 안에 상담할수 있는 경우만
      dp[i + t] = Math.max(dp[i + t], max + p); // MAX(현재까지 알고있는 i+t일 까지 번 최대 금액, i일까지 번 최대 금액 + i일에 번 금액)
    }
  }
  max = Math.max(max, dp[n]); // 마지막날까지 상담하였다면 갱신
  console.log(max);
};

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else inputs.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  dp = new Array(n + 1).fill(0);
  solve();
});
