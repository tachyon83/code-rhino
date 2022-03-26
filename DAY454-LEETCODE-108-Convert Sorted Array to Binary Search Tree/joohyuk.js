var sortedArrayToBST = function(nums) {
  if (!nums.length) return null
  const mid = parseInt(nums.length / 2, 10)
  const root = new TreeNode(nums[mid])
  root.left = sortedArrayToBST(nums.slice(0, mid))
  root.right = sortedArrayToBST(nums.slice(mid + 1, nums.length))
  return root
}
