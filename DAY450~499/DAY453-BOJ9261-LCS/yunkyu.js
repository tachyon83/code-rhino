const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let s1, s2, dp;

rl.on('line', (line) => {
  if (!s1) s1 = line;
  else {
    s2 = line;
    rl.close();
  }
}).on('close', () => {
  s1 = ' ' + s1;
  s2 = ' ' + s2;
  const n1 = s1.length,
    n2 = s2.length;
  dp = [];
  for (let i = 0; i < n1; i++) {
    dp.push(new Array(n2).fill(0));
  }
  //dp[a][b] => s1의 a번째 index && s2의 b번째 index까지의 LCS 최대 길이

  for (let i = 1; i < n1; i++) {
    for (let j = 1; j < n2; j++) {
      if (s1[i] === s2[j]) {
        // 문자가 같을시 s1[i] && s2[j]까지의 LCS최대 길이는 이전 s1[i-1] && s2[j-1]까지의 LCS최대길이에 + 1
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        // 문자가 다를시 s1[i] && s2[j-1] 과 s1[i-1] && s2[j]까지의 LCS최대길이중 큰 것을 택한다.
        dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  console.log(dp[n1 - 1][n2 - 1]);
});
