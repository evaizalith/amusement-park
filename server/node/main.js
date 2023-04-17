const http = require("http");
const fs = require('fs').promises;

const host = 'localhost';
const port = 8080;

dir = "../../"

function createServer(req, res) {
    var path = url.parse(req.url).pathname;
    var fsCallback = function(error, data) {
        if(error) throw error;

        res.writeHead(200);
        res.write(data);
        res.end();
    }

    switch(path) {
        case '/404':
            doc = fs.readFile(dir + '/404.html', fsCallback);
        break;
        default:
            doc = fs.readFile(dir + '/main.html', fsCallback);
        break;
    }
}

app.listen(port);
