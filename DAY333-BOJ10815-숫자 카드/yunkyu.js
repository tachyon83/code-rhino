const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  cardList;

const input = (line) => {
  inputs.push(line.trim());
};

const search = (num, left, right) => {
  // 이진 탐색으로 num값을 찾는다
  if (right < left) return false;

  const mid = Math.floor((left + right) / 2);
  if (num === cardList[mid]) return true;
  else if (num > cardList[mid]) return search(num, mid + 1, right);
  else return search(num, left, mid - 1);
};

const func = () => {
  const n = parseInt(inputs[0]) - 1;
  cardList = inputs[1].split(' ').map((a) => parseInt(a));
  const checkList = inputs[3].split(' ').map((a) => parseInt(a));

  cardList.sort((a, b) => a - b); // 오름차순 정렬

  // M개의 수가 cardList에 있는지 하나씩 확인한다
  const results = checkList.reduce(
    (acc, curr) => (acc += `${search(curr, 0, n) ? 1 : 0} `),
    ''
  );

  console.log(results);
};

rl.on('line', input).on('close', func);
