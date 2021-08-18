const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let dp, N, K;
const mod = 1000000000;

function init() {
  dp = new Array(K + 1);
  for (let i = 0; i <= K; i++) {
    dp[i] = new Array(N + 1).fill(0);
  }

  for (let i = 0; i <= N; i++) {
    dp[1][i] = 1;
  }
}

rl.on('line', (line) => {
  [N, K] = line.split(' ').map((num) => parseInt(num));
  rl.close();
}).on('close', () => {
  init();
  for (let i = 2; i <= K; i++) {
    for (let j = 0; j <= N; j++) {
      for (let l = 0; l <= j; l++) {
        dp[i][j] += dp[i - 1][j - l];
      }
      dp[i][j] %= mod;
    }
  }

  console.log(dp[K][N] % mod);
  process.exit();
});
