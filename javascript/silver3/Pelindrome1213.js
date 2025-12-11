const file = process.platform === "linux" ? "dev/stdin" : "./input.txt";
const input = require('fs').readFileSync(file).toString().trim();

function solution() {
    const arr = input.split('').sort();

    let now_idx = 0;
    let isComparing = false;
    let center = "";

    let stack1 = [];
    let stack2 = [];

    while (now_idx < arr.length) {
        if (!isComparing) {
            stack1.push(arr[now_idx]);
            isComparing = true;
        }

        else {
            if (stack1[stack1.length - 1] === arr[now_idx]) {
                stack2.push(arr[now_idx]);
                isComparing = false;
            }
            else {
                if (center === "") {
                    center = stack1.pop();
                    stack1.push(arr[now_idx]);
                }
                else {
                    return "I'm Sorry Hansoo"
                }
            }
        }

        now_idx += 1;
    }

    if (center !== "") {
        if (isComparing) {
            return "I'm Sorry Hansoo";
        }

        else {
            stack1.push(center);
        }
    }

    while (stack2.length > 0) {
        stack1.push(stack2.pop());
    }

    return stack1.join('');
}

console.log(solution());


