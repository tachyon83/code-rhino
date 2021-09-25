const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n, r, c, ans = null, i = 0

const input = line => {
    [n, r, c] = line.split(' ').map(e => parseInt(e))
}

const dnc = (ri, re, ci, ce, s, e) => {
    if (ans) return
    if (!(ri <= r && r < re && ci <= c && c < ce)) {
        i += e - s
        return
    }
    if (ri + 1 === re && ci + 1 === ce && ri === r && ci === c) {
        ans = i
        return
    }
    const rmid = parseInt((ri + re) / 2)
    const cmid = parseInt((ci + ce) / 2)
    const h = parseInt(parseInt((e - s) / 2) / 2)

    dnc(ri, rmid, ci, cmid, s, s + h)
    dnc(ri, rmid, cmid, ce, s + h, s + 2 * h)
    dnc(rmid, re, ci, cmid, s + 2 * h, s + 3 * h)
    dnc(rmid, re, cmid, ce, s + 3 * h, e)
}

const solve = _ => {
    const sz = 2 ** n
    dnc(0, sz, 0, sz, 0, sz * sz)
    console.log(ans)
}

rl
    .on('line', input)
    .on('close', solve)
