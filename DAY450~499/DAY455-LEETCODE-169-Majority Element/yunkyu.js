/**
 * @param {number[]} nums
 * @return {number}
 */
const majorityElement = function(nums) {
    nums.sort((a,b) => a - b); // nums 정렬
    let answer = nums[0], maxCnt = 0, curr = nums[0], startIdx = 0;
    for(let i = 1; i < nums.length; i++){
        if(curr !== nums[i]) { // count하고 있던값과 다른값이 나오면
            if(maxCnt < i - startIdx) { // 현재까지 count한 값의 개수가 더 크면 갱신
                maxCnt = i - startIdx;
                answer = nums[startIdx];
            }
            // 다음 값으로 갱신하여 탐색
            curr = nums[i]; 
            startIdx = i;
        }
    }
    // 배열 마지막에 count하던 값의 개수와 비교
    if(maxCnt < nums.length - startIdx) {
        answer = nums[startIdx];
    }
    return answer;
};
