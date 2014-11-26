/**
 * Created by Administrator on 14-11-21.
 */
var http = require("http"),
    url = require("url"),
    path = require("path"),
    fs = require("fs")
port = process.argv[2] || 3000;

var mimeTypes = {
    "htm": "text/html",
    "html": "text/html",
    "jpeg": "image/jpeg",
    "jpg": "image/jpeg",
    "png": "image/png",
    "gif": "image/gif",
    "js": "text/javascript",
    "css": "text/css"};

var virtualDirectories = {
    //"images": "../images/"
};

http.createServer(function(request, response) {

    var uri = url.parse(request.url).pathname
        , filename = path.join(process.cwd(), uri)
        , root = uri.split("/")[1]
        , virtualDirectory;
    console.log(uri);
    console.log(filename);
    console.log(root);

    virtualDirectory = virtualDirectories[root];
    if(virtualDirectory){
        uri = uri.slice(root.length + 1, uri.length);
        filename = path.join(virtualDirectory ,uri);
    }

    path.exists(filename, function(exists) {
        if(!exists) {
            response.writeHead(404, {"Content-Type": "text/plain"});
            response.write("404 Not Found\n");
            response.end();
            console.error('404: ' + filename);
            return;
        }

        if (fs.statSync(filename).isDirectory()) filename += '/index.html';

        fs.readFile(filename, "binary", function(err, file) {
            if(err) {
                response.writeHead(500, {"Content-Type": "text/plain"});
                response.write(err + "\n");
                response.end();
                console.error('500: ' + filename);
                return;
            }
            var mimeType = mimeTypes[path.extname(filename).split(".")[1]];
            response.writeHead(200, {"Content-Type": mimeType});
            response.write(file, "binary");
            response.end();
            console.log('200: ' + filename + ' as ' + mimeType);
        });
    });
}).listen(parseInt(port, 10));

console.log("Static file server running at\n  => http://localhost:" + port + "/\nCTRL + C to shutdown");