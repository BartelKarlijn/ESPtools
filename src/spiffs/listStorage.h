#pragma once
String listStorage(bool ishtml) {
// list of free and used storage
  String returnText = "";
  String freebytes  = humanReadableSize(SPIFFS.totalBytes()-SPIFFS.usedBytes()) ;
  String usedbytes  = humanReadableSize(SPIFFS.usedBytes()) ;
  String totalbytes = humanReadableSize(SPIFFS.totalBytes());
  
  if (ishtml) {
    returnText += "<table>";
    returnText += "<tr align='left'><td> Free: " + freebytes + "</td><td>; Used " + usedbytes  + "</td><td>; Total " + totalbytes + "</td>";
    returnText += "</table>";
  }
  else {
      returnText += "Free: " + freebytes + " Size: " + usedbytes + " Total: " + "\n";
  }
  return returnText;
}
