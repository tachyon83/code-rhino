var BSTIterator = function (root) {
  this.list = []; 


  const traversal = (node) => {
    if (!node) {
      return;
    }

    traversal(node.left);
    this.list.push(node.val);
    traversal(node.right);
  };
  traversal(root);
};

BSTIterator.prototype.next = function () {
  return this.list[this.index++];
};

BSTIterator.prototype.hasNext = function () {
 
  return typeof this.list[this.index] === 'number';
};
