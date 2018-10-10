// Arduino code to detect licks, and deliver water rewards
// Christina Kim (kimck@stanford.edu)

#include <TinkerKit.h>
TKTouchSensor lickport1(I0);

// Set these to match which pins you use on your arduino
int lickbnc1 = 8;
int solenoidtrig1 = 10;

#include <SimpleTimer.h>
SimpleTimer watertimer;
int timer1;
int timer2;
int flag_firstlick=0;

// Setup
void setup(){
     Serial.begin(9600);

     //Licking 1
     pinMode(lickbnc1,OUTPUT);
     digitalWrite(lickbnc1,LOW);

     //solenoid 1
     pinMode(solenoidtrig1,OUTPUT);
     digitalWrite(solenoid1,LOW);
}

//Open solenoid1
void Solenoid1() {
  flag_firstlick=1;
  digitalWrite(solenoidtrig1,HIGH);
  timer2=watertimer.setTimeout(50, stopNow);
}

// Close solenoid
void stopNow() {
  digitalWrite(solenoidtrig1,LOW);
  timer1=watertimer.setTimeout(250,pause);
}

void pause() {
  flag_firstlick=0;
}

// Main loop
void loop(){
  watertimer.run();
  
  //Log lickport1
  if (lickport1.read()==HIGH) {
    digitalWrite(lickbnc1,HIGH);
    if (flag_firstlick==0) {
      Solenoid1();
    }
  } else{
    digitalWrite(lickbnc1,LOW);
  }
}
