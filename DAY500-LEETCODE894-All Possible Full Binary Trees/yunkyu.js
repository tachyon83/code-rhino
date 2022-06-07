/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */

const allPossibleFBT = function(n) {
    const dp = new Array(n + 1);
    dp[1] = [new TreeNode()]; // node가 한개일 때 
    
    const solve = (n) => {
        if(dp[n]) return dp[n];
        
        const res = [];
        for(let i = 0; i < n; i++){
            // left sub tree가 i개 노드, right sub tree가 n - 1 - i(-1 => root 제외) 노드를 가질 때의 
            // sub tree를 구한다.
            const [leftSub, rightSub] = [solve(i), solve(n - 1 - i)]; 
            // left, right sub tree 경우의 수를 모두 구한다.
            for(const left of leftSub) {
                for(const right of rightSub) {
                    res.push(new TreeNode(0,left,right));
                }
            }
        }
        
        return dp[n] = res;
    }
    
    return solve(n);
};
