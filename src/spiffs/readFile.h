String readFile(fs::FS &fs, String filename){

  File file = fs.open(filename);
  if(!file || file.isDirectory()){
    Println("readFile -> failed to open file for reading");
    return "";
  }

  String fileText = "";
  while(file.available()){
    fileText = file.readString();
  }

  file.close();
  return fileText;
}