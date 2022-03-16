const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  d,
  p;

const dp = new Array(100001).fill(0);

rl.on('line', (line) => {
  inputs.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  [d, p] = inputs[0];
  inputs.shift();

  dp[0] = Infinity;
  for (let i = 0; i < p; i++) {
    const [l, w] = inputs[i];
    for (let j = d - l; j >= 0; j--) {
      if (j + l > d) continue; // 파이프의 길이를 넘어갔다면
      dp[j + l] = Math.max(Math.min(dp[j], w), dp[j + l]); // 현재 최대용량 vs min(파이프를 더하기 이전의 최대용량,새 파이프의 용량)
    }
  }

  console.log(dp[d]);
});
