const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let s, dq = [], ans = ''

const input = line => {
    s = line
}

const solve = _ => {
    let flag = 0
    for (let i = 0; i < s.length; ++i) {
        if (s[i] != '<') {
            if (flag) {
                if (s[i] != '>') dq.push(s[i])
                else {
                    ans += dq.join('') + s[i]
                    dq = []
                    flag = 0
                }
            } else {
                if (s[i] === ' ') {
                    ans += dq.reverse().join('') + ' '
                    dq = []
                } else dq.push(s[i])
            }
        } else if (s[i] === '<') {
            ans += dq.reverse().join('') + '<'
            dq = []
            flag = 1
        }
    }
    ans += dq.reverse().join('')
    console.log(ans)
}

rl
    .on('line', input)
    .on('close', solve)
