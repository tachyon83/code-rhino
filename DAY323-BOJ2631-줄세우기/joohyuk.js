const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, g = [], arr = []

const bs = v => {
    let i = 0, j = arr.length, ret = j
    while (i < j) {
        let mid = parseInt((i + j) / 2)
        if (arr[mid] < v) i = mid + 1
        else {
            ret = mid
            j = mid
        }
    }
    return ret
}

const input = line => {
    if (!n) n = parseInt(line)
    else g.push(parseInt(line))
}

const solve = _ => {
    g.forEach(e => {
        let idx = bs(e)
        if (idx === arr.length) arr.push(e)
        else arr[idx] = e
    })
    console.log(n - arr.length)
}

rl
    .on('line', input)
    .on('close', solve)
