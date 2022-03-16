const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  start,
  place = [],
  dp = [];

const dy = [0, 0, 0, -1, 1],
  dx = [0, 1, -1, 0, 0],
  INF = 200000 * 100000 + 1;

const input = (line) => {
  if (!n) n = parseInt(line);
  else if (!start) start = line.split(' ').map((a) => parseInt(a));
  else place.push(line.split(' ').map((a) => parseInt(a)));
};

const getDist = (fromX, fromY, toX, toY) => {
  // 두 좌표 사이의 거리를 구한다
  return Math.abs(toX - fromX) + Math.abs(toY - fromY);
};

const func = () => {
  for (let i = 0; i < n; i++) {
    // 배달해야할 케이크의 수만큼 크기5의 배열을 만듬
    dp.push(new Array(5).fill(INF));
  }

  // 시작 지점부터 첫번째 배달 가능지점까지의거리를 모두 구함
  for (let i = 0; i < 5; i++) {
    dp[0][i] = getDist(
      start[0],
      start[1],
      place[0][0] + dx[i],
      place[0][1] + dy[i]
    );
  }

  for (let i = 1; i < n; i++) {
    for (let j = 0; j < 5; j++) {
      for (let k = 0; k < 5; k++) {
        // 이전 배달 지점들로부터 다음 배달 지점들로의 최소 거리를 구한다
        dp[i][j] = Math.min(
          dp[i][j],
          dp[i - 1][k] +
            getDist(
              place[i - 1][0] + dx[k],
              place[i - 1][1] + dy[k],
              place[i][0] + dx[j],
              place[i][1] + dy[j]
            )
        );
      }
    }
  }

  let ans = dp[n - 1][0];
  for (let i = 1; i < 5; i++) {
    // 최소 거리를 구함
    ans = Math.min(ans, dp[n - 1][i]);
  }
  console.log(ans);
};

rl.on('line', input).on('close', func);
