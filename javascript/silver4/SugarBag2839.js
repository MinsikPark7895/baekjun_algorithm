const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString();

let N = parseInt(input);

let count = 0;

while (N >= 0) {
    if (N % 5 === 0) {
        count += N/5;
        console.log(count);
        break;
    }

    N -= 3;
    count++;
}

if(N < 0) {
    console.log(-1);
}