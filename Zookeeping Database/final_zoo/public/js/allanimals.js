
//counts how many new posts there Are
var posts = "0";
var buttonh = "10";
var first = false;
  // Vector vec = new Vector();

var filButton = document.getElementById('new-add');

  document.addEventListener('click', function(e) {
      e = e || window.event;
      var target = e.target || e.srcElement,
          text = target.textContent || target.innerText;

      if (target.className == 'closex') {
        target.parentNode.parentNode.remove();
        first = false;
      }

      else if (target.id == 'del') {
        document.getElementById('hide').style.display = "block";
        document.getElementById('error_box2').style.display = "block";

        var xbox = document.getElementById('close-box1');
        
        var one = target.parentNode.parentNode.childNodes[1].innerHTML;
        document.getElementById('ok-close1').setAttribute("onClick", "deleteanimal(" + one + ")");

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

        })
      }

      else if (target.id == 'edi') {
        document.getElementById('hide').style.display = "block";
        document.getElementById('bigedit').style.display = "block";

        var one = target.parentNode.parentNode.childNodes[1].innerHTML;
        var two = target.parentNode.parentNode.childNodes[3].innerHTML;
        var three = target.parentNode.parentNode.childNodes[5].innerHTML;
        var four = target.parentNode.parentNode.childNodes[7].innerHTML;

        console.log(target.parentNode.parentNode.childNodes[5].innerHTML);

        document.getElementById('exi-id-edit').value = one;
        document.getElementById('exi-name-edit').value = two;
        document.getElementById('exh-id').value = three;
        // document.getElementById('spe-ex-edit').innerHTML = three;
        // document.getElementById('ani-exh-edit').innerHTML = four;

        var xbox = document.getElementById('close-box2');

        var one = target.parentNode.parentNode.childNodes[1].innerHTML;
        document.getElementById('ok-close2').setAttribute("onClick", "editanimal(" + one + ")");

        xbox.addEventListener('click', function (event) {
          document.getElementById('hide').style.display = "none";
          document.getElementById('bigedit').style.display = "none";
        })

        var okbox = document.getElementById('ok-close2');

        okbox.addEventListener('click', function (event) {
          document.getElementById('hide').style.display = "none";
          document.getElementById('bigedit').style.display = "none";
        })
      }
  }, false);
