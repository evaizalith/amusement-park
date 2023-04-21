var http = require("http");
var fs = require('fs');
var url = require('url');
const express = require('express');

const host = 'localhost';
const port = 8080;

dir = "../../";

server = http.createServer((req, res) => {
    console.log(`Request received: ${req.url}, ${req.method}`);

    var path = url.parse(req.url).pathname;
    var fsCallback = function(error, data) {
        if(error) throw error;

        res.writeHead(200);
        res.write(data);
        res.end();
    }

    file = dir; 

    switch(path) {
        case '/':
            file += "home.html";
            break;
        case '/info':
            file += "parkInfo.html";
            break;
        case 'checkout':
            file += "checkout.html";
            break;
        case 'login':
            file += "login.html";
            break;
        case 'rides':
            file += "ridesExperience.html";
            break;
        case 'signup':
            file += "signup.html";
            break;
        case 'tickets':
            file += "ticketsPasses.html";
            break;
        default:
            file += "404.html";
            break;
    }

    docs = fs.readFile(file, fsCallback);
});

server.listen(port, function(error) {
    if(!error)
        console.log(`Server is running on ${host}:${port}`);
    else
        console.log("An error has occurred; server has not started.");
});
