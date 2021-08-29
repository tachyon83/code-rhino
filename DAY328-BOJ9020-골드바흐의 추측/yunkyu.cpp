const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let t,
  inputs = [],
  maxN = 0,
  prime;

const getPrime = () => {
  // 에라토스테네스의 체 이용 범위안의 소수를 모두 구한다
  prime = new Array(maxN + 1);
  for (let i = 1; i <= maxN; i++) prime[i] = i;

  for (let i = 2; i <= maxN; i++) {
    if (prime[i] === 0) continue;
    for (j = i + i; j <= maxN; j += i) {
      if (prime[j] !== 0) prime[j] = 0;
    }
  }
};

const input = (line) => {
  if (!t) t = parseInt(line);
  else {
    inputs.push(parseInt(line));
    maxN = Math.max(maxN, parseInt(line)); // n 중 가장 큰 수를 구함
  }
};

const func = () => {
  getPrime(maxN);
  for (let i = 0; i < t; i++) {
    const n = inputs[i];
    for (let j = n / 2; j >= 2; j--) {
      // 중복 피하기위해 n/2까지, 두 소수의 차이가 가장 작은것을 출력하기 위해 n /2 부터
      if (prime[j] !== 0 && prime[n - j] !== 0) {
        // j와 n-j가 모두 소수라면 골드바흐 파티션이다
        console.log(`${j} ${n - j}`);
        break;
      }
    }
  }
};

rl.on('line', input).on('close', func);
