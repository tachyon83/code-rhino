const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  ans = 1,
  num = [],
  dp = [];

const input = (line) => {
  if (!n) n = parseInt(line);
  else num.push(parseInt(line));
};

const func = () => {
  dp = new Array(n);
  // LIS의 길이를 구함
  for (let i = 0; i < n; i++) {
    dp[i] = 1;
    for (let j = 0; j < i; j++) {
      if (num[i] > num[j]) {
        // 이전 값들보다 크다면 이전의 LIS중 가장큰 값 + 1 을 취함
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
    ans = Math.max(ans, dp[i]);
  }

  console.log(n - ans); // LIS를 제외한 나머지의 개수가 위치를 옮겨야하는 수
};

rl.on('line', input).on('close', func);
