const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  t,
  n,
  m,
  sa = [],
  sb = [];

const init = () => {
  // 입출력 정리
  t = inputs[0];
  n = inputs[1];
  m = inputs[3];
  // 부분합을 모두 구한다
  for (let i = 0; i < n; i++) {
    let sum = inputs[2][i];
    sa.push(sum);
    for (let j = i + 1; j < n; j++) {
      sum += inputs[2][j];
      sa.push(sum);
    }
  }
  for (let i = 0; i < m; i++) {
    let sum = inputs[4][i];
    sb.push(sum);
    for (let j = i + 1; j < m; j++) {
      sum += inputs[4][j];
      sb.push(sum);
    }
  }
};

const upperBound = (num) => {
  // num을 처음으로 초과하는 index
  let start = 0,
    end = sb.length;

  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    if (sb[mid] <= num) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }

  return end;
};

const lowerBound = (num) => {
  // num이상인 첫 index
  let start = 0,
    end = sb.length;

  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    if (sb[mid] < num) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }

  return end;
};

rl.on('line', (line) => {
  inputs.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  init();

  // 부분합 정렬
  sa.sort((a, b) => a - b);
  sb.sort((a, b) => a - b);

  let cnt = 0;
  for (let i = 0; i < sa.length; i++) {
    // t에서 sa의 i번째 부분합을 제외한 값을 sb의 부분합에서 찾는다
    cnt += upperBound(t - sa[i]) - lowerBound(t - sa[i]);
  }

  console.log(cnt);
});
