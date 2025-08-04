const fs = require('fs');
// const input = fs.readFileSync('input.txt').toString();
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let lastValue = 0;
let valueIndex = 0;

for(let i=0; i < input.length; i++){
    if(input[i] !== "Fizz" && input[i] !== "Buzz" && input[i] !== "FizzBuzz"){
        lastValue = Number(input[i]);
        valueIndex = i;
    }
}


if(valueIndex === 0) {
    lastValue += 3;
} else if (valueIndex === 1) {
    lastValue += 2;
} else if (valueIndex === 2){
    lastValue += 1;
}

if(lastValue % 3 === 0 && lastValue % 5 === 0) {
    console.log("FizzBuzz");
} else if (lastValue % 3 === 0) {
    console.log("Fizz");
} else if (lastValue % 5 === 0) {
    console.log("Buzz");
} else {
    console.log(lastValue);
}
