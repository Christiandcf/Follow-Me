#include <rgb_lcd.h>
#include <Wire.h>
 
rgb_lcd lcd;
 
int colorR = 0;
int colorG = 255;
int colorB = 0;
int secs = 0;
int mins = 0;
int hours = 0;
int minsreal=0;
int hoursreal=0;
int start =A2;
int watchStop = A1;
int valstart=0;
int valstop = 0;
int count=0;

int seconds;
int minutes;
int hour;
 
void setup()
{
 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
 
  lcd.setRGB(colorR, colorG, colorB);
 
  // Print a message to the LCD.
  lcd.print("   Follow Me!");
  lcd.setCursor(0, 2);
  lcd.print(" Press Start");

  //lcd.print("Press start to run\n");
  
  pinMode(start, INPUT); 
  pinMode(watchStop, INPUT);

  
}
 
void loop()
{

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  valstart=digitalRead(start);
  valstop=digitalRead(watchStop);
  

if(valstart == HIGH){
  count=1;
}

if(count==1)
{
  lcd.setCursor(0, 1);
 secs+=10;

    if(secs %60==0){
      secs=0;
        mins++;
            if(mins %60==0){
                mins=0;
                hours++;
                  if(hours%60==0){
                    hours=0;
                    minsreal++;

                  
                  }
            }    
    } 
               
 if(hoursreal < 10)
 {
  lcd.print("    0");
 }              
  lcd.print(hoursreal);
  
  lcd.print(":");
  
  if(minsreal < 10)
 {
  lcd.print("0");
 }
  lcd.print(minsreal);
  
 lcd.print(":");
 
 if(hours < 10)
 {
  lcd.print("0");
 }
 lcd.print(hours);
 
  if (valstop==HIGH){
    count++;
  }
}


if(count==2)
{
  lcd.begin(16, 2);
  lcd.print("  Your time is:");
  saveTime();
}

if(valstop==HIGH && valstart==HIGH){
  count++;
}

if(count==3){
  setup();
  count=0;
  secs = 0;
  mins = 0;
  hours = 0;
  minsreal=0;
  hoursreal=0;
  
}
  
}

void saveTime()
{
  
  lcd.setCursor(0, 2);
  seconds = hours;
  minutes = minsreal;
  hour = hoursreal;
  
if(hour < 10)
 {
  lcd.print("    0");
 }              
  lcd.print(hour);
  
  lcd.print(":");
  
  if(minutes < 10)
 {
  lcd.print("0");
 }
  lcd.print(minutes);
  
 lcd.print(":");
 
 if(seconds < 10)
 {
  lcd.print("0");
 }
 lcd.print(seconds);
}


    
