const fs = require('fs')
// 전체 입력의 공백/ 줄바꿈 기준으로 미리 다 쪼개놓음
const input = fs.readFileSync(0, 'utf8').split(/\s+/)

// 스택 배열 2개 생성
let lStack = input[0].split("")
let rStack = []
let length = Number(input[1])

let cursor = 2

// 실제 명령어부터 
for (let i = 2; i < 2 + length; i++) {
    let cmd = input[cursor++]

    if (cmd === "L" && lStack.length > 0) {
        rStack.push(lStack.pop())
    }
    else if (cmd === "D" && rStack.length > 0) {
        lStack.push(rStack.pop())
    }
    else if (cmd === "B" && lStack.length > 0) {
        lStack.pop();
    }
    else if (cmd === "P") {
        let value = input[cursor++]
        lStack.push(value)
    }
}

// 오른쪽 스택은 뒤집어서 합쳐야 함
let answer = lStack.join("");
answer += rStack.reverse().join("");
console.log(answer)

