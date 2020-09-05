module.exports = function(){
    var express = require('express');
    var router = express.Router();

    function getExhibits(res, mysql, context, complete){
            mysql.pool.query("SELECT * FROM exhibits", function(error, results, fields){
                if(error){
                    res.write(JSON.stringify(error));
                    res.end();
                }
                context.exhibits = results;
        
                    mysql.pool.query("SELECT zookeepers.keeper_id as keeper_id, keeper_name FROM zookeepers", function(error, results, fields){
                        if(error){
                            res.write(JSON.stringify(error));
                            res.end();
                        }
                        context.addanimal2 = results;
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
                res.render('zookeepertoexhibits', {
                    exhibits: context.exhibits,
                    addanimal2: context.addanimal2,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'All Exhibits',
                    java: 'allzootoexh.js',
                    java1: 'deleteexhibit.js',
                    java2: 'editzooex.js' 
                });
            }
        }
    });

    function getSearch(res, req, mysql, context, complete) {
        var sq = "SELECT * FROM zookeepers_exhibits INNER JOIN exhibits ON zookeepers_exhibits.exhibit_id = exhibits.exhibit_id WHERE keeper_id = (SELECT zookeepers.keeper_id FROM zookeepers WHERE zookeepers.keeper_name = '";
        var counter = 0;

        if (req.body.exhibit_home != '') {sq = sq + req.body.exhibit_home + "\')";}
        else {sq = "SELECT * FROM exhibits"}

        mysql.pool.query(sq,function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.exhibits = results;
            mysql.pool.query("SELECT zookeepers.keeper_id as keeper_id, keeper_name FROM zookeepers", function(error, results, fields){
                if(error){
                    res.write(JSON.stringify(error));
                    res.end();
                }
                context.addanimal2 = results;
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
                res.render('zookeepertoexhibits', {
                    exhibits: context.exhibits,
                    addanimal2: context.addanimal2,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'All Exhibits',
                    java: 'allzootoexh.js',
                    java1: 'deleteexhibit.js',
                    java2: 'editzooex.js' 
                });
            }

        }

    });

    router.put('/:exhibit_id', function(req, res){
        var mysql = req.app.get('mysql');

        var sql = "UPDATE exhibits SET exhibit_id=" + req.params.exhibit_id + ", exhibit_name=" + req.body.keeper_name 
                    + ", max_species=" + req.body.max_exhibits + ", exhibit_size=" + req.body.keeper_total
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

