const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const sz = 10000
let t = 0, primes = []

const bs = v => {
    let i = 0, j = primes.length, ret
    while (i < j) {
        let mid = parseInt((i + j) / 2)
        if (primes[mid] <= v) {
            ret = mid
            i = mid + 1
        } else j = mid
    }
    return ret
}

const isPrime = v => {
    for (let i = 2; i <= Math.sqrt(v); ++i)if (!(v % i)) return false
    return true
}
for (let i = 2; i <= sz; ++i)if (isPrime(i)) primes.push(i)

const input = line => {
    if (!t) t = parseInt(line)
    else solve(parseInt(line))
}

const solve = v => {
    let idx = bs(parseInt(v / 2))
    while (idx >= 0) {
        let temp = v - primes[idx]
        if (isPrime(temp)) {
            console.log(primes[idx], temp)
            return
        } else idx--
    }
}

rl
    .on('line', input)
    // .on('close', solve)
