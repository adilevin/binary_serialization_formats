var protobuf = require('protobufjs');
var fs = require('fs');
let program = require('commander');

class Conv {

    constructor(proto_filepath, message_name) {
        let root = protobuf.loadSync(proto_filepath);
        this.message_type = root.lookupType(message_name);
    }

    obj2pb(obj) {
        var message = this.message_type.fromObject(obj);
        return this.message_type.encode(message).finish();
    }

    pb2obj(pb) {
        return this.message_type.decode(pb);
    }

    json2pb_file(json_filename, pb_filename) {
        let json = fs.readFileSync(json_filename, { encoding: 'utf8' });
        let pb = this.obj2pb(JSON.parse(json));
        fs.writeFileSync(pb_filename, pb);
    }

    pb2json(pb_filename) {
        let pb = fs.readFileSync(pb_filename);
        let obj = this.pb2obj(pb);
        return JSON.stringify(obj, null, '  ');
    }

    pb2json_file(pb_filename, json_filename) {
        fs.writeFileSync(json_filename, this.pb2json(pb_filename));
    }

}

function validate_args(cb) {
    if (!(program.proto && program.message && program.input && program.output))
        program.outputHelp();
    else
        cb();
}


program
.option('-p, --proto <proto>', 'Path to .proto file')
.option('-m, --message <message>', 'Name of message')
.option('-i, --input <input>', 'Path to input file')
.option('-o, --output <output>','Path to output file')

program
.command('pb2json')
.action(function() {
    validate_args(() => {    
        var c = new Conv(program.proto, program.message);
        c.pb2json_file(program.input, program.output);
    });
});

program
.command('json2pb')
.action(function() {
    validate_args( () => {
        var c = new Conv(program.proto, program.message);
        c.json2pb_file(program.input, program.output);
    });
});

program.on('--help', function(){
    console.log('');
    console.log('  Examples:');
    console.log('');
    console.log('    $ node Conv.js --help');
    console.log('    $ node Conv.js --proto ../proto/my_proto.proto -m MyMessage -i ./input.json -o ./output.bin json2pb');
    console.log('    $ node Conv.js --proto ../proto/my_proto.proto -m MyMessage -i ./input.bin -o ./output.json pb2json2');    
    console.log('');
  });

program.parse(process.argv);
