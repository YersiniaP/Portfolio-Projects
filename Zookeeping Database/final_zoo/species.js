module.exports = function(){
    var express = require('express');
    var router = express.Router();

    function getExhibits(res, mysql, context, complete){
        mysql.pool.query("SELECT * FROM species", function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.species = results;

            mysql.pool.query("SELECT exhibits.exhibit_id as exhibit_id, exhibit_name FROM exhibits", function(error, results, fields){
                if(error){
                    res.write(JSON.stringify(error));
                    res.end();
                }
                context.addspecies = results;
                complete();
            });
            
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
                res.render('species', {
                    addspecies: context.addspecies,
                    species: context.species,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'ALL Exhibits',
                    java: 'allspecies.js',
                    java1: 'deletespecies.js',
                    java2: 'editspecies.js' 
                });
            }

        }
    });

    
    function getSearch(res, req, mysql, context, complete) {
        var sq = "SELECT * FROM species WHERE ";
        var counter = 0;

        if(req.body.exhibit_home != '') {
            sq = sq + "species_location = " + "\"" + req.body.exhibit_home + "\" ";
            counter = 1;
        }
        if(req.body.wild_pop_min != '' || req.body.wild_pop_max != '') {
            if(counter = 1) {sq = sq + "&& "}
            if(req.body.wild_pop_min != '' && req.body.wild_pop_max != '') {
                sq = sq + "wild_population >= " + req.body.wild_pop_min +
                 " && wild_population <= " + req.body.wild_pop_max;
            }
            else if(req.body.wild_pop_min != '') {
                sq = sq + "wild_population >= " + req.body.wild_pop_min;
            }
            else if(req.body.wild_pop_max != '') {
                sq = sq + "wild_population <= " + req.body.wild_pop_max;
            }
        }
        if(req.body.wild_pop_min == '' && req.body.wild_pop_max == '' && req.body.exhibit_home == '') {sq = "SELECT * FROM species";}

        mysql.pool.query(sq, function(error, results, fields){
            if(error){
                console.log(JSON.stringify(error))
                res.write(JSON.stringify(error));
                res.end();
            }
            context.species = results;

            mysql.pool.query("SELECT exhibits.exhibit_id as exhibit_id, exhibit_name FROM exhibits", function(error, results, fields){
                if(error){
                    res.write(JSON.stringify(error));
                    res.end();
                }
                context.addspecies = results;
                complete();
            });
        });

    }

    router.post('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        var mysql = req.app.get('mysql');

        getSearch(res, req, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 1){
                res.render('species', {
                    addspecies: context.addspecies,
                    species: context.species,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'ALL Exhibits',
                    java: 'allspecies.js',
                    java1: 'deletespecies.js',
                    java2: 'editspecies.js'  
                });
            }

        }

    });

    router.put('/:species_id', function(req, res){
        var mysql = req.app.get('mysql');

        var sql = "UPDATE species SET species_id=" + req.params.species_id + ", species_name=" + req.body.species_name 
                    + ", species_location='" + req.body.species_location + "', wild_population=" + req.body.wild_population 
                    + " WHERE species_id=" + req.params.species_id;
        
        sql = mysql.pool.query(sql,function(error, results, fields){
            if(error){
                console.log(error)
                res.write(JSON.stringify(error));
                res.end();
            }else{
                res.status(200);
                res.end();
            }
        });
    })




    router.delete('/:species_id', function(req, res){
        var mysql = req.app.get('mysql');
        var sq = "DELETE FROM species WHERE species_id = ";
        sq = sq + req.params.species_id;
        
        sq = mysql.pool.query(sq, function(error, results, fields){
            if(error){
                console.log(error)
                res.write(JSON.stringify(error));
                res.status(400);
                res.end();
            }else{
                res.status(202).end();
            }
        })
    })

    return router;
}();