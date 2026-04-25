const fs = require('fs');
const input = fs.readFileSync(0, "utf8").trim();
const lines = input.split('\n')

const [K, N] = lines[0].split(" ").map(Number);

const arr = new Array(K); // 선분의 길이를 담을 배열

let max_length = 0  // 선분의 최대 길이 저장

// 선분 길이 저장 및 최대값 저장
for (let i = 0; i < K; i++) {
    arr[i] = Number(lines[i + 1])
    if (max_length < arr[i]) {
        max_length = arr[i]
    }
}

// 이진 탐색을 위한 준비
let left = 1;
let right = max_length;
let result = 0;

// 이진 탐색 시작
while (left <= right) {
    const mid = Math.trunc((left + right) / 2)

    let cnt = 0

    for (let i = 0; i < K; i++) {
        cnt += Math.trunc(arr[i] / mid)
    }

    if (cnt >= N) {
        result = mid;
        left = mid + 1
    } else {
        right = mid - 1
    }
}

console.log(result)

