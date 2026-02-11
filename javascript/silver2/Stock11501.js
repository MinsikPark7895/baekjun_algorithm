const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')


for (let i = 2; i < input.length; i += 2) {
    let stockChart = input[i].split(' ').map(Number)
    let marketProfit = 0  // 시세차익
    let maxPrice = 0  // 현재 최대 주식가격
    // 뒤에서부터 순회
    for(let j = stockChart.length - 1; j >= 0; j--) {
        // 뒤에서부터 찾은 최대 가격보다 큰 가격이 나오면 최대값 교체
        if (stockChart[j] > maxPrice) {
            maxPrice = stockChart[j]
        }
        // 최대 값을 더함
        marketProfit += maxPrice - stockChart[j]
    }

    console.log(marketProfit)
}