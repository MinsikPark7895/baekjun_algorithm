const fs = require('fs')
const input = fs.readFileSync(0, 'utf8').trim().split(' ')

const F = Number(input[0])
const S = Number(input[1])
const G = Number(input[2])
const U = Number(input[3])
const D = Number(input[4])

const visited = new Array(F + 1).fill(false);

const queue = [[S, 0]]
visited[S] = true;

let result = "use the stairs"
let head = 0  // 현재 확인하는 큐의 인덱스

// BFS
while (head < queue.length) {
    const [cur, cnt] = queue[head++]

    // 목표 층에 도달한 경우
    if (cur === G) {
        result = cnt
        break
    }

    // 위로 가는 경우
    const nextUp = cur + U
    if (nextUp <= F && !visited[nextUp]) {
        visited[nextUp] = true;
        queue.push([nextUp, cnt + 1])
    }

    // 아래로 가는 경우
    const nextDown = cur - D
    if (nextDown >= 1 && !visited[nextDown]) {
        visited[nextDown] = true
        queue.push([nextDown, cnt + 1])
    }
}

console.log(result)