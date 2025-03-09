#pragma once
String listFiles(bool ishtml) {
// list all of the files, if ishtml=true, return html rather than simple text
  String returnText = "";
  Println("Listing files stored on SPIFFS");
  File root = SPIFFS.open("/");
  File foundfile = root.openNextFile();
  if (ishtml) {
    returnText += "<table class='center'><tr><th align='left'>Name</th><th align='left'>Size</th><th></th><th></th></tr>";
  }
  while (foundfile) {
    if (ishtml) {
      returnText += "<tr align='left'><td>" + String(foundfile.name()) + "</td><td>" + humanReadableSize(foundfile.size()) + "</td>";
      returnText += "<td><button class='button-small' onclick='downloadDeleteButton(\"" + String(foundfile.name()) + "\", \"download\")\'> Download</button>";
      returnText += "<td><button class='button-small' onclick='downloadDeleteButton(\"" + String(foundfile.name()) + "\", \"delete\")\'  > Delete</button></tr>";
    } else {
      returnText += "File: " + String(foundfile.name()) + " Size: " + humanReadableSize(foundfile.size()) + "\n";
    }
    foundfile = root.openNextFile();
  }
  if (ishtml) {
    returnText += "</table>";
  }
  root.close();
  foundfile.close();
  return returnText;
}
