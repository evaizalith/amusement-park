var http = require("http");
var fs = require('fs');
var url = require('url');
var mysql = require('mysql');
const express = require('express');
const { Hash } = require("crypto");

const host = 'localhost';
const port = 8080;

dir = "../../";

var db = mysql.createConnection({
    host: "localhost",
    user: "googalake2",
    password: "",
    database: "amusement-park"
});

db.connect(function(err) {
    if(err) throw err;
    console.log("Connected to database");
});

function addUser(visitor_id, password, email) {
    get_max = "SELECT max(user_id) FROM userAccounts";
    max_id = db.query(get_max, function (err, result) {
        if (err) throw (err);
        console.log(result);
        return result; 
    });

    new_id = max_id + 1;

    new_user = "INSERT INTO userAccounts VALUES (" + new_id + ", " + visitor_id, + ", " + password, + ", " + email;
    
    db.query(new_user, function(err, result) {
        if (err) throw (err);
        console.log(result);
    })
}

server = http.createServer((req, res) => {
    console.log(`Request received: ${req.url}, ${req.method}`);

    addUser(12345, "password", "user@email.com");

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
        case '/checkout':
            file += "checkout.html";
            break;
        case '/login':
            file += "login.html";
            break;
        case '/rides':
            file += "ridesExperience.html";
            break;
        case '/signup':
            file += "signup.html";
            break;
        case '/tickets':
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
