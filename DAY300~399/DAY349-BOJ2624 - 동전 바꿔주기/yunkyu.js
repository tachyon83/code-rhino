const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  T,
  k,
  coin = [],
  dp;

rl.on('line', (line) => {
  inputs.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  T = inputs[0][0];
  k = inputs[1][0];
  for (let i = 0; i < k; i++) {
    coin.push(inputs[i + 2]);
  }
  dp = new Array(T + 1).fill(0);
  dp[0] = 1; // 0원이 되면 성공

  // k개의 동전 사용
  for (let i = 0; i < k; i++) {
    const [money, cnt] = coin[i];
    for (let j = T; j >= money; j--) {
      for (let l = 1; l <= cnt; l++) {
        // 현재 금액에서 (동전 금액 * 동전 개수) 만큼 뺀다
        if (j - money * l < 0) break; // 0원 이하일시 불가
        dp[j] += dp[j - money * l]; // 남은 돈의 가짓수만큼 더해준다
      }
    }
  }

  console.log(dp[T]);
});
