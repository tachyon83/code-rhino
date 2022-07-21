const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N,
  tasks = [],
  dp,
  inDegree,
  graph = [];

const input = (line) => {
  if (!N) N = parseInt(line);
  else tasks.push(line.split(' ').map((a) => parseInt(a)));
};

const solve = () => {
  inDegree = new Array(N + 1).fill(0);
  dp = new Array(N + 1).fill(0);
  for (let i = 0; i <= N; i++) graph.push([]);

  tasks.forEach((task, i) => {
    inDegree[i + 1] = task[1]; // i + 1번째 작업의 선행작업의 개수
    // graph 생성
    for (let j = 0; j < task[1]; j++) {
      graph[task[j + 2]].push(i + 1);
    }
  });

  const topology = () => {
    const queue = [];
    for (let i = 1; i <= N; i++) {
      // 선행작업이 없는 작업
      if (inDegree[i] === 0) {
        queue.push(i);
        dp[i] = tasks[i - 1][0];
      }
    }

    while (queue.length > 0) {
      const curr = queue.shift();
      for (let i = 0; i < graph[curr].length; i++) {
        const next = graph[curr][i];
        // 선행 작업중 가장 오래걸린 작업의 시간을 취한다.
        dp[next] = Math.max(dp[next], tasks[next - 1][0] + dp[curr]);
        // 선행작업을 모두 수행하엿다면
        if (--inDegree[next] === 0) {
          queue.push(next);
        }
      }
    }
  };

  topology(); // 위상정렬 이용
  let ans = 0;
  // 가장 오래걸린 시간을 찾는다.
  for (let i = 1; i <= N; i++) ans = Math.max(ans, dp[i]);
  console.log(ans);
};

rl.on('line', input).on('close', solve);
