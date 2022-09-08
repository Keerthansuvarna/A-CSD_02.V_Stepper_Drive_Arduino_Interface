#include<string.h>
#define dP 4 //Dir
#define cP 3 //Step In

/*This code will only work on 7.5 degree step angle stepper motors with 1/4 stepping (i.e 800 resolution setting done in driver)*/
/*To run 1.8 degree step angle stepper motor replace 192 by 800 in " float tRot = 192*rot "    */

//Resolution = Type of microstepping * Total steps per revolution 
//Resolution = Quater stepping * 48
//Resolution = 4 * 48
//Resolution = 192

void setup()
{
  pinMode(dP, OUTPUT);
  pinMode(cP, OUTPUT);
}

 int microStep(bool dir, float rot, float speed)
 {
     float RPM = speed/60;
     float RPmS= 1000/RPM;
     float rpm = RPmS/194; 
     float tRot = 192*rot;
  
  if(dir)
  {
   digitalWrite(dP, LOW); // For CW direction
   for (int i = 0; i < tRot; i++)
{
  digitalWrite(cP, HIGH);
  digitalWrite(cP, LOW);
  delay(rpm);
}
}

else
{
  
  digitalWrite(dP, HIGH); // For CCW direction
  for (int i = 0; i < tRot; i++)
  {
    digitalWrite(cP, HIGH);
    digitalWrite(cP, LOW);
    delay(rpm);
  }
}

}

void loop()
{
  bool direction = true; //true for CW & false for CCW
  float speed = 10; //RPM (Min 1 & MAX 300)
  float required_rotation = 1; //No of rotation stepper motor should rotate
  microStep(direction, required_rotation, speed);
  delay(500);

//  direction = false; //true for CW & false for CCW
//  speed = 100; //RPM (Min 1 & MAX 300)
//  required_rotation = 1; //No of rotation stepper motor should rotate
//  count = microStep(direction, required_rotation, speed);
//  delay(500);


}

// This is purely for education purpose. Any one can use the code with out any prior notice
// Open for suggentions if any
