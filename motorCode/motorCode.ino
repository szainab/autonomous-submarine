
/*
*  This code is in the public domain.
*  (Do whatever you want with it.)
*/

// Need the Servo library
#include <Servo.h>

// This is our motor.
Servo back_right;
Servo front_right;
Servo back_left;
Servo front_left;

// This is the final output
// written to the motor.
String incomingString;
int sharifs_counter = 0;

// Set everything up
void setup()
{
  // Put the motor to Arduino pin #9
  back_right.attach(11);
  front_right.attach(9);
  back_left.attach(8);
  front_left.attach(10);

  // Required for I/O from Serial monitor
  Serial.begin(9600);
  // Print a startup message
  Serial.println("initializing");
}


void loop()
{
  
  // If there is incoming value
  if(Serial.available() > 0)
  {
    // read the value
    char ch = Serial.read();
    
    /*
    *  If ch isn't a newline
    *  (linefeed) character,
    *  we will add the character
    *  to the incomingString
    */
    //if (ch != 10){
    if (false){
      // Print out the value received
      // so that we can see what is
      // happening
      Serial.print("I have received: ");
      Serial.print(ch, DEC);
      Serial.print('\n');
    
      // Add the character to
      // the incomingString
      incomingString += ch;
      sharifs_counter++;
    }
    // received a newline (linefeed) character
    // this means we are done making a string
    else
    {
      // print the incoming string
      Serial.println("I am printing the entire string");
      Serial.println(incomingString);
    
      // Convert the string to an integer
      int val = incomingString.toInt();

      //////////////Our change
      val = 25;
    
      // print the integer
      Serial.println("Printing the value: ");
      Serial.println(val);
    
      /*
      *  We only want to write an integer between
      *  0 and 180 to the motor. 
      */
      if (val > -1 && val < 181)
     {
       // Print confirmation that the
       // value is between 0 and 180
       Serial.println("Value is between 0 and 180");
       // Write to Servo
 //      back_right.write(val);
  //     front_right.write(val);
//       back_left.write(val);
       front_left.write(val);
     }
     // The value is not between 0 and 180.
     // We do not want write this value to
     // the motor.
     else
     {
       Serial.println("Value is NOT between 0 and 180");
      
       // IT'S a TRAP!
       Serial.println("Error with the input");
     }
    
      // Reset the value of the incomingString
      incomingString = "";
    }
  }
}
