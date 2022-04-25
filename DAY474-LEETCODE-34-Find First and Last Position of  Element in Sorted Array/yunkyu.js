/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const searchRange = function(nums, target) {
    let ret = [-1, -1];
    
    let start = 0, end = nums.length - 1;
    // 이진 탐색을 통해 시작점 탐색
    while(start <= end) {
        const mid = Math.floor((start + end) / 2);
        
        if(nums[mid] === target) {
            ret[0] = mid;
            end = mid - 1; // 가장 왼쪽 sub part에서 찾는다.
        }
        else if(nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    start = 0, end = nums.length - 1;
     // 이진 탐색을 통해 끝점 탐색
    while(start <= end) {
        const mid = Math.floor((start + end) / 2);
        
        if(nums[mid] === target) {
            ret[1] = mid;
            start = mid + 1; // 가장 오른쪽 sub part에서 찾는다.
        }
        else if(nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return ret;
};
