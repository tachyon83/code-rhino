import copy


def isRight(keysz, locksz, lockcopy):
    for i in range(keysz-1, keysz-1+locksz):
        for j in range(keysz-1, keysz-1+locksz):
            if not lockcopy[i][j]:
                return False
    return True


def check(key, locksz, nlock):
    keysz = len(key)
    sz = locksz+keysz-1
    for i in range(sz):
        for j in range(sz):
            nlockcopy = copy.deepcopy(nlock)
            flag = False
            for ik in range(keysz):
                for jk in range(keysz):
                    if nlockcopy[i+ik][j+jk] and key[ik][jk]:
                        flag = True
                        break
                    if not nlockcopy[i+ik][j+jk]:
                        nlockcopy[i+ik][j+jk] = key[ik][jk]
                if flag:
                    break
            if not flag and isRight(keysz, locksz, nlockcopy):
                return True
    return False


def rotate(key):
    keysz = len(key)
    nkey = [[0 for _ in range(keysz)] for _ in range(keysz)]
    for i in range(keysz):
        for j in range(keysz):
            nkey[j][keysz-i-1] = key[i][j]
    return nkey


def expand(keysz, lock):
    locksz = len(lock)
    nsz = locksz+(keysz-1)*2
    nlock = [[0 for _ in range(nsz)]for _ in range(nsz)]
    for i in range(keysz-1, keysz-1+locksz):
        for j in range(keysz-1, keysz-1+locksz):
            nlock[i][j] = lock[i-(keysz-1)][j-(keysz-1)]
    return nlock


def solution(key, lock):
    nlock = expand(len(key), lock)
    for _ in range(4):
        key = rotate(key)
        if check(key, len(lock), nlock):
            return True
    return False
