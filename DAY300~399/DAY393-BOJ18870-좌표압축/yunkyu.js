const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, arr;
const obj = {};

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else arr = line.split(' ').map((a) => parseInt(a));
}).on('close', () => {
  const set = Array.from(new Set([...arr])).sort((a, b) => a - b); // 중복 제거 위해 set 사용 => 배열로 변환후 정렬
  for (let i = 0; i < set.length; i++) {
    obj[set[i]] = i; // 오름차순에서 idx가 좌표압축 값
  }

  const answer = [];
  for (let i = 0; i < arr.length; i++) {
    answer.push(obj[arr[i]]);
  }

  console.log(answer.join(' '));
});
