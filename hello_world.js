// var factorial = require('./node_cpp/factorial/build/Release/factorial.node');

var sumnumber = require('./node_cpp/sum_perfomance/build/Release/sum_perfomance.node');

function countSum(longValue){
    var sum = 0;
    while(longValue > 0){
        sum += 1;
        longValue--;
    }
    return sum;
}
console.time('C++');
console.log(sumnumber.sumNow(1000000000));
console.timeEnd('C++');


console.time('js');
console.log(countSum(1000000000));
console.timeEnd('js');



