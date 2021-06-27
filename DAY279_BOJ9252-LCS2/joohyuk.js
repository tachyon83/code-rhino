const { mainModule } = require('process');
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let ln = 0, dp = [], a, b

const input = line => {
    if (!ln) a = line
    else {
        b = line
        for (let j = 0; j < b.length + 1; ++j) {
            temp = []
            for (let i = 0; i < a.length + 1; ++i)temp.push(0)
            dp.push(temp)
        }
    }
    ln++
}

const solve = _ => {
    for (let j = 0; j < b.length; ++j) {
        for (let i = 0; i < a.length; ++i) {
            if (a[i] == b[j]) dp[j + 1][i + 1] = dp[j][i] + 1
            else dp[j + 1][i + 1] = Math.max(dp[j][i + 1], dp[j + 1][i])
        }
    }
    let cnt = dp[b.length][a.length]
    let i = a.length, j = b.length, found = false, ans = '', hold = a.length
    while (j) {
        found = false
        for (; i > 0; --i) {
            if (dp[j][i] < cnt) break
            if (dp[j][i] == cnt && dp[j][i] > dp[j - 1][i] && dp[j][i] > dp[j][i - 1]) {
                found = true
                cnt--
                hold = i - 1
                ans += b[j - 1]
                break
            }
        }
        if (!found) i = hold
        j--
    }
    console.log(ans.length)
    for (let j = ans.length; j > 0; --j)process.stdout.write(ans[j - 1])
}

rl
    .on('line', input)
    .on('close', solve)
