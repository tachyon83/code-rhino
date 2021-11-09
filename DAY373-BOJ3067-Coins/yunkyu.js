const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  N,
  M,
  coins;
let dp = new Array(10001);

rl.on('line', (line) => {
  inputs.push(line);
}).on('close', () => {
  const T = parseInt(inputs[0]);
  for (let i = 0; i < T; i++) {
    N = parseInt(inputs[i * 3 + 1]);
    coins = inputs[i * 3 + 2].split(' ').map((a) => parseInt(a));
    M = parseInt(inputs[i * 3 + 3]);
    dp.fill(0);

    dp[0] = 1;
    for (let i = 0; i < N; i++) {
      for (let j = 1; j <= M; j++) {
        // 현재 금액에서 동전값을 뺀 금액의 가짓수를 더해준다. 
        if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
      }
    }

    console.log(dp[M]);
  }
});
