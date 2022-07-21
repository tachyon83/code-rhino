const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const sudoku = [],
  rows = [],
  columns = [],
  squares = [];

const input = (line) => {
  sudoku.push(line.split(' ').map((a) => parseInt(a)));
};

// 스도쿠 가로, 세로, 정사각형에 num값이 있는지 확인
const check = (y, x, num) => {
  if (
    rows[y].has(num) ||
    columns[x].has(num) ||
    squares[Math.floor(y / 3)][Math.floor(x / 3)].has(num)
  )
    return false;
  else return true;
};

// 스도쿠 보드를 출력
const printSudoku = () => {
  sudoku.forEach((s) => {
    console.log(s.join(' '));
  });
};

const DFS = (idx, empty) => {
  if (idx === empty.length) {
    // 스도쿠 보드를 모두 채웠다면
    return true;
  }

  const { y, x } = empty[idx];
  for (let i = 1; i <= 9; i++) {
    if (check(y, x, i)) {
      // 숫자를 할당한다
      sudoku[y][x] = i;
      rows[y].add(i);
      columns[x].add(i);
      squares[Math.floor(y / 3)][Math.floor(x / 3)].add(i);
      // 다음 단계로
      if (DFS(idx + 1, empty)) return true;
      // 숫자를 할당하기 이전으로
      sudoku[y][x] = 0;
      rows[y].delete(i);
      columns[x].delete(i);
      squares[Math.floor(y / 3)][Math.floor(x / 3)].delete(i);
    }
  }

  return false;
};

const solve = () => {
  for (let i = 0; i < 9; i++) {
    rows.push(new Set());
    columns.push(new Set());
  }
  for (let i = 0; i < 3; i++) {
    squares[i] = [];
    for (let j = 0; j < 3; j++) {
      squares[i].push(new Set());
    }
  }

  const empty = [];
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      const value = sudoku[i][j];
      if (value) {
        // 가로, 세로, 정사각형에 이미 존재하는 숫자를 set에 기록
        rows[i].add(value);
        columns[j].add(value);
        squares[Math.floor(i / 3)][Math.floor(j / 3)].add(value);
      } else {
        // 빈 공간의 좌표를 저장한다
        empty.push({ y: i, x: j });
      }
    }
  }

  DFS(0, empty);
  printSudoku();
};

rl.on('line', input).on('close', solve);
