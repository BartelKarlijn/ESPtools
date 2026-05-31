#pragma once
String listFiles(bool ishtml) {
// list all of the files, if ishtml=true, return html rather than simple text
  String returnText = "";
  Println("Listing files stored on SPIFFS");
  File root = SPIFFS.open("/");
  
  // Collect files and sizes into vectors
  std::vector<String> fileNames;
  std::vector<size_t> fileSizes;
  
  File foundfile = root.openNextFile();
  while (foundfile) {
    fileNames.push_back(String(foundfile.name()));
    fileSizes.push_back(foundfile.size());
    foundfile = root.openNextFile();
  }
  
  // Sort fileNames alphabetically (with corresponding sizes)
  for (int i = 0; i < fileNames.size(); i++) {
    for (int j = i + 1; j < fileNames.size(); j++) {
      if (fileNames[j] < fileNames[i]) {
        // Swap names
        String temp = fileNames[i];
        fileNames[i] = fileNames[j];
        fileNames[j] = temp;
        // Swap sizes
        size_t tempSize = fileSizes[i];
        fileSizes[i] = fileSizes[j];
        fileSizes[j] = tempSize;
      }
    }
  }
  
  if (ishtml) {
    returnText += "<table class='center'><tr><th align='left'>Name</th><th align='left'>Size</th><th></th><th></th></tr>";
  }
  
  // Process sorted files
  for (int i = 0; i < fileNames.size(); i++) {
    if (ishtml) {
      returnText += "<tr align='left'><td>" + fileNames[i] + "</td><td>" + humanReadableSize(fileSizes[i]) + "</td>";
      returnText += "<td><button class='button-small' onclick='downloadDeleteButton(\"" + fileNames[i] + "\", \"download\")\'> Download</button>";
      returnText += "<td><button class='button-small' onclick='downloadDeleteButton(\"" + fileNames[i] + "\", \"delete\")\'  > Delete</button></tr>";
    } else {
      returnText += "File: " + fileNames[i] + " Size: " + humanReadableSize(fileSizes[i]) + "\n";
    }
  }
  
  if (ishtml) {
    returnText += "</table>";
  }
  root.close();
  return returnText;
}
