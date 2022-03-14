const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N,
  arr = [],
  check = [];
rl.on('line', (line) => {
  if (!N) N = parseInt(line);
  else {
    arr.push(line.split(' ').map((a) => parseInt(a)));
    check.push(new Array(N).fill(true));
  }
}).on('close', () => {
  // floyd warshal 을 통해 최단거리 도출
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      for (let k = 0; k < N; k++) {
        if (i === j) continue;
        if (i === k || j === k) continue;
        if (arr[i][j] > arr[i][k] + arr[k][j]) {
          // 구해져있는 최소이동시간보다 더 짧은 시간에 이동할 수 있는 경우
          console.log('-1');
          process.exit();
        }
        if (arr[i][j] === arr[i][k] + arr[k][j]) {
          // i => j 경로를 k를 통하여 최단 시간에 이동할 수 있기 때문에 경로에서 제외
          check[i][j] = false;
          break;
        }
      }
    }
  }
  let cnt = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (check[i][j]) cnt += arr[i][j];
    }
  }
  console.log(cnt / 2); // i -> j 와  j -> i  경로가 중복으로 더해졌기 때문에 2를 나눈다.
});
