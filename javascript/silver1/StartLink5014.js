const fs = require('fs')
const input = fs.readFileSync(0, 'utf').trim().split(' ')

const F = Number(input[0])
const S = Number(input[1])
const G = Number(input[2])
const U = Number(input[3])
const D = Number(input[4])

let result = "use the stairs"
let cur = S
let cnt = 0

while (cur != G) {
    cnt++
    let next_U = cur + U
    let next_D = cur - D
    if (cur < G) {
        if (next_U == G) {
            result = cnt
            break
        }
        else if (next_U > G) {
            
        }
    }
    else if(cur > G) {

    }
    
}
