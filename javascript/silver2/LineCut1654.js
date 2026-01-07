const fs = require('fs');
const input = fs.readFileSync(0, "utf8").trim();
const lines = input.split('\n')

const [K, N] = lines[0].split(" ").map(Number);

const arr = new Array(K);

let max_length = 0

for (let i = 0; i < K; i++) {
    arr[i] = Number(lines[i + 1])
    if (max_length < arr[i]) {
        max_length = arr[i]
    }
}

let left = 1;
let right = max_length;
let ans = 0;

while (left <= right) {
    
}

