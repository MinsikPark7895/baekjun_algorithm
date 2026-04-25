const fs = require('fs');
const input = fs.readFileSync(0, 'utf8').trim().split(' ');
const N = Number(input[0]);
const K = Number(input[1]);

let isPrime = new Array(N + 1).fill(true);
let count = 0;

for (let i = 2; i <= N; i++) {
    if (isPrime[i]) {
       isPrime[i] = false;
        count++;
        
        if (count === K) {
            console.log(i);
            return;
        }

       for (let j = i * i; j <= N; j += i) {
            if (isPrime[j]) {
                isPrime[j] = false;
                count++;

                if (count === K) {
                    console.log(j);
                    return;
                }
            }
        }
    }
}