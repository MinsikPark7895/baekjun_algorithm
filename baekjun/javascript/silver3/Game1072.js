const fs = require('fs')
const input = fs.readFileSync(0, "utf8").trim()
const lines = input.split("\n")

const [X, Y] = lines[0].split(" ").map(Number)

let Z = Math.trunc((Y * 100) / X)  // 현재 확률

// (현재 확률 + 1 > 100) 일 경우
if (Z >= 99) {
    console.log(-1)
}
// 나머지
else {
    // 이진 탐색
    let result = -1
    let left = 1
    let right = 1000000000

    while (left <= right) {
        let mid = Math.trunc((left + right) / 2)

        let curZ = Math.trunc(((Y + mid) * 100) / (X + mid))

        if (curZ > Z) {
            result = mid
            right = mid - 1
        }
        else {
            left = mid + 1
        }
    }

    console.log(result)
}
