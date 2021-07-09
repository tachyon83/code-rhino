const fs = require('fs')
let input;
try {
    input = fs.readFileSync(__dirname + '/input.txt').toString().trim().split('\n');
} catch (_) {
    input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
}

const solution = (cmd, n, arr) => {
    let error = 0, dir = false, si = 0, ei = n - 1
    for (let i = 0; i < cmd.length; ++i) {
        if (!error) {
            if (cmd[i] == 'R') dir = !dir
            else {
                if (ei < si) {
                    error = 1
                    break
                } else {
                    if (dir) ei--
                    else si++
                }
            }
        }
    }

    let ans = []
    for (let i = si; i <= ei; ++i)ans.push(arr[i])
    if (!error) console.log(`[${!dir ? ans.join(',') : ans.reverse().join(',')}]`)
    else console.log('error')
}

const T = parseInt(input[0].trim());
for (let num = 0; num < T; num++) {
    let arr = input[3 * num + 3].trim();
    arr = arr.length === 2
        ? []
        : arr
            .slice(1, arr.length - 1)
            .split(',')
    // .map(v => parseInt(v));
    solution(input[3 * num + 1].trim(), input[3 * num + 2].trim(), arr);
}
