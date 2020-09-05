module.exports = function(){
    var express = require('express');
    var router = express.Router();

    function getExhandAni(res, mysql, context, complete){
        mysql.pool.query("SELECT exhibits.exhibit_id as exhibit_id, exhibit_name FROM exhibits", function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.addanimal1 = results;

            mysql.pool.query("SELECT species.species_id as species_id, species_name FROM species", function(error, results, fields){
                if(error){
                    res.write(JSON.stringify(error));
                    res.end();
                }
                context.addanimal2 = results;
                complete();
            });
        });
    }

    function getAnimals(res, mysql, context, complete){
        mysql.pool.query("SELECT * FROM animals", function(error, results, fields){
            if(error){
                res.write(JSON.stringify(error));
                res.end();
            }
            context.animals = results;

            mysql.pool.query("SELECT exhibits.exhibit_id as exhibit_id, exhibit_name FROM exhibits", function(error, results, fields){
                if(error){
                    res.write(JSON.stringify(error));
                    res.end();
                }
                context.addanimal1 = results;
    
                mysql.pool.query("SELECT species.species_id as species_id, species_name FROM species", function(error, results, fields){
                    if(error){
                        res.write(JSON.stringify(error));
                        res.end();
                    }
                    context.addanimal2 = results;
                    complete();
                });
            });
        });
    }

    router.get('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        var mysql = req.app.get('mysql');
        getAnimals(res, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 1){
                res.render('animals', {
                    animals: context.animals,
                    addanimal1: context.addanimal1,
                    addanimal2: context.addanimal2,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    java: 'allanimals.js',
                    java1: 'deleteanimal.js',
                    java2: 'editanimal.js' 
                });
            }

        }
    });


    function getSearch(res, req, mysql, context, complete) {
        var sq = "SELECT * FROM animals WHERE ";
        var counter = 0;

        if (req.body.exhibit_home != '' || req.body.species_type != '') {
            if (req.body.exhibit_home != '' && req.body.species_type != '') {
                sq = sq + "exhibit_home = " + "\"" + req.body.exhibit_home + "\"" + " && species_type = "
                 + "\"" + req.body.species_type + "\"";
            }
            else if(req.body.exhibit_home != '') {
                sq = sq + "exhibit_home = " + "\"" + req.body.exhibit_home + "\"";
            }
            else if(req.body.species_type != '') {
                sq = sq + "species_type = " + "\"" + req.body.species_type + "\"";
            }
        }

        else {sq = "SELECT * FROM animals"}

        mysql.pool.query(sq, function(error, results, fields){
            if(error){
                console.log(JSON.stringify(error))
                res.write(JSON.stringify(error));
                res.end();
            }
            context.animals = results;

            mysql.pool.query("SELECT exhibits.exhibit_id as exhibit_id, exhibit_name FROM exhibits", function(error, results, fields){
                if(error){
                    res.write(JSON.stringify(error));
                    res.end();
                }
                context.addanimal1 = results;
    
                mysql.pool.query("SELECT species.species_id as species_id, species_name FROM species", function(error, results, fields){
                    if(error){
                        res.write(JSON.stringify(error));
                        res.end();
                    }
                    context.addanimal2 = results;
                    complete();
                });
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
                res.render('animals', {
                    animals: context.animals,
                    addanimal1: context.addanimal1,
                    addanimal2: context.addanimal2,
                    style: 'addexhibit.css',
                    style1: 'all.css',
                    title: 'Searched Exhibits',
                    java: 'allanimals.js',
                    java1: 'deleteanimal.js',
                    java2: 'editanimal.js' 
                });
            }

        }

    });


    router.put('/:animal_id', function(req, res){
        var mysql = req.app.get('mysql');

        var sql = "UPDATE animals SET animal_id=" + req.params.animal_id + ", animal_name=" + req.body.animal_name 
                    + ", exhibit_home='" + req.body.exhibit_home + "', species_type='" + req.body.species_type 
                    + "' WHERE animal_id=" + req.params.animal_id;
        
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




    router.delete('/:animal_id', function(req, res){
        var mysql = req.app.get('mysql');
        var sq = "DELETE FROM animals WHERE animal_id = ";
        sq = sq + req.params.animal_id;
        
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
