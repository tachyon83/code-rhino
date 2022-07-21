const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  m,
  board = [],
  // 상하좌우
  dy = [-1, 1, 0, 0],
  dx = [0, 0, -1, 1];

const input = (line) => {
  if (!n) [n, m] = line.split(' ').map((a) => parseInt(a));
  else board.push(line);
};

const move = (y, x, dir) => {
  // 공을 dir방향으로 이동시킨다.
  let ny, nx;
  while (true) {
    ny = y + dy[dir];
    nx = x + dx[dir];
    if (board[ny][nx] === 'O') {
      // 구멍에 빠졌을때
      return [ny, nx];
    }
    if (board[ny][nx] === '#') {
      // 벽에 막혔을때
      return [y, x];
    }

    y = ny;
    x = nx;
  }
};

const solve = () => {
  let by, bx, ry, rx, hy, hx;
  for (let i = 1; i <= n - 2; i++) {
    for (let j = 1; j <= m - 2; j++) {
      if (board[i][j] === 'B') {
        by = i;
        bx = j;
      }
      if (board[i][j] === 'R') {
        ry = i;
        rx = j;
      }
      if (board[i][j] === 'O') {
        hy = i;
        hx = j;
      }
    }
  }

  const dfs = (ry, rx, by, bx, cnt) => {
    if (cnt > 10) return 0; // 10번을 넘으면 실패
    if (ry === hy && rx === hx) return 1; // 빨간공이 구멍에 들어갔으면 성공

    for (let i = 0; i < 4; i++) {
      let [nry, nrx] = move(ry, rx, i);
      let [nby, nbx] = move(by, bx, i);
      if (nby === hy && nbx === hx) continue; // 파란공이 구멍에 빠졌을 때
      if (nry === nby && nrx === nbx) {
        // 파란공과 빨간공이 겹쳐지면 더 많이 이동한 공을 한칸 반대 방향으로 당겨야 한다.
        if (
          Math.abs(nry - ry) + Math.abs(nrx - rx) >
          Math.abs(nby - by) + Math.abs(nbx - bx)
        ) {
          nry -= dy[i];
          nrx -= dx[i];
        } else {
          nby -= dy[i];
          nbx -= dx[i];
        }
      }

      if (dfs(nry, nrx, nby, nbx, cnt + 1)) return 1;
    }

    return 0;
  };

  console.log(dfs(ry, rx, by, bx, 0));
};

rl.on('line', (line) => input(line)).on('close', solve);
