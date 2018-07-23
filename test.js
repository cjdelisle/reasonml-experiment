const PORT = 9009;
const HOST = '127.0.0.1';
const Udp = require('dgram');
const main = () => {
    const cli = Udp.createSocket('udp4');
    const msg = new Buffer("Hello World", "utf8");
    cli.send(msg, 0, msg.length, PORT, HOST, (err, bytes) => {
        if (err) { throw err; }
        console.log('UDP message sent to ' + HOST +':'+ PORT);
    });
    cli.on('message', (message, remote) => {
        console.log('Received: ' + remote.address + ':' + remote.port +' - ' + message);
        if (message.toString('utf8') === 'Hello World') { cli.close(); }
    });
    setTimeout(() => {
        console.log("Failed");
        process.exit(100);
    }, 1000);
};
main();