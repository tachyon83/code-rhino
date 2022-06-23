var sumOfLeftLeaves = function(root) {
    let s=0
    const solve=(node,isLeft)=>{
        if(!node)return
        if(!node.left&&!node.right){
            if(isLeft)s+=node.val
            return
        }
        solve(node.left,true)
        solve(node.right,false)
    }
    solve(root,false)
    return s
};
