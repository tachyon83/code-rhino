const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  p = [];

const MAX = 2000000;

const getPrime = () => {
  // (에라토스테네스의 체) 소수인값들을 구한다
  p = new Array(MAX);

  for (let i = 0; i < MAX; i++) {
    p[i] = i;
  }

  for (let i = 2; i < MAX; i++) {
    if (p[i] === 0) continue;
    for (let j = i + i; j < MAX; j += i) {
      if (p[j] !== 0) p[j] = 0;
    }
  }
};

const isPalindrome = (n) => {
  let i = 0,
    j = n.length - 1;

  while (true) {
    // 양 끝에서부터 같은수인지 비교
    if (i > j) break;
    if (n[i] !== n[j]) {
      return false;
    }
    i++;
    j--;
  }

  return true;
};

const input = (line) => {
  n = parseInt(line);
  rl.close();
};

const func = () => {
  getPrime();
  for (let i = n; i < MAX; i++) {
    if (p[i] !== 0) {
      // 소수라면
      if (isPalindrome(String(p[i]))) {
        console.log(p[i]);
        process.exit();
      }
    }
  }
};

rl.on('line', input).on('close', func);
