/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

var levelOrderBottom=function(root){
    const lob=new LevelOrderBottom(root)
    return lob.solve()
}
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var LevelOrderBottom = function(root) {
    this.arr=[]
    this.process(root,0)
    this.solve()
};

LevelOrderBottom.prototype.process=function(node,n){
    if(!node)return
    if(this.arr.length<n+1)this.arr.push([])
    this.arr[n].push(node.val)
    this.process(node.left,n+1)
    this.process(node.right,n+1)
}

LevelOrderBottom.prototype.solve=function(){
    const ret=[]
    for(let i=this.arr.length-1;i>=0;--i){
        const temp=[]
        for(const v of this.arr[i])temp.push(v)
        ret.push(temp)
    }
    return ret
}
