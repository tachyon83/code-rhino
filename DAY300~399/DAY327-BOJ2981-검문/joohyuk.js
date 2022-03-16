const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, arr = [], v

const merge = (a, b) => {
    let i = 0, j = 0, al = a.length, bl = b.length, ret = []
    while (i < al && j < bl) {
        if (a[i] < b[j]) ret.push(a[i++])
        else ret.push(b[j++])
    }
    while (i < al) ret.push(a[i++])
    while (j < bl) ret.push(b[j++])
    return ret
}

const merge_sort = arr => {
    if (arr.length <= 1) return arr
    let mid = parseInt(arr.length / 2)
    return merge(merge_sort(arr.slice(0, mid)), merge_sort(arr.slice(mid, arr.length)))
}

const gcd = (a, b) => {
    return b ? gcd(b, a % b) : a;
}

const input = line => {
    if (!n) n = parseInt(line)
    else arr.push(parseInt(line))
}

const solve = _ => {
    arr = merge_sort(arr)
    v = arr[1] - arr[0], ret = new Set()
    for (let i = 2; i < n; ++i)v = gcd(v, arr[i] - arr[i - 1])
    for (let i = 2; i * i <= v; ++i) {
        if (!(v % i)) {
            ret.add(i)
            ret.add(parseInt(v / i))
        }
    }
    ret.add(v)
    ret = merge_sort(Array.from(ret))
    ans = ''
    for (const e of ret) ans += e + ' '
    console.log(ans)
}

rl
    .on('line', input)
    .on('close', solve)
