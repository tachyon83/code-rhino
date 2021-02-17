def solution(name):
    make_name = [min(ord(i) - ord("A"), ord("Z") - ord(i)+1) for i in name]
    idx, answer = 0, 0
    while True:
        answer += make_name[idx]
        make_name[idx] = 0
        if sum(make_name) ==0:
            break
        #이부분을 생각 못했음..좌우로 이동방향을 정할 때 바꿔야하는 알파벳이 나오기 까지 가장 짧은 거리구함
        left, right = 1, 1
        while make_name[idx - left] == 0:
            left +=1
        while make_name[idx + right] == 0:
            right +=1
        answer += left if left < right else right
        idx += -left if left < right else right
    return answer
