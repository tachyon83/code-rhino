/**
 * @param {string[]} words
 * @param {number} k
 * @return {string[]}
 */
const topKFrequent = function(words, k) {
    const cnt_map = new Map();
    
    // 각 단어의 개수를 count
    words.forEach((word) => {
        if(!cnt_map.get(word)) cnt_map.set(word, 1);
        else cnt_map.set(word, cnt_map.get(word) + 1);
    })
    
    // set자료구조를 통해 중복 제거
    words = [...new Set(words)];
    
    // 먼저 사전순 정렬
    words.sort();
    
    // 빈도순 내림차순 정렬
    words.sort((a,b) => {
        const first = cnt_map.get(a), second = cnt_map.get(b);
        return second - first;
    })

    return words.slice(0, k);
};
