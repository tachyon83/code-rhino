const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  arr = [],
  dp = [],
  h,
  w;

rl.on('line', (line) => {
  inputs.push(line.trim());
}).on('close', () => {
  [h, w] = inputs[0].split(' ').map((a) => parseInt(a));
  for (let i = 1; i < inputs.length; i++) {
    arr.push(inputs[i].split(''));
  }

  for (let i = 0; i < h; i++) {
    dp.push(new Array(w).fill(-1));
    for (let j = 0; j < w; j++) {
      if (j === 0 && arr[i][j] !== 'c') continue; // 처음이고 구름이 없다면 -1
      if (arr[i][j] === 'c') dp[i][j] = 0;
      // 구름의 시작지점일시 0
      else if (dp[i][j - 1] === -1) {
        // 이전 위치에 구름이 오지 않는다면
        continue;
      } else dp[i][j] = dp[i][j - 1] + 1; // 이전 위치에서의 구름 도착시간 + 1
    }
  }

  for (let i = 0; i < h; i++) {
    console.log(dp[i].join(' '));
  }
});
