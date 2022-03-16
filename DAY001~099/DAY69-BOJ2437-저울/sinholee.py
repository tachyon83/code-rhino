def solution(n, arr):
    arr.sort()

    temp = 0
    for i in range(n):
	    if temp+1 < arr[i]:
		    return temp +1
	    temp += arr[i]
    return temp + 1
                
if __name__=='__main__':
    n = int(input())
    arr = [*map(int, input().split())]
    print(solution(n, arr))
