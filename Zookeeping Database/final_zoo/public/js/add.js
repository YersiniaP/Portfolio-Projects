
//counts how many new posts there Are
var posts = "0";
var buttonh = "10";

//finds out what add function
var tit = document.getElementById('find-add').innerHTML;

//this is the big add button when you fill in the fields
var filButton = document.getElementById('new-add');

try{
  filButton.addEventListener('click', function (event) {

    var value1 = document.getElementById('exi-name').value;
    var value2 = document.getElementById('spe-ex').value;
    var value3 = document.getElementById('ani-exh').value;

    //if any of the variables are empty then it pops with an error screen
    if (value1 == "" || value2 == "" || value3 == "") {
      document.getElementById('hide').style.display = "block";
      document.getElementById('error_box1').style.display = "block";
    }
    
    //if all the areas are met then go into this
    else{

      //this is the outter div this makes the html element
      var next1 = document.getElementById('next1');

      var firstdiv = document.createElement('div');
      firstdiv.classList.add('box');
      firstdiv.setAttribute("id", posts);

      var seconddiv = document.createElement('div');
      seconddiv.classList.add('top2');
      firstdiv.appendChild(seconddiv);

      var notediv = document.createElement('div');
      notediv.classList.add('side-note');
      notediv.innerHTML = "You have added...";
      seconddiv.appendChild(notediv);

      var xbu = document.createElement('input');
      xbu.classList.add('closex');
      xbu.setAttribute('id', buttonh);
      xbu.type = "submit";
      xbu.value = "X";
      seconddiv.appendChild(xbu);

      var fulltable = document.createElement('table');
      fulltable.classList.add('table1');
      firstdiv.appendChild(fulltable);

      var tr1 = document.createElement('tr');
      fulltable.appendChild(tr1);

      var th1 = document.createElement('th');
      th1.classList.add('col');
      th1.innerHTML = "Exhibit Name";
      tr1.appendChild(th1);

      var th1 = document.createElement('th');
      th1.classList.add('col');
      th1.innerHTML = "Species in Exhibit";
      tr1.appendChild(th1);

      var th1 = document.createElement('th');
      th1.classList.add('col');
      th1.innerHTML = "Exhibit Size";
      tr1.appendChild(th1);

      var tbody1 = document.createElement('tbody');
      fulltable.appendChild(tbody1);

      var tr2 = document.createElement('tr');
      tbody1.appendChild(tr2);

      var td2 = document.createElement('td');
      td2.classList.add('ex_name');
      td2.innerHTML = value1;
      tr2.appendChild(td2);

      var td2 = document.createElement('td');
      td2.classList.add('spec');
      td2.innerHTML = value2;
      tr2.appendChild(td2);

      var td2 = document.createElement('td');
      td2.classList.add('ani');
      td2.innerHTML = value3;
      tr2.appendChild(td2);

      // var td2 = document.createElement('td');
      // tr2.appendChild(td2);

      // var edit1 = document.createElement('input');
      // edit1.classList.add('fbutton');
      // edit1.classList.add('edit-button');
      // edit1.setAttribute("id", "edi");
      // edit1.type = "submit";
      // edit1.value = "Edit";
      // td2.appendChild(edit1);

      // var delete1 = document.createElement('input');
      // delete1.classList.add('fbutton');
      // delete1.classList.add('delete-button');
      // delete1.setAttribute("id", "del");
      // delete1.type = "submit";
      // delete1.value = "Delete";
      // td2.appendChild(delete1);

      next1.appendChild(firstdiv);

      //adding to the increment so each addation has a specicif id
      posts += 1;
      buttonh += 1;
      }
    })
}
catch (err){
}

  document.addEventListener('click', function(e) {
      e = e || window.event;
      var target = e.target || e.srcElement,
          text = target.textContent || target.innerText;

      if (target.className == 'closex') {
        target.parentNode.parentNode.remove();
      }

      else if (target.id == 'del') {
        document.getElementById('hide').style.display = "block";
        document.getElementById('error_box2').style.display = "block";

        var xbox = document.getElementById('close-box1');

        xbox.addEventListener('click', function (event) {
          document.getElementById('hide').style.display = "none";
          document.getElementById('error_box2').style.display = "none";
        })

        var okbox = document.getElementById('ok-close1');

        okbox.addEventListener('click', function (event) {
          document.getElementById('hide').style.display = "none";
          document.getElementById('error_box2').style.display = "none";

          //this is what we will send and delete on the website
          // console.log(target.parentNode.parentNode);
          target.parentNode.parentNode.parentNode.parentNode.parentNode.remove();
        })
      }

      else if (target.id == 'edi') {
        document.getElementById('hide').style.display = "block";
        document.getElementById('bigedit').style.display = "block";

        var xbox = document.getElementById('close-box2');

        xbox.addEventListener('click', function (event) {
          document.getElementById('hide').style.display = "none";
          document.getElementById('bigedit').style.display = "none";
        })

        var okbox = document.getElementById('ok-close2');

        okbox.addEventListener('click', function (event) {
          document.getElementById('hide').style.display = "none";
          document.getElementById('bigedit').style.display = "none";

          //this is where we send this data to the server
          // target.parentNode.parentNode
          var value0 = document.getElementById('exi-id-edit').value;
          var value1 = document.getElementById('exi-name-edit').value;
          var value2 = document.getElementById('spe-ex-edit').value;
          var value3 = document.getElementById('ani-exh-edit').value;

          if (value0 != "") {target.parentNode.parentNode.childNodes[0].innerHTML = value0;}
          if (value1 != "") {target.parentNode.parentNode.childNodes[1].innerHTML = value1;}
          if (value2 != "") {target.parentNode.parentNode.childNodes[2].innerHTML = value2;}
          if (value3 != "") {target.parentNode.parentNode.childNodes[3].innerHTML = value3;}

          document.getElementById('exi-id-edit').value = "";
          document.getElementById('exi-name-edit').value = "";
          document.getElementById('spe-ex-edit').value = "";
          document.getElementById('ani-exh-edit').value = "";
        })
      }
  }, false);



var xbox = document.getElementById('close-box');

xbox.addEventListener('click', function (event) {
  document.getElementById('hide').style.display = "none";
  document.getElementById('error_box1').style.display = "none";
})

var okbox = document.getElementById('ok-close');

okbox.addEventListener('click', function (event) {
  document.getElementById('hide').style.display = "none";
  document.getElementById('error_box1').style.display = "none";
})
