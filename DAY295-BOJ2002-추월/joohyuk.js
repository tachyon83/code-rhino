const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, i = 0, cars = {}, after = [], cnt = 0

const input = line => {
    if (!n) n = parseInt(line)
    else if (i < n) cars[line] = i++
    else after.push(line)
}

const solve = _ => {
    after.forEach((car, i) => {
        if (i < n - 1) {
            for (let j = i + 1; j < n; ++j) {
                if (cars[car] > cars[after[j]]) {
                    cnt++
                    break
                }
            }
        }
    })
    console.log(cnt)
}

rl
    .on('line', input)
    .on('close', solve)
