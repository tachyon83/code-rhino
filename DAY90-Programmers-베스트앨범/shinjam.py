from collections import defaultdict


def solution(genres, plays):
    genre_dict = defaultdict(list)
    plays_sum = defaultdict(int)
    
    for idx, g, t in enumerate(zip(genres, plays)):
        plays_sum[g] += t
        genre_dict[g].append((idx, t))
        genre_dict[g].sort(key=lambda x: (-x[1], x[0]))
        
    ordered_plays_sum = dict(sorted(plays_sum.items(), key=lambda x: -x[1]))
    
    
    ret = []
    
    for gg in ordered_plays_sum:
        ret.extend(g[0] for g in genre_dict[gg][:2])   
        
    return ret
