const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  n,
  m;

rl.on('line', (line) => {
  inputs.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  [n, m] = inputs[0];

  if (n < m) {
    console.log(n);
    process.exit();
  }

  let start = 0,
    end = 2e9 * 30,
    t;

  // 마지막 아이가 탄 시간을 찾는다
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    let cnt = m;
    for (let i = 0; i < m; i++) {
      // mid 시간까지 탈수 있는 아이들의 수
      cnt += Math.floor(mid / inputs[1][i]);
    }

    if (cnt >= n) {
      t = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  let cnt = m;
  for (let i = 0; i < m; i++) {
    // t시간 바로 이전까지 탄 아이들의 수를 구함
    cnt += Math.floor((t - 1) / inputs[1][i]);
  }

  for (let i = 0; i < m; i++) {
    // t시간에 탄 아이의 수를 구한다
    if (t % inputs[1][i] === 0) cnt++;
    if (cnt === n) {
      // 마지막 아이라면 현재 놀이기구의 번호 출력
      console.log(i + 1);
      process.exit();
    }
  }
});
