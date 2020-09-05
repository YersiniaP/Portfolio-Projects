
module.exports = function(){
    var express = require('express');
    var router = express.Router();

    function getExhibits(res, mysql, context, complete){
        mysql.pool.query("SELECT exhibits.exhibit_id as exhibit_id, exhibit_name FROM exhibits", function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.addspecies = results;
            complete();
        });
    }
    
    router.get('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        var mysql = req.app.get('mysql');
        getExhibits(res, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 1){
                res.render('addspecies', {
                    addspecies: context.addspecies,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    java: 'addspec.js'
                });
            }
    
        }
    });

    router.post('/', function(req, res){
        var mysql = req.app.get('mysql');
        var sql = "INSERT INTO species (species_id, species_name, species_location, wild_population) VALUES (?,?,?,?)";
        var inserts = [req.body.species_id, req.body.species_name, req.body.species_location, req.body.wild_population];
        if (req.body.species_name == '' || req.body.species_location == '') {}

        else{

            sql = mysql.pool.query(sql,inserts,function(error, results, fields){
                if(error){
                    res.redirect('/addspecies');
                }
                else{}
            });
        }
    });

    return router;
}();
