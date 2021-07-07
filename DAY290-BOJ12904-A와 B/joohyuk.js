const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let s = 0, t, found = 0

const input = line => {
    if (!s) s = line
    else t = line
}

const solve = _ => {
    t = t.split('')
    while (t.length >= s.length) {
        if (s == t.join('')) {
            found = 1
            break
        }
        let lc = t[t.length - 1]
        t.pop()
        if (lc == 'B') t.reverse()
    }
    console.log(found)
    return
}

rl
    .on('line', input)
    .on('close', solve)
