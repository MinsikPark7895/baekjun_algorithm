const fs = require('fs');
const input = fs.readFileSync(0, "utf8").trim();
const lines = input.split('\n')

const [K, N] = lines[0].split(" ").map(Number);

let total_length = 0

for(let i = 0; i < K; i++) {
    total_length += Number(lines[i + 1])
}

let max_length = Math.floor(total_length / N)

let current_num = 0

function two_pointer(start, end ,target) {
    
    flag = true
    
    while (flag) {
        cur_start = start
        cur_end = end
        mid = Math.floor((cur_start + cur_end) / 2)

        

        flag = false
    }
}

while (current_num !== N){   
    current_num = 0
    for (let i = 0; i < K; i++){
        current_num += Math.floor(Number(lines[i + 1]) / max_length)
    }
    if(current_num !== N) {
        max_length -= 1
    }
}

console.log(max_length)



