const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n
const input = line => {
    n = parseInt(line)
}

const isPrime = n => {
    if (n === 1) return false
    let v = parseInt(Math.sqrt(n))
    for (let i = 2; i < v + 1; ++i)if (!(n % i)) return false
    return true
}
const isPalindrome = s => {
    s += ''
    let sz = s.length, hf = parseInt(s.length / 2)
    for (let i = 0; i < hf; ++i)if (s[i] != s[sz - 1 - i]) return false
    return true
}

const solve = _ => {
    while (!isPrime(n) || !isPalindrome(n)) n += 1
    console.log(n)
}

rl
    .on('line', input)
    .on('close', solve)
