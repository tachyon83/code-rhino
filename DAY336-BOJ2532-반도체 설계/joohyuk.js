const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, arr, ans = []

const input = line => {
    if (!n) n = parseInt(line)
    else arr = line.split(' ').map(e => parseInt(e))
}

const bs = e => {
    let i = 0, j = ans.length, ret = ans.length
    while (i < j) {
        const mid = parseInt((i + j) / 2)
        if (ans[mid] >= e) {
            ret = mid
            j = mid
        } else i = mid + 1
    }
    return ret
}

const solve = _ => {
    for (const e of arr) {
        if (!ans.length) ans.push(e)
        else {
            const idx = bs(e)
            if (idx > ans.length) ans.push(e)
            else ans[idx] = e
        }
    }
    console.log(ans.length)
}

rl
    .on('line', input)
    .on('close', solve)
