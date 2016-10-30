#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <SD.h>


const int chipSelect = 10;
const int T1=23;
const int T2=24;
const int T3=25;
const int Reset=26;
 
TMRpcm tmrpcm;   // create an object for use in this sketch
 
void setup()
{
  // Initialize the input pins
  pinMode(T1,INPUT);
  pinMode(T2,INPUT);
  pinMode(T3,INPUT);
  pinMode(Reset,INPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);
 
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1) ;
  }
  Serial.println("card initialized."); 
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
  tmrpcm.volume(1);
}
 
void loop()
{
  int buttonStateT1=digitalRead(T1);
  int buttonStateT2=digitalRead(T2);
  int buttonStateT3=digitalRead(T3);
  int buttonStateReset=digitalRead(Reset);
  if( buttonStateT1==HIGH ){
    Serial.println("M1");
    tmrpcm.play("M1.wav"); //the sound file "1" will play each time the arduino powers up, or is reset
  }
  if( buttonStateT2==HIGH ){
    Serial.println("M2");
    tmrpcm.play("M2.wav");
  }
  if( buttonStateT3==HIGH ){
    Serial.println("M3");
    tmrpcm.play("M3.wav");
  }
  if( buttonStateReset==HIGH ){
    Serial.println("Stop");
    tmrpcm.stopPlayback();
  }
}
