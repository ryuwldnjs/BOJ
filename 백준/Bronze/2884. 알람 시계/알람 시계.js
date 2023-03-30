//const input = require("fs").readFileSync("input.txt").toString().split(" ");
const input = require("fs").readFileSync("/dev/stdin").toString().split(" ");
//const input = require('readline-sync').question().split(" ");
// 않이 외 않되 ??????
let a = Number(input[0]);
let b = Number(input[1]);
//var보단 let을 쓰는 추세라고 함

if(b < 45) a--;
if(a < 0) a = 23;

b = (b+15) % 60; // (-45 + 60) %60

console.log(a, b);