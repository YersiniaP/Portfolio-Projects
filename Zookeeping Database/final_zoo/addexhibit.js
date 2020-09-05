module.exports = function(){
    var express = require('express');
    var router = express.Router();

    router.post('/', function(req, res){
        var dup = false;

        var mysql = req.app.get('mysql');
        var sql = "INSERT INTO exhibits (exhibit_id, exhibit_name, max_species, exhibit_size) VALUES (?,?,?,?)";
        var inserts = [req.body.exhibit_id, req.body.exhibit_name, req.body.species_in_exhibit, req.body.exhibit_total];
        var context = {};
        if (req.body.exhibit_id == '' || req.body.exhibit_name == '' || req.body.species_in_exhibit == '' || req.body.exhibit_total == '') {}
        else{
            sql = mysql.pool.query(sql,inserts,function(error, results, fields){
                if(error){
                    if (error.sqlMessage = "Duplicate entry") {
                        dup = true;
                        res.redirect('/addexhibit');
                    }
                }
                else{}
            });
        }
    });

    router.put('/:exhibit_id', function(req, res){
        var mysql = req.app.get('mysql');
        console.log(req.body);
        
        var v = [req.body.species_in_exhibit11 ]
        console.log(v);

        var sql = "UPDATE exhibits SET exhibit_id=" + req.params.exhibit_id + ", exhibit_name=" + req.body.exhibit_name11 
                    + ", max_species=" + req.body.species_in_exhibit11 + ", exhibit_size=" + req.body.exhibit_total11 
                    + " WHERE exhibit_id=" + req.params.exhibit_id;
        
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
