function solution(genres, plays) {
    let answer = [];
    let obj = {};
    
    for(let i = 0; i < genres.length; i++) {
        const genre = genres[i];
        if(!obj[genre]) {  // 객체에 장르가 존재하지 않을때 생성하고 초기화
            obj[genre] = {
                cnt : plays[i],
                songs : [
                    {
                        num: i,
                        cnt: plays[i]
                    },
                ]
            }
        }
        else { // 존재할때
            obj[genre].cnt += plays[i]; // 장르 재생횟수 누적 
            obj[genre].songs.push({ // 곡 추가
                num:i,
                cnt:plays[i],
            });
        }
    }
    
    let arr = [];
    // 배열에 장르별 곡들을 기준에 맞게 정렬
    for(const key in obj) { 
        obj[key].songs.sort((a,b) => {
            if(b.cnt === a.cnt) return a.num - b.num;
            return b.cnt - a.cnt
        });
        arr.push(obj[key]);
    }
    // 많이 재생된 장르별 내림차순으로 정렬
    arr.sort((a,b) => b.cnt - a.cnt);
    for(let i = 0; i < arr.length; i++) {
        const songs = arr[i].songs;
        if(songs.length === 1) answer.push(songs[0].num); // 하나라면 하나의 곡만 선택
        else { // 아니라면 가장많이재생된 노래 두가지 선택
            for(let j = 0; j < 2; j++) answer.push(songs[j].num);
        }
    }
    
    return answer;
}
