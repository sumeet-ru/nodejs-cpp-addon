var factorial = require('./node_cpp/factorial/build/Release/factorial.node');


console.time('factorial');
console.log(factorial.find(50));
console.timeEnd('factorial');