#ifndef WebserverWifiEEPROM_H
#define WebserverWifiEEPROM_H

const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <title>Phan Thanh Hải</title> 
       <style> 
          body {text-align:center;background-color:#222222; color:white}
          input {
            height:25px; 
            width:270px;
            font-size:20px;
            margin: 10px auto;
          }
          #content {
            border: white solid 1px; 
            padding:5px;  
            height:375px; 
            width:330px; 
            border-radius:20px;
            margin: 0 auto
          }
          .ledstatus{
              outline: none;
              margin: 15px 5px;
              width: 60px;
              height: 60px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:white;
              font-size:20px;
              font-weight: bold;
          }
          
          #ledconnect{
              outline: none;
              margin: 0px 5px -1px 5px;
              width: 15px;
              height: 15px;
              border: solid 1px #00EE00;
              background-color: #00EE00;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
          }
          .button {
            height:65px; 
            width:70px; 
            margin:10px 0;
            background-color:#3C89BC;
            border-radius:10px;
            outline:none;
            color:white;
            font-size:25px;
            font-weight: bold;
          }
        
          .button_setup {
            height:30px; 
            width:280px; 
            margin:10px 0;
            background-color:#3C89BC;
            border-radius:10px;
            outline:none;
            color:white;
            font-size:20px;
            font-weight: bold;
          }
          .button_wifi{
            height:50px; 
            width:90px; 
            margin:5px 0;
            outline:none;
            color:white;
            font-size:15px;
            font-weight: bold;
          }
          #button_save {
            background-color:#00BB00;
            border-radius:5px;
          }
          #button_restart {
            background-color:#FF9900;
            border-radius:5px;
          }
          #button_reset {
            background-color:#CC3300;
            border-radius:5px;
          }
       </style>
       <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
   </head>
   <body> 
      <div><h1>LÒ SẤY IOT</h1></div>
      <div id="content"> 
        <div id="homecontrol" style="height:340px";>
      
          <div><input class="button_setup" type="button" onclick="configurewifi()" value="Configure WiFi"/></div>
          <div>IP connected: <b><pan id="ipconnected"></pan></b></div>
        </div>
        
        <div id="wifisetup" style="height:340px; font-size:20px; display:none";>
          <div style="text-align:left; width:270px; margin:0px 25px">SSID: </div>
          <div><input id="ssid"/></div>
          <div style="text-align:left; width:270px; margin:0px 25px">Password: </div>
          <div><input id="pass"/></div>
          <div style="text-align:left; width:270px; margin:0px 25px">Auth token: </div>
          <div><input id="auth"/></div>
          <div>
            <button id="button_save" class="button_wifi" onclick="writeEEPROM()">SAVE</button>
            <button id="button_restart" class="button_wifi" onclick="restartESP()">RESTART</button>
            <button id="button_reset" class="button_wifi" onclick="clearEEPROM()">RESET</button>
          </div>
          <div><input class="button_setup" type="button" onclick="backHOME()" value="Back home"/></div>
          <div id="reponsetext"></div>
        </div>
        <div><input id="ledconnect" type="button"/>Connection status</div>
      </div>
      <div id="footer">
          <br>Email: <b>Haiqb28@gmail.com</b></i>
        </p>
      </div>
      <script>

        function create_obj(){
          td = navigator.appName;
          if(td == "Microsoft Internet Explorer"){
            obj = new ActiveXObject("Microsoft.XMLHTTP");
          }else{
            obj = new XMLHttpRequest();
          }
          return obj;
        }

        var xhttp = create_obj();
        var xhttp_statusD = create_obj();
        var D5,D6,D7,D8;
        var ledconnect = 1;

        window.onload = function(){
          document.getElementById("homecontrol").style.display = "block";
          document.getElementById("wifisetup").style.display = "none";
          getIPconnect();//Gửi yêu cầu lấy IP kết nối
          getstatusD();//Gửi yêu cầu lấy trạng thái các chân điều khiển
        }

        function getIPconnect(){
          xhttp.open("GET","/getIP",true);
          xhttp.onreadystatechange = process_ip;//nhận reponse 
          xhttp.send();
        }

        function process_ip(){
          if(xhttp.readyState == 4 && xhttp.status == 200){

            ketqua = xhttp.responseText; 
            document.getElementById("ipconnected").innerHTML=ketqua;       
          }
        }

        function getstatusD(){
          xhttp_statusD.open("GET","/getSTATUSD",true);
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
        }

        function process_statusD(){
          if(xhttp_statusD.readyState == 4 && xhttp_statusD.status == 200){
            if(ledconnect == 1){
              ledconnect = 0;
              document.getElementById("ledconnect").style.background = "#222222";
            }else{
              ledconnect = 1;
              document.getElementById("ledconnect").style.background = "#00EE00";
            }
           
          }
        }
       function configurewifi(){
          document.getElementById("homecontrol").style.display = "none";
          document.getElementById("wifisetup").style.display = "block";
        }
        //-----------Thiết lập dữ liệu và gửi request ssid và password---
        function writeEEPROM(){
          if(Empty(document.getElementById("ssid"), "Please enter ssid!")&&Empty(document.getElementById("pass"), "Please enter password")){
            var ssid = document.getElementById("ssid").value;
            var pass = document.getElementById("pass").value;
            var auth = document.getElementById("auth").value;
            xhttp.open("GET","/writeEEPROM?ssid="+ssid+"&pass="+pass+"&auth="+auth,true);
            xhttp.onreadystatechange = process;//nhận reponse 
            xhttp.send();
          }
        }
        function clearEEPROM(){
          if(confirm("Do you want to delete all saved wifi configurations?")){
            xhttp.open("GET","/clearEEPROM",true);
            xhttp.onreadystatechange = process;//nhận reponse 
            xhttp.send();
          }
        }
        function restartESP(){
          if(confirm("Do you want to reboot the device?")){
            xhttp.open("GET","/restartESP",true);
            xhttp.send();
            alert("Device is restarting! If no wifi is found please press reset!");
          }
        }
        //-----------Kiểm tra response -------------------------------------------
        function process(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Updat data sử dụng javascript----------
            ketqua = xhttp.responseText; 
            alert(ketqua);       
          }
        }

        setInterval(function() {
          getstatusD();
        },2000);
       //--------Load lại trang để quay về Home control-------------------------
        function backHOME(){
          window.onload();
        }
       //----------------------------CHECK EMPTY--------------------------------
       function Empty(element, AlertMessage){
          if(element.value.trim()== ""){
            alert(AlertMessage);
            element.focus();
            return false;
          }else{
            return true;
          }
       }
       //------------------------------------------------------------------------
      </script>
   </body> 
  </html>
)=====";
//=========================================//


#endif
