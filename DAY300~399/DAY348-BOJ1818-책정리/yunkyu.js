const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  arr = [],
  lis = [];

const lowerBound = (ind, num) => {
  let start = 0,
    end = ind;
  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    if (lis[mid] > num) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }

  return end;
};

const solve = () => {
  lis.push(arr[0]);
  let ind = 0;
  //  현재 책들의 배열순서에 대해
  for (let i = 1; i < n; i++) {
    if (lis[ind] < arr[i]) {
      // lis의 마지막 값보다 번호가 크다면 push
      lis.push(arr[i]);
      ind++;
    } else {
      // 작다면 lis에 들어가야 할 위치를 lower bound로 찾는다
      lis[lowerBound(ind, arr[i])] = arr[i];
    }
  }

  return lis.length;
};

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else arr = line.split(' ').map((a) => parseInt(a));
}).on('close', () => {
  console.log(n - solve()); // lis를 제외한 나머지가 순서를 바꿔야 할 책들
});
