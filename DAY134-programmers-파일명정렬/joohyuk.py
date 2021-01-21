def solution(files):
    files_filtered = [0 for _ in range(len(files))]

    for filenum, file in enumerate(files):
        head, number = '', ''
        for idx, e in enumerate(file):
            if e in '0123456789':
                if len(head):
                    i = idx
                    break
            head += e
        head = head.lower()

        while i < len(file) and len(number) < 5 and file[i] in '0123456789':
            number += file[i]
            i += 1
        files_filtered[filenum] = (head, int(number), filenum)

    files_filtered = sorted(files_filtered)
    answer = []
    for e in files_filtered:
        answer.append(files[e[2]])
    return answer
