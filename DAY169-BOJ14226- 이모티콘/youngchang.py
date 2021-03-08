S = int(input())

seen = set()
q = [(1, 0, 0)]
for cnt, step, clipboard in q:
    if cnt == S:
        break
    if (cnt, clipboard) in seen: continue
    seen.add((cnt, clipboard))
    # 클립보드 붙여넣기
    if clipboard:
        q.append((cnt + clipboard, step + 1, clipboard))
    # 하나 삭제하기
    if cnt > 1:
        q.append((cnt - 1, step + 1, clipboard))
    # 클립보드에 복사하기
    q.append((cnt, step + 1, cnt))

print(step)