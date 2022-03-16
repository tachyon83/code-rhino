const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, m, words = new Set(), c = 0, cnt = 0

const input = line => {
    if (!n) [n, m] = line.split(' ').map(e => parseInt(e))
    else {
        if (c < n) {
            c++
            words.add(line)
        } else {
            if (words.has(line)) cnt++
        }
    }
}

const solve = _ => {
    console.log(cnt)
}

rl
    .on('line', input)
    .on('close', solve)
