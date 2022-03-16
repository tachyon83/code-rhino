const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N,
  dp = [];

rl.on('line', (line) => {
  N = parseInt(line);
  rl.close();
}).on('close', () => {
  for (let i = 0; i < N; i++) {
    dp.push(new Array(10).fill(0));
  }

  // 한 자리수인 오르막수는 (1,2,3,...,10)으로 총 10개
  for (let i = 0; i < 10; i++) {
    dp[0][i] = 1;
  }

  for (let i = 1; i < N; i++) {
    for (let j = 0; j < 10; j++) {
      for (k = 0; k <= j; k++) {
        dp[i][j] += dp[i - 1][k] % 10007; // i + 1 자릿수가 j인 오르막수는 이전 자릿수가 j보다 같거나 작은 수를 가진 오르막수 개수의 합이다.
      }
    }
  }

  let ans = 0;
  for (let i = 0; i < 10; i++) {
    ans += dp[N - 1][i];
  }

  console.log(ans % 10007);
});
