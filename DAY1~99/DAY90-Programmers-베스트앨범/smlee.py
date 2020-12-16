def solution(genres, plays):
    answer = []

    dic = {x:[] for x in set(genres)}

    for x in zip(genres, plays, range(len(genres))):
        dic[x[0]].append([x[1], x[2]])

    genres = sorted(list(dic.keys()), key=lambda x: sum(map(lambda y: y[0], dic[x])), reverse=True)

    for i in genres:
        best_genres = [x[1] for x in sorted(dic[i], key=lambda x: (x[0], -x[1]), reverse=True)]
        answer.extend(best_genres[:min(len(best_genres), 2)])

    return answer
