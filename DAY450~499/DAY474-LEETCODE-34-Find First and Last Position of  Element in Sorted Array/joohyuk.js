/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

const bs1 = (nums, target) => {
  let i = 0
  let j = nums.length
  let ret = -1

  while (i < j) {
    const mid = parseInt((i + j) / 2)
    if (nums[mid] === target) {
      ret = mid
      j = mid
    } else if (nums[mid] < target) i = mid + 1
    else j = mid
  }
  return ret
}

const bs2 = (nums, target) => {
  let i = 0
  let j = nums.length
  let ret = -1

  while (i < j) {
    const mid = parseInt((i + j) / 2)
    if (nums[mid] === target) {
      ret = mid
      i = mid + 1
    } else if (nums[mid] < target) i = mid + 1
    else j = mid
  }
  return ret
}

var searchRange = function(nums, target) {
  return [ bs1(nums, target), bs2(nums, target) ]
}
