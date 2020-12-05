"""
["987987", "87"] 〉	true
["111113", "1112", "12"] 〉	true
"""

def solution(pbs):
    answer = True
    for i in range(len(pbs)-1):
        for j in range(i+1, len(pbs)):
            if len(pbs[i]) < len(pbs[j]):
                spb = pbs[i]
                lpb = pbs[j]
            else:
                spb = pbs[j]
                lpb = pbs[i]
            if spb in lpb[:len(spb)]:
                return False
    return answer
