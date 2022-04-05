const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  arr = [],
  coins,
  ans = 20 * 20 + 1;

const input = (line) => {
  if (!n) n = parseInt(line);
  else arr.push(line);
};

const flip = (index) => {
  if (index === n) {
    let tail,
      sum = 0;
    for (let i = 0; i < n; i++) {
      tail = 0;
      for (let j = 0; j < n; j++) {
        if (coins[j] & (1 << i)) {
          tail++;
        }
      }
      sum += Math.min(tail, n - tail);
    }

    ans = Math.min(ans, sum);
    return;
  }

  flip(index + 1);
  coins[index] = ~coins[index];
  flip(index + 1);
};

const solve = () => {
  coins = new Array(n).fill(0);
  arr.forEach((line, i) => {
    for (let j = 0; j < n; j++) {
      if (line[j] === 'T') {
        coins[i] |= 1 << j;
      }
    }
  });

  flip(0);

  console.log(ans);
};

rl.on('line', (line) => input(line)).on('close', solve);
