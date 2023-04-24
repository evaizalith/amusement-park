var http = require("http");
var fs = require('fs');
var url = require('url');
var mysql = require('mysql');
const express = require('express');

const host = 'localhost';
const port = 8080;

dir = "../../";

var db = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",
    database: "amusement-park"
});

db.connect(function(err) {
    if(err) throw (err);
    console.log("Connected to database");
});

function addUser(visitor_id, password, email) {
    //Implement hashing later 
    hash = password;

    new_user = "INSERT INTO userAccounts (visitor_id, password, email) VALUES (" 
    + visitor_id + ", "
    + "\"" + hash + "\""  + ", " 
    + "\"" + email + "\");";
    
    db.query(new_user, function(err, result) {
        if (err) throw (err);
        console.log(result);
    })
}

function addEmployee(emp_id, password, email) {
    //Implement hashing later 
    hash = password;

    new_user = "INSERT INTO staffAccounts (emp_id, password, email) VALUES (" 
    + emp_id + ", "
    + "\"" + hash + "\""  + ", " 
    + "\"" + email + "\");";
    
    db.query(new_user, function(err, result) {
        if (err) throw (err);
        console.log(result);
    })
}

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
        case '/checkout':
            file += "checkout.html";
            break;
        case '/login':
            file += "login.html";
            break;
        case '/rides':
            file += "ridesExperiences.html";
            break;
        case '/signup':
            file += "signup.html";
            break;
        case '/tickets':
            file += "ticketsPasses.html";
            break;
        case '/search':
            file += "Search.html";
            break;
        case '/staff-info':
            file += "staffInfo.html";
            break;
        case '/dashboard':
            file += "staffhomepage.html";
            break;
        case '/staff-login':
            file += "staffsignin.html";
            break;
        case '/schedules':
            file += "EmpHours.html";
            break;
        case '/management':
            file += "managerhomepage.html";
            break;
        case '/images/jpg/GeaugaLakeIsReal.jpg':
            file += "images/jpg/GeaugaLakeIsReal.jpg";
            break;
        case '/images/jpg/redRollerCoaster.jpg':
            file += "/images/jpg/redRollerCoaster.jpg";
            break;
        case '/images/png/bastard.png':
            file += "/images/png/bastard.png";
            break;
        case '/images/png/Arcade.png':
            file += "/images/png/Arcade.png";
            break;
        case '/images/jpg/mylifeislikeavideogame.jpg':
            file += "/images/jpg/mylifeislikeavideogame.jpg";
            break;
        case '/images/jpg/RobinsWildRide.jpg':
            file += "/images/jpg/RobinsWildRide.jpg";
            break;
        case '/images/jpg/ferris_wheel.jpg':
            file += "/images/jpg/ferris wheel.jpg";
            break;
        case '/images/jpg/contract.jpg':
            file += "/images/jpg/contract.jpg";
            break;
        case '/styles/Accordion.css':
            file += "/styles/Accordion.css";
            break;
        case '/styles/Card.css':
            file += '/styles/Card.css';
            break;
        case '/styles/checkout.css':
            file += '/styles/checkout.css';
            break;
        case '/styles/login.css':
            file += '/styles/login.css';
            break;
        case '/styles/searchBar.css':
            file += '/styles/searchBar.css';
            break;
        case '/searchBar.js':
            file += '/searchBar.js';
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
