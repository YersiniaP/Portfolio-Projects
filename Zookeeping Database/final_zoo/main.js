var express = require('express');
var mysql = require('./dbcon.js');
var bodyParser = require('body-parser');

var app = express();
var handlebars = require('express-handlebars').create({
        defaultLayout:'main',
        });

app.engine('handlebars', handlebars.engine);
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static('public'));
app.set('view engine', 'handlebars');
app.set('port', process.argv[2]);
app.set('mysql', mysql);


app.use('/exhibits', require('./exhibits.js'));
app.use('/animals', require('./animals.js'));
app.use('/species', require('./species.js'));
app.use('/zookeepers', require('./zookeepers.js'));
app.use('/addexhibit', require('./addexhibit.js'));
app.use('/addspecies', require('./addspecies.js'));
app.use('/addanimal', require('./addanimal.js'));
app.use('/addkeep', require('./addkeep.js'));
app.use('/animalsinexhibit', require('./animalsinexhibit.js'));
app.use('/addkeepspeciesinexhibit', require('./speciesinexhibit.js'));
app.use('/stafftoanimals', require('./stafftoanimals.js'));
app.use('/stafftoexhibit', require('./stafftoexhibit.js'));
app.use('/zookeepertoexhibits', require('./zookeepertoexhibits.js'));
app.use('/exhibittozookeeper', require('./exhibittozookeeper.js'));


app.get('/', (req,res) => {
  res.render('lowindex', { 
    style: 'lowindex.css'
   });
});

//all the add pages 
app.get('/addexhibit', (req,res) => {
  res.render('addexhibit', { 
    style: 'addexhibit.css',
    java: 'add.js',
    java1: 'deleteexhibit.js',
    java2: 'editexhibit.js'
   });
});
app.get('/addkeep', (req,res) => {
  res.render('addkeep', { 
    style: 'addexhibit.css',
    java: 'addzoo.js',
    java1: 'deleteexhibit.js',
    java2: 'editexhibit.js'
   });
});

//this is the map and about us page
app.get('/map', (req,res) => {
  res.render('map', { 
    style: 'zoomap.css'
   });
});
app.get('/aboutus', (req,res) => {
  res.render('aboutus', { 
    style: 'aboutus.css'
   });
});

//start up the server
app.listen(8080, function(){
  console.log('Express started on http://localhost:' + 8080 + '; press Ctrl-C to terminate.');
});
