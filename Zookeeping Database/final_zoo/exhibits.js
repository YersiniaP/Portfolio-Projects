module.exports = function(){
    var express = require('express');
    var router = express.Router();

    function getExhibits(res, mysql, context, complete){
        mysql.pool.query("SELECT * FROM exhibits", function(error, results, fields){
            if(error){
                console.log(JSON.stringify(error))
                res.write(JSON.stringify(error));
                res.end();
            }
            context.exhibits = results;
            complete();
        });
    }

    function getSearch(res, req, mysql, context, complete) {
        var sq = "SELECT * FROM exhibits WHERE ";
        var counter = 0;
    
        if (req.body.species_in_exhibit_max != '' || req.body.species_in_exhibit_min != '') {
            if (req.body.species_in_exhibit_max != '' && req.body.species_in_exhibit_min != '') {
                sq = sq + "max_species" + " >= " + req.body.species_in_exhibit_min + " && max_species" 
                + " <= " + req.body.species_in_exhibit_max;
            }
            else if(req.body.species_in_exhibit_max == '') {
                sq = sq + "max_species" + " >= " + req.body.species_in_exhibit_min
            }
            else if(req.body.species_in_exhibit_min == '') {
                sq = sq + "max_species" + " <= " + req.body.species_in_exhibit_max
            }
            counter = 1;
        }

        if (req.body.exhibit_total_max != '' || req.body.exhibit_total_min != '') {
            if (counter == 1) {sq = sq + " && "}
            if (req.body.exhibit_total_max != '' && req.body.exhibit_total_min != '') {
                sq = sq + " exhibit_size >= " + req.body.exhibit_total_min + " && exhibit_size <= " 
                + req.body.exhibit_total_max;
            }
            else if(req.body.exhibit_total_max == '') {
                sq = sq + " exhibit_size" + " >= " + req.body.exhibit_total_min
            }
            else if(req.body.exhibit_total_min == '') {
                sq = sq + " exhibit_size <= " + req.body.exhibit_total_max
            }
        }

        else if(req.body.species_in_exhibit_max == '' && req.body.species_in_exhibit_min == '' && req.body.exhibit_total_max == '' && req.body.exhibit_total_min == '') {
            sq = "SELECT * FROM exhibits";
        }

        mysql.pool.query(sq, function(error, results, fields){
            if(error){
                console.log(JSON.stringify(error))
                res.write(JSON.stringify(error));
                res.end();
            }
            context.exhibits = results;
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
                res.render('exhibits', {
                    exhibits: context.exhibits,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'All Exhibits',
                    id: context.exhibits.exhibit_id,
                    java: 'allexhibits.js',
                    java1: 'deleteexhibit.js',
                    java2: 'editexhibit.js' 
                });
            }
        }
    });

    router.post('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        var mysql = req.app.get('mysql');

        getSearch(res, req, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 1){
                res.render('exhibits', {
                    exhibits: context.exhibits,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'ALL Exhibits',
                    id: context.exhibits.exhibit_id,
                    java: 'allexhibits.js',
                    java1: 'deleteexhibit.js',
                    java2: 'editexhibit.js'
                });
            }

        }

    });


    router.put('/:exhibit_id', function(req, res){
        var mysql = req.app.get('mysql');

        var sql = "UPDATE exhibits SET exhibit_id=" + req.params.exhibit_id + ", exhibit_name=" + req.body.exhibit_name11 
                    + ", max_species=" + req.body.species_in_exhibit11 + ", exhibit_size=" + req.body.exhibit_total11 
                    + " WHERE exhibit_id=" + req.params.exhibit_id;
        
        sql = mysql.pool.query(sql,function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }else{
                res.status(200);
                res.end();
            }
        });
    })




    router.delete('/:exhibit_id', function(req, res){
        var mysql = req.app.get('mysql');
        var sq = "DELETE FROM exhibits WHERE exhibit_id = ";
        sq = sq + req.params.exhibit_id;
        
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

