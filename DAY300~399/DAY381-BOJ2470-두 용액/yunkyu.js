const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, arr;

rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else arr = line.split(' ').map((a) => parseInt(a));
}).on('close', () => {
  arr.sort((a, b) => a - b); // 오름차순 정렬
  const ans = [0, 0];
  let start = 0,
    end = n - 1;

  let min = Infinity;
  while (start < end) {
    // 양쪽 끝부터 중간으로
    const sum = arr[start] + arr[end];
    if (Math.abs(sum) < min) {
      // 현재 start, end가 가르치는 양끝 합의 절댓값이 가장 작은지 비교
      min = Math.abs(sum);
      ans[0] = arr[start];
      ans[1] = arr[end];
    }

    const a = arr[start] + arr[end - 1];
    const b = arr[start + 1] + arr[end];
    // 양쪽 끝중에 중간으로 가까워질때 합(절댓값)이 더 작아지는 방향으로 선택
    if (Math.abs(a) < Math.abs(b)) end--;
    else start++;
  }

  console.log(ans.join(' '));
});
