/**
 * @param {number[]} nums
 * @return {number[][]}
 */

const permute = function(nums) {
    const ret = [];
    const permutation = (arr, bitmask) => {
        if(arr.length === nums.length) { // 순열 조합을 구했을시 결과배열에 push
            ret.push(arr);
            return;
        }
        
        for(let i = 0; i < nums.length; i++){
            if(bitmask & (1 << i)) continue; // 비트마스크로 방문 확인
            permutation([...arr,nums[i]],bitmask | (1 << i)); // 원소 추가, 비트마스크 체크
        }
    }
    permutation([],0);
    
    return ret;
};
