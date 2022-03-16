const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let t = 0,
  n = 0,
  card = [],
  dp;

const input = (line) => {
  if (!t) t = parseInt(line);
  else if (!n) n = parseInt(line);
  else {
    n = 0;
    card.push(line.split(' ').map((a) => parseInt(a)));
  }
};

const play = (left, right, cnt, arr) => {
  if (left > right) return 0;
  if (dp[left][right]) return dp[left][right]; // 이미 구한 값이라면 반환

  if (cnt % 2 === 0) {
    // 근우 차례
    dp[left][right] = Math.max(
      arr[left] + play(left + 1, right, cnt + 1, arr),
      arr[right] + play(left, right - 1, cnt + 1, arr)
    ); // 근우 입장에서 최선은 왼쪽 카드와 오른쪽 카드중 더 큰값을 가지는 것
  } else {
    // 명우 차례
    dp[left][right] = Math.min(
      play(left + 1, right, cnt + 1, arr),
      play(left, right - 1, cnt + 1, arr)
    ); // 명우 입장에서 최선은 왼쪽,오른쪽 카드중 근우가 더 작은값을 가지는 것
  }

  return dp[left][right];
};

const init = () => {
  for (let i = 0; i < 1001; i++) {
    for (let j = 0; j < 1001; j++) {
      dp[i][j] = 0;
    }
  }
};

const func = () => {
  dp = new Array(1001);
  for (let i = 0; i < dp.length; i++) dp[i] = new Array(1001).fill(0);

  for (let i = 0; i < card.length; i++) {
    console.log(play(0, card[i].length - 1, 0, card[i]));
    init(); // dp배열 초기화
  }
  process.exit();
};

rl.on('line', input).on('close', func);
