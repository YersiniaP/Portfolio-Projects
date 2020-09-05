var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit : 10,
  host            : 'classmysql.engr.oregonstate.edu',
  user            : 'cs340_schneisa',
  password        : '6621',
  database        : 'cs340_schneisa'
});
module.exports.pool = pool;
