const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  arr = [],
  dp = [],
  check = [],
  idx = 0,
  l = 1;

const solve = () => {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
        // 이전보다 값이 작고 현재까지의 LIS의 길이보다 이전까지의 LIS길이 + 1이 클때
        dp[i] = dp[j] + 1;
        check[i] = j; // check배열에 거쳐온 경로 저장
      }
    }
    if (l < dp[i]) {
      // LIS의 가장 끝자리 index 저장
      l = dp[i];
      idx = i;
    }
  }
};

// 끝에서부터 거쳐온 경로를 역추적해 부분 수열 출력
const backtrack = (i) => {
  if (i === -1) return;
  backtrack(check[i]); // 이전 원소로
  process.stdout.write(String(arr[i]) + ' ');
};

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else arr = line.split(' ').map((a) => parseInt(a));
}).on('close', () => {
  // 초기화
  dp = new Array(n).fill(1);
  check = new Array(n).fill(-1);

  solve();
  console.log(l);
  backtrack(idx);
});
