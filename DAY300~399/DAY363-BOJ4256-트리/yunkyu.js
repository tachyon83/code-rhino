const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputs = [],
  t,
  n,
  preorder,
  inorder,
  idx;

const getPost = (pre_left, pre_right, in_left, in_right) => {
  if (pre_left > pre_right || in_left > in_right) return; // left 가 right 를 넘어서면 종료
  const root = preorder[pre_left]; // preorder 에서 가장 왼쪽 index 는 root
  const rootIdx = idx[root]; // inorder의 root 위치

  /* 
  inorder에서 root 왼쪽은 left sub tree, 오른쪽은 right sub tree 이다. 
  left sub tree와 right sub tree의 노드 개수를 이용해 preorder의 left, right sub tree로 나눈다.
  */
  getPost(pre_left + 1, pre_left + rootIdx - in_left, in_left, rootIdx - 1);
  getPost(pre_left + rootIdx - in_left + 1, pre_right, rootIdx + 1, in_right);
  process.stdout.write(root + ' '); // postorder는 가장 나중에 루트를 출력
};

rl.on('line', (line) => {
  inputs.push(line);
}).on('close', () => {
  t = parseInt(inputs[0]);
  for (let i = 0; i < t; i++) {
    const j = i * 3;
    n = parseInt(inputs[1 + j]);
    preorder = inputs[2 + j].split(' ').map((a) => parseInt(a));
    inorder = inputs[3 + j].split(' ').map((a) => parseInt(a));

    // inorder에서 값들의 index를 저장
    idx = new Array(n);
    for (k = 0; k < n; k++) {
      idx[inorder[k]] = k;
    }
    getPost(0, n - 1, 0, n - 1);
    console.log();
  }
});
