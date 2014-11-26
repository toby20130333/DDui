/**
 * Created by Administrator on 14-11-24.
 */

var express = require('express');
var app = express();
//接着，我们可以使用app.动词()定义路由。
//比如使用"GET /"响应"Hello World"字符串，因为res、req都是Node提供的准确的对象，因此你可以调用res.pipe()
//或req.on('data', callback)或者其它。
//app.get('/hello.txt', function(req, res){
//    var body = 'Hello World';
//    res.setHeader('Content-Type', 'text/plain');
//    res.setHeader('Content-Length', body.length);
//    res.end(body);
//});

//ExpressJS框架提供了更高层的方法，比如res.send()，它可以省去诸如添加Content-Length之类的事情。如下：
//处理GET请求
//http://127.0.0.1:8080/hello/?name=wujintao&email=cino.wu@gmail.com
app.get('/hello/*', function(req, res){
    console.log(req.query.name);
    console.log(req.query.email);
    res.send('Get Over');
});
//以上表示凡是url能够匹配/hello/*的GET请求，服务器都将向客户端发送字符串“Hello World"

//app.get('/', function(req, res){
// res.render('index', {
//    title: 'Express'
//  });
//});
//上面的代码意思是，get请求根目录则调用views文件夹中的index模板，并且传入参数title为“Express”，这个title就可以在模板文件中直接使用。


//现在可以绑定和监听端口了，调用app.listen()方法，接收同样的参数，比如：
app.listen(8080);
console.log('Listening on port 8080');