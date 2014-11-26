/**
 * Created by Administrator on 14-11-20.
 */
var http =require('http');
var urlParser = require('url');
var util = require('util');
var querystring =require('querystring');
var jsonstr='';

var mongodb = require("./node_modules/mongoose/node_modules/mongodb");

var server = new mongodb.Server('localhost',27017,{auto_reconnect:true});

var db = new mongodb.Db("test",server,{safe:false});

db.open(function(err,db){
    if(err){
        console.log(err);
        return false;
    }
    console.log("We are connected!");
    db.collection('test',{safe:true},function(err,collection){
        collection.find({unique:{"$exists":true}}).toArray(function(err,items){
            if(err){
                console.log(err);
                return false;
            }
            for(item in items) console.log(items[item]);
            //process.exit();
        });
    });
});



http.createServer(function(req,res){
    var urlObject = urlParser.parse(req.url, true),
            obj = urlObject.query,
            pathname = decodeURIComponent(urlObject.pathname),
            requesttype = pathname.split("/")[1];
    console.log("urlObject------- "+urlObject+" requesttype "+requesttype);
    if(req.method == 'GET')
    {
        if(requesttype === "login"){
            console.log(urlObject.query.username);//返回001
            console.log(urlObject.query.passwd);//返回002
            if(urlObject){
                jsonstr = JSON.stringify(urlObject);
                res.write(jsonstr);
                res.end("  success json");
            }else{
                res.end("format error");
            }
        }else if(requesttype == "show")
        {
            console.log(urlObject.query.username);//返回001
            console.log(urlObject.query.passwd);//返回002
            if(urlObject){
                jsonstr = JSON.stringify(urlObject);
                res.write(jsonstr);
                res.end("  success json");
            }else{
                res.end("  format error");
            }
        }else{
            //res.write(jsonstr);
            res.end("  error or can't find argument json");
        }
    }else if(req.method == 'POST')
    {
        res.end("  this is a post method json");
    }else{
        res.end(" can't support this type");
    }


    //然后就可以根据所得到的数据处理了

}).listen(3000);
console.log("HTTP server is listening at port 3000");
