void get_time(void){

  // Initialize Serial Monitor
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // OLED init
  // OLED init
  SetupOledI2C(); 
  SetupOledPix();
  LiCol(0,0);
  Text("Connecting....");
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address 
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  LiCol(0,0);
  Text("Connected  ");
  
// Initialize a NTPClient to get time
  timeClient.begin();

  timeClient.setTimeOffset(TZ);// Set right Time Zone
 

  
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }

  now=millis(); // read Timer when client updated
  last_time=now; 

  // The formattedDate comes with the following format:
  // 2018-05-28T16:00:13Z
  // We need to extract date and time
  formattedDate = timeClient.getFormattedTime();
  Serial.println(formattedDate);

  // Extract date
  int splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);
  Serial.print("DATE: ");
  Serial.println(dayStamp);
  // Extract time
  timeStamp = formattedDate.substring(splitT+1, formattedDate.length()-1);
  Serial.print("HOUR: ");
  Serial.println(timeStamp);

  // OLED Display
     // OLED Display with modified Didel Library   
   LiCol(0,0);
   Text("       "+formattedDate.substring(0,11)); 

  timeStamp.toCharArray(buf, 14);

   LiCol(7,0); 
   Big(buf[0]);Big(buf[1]); //Hours

   LiCol(7,48); 
   Big(0x3c); //: separator

   LiCol(7,72); 
   Big(buf[3]);Big(buf[4]); //Minutes

  // Set initial h,m,s values according to 
  h= ((buf[0]&0x0f)*10)+(buf[1]&0x0f);
  m= ((buf[3]&0x0f)*10)+(buf[4]&0x0f);
  s= ((buf[6]&0x0f)*10)+(buf[7]&0x0f);

  //Serial.end();
  //timeClient.end();
  //WiFi.disconnect(true); // disconnect and turn off, minimise power consumption
  
}
