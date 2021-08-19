const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, k;

rl.on('line', (line) => {
  [n, k] = line.split(' ').map((a) => parseInt(a));
  rl.close();
}).on('close', () => {
  const arr = new Array(n + 1);
  for (let i = 2; i <= n; i++) {
    // 2부터 n까지 배열에 삽입
    arr[i] = i;
  }

  let cnt = 0;
  for (let i = 2; i <= n; i++) {
    for (let j = i; j <= n; j += i) {
      if (arr[j] === 0) continue; // 지워진 수라면 다음 숫자로
      arr[j] = 0; // 수를 지움

      if (++cnt === k) {
        // k번째 지워지는 숫자 출력
        console.log(j);
        process.exit();
      }
    }
  }
});
