var i = 0;
function move() {
  if (i == 0) {
    i = 1;
    var elem = document.getElementById("myBar");
    var width = 1;
    var id = setInterval(frame, 10);
    function frame() {
      if (width >= 100) {
        clearInterval(id);
        i = 0;
      } else {
        width++;
        elem.style.width = width + "%";
      }
    }
  }
}

var xmlHttp;
function createXMLHttpRequest() {
  if (window.ActiveXObject) { // Internet Explorer
    xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
  } else { // Firefox, Opera 8.0+, Safari
    xmlHttp = new XMLHttpRequest();
  }
} //end function createXMLHttpRequest()
function showList(str) {
  createXMLHttpRequest();
  var search = str;
  var url = "volunteerDB.php";
  url = url+"?search="+search;
  xmlHttp.open("GET", url, true);
  xmlHttp.onreadystatechange = () => {
    var result = "";
    if (xmlHttp.readyState == 4) {
      var str = xmlHttp.responseText;
      alert(str);
    }
  };
  xmlHttp.send(null);
} //end function showHint(str)