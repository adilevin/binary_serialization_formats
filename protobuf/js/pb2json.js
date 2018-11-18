let program = require('commander');
let Conv = require('./Conv');

program
.version('0.1.0')
.option('-p, --proto <proto>', 'Path to .proto file')
.option('-m, --message <message>', 'Name of message')
.option('-i, --input <input>', 'Path to input binary file')
.parse(process.argv);

var c = new Conv(program.proto, program.message);
console.log(c.pb2json(program.input));
