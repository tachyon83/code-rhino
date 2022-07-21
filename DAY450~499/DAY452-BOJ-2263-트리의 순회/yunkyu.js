const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n,
  inputs = [];
rl.on('line', (line) => {
  if (!n) n = parseInt(line);
  else inputs.push(line.split(' ').map((a) => parseInt(a)));
}).on('close', () => {
  const inOrder = inputs[0];
  const postOrder = inputs[1];
  const inIndex = new Array(n);
  for (let i = 0; i < inOrder.length; i++) {
    // inorder 각각의 값에 대한 index를 저장한다.
    inIndex[inOrder[i]] = i;
  }
  const preOrder = [];
  const getPre = (p_left, p_right, i_left, i_right) => {
    if (p_left > p_right || i_left > i_right) {
      return;
    }
    const root = postOrder[p_right]; // postorder에선 마지막이 root
    preOrder.push(root); // preorder이므로 루트 먼저 삽입
    const rootIndex = inIndex[root]; // inorder에서의 root의 index
    // inorder는 root를 기준으로 양쪽으로 left, right sub tree
    // postorder는 inorder의 left, right sub tree의 노드수를 이용하여 left, right구간을 알아낸다
    getPre(p_left, p_left + rootIndex - i_left - 1, i_left, rootIndex - 1);
    getPre(p_left + rootIndex - i_left, p_right - 1, rootIndex + 1, i_right);
  };
  getPre(0, n - 1, 0, n - 1);
  console.log(preOrder.join(' '));
});
