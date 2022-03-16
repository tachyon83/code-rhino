const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [];

rl.on('line', (line) => {
  inputs.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  const [h, w] = inputs[0];
  let ans = 0;
  for (let i = h; i >= 0; i--) {
    // 가장 높은 높이부터
    let prev;
    for (let j = 0; j < w; j++) {
      if (i <= inputs[1][j]) {
        // i보다 높은 높이라면
        if (prev !== undefined) {
          // 두 블록사이에 공간이 있다면 공간만큼 빗물이 찬다
          ans += j - prev - 1;
        }
        prev = j; // 이전 블록 기록
      }
    }
  }

  console.log(ans);
});
