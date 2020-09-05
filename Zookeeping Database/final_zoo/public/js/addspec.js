//counts how many new posts there Are
var posts = "0";
var buttonh = "10";
  // Vector vec = new Vector();

var filButton = document.getElementById('new-add');

filButton.addEventListener('click', function (event) {
  var name = document.getElementById('exi-name').value;

  console.log("name");
  var animal_exhibit = document.getElementById('ani-exh').value;
  var e = document.getElementById('exh-id');

  var species_exhibit = e.options[e.selectedIndex].text;

  if (name == "" || animal_exhibit == "") {
    document.getElementById('hide').style.display = "block";
    document.getElementById('error_box1').style.display = "block";
  }

  else{
    //shows the box in total
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
    th1.innerHTML = "Species Name"
    tr1.appendChild(th1);

    var th1 = document.createElement('th');
    th1.classList.add('col');
    th1.innerHTML = "Exhibit that Species are in"
    tr1.appendChild(th1);

    var th1 = document.createElement('th');
    th1.classList.add('col');
    th1.innerHTML = "Wild Population"
    tr1.appendChild(th1);

    var tbody1 = document.createElement('tbody');
    fulltable.appendChild(tbody1);

    var tr2 = document.createElement('tr');
    tbody1.appendChild(tr2);

    var td2 = document.createElement('td');
    td2.classList.add('an_name');
    td2.innerHTML = name;
    tr2.appendChild(td2);

    var td2 = document.createElement('td');
    td2.classList.add('spec');
    td2.innerHTML = species_exhibit;
    tr2.appendChild(td2);

    var td2 = document.createElement('td');
    td2.classList.add('ani');
    td2.innerHTML = animal_exhibit;
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

    posts += 1;
    buttonh += 1;
    }
  })

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
          var edit_id = document.getElementById('ani-id-edit').value;
          var edit_name = document.getElementById('ani-name-edit').value;
          var edit_spec = document.querySelector('#spe-id-edit').value;
          var edit_anim = document.querySelector('#exh-id-edit').value;

          if (edit_id != "") {target.parentNode.parentNode.childNodes[0].innerHTML = edit_id;}
          if (edit_name != "") {target.parentNode.parentNode.childNodes[1].innerHTML = edit_name;}
          if (edit_spec != "") {target.parentNode.parentNode.childNodes[2].innerHTML = edit_spec;}
          if (edit_anim != "") {target.parentNode.parentNode.childNodes[3].innerHTML = edit_anim;}
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
