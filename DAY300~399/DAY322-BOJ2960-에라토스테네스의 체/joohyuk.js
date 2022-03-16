const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n, k, arr = [], cnt = 0

const small = _ => {
    for (let i = 0; i < arr.length; ++i) {
        if (!arr[i][1]) return i
    }
}

const input = line => {
    [n, k] = line.split(' ').map(e => parseInt(e))
    for (let i = 2; i <= n; ++i)arr.push([i, 0])
}

const solve = _ => {
    while (1) {
        let i = small()
        let v = arr[i][0]
        while (i < n - 1 && arr[i][0] <= n) {
            if (!arr[i][1]) {
                arr[i][1] = 1
                cnt++
                if (cnt == k) {
                    console.log(arr[i][0])
                    return
                }
            }
            i += v
        }
    }
}

rl
    .on('line', input)
    .on('close', solve)
