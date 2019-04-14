var loopAddon = require('./loop_addon/build/Release/loop_addon.node');

function countSum(longValue) {
    var sum = 0;
    while (longValue > 0) {
        sum += 1;
        longValue--;
    }
    return sum;
}

var billion = 1000000000;

console.time('js_loop');
console.log("sum = " + countSum(billion));
console.timeEnd('js_loop');

console.log("\n-------------------------------------------\n");

console.time('cpp_loop');
console.log("sum = " + loopAddon.sumNow(billion));
console.timeEnd('cpp_loop');