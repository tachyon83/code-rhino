const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  cache = [];

const MAX = 1 << 15;

const dp = () => {
  // dp[2<<15][4] N이 최대 (2 << 15) - 1 까지, [4]:최대 4개의 제곱수의 합이 가능
  for (let i = 0; i < MAX; i++) {
    cache.push(new Array(4).fill(0));
  }

  for (let i = 1; i * i < MAX; i++) {
    cache[i * i][0] = 1; // 자체가 제곱수일 경우에 1개의 제곱수로
    for (let j = i * i; j < MAX; j++) {
      // i*i 보다 크거나 같은 모든 수들에 대해 i*i 를 뺀 수의 경우의 수를 더한다
      cache[j][1] += cache[j - i * i][0]; // j의 2개의 제곱수로 이루어진 경우  => i*i를 뺀 수의 (2-1)1개의 제곱수로 이루어진 경우의 수를 더해준다
      cache[j][2] += cache[j - i * i][1];
      cache[j][3] += cache[j - i * i][2];
    }
  }
};

rl.on('line', (line) => {
  if (parseInt(line) === 0) rl.close();
  inputs.push(parseInt(line));
}).on('close', () => {
  dp();
  for (let i = 0; i < inputs.length; i++) {
    let ans = 0;
    for (let j = 0; j < 4; j++) {
      ans += cache[inputs[i]][j];
    }
    console.log(ans);
  }
});
