function solution(routes) {
    let answer = 1;
    routes.sort((a,b) => a[0] - b[0]); // 진입지점에 따라 오름차순
    
    let camera = routes[0][1]; // 첫 차량의 진출점에 카메라 설치
    for(let i = 1; i < routes.length; i++){
        if(camera < routes[i][0]) { // 카메라가 현재 차량의 진입점보다 이전에 존재할시
            answer++;
            camera = routes[i][1]; // 현재 차량의 진출점에 카메라 설치
        }
        
        if(camera > routes[i][1]) { // 현재 차량의 진출점이 카메라 위치보다 이전일시
            camera = routes[i][1]; // 카메라를 현재 차량의 진출점으로 옮긴다
        }
        
    }
   
    return answer;
}
