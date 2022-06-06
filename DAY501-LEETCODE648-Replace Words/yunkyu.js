/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
const replaceWords = function(dictionary, sentence) {
    dictionary.sort((a,b) => { // 길이 오름차순 정렬
        return a.length - b.length
    });
    const splited = sentence.split(" ");
    
    const res = []
    for(const word of splited) {
        let flag = false;
        for(const d_word of dictionary){
            if(word.startsWith(d_word)) { // 현재 단어가 d_word로 시작한다면 replace
                res.push(d_word);
                flag = true;
                break;
            }
        }
        if(!flag) res.push(word);
    }
    
    return res.join(" ");
};
