module.exports = function(){
    var express = require('express');
    var router = express.Router();

    function getExhibits(res, mysql, context, complete){
        mysql.pool.query("SELECT * FROM zookeepers", function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.zookeepers = results;
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
                res.render('zookeepers', {
                    zookeepers: context.zookeepers,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    java: 'allzookeepers.js',
                    java1: 'deletezookeepers.js',
                    java2: 'editzookeepers.js'
                });
            }

        }
    });


    function getSearch(res, req, mysql, context, complete) {
        var sq = "SELECT * FROM zookeepers WHERE ";
        var counter = 0;
    
        if (req.body.zoo_exhibit_max != '' || req.body.zoo_exhibit_min != '') {
            if (req.body.zoo_exhibit_max != '' && req.body.zoo_exhibit_min != '') {
                sq = sq + "max_exhibits" + " >= " + req.body.zoo_exhibit_min + " && max_exhibits" 
                + " <= " + req.body.zoo_exhibit_max;
            }
            else if(req.body.zoo_exhibit_max == '') {
                sq = sq + "max_exhibits" + " >= " + req.body.zoo_exhibit_min
            }
            else if(req.body.zoo_exhibit_min == '') {
                sq = sq + "max_exhibits" + " <= " + req.body.zoo_exhibit_max
            }
            counter = 1;
        }

        if (req.body.animal_total_max != '' || req.body.animal_total_min != '') {
            if (counter == 1) {sq = sq + " && "}
            if (req.body.animal_total_max != '' && req.body.animal_total_min != '') {
                sq = sq + " keeper_total >= " + req.body.animal_total_min + " && keeper_total <= " 
                + req.body.animal_total_max;
            }
            else if(req.body.animal_total_max == '') {
                sq = sq + " keeper_total" + " >= " + req.body.animal_total_min
            }
            else if(req.body.animal_total_min == '') {
                sq = sq + " keeper_total <= " + req.body.animal_total_max
            }
        }

        else if(req.body.zoo_exhibit_max  == '' && req.body.zoo_exhibit_min == '' && req.body.animal_total_max == '' && req.body.animal_total_min == '') {
            sq = "SELECT * FROM zookeepers";
        }

        mysql.pool.query(sq, function(error, results, fields){
            if(error){
                console.log(JSON.stringify(error))
                res.write(JSON.stringify(error));
                res.end();
            }
            context.zookeepers = results;
            complete();
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
                res.render('zookeepers', {
                    zookeepers: context.zookeepers,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'ALL Exhibits',
                    java: 'allzookeepers.js',
                    java1: 'deletezookeepers.js',
                    java2: 'editzookeepers.js' 
                });
            }

        }

    });

    router.put('/:keeper_id', function(req, res){
        var mysql = req.app.get('mysql');

        var sql = "UPDATE zookeepers SET keeper_id=" + req.params.keeper_id + ", keeper_name=" + req.body.keeper_name 
                    + ", max_exhibits=" + req.body.max_exhibits + ", keeper_total=" + req.body.keeper_total
                    + " WHERE keeper_id=" + req.params.keeper_id;
        
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




    router.delete('/:keeper_id', function(req, res){
        var mysql = req.app.get('mysql');
        console.log('hey');
        var sq = "DELETE FROM zookeepers WHERE keeper_id = ";
        sq = sq + req.params.keeper_id;
        
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