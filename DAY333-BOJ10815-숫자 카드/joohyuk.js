const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, m = 0
cards = 0, arr = 0

const input = line => {
    if (!n) n = parseInt(line)
    else if (!cards) cards = new Set(line.split(' ').map(e => parseInt(e)))
    else if (!m) m = parseInt(line)
    else arr = line.split(' ').map(e => parseInt(e))
}

const solve = _ => {
    let ret = ''
    for (const e of arr) ret += cards.has(e) ? 1 + ' ' : 0 + ' '
    console.log(ret)
}

rl
    .on('line', input)
    .on('close', solve)
