const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, k;

const binarySearch = () => {
  let start = 1,
    end = k;

  let ans = 0;

  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    let cnt = 0;
    for (let i = 1; i <= n; i++) {
      // i번째 행에서 mid값을 i로 나눈 몫이 i보다 같거나작은값의 개수, 열의 최댓값인 n을 넘는다면 n이 돼야함
      cnt += Math.min(Math.floor(mid / i), n);
    }

    if (cnt >= k) {
      // 개수가 더 많다면 값을 감소시킴
      ans = mid;
      end = mid - 1;
    } else {
      // 개수가 적다면 값을 증가시킴
      start = mid + 1;
    }
  }

  return ans;
};

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else k = parseInt(line);
}).on('close', () => {
  console.log(binarySearch());
});
