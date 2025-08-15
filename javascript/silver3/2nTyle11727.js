const fs = require('fs');
// const input = fs.readFileSync('input.txt').toString();
const n = parseInt(fs.readFileSync('/dev/stdin').toString().trim());

const MOD = 10007;

if (n === 1) {
    console.log(1);
    process.exit();
}

let dp = Array(n + 1).fill(0);
dp[1] = 1;
dp[2] = 3;

for (let i = 3; i <= n; i++){
    dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
}

console.log(dp[n] % MOD);

