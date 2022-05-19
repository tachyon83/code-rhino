const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const arr = []
const bs = e => {
  let i = 0
  let j = arr.length
  let ret = j

  while (i < j) {
    let mid = parseInt((i + j) / 2)
    if (arr[mid] >= e) {
      ret = mid
      j = mid
    } else {
      i = mid + 1
    }
  }
  return ret
}

const n = parseInt(input[0], 10)
const nums = input[1].split(' ').map(e => parseInt(e, 10))
nums.forEach(e =>(arr[bs(e)] = e))
console.log(arr.length)
