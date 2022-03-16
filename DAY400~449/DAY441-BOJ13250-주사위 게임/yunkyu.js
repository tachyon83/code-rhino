const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N;

rl.on('line', (line) => {
  N = parseInt(line);
  rl.close();
}).on('close', () => {
  const dp = new Array(N + 1).fill(0);
  dp[1] = 1;
  for (let i = 2; i <= N; i++) {
    for (let j = 1; j <= 6; j++) {
      if (i <= j) dp[i] += 1 / 6;
      else dp[i] += (dp[i - j] + 1) / 6; // 한번 던졌으므로 + 1
    }
  }

  console.log(dp[N]);
});
