const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  ouput: process.stdout,
});

let n,
  arr = [];

const solve = (r, c, l) => {
  if (l === 3) {
    // 삼각형의 길이가 3일때 출력
    arr[r][c] = '*'; // 첫번째 줄
    arr[r + 1][c - 1] = '*'; // 두번째 줄
    arr[r + 1][c + 1] = '*';
    for (let i = c - 2; i <= c + 2; i++) arr[r + 2][i] = '*'; // 세번째 줄

    return;
  }

  solve(r, c, l / 2); // 첫번째 삼각형의 꼭짓점
  solve(r + l / 2, c - l / 2, l / 2); // 두번째 삼각형의 꼭짓점
  solve(r + l / 2, c + l / 2, l / 2); // 세번째 삼각형의 꼭짓점
};

rl.on('line', (line) => {
  n = parseInt(line);
  rl.close();
}).on('close', () => {
  const row = n,
    col = n * 2 - 1;
  // 초기화
  for (let i = 0; i < row; i++) {
    arr.push(new Array(col).fill(' '));
  }

  solve(0, n - 1, n); // 삼각형의 세로 길이와 가장 위 꼭짓점 좌표

  for (let i = 0; i < row; i++) {
    console.log(arr[i].join('')); // arr[i]배열을 string으로 변환
  }
});
