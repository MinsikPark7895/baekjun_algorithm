const fs = require('fs');
const input = fs.readFileSync(0, "utf8").trim();
const lines = input.split("\n");

const [N, M] = lines[0].split(" ").map(Number); // 입력 받기

const arr = [];  // 백트래킹을 위한 배열
let result = "";  // 출력할 결과값

// 백트래킹 로직
function backtrack(depth) {
    // 배열의 길이가 입력의 길이값과 일치하게 되면 
    if(depth === M) {
        result += arr.join(" ") + "\n";
        return ;
    }
    // 배열의 길이가 아직 길이보다 적을 경우
    else {
        for(let i = 1; i < N + 1; i++){    
            arr.push(i);
            backtrack(depth + 1);
            arr.pop();
        }
    }
}

// 백트리킹 실행
backtrack(0);
console.log(result);