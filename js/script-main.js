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
  var url = "volunteerDB.php";
  xmlHttp.open("GET", , true);
  xmlHttp.onreadystatechange = () => {
    var result = "";
    if (xmlHttp.readyState == 4) {
      let res = xmlHttp.responseText.split(',');
      for(suggest in res){
        result += "<option value="+res[suggest]+">" + res[suggest]+"</option>";
      }
      document.getElementById("namesugg").innerHTML = result;
      //alert(result);
    }
  };
  xmlHttp.send(null);
} //end function showHint(str)