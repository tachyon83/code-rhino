function solution(arr) {
    const answer = new Array(2).fill(0);
     const n = arr.length;
    
    const solve = (x_start,x_end,y_start,y_end) => {
        let zero = true, one = true;
        // 현재 영역이 1이나 0으로만 이루어져있는지 확인
        for(let i = x_start; i <= x_end; i++) {
            for(let j = y_start; j <= y_end; j++){
                if(arr[i][j] === 0) one = false;
                else zero = false;
            }
        }
        
        // 0 으로 압축
        if(zero) {
            answer[0] ++;
            return;
        }
        // 1 로 압축
        if(one) {
            answer[1] ++;
            return;
        }
        
        // 압축할 수 없다면 4개 영역으로 분리
        const x_mid = Math.floor((x_end + x_start) / 2);
        const y_mid = Math.floor((y_end + y_start) / 2);
        solve(x_start,x_mid,y_start,y_mid);
        solve(x_mid + 1,x_end,y_start,y_mid);
        solve(x_start,x_mid,y_mid+1,y_end);
        solve(x_mid + 1,x_end,y_mid+1,y_end);
    }
    
    solve(0, n - 1, 0, n - 1);
    return answer;
}
