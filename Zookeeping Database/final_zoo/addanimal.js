
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
    
    router.get('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        var mysql = req.app.get('mysql');
        getExhandAni(res, mysql, context, complete);

        function complete(){
            callbackCount++;
            if(callbackCount <= 2){
                if (callbackCount == 2) {
                }
                else {
                    res.render('addanimal', {
                        addanimal1: context.addanimal1,
                        addanimal2: context.addanimal2,
                        style: 'addexhibit.css',
                        style1: 'all.css',
                        java: 'addani.js'
                    });
                }
            }
    
        }
    });

    router.post('/', function(req, res){
        
        var mysql = req.app.get('mysql');
        var sql = "INSERT INTO animals (animal_id, animal_name, exhibit_home, species_type) VALUES (?,?,?,?)";
        var inserts = [req.body.animal_id, req.body.animal_name, req.body.exhibit_home, req.body.species_type];
         var bo = true;

        if (req.body.animal_name  =='') {}

        else{

            sql = mysql.pool.query(sql,inserts,function(error, results, fields){
                if(error){
                    res.redirect('/addanimal');
                }
                else{}
            });
        }
    });


    return router;
}();
