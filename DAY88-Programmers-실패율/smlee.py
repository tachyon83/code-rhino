# 풀이1
def solution(N, stages):
    stages_num = {}
    player_cnt = len(stages)
    for i in range(1, n+1):
        if player_cnt != 0:
            no_clear = stages.count(i)
            stages_num[i] = no_clear / player_cnt
            player_cnt -= no_clear
        else:
            stages_num[i] = 0
    return sorted(stages_num, key=lambda x : stages_num[x], reverse=True)
    
# 풀이2
def solution(N, stages):
    stages_num = {}

    for i in range(1, N+1) :      
      if i == 1 :
        stages_num[i] = stages.count(i) / len(stages)
        no_clear = stages.count(1)
      elif stages.count(i) == 0 :
        stages_num[i] = 0
      else :
        stages_num[i] = stages.count(i) / (len(stages) - no_clear)
        no_clear += stages.count(i)
      
    return sorted(stages_num, key=lambda x : stages_num[x],reverse=True)
