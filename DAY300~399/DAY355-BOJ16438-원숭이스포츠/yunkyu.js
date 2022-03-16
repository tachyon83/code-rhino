// 원숭이 스포츠
// https://www.acmicpc.net/problem/16438

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  arr = [],
  idx = 0;

const dfs = (left, right, cnt) => {
  if (left > right || cnt === 7) {
    return;
  }
  const mid = Math.floor((left + right) / 2);
  if (left !== right) idx = Math.max(idx, cnt); // 바뀌는 경우가 있을때만

  // 반틈은 A
  for (let i = left; i <= mid; i++) {
    arr[cnt][i] = 'A';
  }
  // 반틈은 B
  for (let i = mid + 1; i <= right; i++) {
    arr[cnt][i] = 'B';
  }

  // 나눈 두팀을 또 나누어준다.
  dfs(left, mid, cnt + 1);
  dfs(mid + 1, right, cnt + 1);
};

rl.on('line', (line) => {
  n = parseInt(line);
  rl.close();
}).on('close', () => {
  for (let i = 0; i < 7; i++) {
    arr.push(new Array(n));
  }

  dfs(0, n - 1, 0);
  for (i = idx + 1; i < 7; i++) {
    // 모든 원숭이가 한번씩 만났다면 나머지 대진은 두팀으로 나누어주기만 하면 된다
    arr[i][0] = 'B';
  }

  for (i = 0; i < 7; i++) {
    let s = arr[i].join(''); // 배열을 문자열로
    console.log(s);
  }
});
