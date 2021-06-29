
word  Y;
word NY;
int MoveSpeed=600; //step in Microseconds
String     inputString = "help\n"; // a string to hold incoming data
boolean stringComplete = true;     // whether the string is completet
boolean        ComData = false;    // whether com data is on when motors are moving will slow them down
int relay =2;
word  X;
word NX;
//int MoveSpeed=600; //step in Microseconds
//String     inputString = "help\n"; // a string to hold incoming data
//boolean stringComplete = true;     // whether the string is completet
//boolean        ComData = false;    // whether com data is on when motors are moving will slow them down

# define Y_ENgnd  48 //ENA-(ENA) stepper motor enable , active low     Gray 
# define Y_EN_5v  46 //ENA+(+5V) stepper motor enable , active low     Orange
# define Y_DIRgnd 42 //DIR-(DIR) axis stepper motor direction control  Blue
# define Y_DIR_5v 44//DIR+(+5v) axis stepper motor direction control  Brown
# define Y_STPgnd 52 //PUL-(PUL) axis stepper motor step control       Black
# define Y_STP_5v 50 //PUL+(+5v) axis stepper motor step control       RED
# define X_ENgnd  20 //ENA-(ENA) stepper motor enable , active low     Gray 
# define X_EN_5v  21 //ENA+(+5V) stepper motor enable , active low     Orange
# define X_DIRgnd 16 //DIR-(DIR) axis stepper motor direction control  Blue
# define X_DIR_5v 17 //DIR+(+5v) axis stepper motor direction control  Brown
# define X_STPgnd 18 //PUL-(PUL) axis stepper motor step control       Black
# define X_STP_5v 19 //PUL+(+5v) axis stepper motor step control       RED
int relayx=3;
int relayy=2;


