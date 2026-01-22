const fs = require('fs')
const input = fs.readFileSync(0, 'utf8').trim()
const lines = input.split('\n')

const T = Number(lines[0])

let Ns = new Array(T)
let maxN = 0

// 모든 테스트케이스의 최대값부터 구하기
for (let i = 0; i < T; i++) {
    const N = Number(lines[i + 1])
    Ns[i] = N
    if(N > maxN){
        maxN = N
    }
    
}

// 최대 값 기준으로 소수 여부 판단
let isPrime = new Array(maxN + 1).fill(true)
if (maxN >= 0) {
    isPrime[0] = false
}
if (maxN >= 1) {
    isPrime[1] = false
}

for (let i = 2; i * i <= maxN; i++) {
    if (!isPrime[i]) {
        continue
    }
    for (let j = i * i; j <= maxN; j += i) {
        isPrime[j] = false
    }
}

let result = ''
for (let i = 0; i < T; i++) {
    const N = Ns[i]
    let count = 0

    for (let p = 2; p <= N / 2; p++) {
        if (isPrime[p] && isPrime[N - p]) {
            count++
        }
    }

    result = result + String(count) + '\n'
}

console.log(result)
