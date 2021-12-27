const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let D, K;
let a = 0,
  b = 0;

const solve = (day) => {
  if (day === 2) {
    b++;
    return;
  } else if (day === 1) {
    a++;
    return;
  }

  solve(day - 2);
  solve(day - 1);
};

rl.on('line', (line) => {
  [D, K] = line.split(' ').map((a) => parseInt(a));
}).on('close', () => {
  solve(D); // D날을 어제와 그저께로 나누어서 모두 2일째와 1일째로 나눈다 (a => 1일째의 수, b => 2일째의 수)

  for (let i = 1; i <= K; i++) {
    for (let j = i; j <= K; j++) {
      const sum = a * i + b * j; // ax + by꼴 다항식
      if (sum > K) break;
      if (sum === K) {
        // 다항식에 맞는 i와 j를 찾았다면 출력하고 종료
        console.log(i);
        console.log(j);
        process.exit();
      }
    }
  }
});
