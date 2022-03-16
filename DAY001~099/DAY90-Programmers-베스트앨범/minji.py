from collections import defaultdict

def solution(genres, plays):
    answer = []
    total_play = defaultdict(int)
    g_dic = defaultdict(list)
    for i, v in enumerate(genres):
        g_dic[v].append((plays[i], i))
        total_play[v] += plays[i]
    # print(total_play)
    # print(g_dic)
    
    sorted_total_play = sorted(total_play.items(), key=lambda x: x[1], reverse=True)
    
    for g in sorted_total_play:
        song = g_dic[g[0]]
        song = sorted(song, key = lambda x: (-x[0], x[1]))

        for i in range(len(song)):
            if i == 2:
                break
            answer.append(song[i][1])
        
    return answer
