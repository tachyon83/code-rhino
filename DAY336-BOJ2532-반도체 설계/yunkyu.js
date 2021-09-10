const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  inputs,
  arr = [],
  cnt = 0;

const lowerBound = (num) => {
  let start = 0,
    end = cnt;

  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (arr[mid] < num) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  arr[start] = num; // 이진탐색으로 찾은 위치에 삽입
};

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else inputs = line.split(' ').map((a) => parseInt(a));
}).on('close', () => {
  arr.push(inputs[cnt]);
  for (let i = 1; i < n; i++) {
    if (arr[cnt] < inputs[i]) {
      // arr 마지막 인덱스의 값보다 크다면 삽입
      arr.push(inputs[i]);
      cnt++;
    } else {
      // 작다면 arr배열에 들어가야할 위치를 이분탐색으로 찾는다
      lowerBound(inputs[i]);
    }
  }

  console.log(arr.length); // 최장 증가수열의 길이
});
