// 시험감독
// https://www.acmicpc.net/problem/13458

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, arr, B, C;

const input = (line) => {
  if (!N) N = parseInt(line);
  else if (!arr) arr = line.split(' ').map((i) => parseInt(i));
  else [B, C] = line.split(' ').map((i) => parseInt(i));
};

const solve = () => {
  let cnt = arr.length; // 시험장 수 만큼 총 감독관 필요
  for (let i = 0; i < arr.length; i++) {
    const res = arr[i] - B; // 총 감독관이 감시하는 응시자를 제외
    if (res <= 0) continue;
    cnt += Math.ceil(res / C); // 나머지 응시자를 감시하는데 필요한 부감독관 수
  }

  console.log(cnt);
};

rl.on('line', (line) => input(line)).on('close', solve);
