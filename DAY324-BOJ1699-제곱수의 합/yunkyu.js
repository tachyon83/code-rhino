const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  dp = [];

const input = (line) => {
  n = parseInt(line);
  rl.close();
};

const func = () => {
  dp = new Array(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (let i = 2; i <= n; i++) {
    const sq = Math.sqrt(i); // 제곱근을 구한다
    dp[i] = i; // 1로만 구성됐을시에 i는 i개의 1로 구성
    //  1부터 제곱근까지
    for (let j = 1; j <= sq; j++) {
      dp[i] = Math.min(dp[i], 1 + dp[i - j * j]); //정수 j의 제곱을 더했을때와 비교하여 최소값을 찾는다
    }
  }

  console.log(dp[n]);
  process.exit();
};

rl.on('line', input).on('close', func);
