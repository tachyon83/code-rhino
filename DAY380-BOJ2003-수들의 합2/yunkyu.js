const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, m, arr, prefix, sum;

rl.on('line', (line) => {
  if (!n) [n, m] = line.split(' ').map((a) => parseInt(a));
  else arr = line.split(' ').map((a) => parseInt(a));
}).on('close', () => {
  prefix = new Array(n);
  for (let i = 0; i < n; i++) prefix[i] = arr[i];

  // 배열의 구간합을 구한다
  for (let i = 1; i < n; i++) {
    prefix[i] += prefix[i - 1];
  }

  let cnt = 0;
  for (let i = 0; i < n; i++) {
    if (arr[i] > m) continue; // i번째 값이 m을 넘는다면 구간합을 알아볼 필요가 없다
    if (arr[i] === m) {
      // i번째 값 자체가 m 일 경우
      cnt++;
    } else if (arr[i] < m) {
      // m보다 작다면 i부터 끝까지의 구간합을 탐색
      for (let j = i + 1; j < n; j++) {
        if (i === 0) {
          sum = prefix[j];
        } else {
          sum = prefix[j] - prefix[i - 1];
        }
        if (sum === m) {
          // 구간합중에 m이 있을때
          cnt++;
          break;
        } else if (sum > m) {
          // 구간합이 m을 넘었다면
          break;
        }
      }
    }
  }

  console.log(cnt);
});
