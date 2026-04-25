const fs = require('fs')
// const input = fs.readFileSync(0, 'utf8').trim().split('\n')
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().split('\n');

const N = Number(input[0])
const A = input[1].split(' ').map(Number)

const dp = new Array(N).fill(1)

for (let i = 0; i < N; i++) { 
    for(let j = 0; j < i; j++) {
        if (A[j] > A[i]) {
            dp[i] = Math.max(dp[i], dp[j] + 1)
        }
    }
}

console.log(Math.max(...dp))

