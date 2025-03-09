void writeFile(fs::FS &fs, String filename, String message){
  Println("writeFile -> Writing file: " + filename);

  File file = fs.open(filename, FILE_WRITE);
  if(!file){
    Println("writeFile -> failed to open file for writing");
    return;
  }
  if(file.print(message)){
    Println("writeFile -> file written");
  } else {
    Println("writeFile -> write failed");
  }
  file.close();
}