void setup() {
  // put your setup code here, to run once:
//relay
pinMode(relayx,OUTPUT);
pinMode(relayy,OUTPUT);
digitalWrite(relayx,HIGH);
digitalWrite(relayy,HIGH);
//realy end

pinMode (X_ENgnd ,OUTPUT); //ENA-(ENA)
pinMode (X_EN_5v ,OUTPUT); //ENA+(+5V)
pinMode (X_DIRgnd,OUTPUT); //DIR-(DIR)
pinMode (X_DIR_5v,OUTPUT); //DIR+(+5v)
pinMode (X_STPgnd,OUTPUT); //PUL-(PUL)
pinMode (X_STP_5v,OUTPUT); //PUL+(+5v)
digitalWrite (X_ENgnd,  LOW); //ENA-(ENA)
digitalWrite (X_EN_5v, HIGH); //ENA+(+5V) low=enabled
digitalWrite (X_DIRgnd, LOW); //DIR-(DIR)
digitalWrite (X_DIR_5v, LOW); //DIR+(+5v)
digitalWrite (X_STPgnd, LOW); //PUL-(PUL)
digitalWrite (X_STP_5v, LOW); //PUL+(+5v)
pinMode (Y_ENgnd ,OUTPUT); //ENA-(ENA)
pinMode (Y_EN_5v ,OUTPUT); //ENA+(+5V)
pinMode (Y_DIRgnd,OUTPUT); //DIR-(DIR)
pinMode (Y_DIR_5v,OUTPUT); //DIR+(+5v)
pinMode (Y_STPgnd,OUTPUT); //PUL-(PUL)
pinMode (Y_STP_5v,OUTPUT); //PUL+(+5v)
//pinMode (2,OUTPUT);
//digitalWrite(relay,LOW);
digitalWrite (Y_ENgnd,  LOW); //ENA-(ENA)
digitalWrite (Y_EN_5v, HIGH); //ENA+(+5V) low=enabled
digitalWrite (Y_DIRgnd, LOW); //DIR-(DIR)
digitalWrite (Y_DIR_5v, LOW); //DIR+(+5v)
digitalWrite (Y_STPgnd, LOW); //PUL-(PUL)
digitalWrite (Y_STP_5v, LOW); //PUL+(+5v)
Serial.begin(115200);
}
void serialEvent()// ********************************************************      Serial in
{ while (Serial.available()) 
  {
    char inChar = (char)Serial.read();            // get the new byte:
    if (inChar > 0)     {inputString += inChar;}  // add it to the inputString:
    if (inChar == '\n') { stringComplete = true;} // if the incoming character is a newline, set a flag so the main loop can do something about it: 
  }
}
void Help(){ // **************************************************************   Help
 Serial.println("Commands step by step guide");
 Serial.println("Type hello -sends TB6600 Tester on ");
 Serial.println("Type bye -sends TB6600 Tester off");
 Serial.println("Type yon  -turns TB6600 on");
 Serial.println("Type y+Number(0-60000) eg y1904 -to set next move steps");
 Serial.println("Type my -to make motor move to next postion");
 Serial.println("Type cdon -turns on postion data when moving will increase time of step");
 Serial.println("Type y0");
 Serial.println("Type my");
 Serial.println("Type s+Number(0-2000) eg s500 -to set Microseconds betwean steps");
 Serial.println("Type s2000");
 Serial.println("Type x300");
 Serial.println("Type my");
 Serial.println("Type yoff -turns TB6600 off");
 Serial.println("Type cdoff -turns off postion data when moving");
  Serial.println("Type xon  -turns TB6600 on");
 Serial.println("Type x+Number(0-60000) eg x1904 -to set next move steps");
 Serial.println("Type mx -to make motor move to next postion");
 Serial.println("Type cdon -turns on postion data when moving will increase time of step");
 Serial.println("Type x0");
 Serial.println("Type mx");
 Serial.println("Type s+Number(0-2000) eg s500 -to set Microseconds betwean steps");
 Serial.println("Type s2000");
 Serial.println("Type x300");
 Serial.println("Type mx");
 Serial.println("Type xoff -turns TB6600 off");
 Serial.println("Type cdoff -turns off postion data when moving");

 inputString="";
}
void Hello(){ // **************************************************************   Hello
 Serial.println("TB6600 Tester Ready relay on");
digitalWrite(relayx,LOW);
digitalWrite(relayy,LOW);
 inputString="";

 
}
void bye(){ // **************************************************************   Hello
 Serial.println("TB6600 Tester Ready relay off");
digitalWrite(relayx,HIGH);
digitalWrite(relayy,HIGH);
 inputString="";

 
}
void ENAYON(){ // *************************************************************   ENAYON
 Serial.println("ENAYON");
 digitalWrite (Y_EN_5v, LOW);//ENA+(+5V) low=enabled
 inputString="";
}
void ENAXON(){ // *************************************************************   ENAXON
 Serial.println("ENAXON");
 digitalWrite (X_EN_5v, LOW);//ENA+(+5V) low=enabled
 inputString="";
}
void ENAYOFF(){  // ***********************************************************   ENAYOFF
 Serial.println("ENAYOFF");
 digitalWrite (Y_EN_5v, HIGH);//ENA+(+5V) low=enabled
 inputString="";
}
void ENAXOFF(){  // ***********************************************************   ENAXOFF
 Serial.println("ENAXOFF");
 digitalWrite (X_EN_5v, HIGH);//ENA+(+5V) low=enabled
 inputString="";
}
void MSpeed(){  // ************************************************************   MoveSpeed
 inputString.setCharAt(0,' ');
 MoveSpeed=inputString.toInt();
 Serial.print("Speed=");
 Serial.println(MoveSpeed);
 inputString="";
}
void ComDataON(){  // *********************************************************   ComDataON
 ComData=true;
 Serial.println("ComDataOn");
 inputString="";
}
void ComDataOFF(){  // ********************************************************   ComDataOFF
 ComData=false;
 Serial.println("ComDataOFF");
 inputString="";
}
void NextY(){ // **************************************************************    NextY
 inputString.setCharAt(0,' ');
 NY=inputString.toInt();
 Serial.print("NY=");
 Serial.println(NY);
 inputString="";
}
void NextX(){ // **************************************************************    NextX
 inputString.setCharAt(0,' ');
 NX=inputString.toInt();
 Serial.print("NX=");
 Serial.println(NX);
 inputString="";
}
void MoveX(){ // **************************************************************    Move
int xt , yt;
if (NX>X && NY>Y )
 {xt=NX-X; digitalWrite (X_DIR_5v,LOW);xt=1;yt=NY-Y; digitalWrite (Y_DIR_5v,LOW);yt=1;}
 
else
{xt=X-NX; digitalWrite (X_DIR_5v,HIGH);xt=-1;yt=Y-NY; digitalWrite (Y_DIR_5v,HIGH);yt=-1;}
if (ComData==true)
{for (; X !=NX; X=X+xt)
{    digitalWrite (X_STP_5v & X_STP_5v, HIGH);
     Serial.print("X=");
     delayMicroseconds (MoveSpeed);
     digitalWrite (X_STP_5v  , LOW);
     delayMicroseconds (MoveSpeed);
     Serial.println(X+100000);
}{for (; Y !=NY; Y=Y+yt)
{    digitalWrite (Y_STP_5v, HIGH);
     Serial.print("Y=");
     delayMicroseconds (MoveSpeed);
     digitalWrite (Y_STP_5v, LOW);
     delayMicroseconds (MoveSpeed);
     Serial.println(Y+100000);
}}}
else
{for (; X !=NX; X=X+xt)
{    digitalWrite (X_STP_5v, HIGH);
     delayMicroseconds (MoveSpeed);
     digitalWrite (X_STP_5v, LOW);
     delayMicroseconds (MoveSpeed);
}{for (; Y !=NY; Y=Y+yt)
{    digitalWrite (Y_STP_5v, HIGH);
     delayMicroseconds (MoveSpeed);
     digitalWrite (Y_STP_5v, LOW);
     delayMicroseconds (MoveSpeed);
}}}
Serial.print("X=");
Serial.println(X);
//X=NX;
inputString="";
Serial.print("Y=");
Serial.println(Y);
//Y=NY;
inputString="";
}


