const findHit = (cache,city) => cache.findIndex((c) => c.toUpperCase() === city.toUpperCase()); // cache에 city가 존재하는지 확인

function solution(cacheSize, cities) {
    let answer = 0;
    const cache = [];
    if(cacheSize === 0) return cities.length * 5; // cacheSize가 0이면 모두 cache miss
    
    for(const city of cities) {
        const hit = findHit(cache,city);
        if(hit !== -1) { // 캐시에 존재한다면
            cache.splice(hit,1);
            cache.push(city); // 제일 최신으로
            answer += 1;
        }
        else {
            if(cache.length < cacheSize) { // 캐시에 공간이 남았다면
                cache.push(city); 
                answer += 5;
            }
            else { // 없다면 가장 오래된 메모리를 제거
                cache.shift();
                cache.push(city);
                answer += 5;
            }
        }
    }
    return answer;
}
