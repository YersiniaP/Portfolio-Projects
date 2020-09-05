module.exports = function(){
    var express = require('express');
    var router = express.Router();

    router.post('/', function(req, res){
        // console.log(req.body);
        
        var mysql = req.app.get('mysql');
        var sql = "INSERT INTO zookeepers (keeper_id, keeper_name, max_exhibits, keeper_total) VALUES (?,?,?,?)";
        var inserts = [req.body.keeper_id, req.body.keeper_name, req.body.max_exhibits, req.body.keeper_total];
        // var bo = dup(req, res, mysql, context);

        if (req.body.keeper_id == '' || req.body.keeper_name == '' || req.body.max_exhibits == '' || req.body.keeper_total == '') {}

        // else if(bo == true) {

        // }

        else{

            sql = mysql.pool.query(sql,inserts,function(error, results, fields){
                if(error){
                    res.redirect('/addkeep');
                }
                else{}
            });
        }
    });


    return router;
}();