void MoveY(){ // **************************************************************    Move
int yt;
if (NY>Y)
{yt=NY-Y; digitalWrite (Y_DIR_5v,LOW);yt=1;}
else
{}
if (ComData==true)
{for (; Y !=NY; Y=Y+yt)
{    digitalWrite (Y_STP_5v, HIGH);
     Serial.print("Y=");
     delayMicroseconds (MoveSpeed);
     digitalWrite (Y_STP_5v, LOW);
     delayMicroseconds (MoveSpeed);
     Serial.println(Y+100000);
}}
else
{for (; Y !=NY; Y=Y+yt)
{    digitalWrite (Y_STP_5v, HIGH);
     delayMicroseconds (MoveSpeed);
     digitalWrite (Y_STP_5v, LOW);
     delayMicroseconds (MoveSpeed);
}}
Serial.print("Y=");
Serial.println(Y);
//Y=NY;
inputString="";
}
void runsametime(){
  MoveY(); MoveX();
  }
void loop()  // **************************************************************     loop
{
 serialEvent(); 
 if (stringComplete) 
 {
  if (inputString=="help\n")      {Help();}
  if (inputString=="hello\n")     {Hello();}  
  if (inputString=="bye\n")      {bye();}
  if (inputString=="xon\n")       {ENAXON();}   
  if (inputString=="xoff\n")      {ENAXOFF();}
  if (inputString=="cdon\n")      {ComDataON();}
  if (inputString=="cdoff\n")     {ComDataOFF();}
  if (inputString=="mx\n")        {MoveX();}
  if (inputString.charAt(0)=='s')   {MSpeed();}
  if (inputString.charAt(0)=='x')   {NextX();} 
  if (inputString=="yon\n")       {ENAYON();}   
  if (inputString=="yoff\n")      {ENAYOFF();}
  if (inputString=="mx\n")        {MoveY();}
  if (inputString.charAt(0)=='y')   {NextY();} 
  
  if (inputString !="") {Serial.println("BAD COMMAND="+inputString);}// Serial.print("\n"); }// "\t" tab      
  inputString = ""; stringComplete = false; // clear the string:
 }

}
