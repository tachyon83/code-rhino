var ans = 0, nums = [], target, stack = []

const repeat = (fn, v) => {
    return () => {
        if (!v) return
        return repeat(fn, fn(v))
    }
}

const checker = fn => {
    while (typeof fn == 'function') fn = fn()
}

const starter = (fn, v) => {
    checker(function () {
        return repeat(fn, v)
    })
}

const dfs = arr => {
    const [v, cnt, ii] = arr
    if (cnt == nums.length) {
        if (v == target) ans++
        return false
    }
    for (let i = ii; i < 2; ++i) {
        if (!i) {
            stack.push([v, cnt, ii + 1])
            return [v - nums[cnt], cnt + 1, 0]
        } else return [v + nums[cnt], cnt + 1, 0]
    }
}

function solution(numbers, tg) {
    nums = numbers, target = tg
    starter(dfs, [0, 0, 0])
    while (stack.length) starter(dfs, stack.pop())
    return ans;
}
