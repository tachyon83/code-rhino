var tree2str = function(root) {
    const solve=node=>{
        if(!node)return ''
        let t=String(node.val)
        const left=solve(node.left)
        const right=solve(node.right)
        if(left.length!==0 || right.length!==0)t+=`(${left})`
        if(right.length>0)t+=`(${right})`
        return t
    }
    return solve(root)
}
