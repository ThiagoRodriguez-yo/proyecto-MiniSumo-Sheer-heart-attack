class Motor {
 private: 
 int _INA;
 int _INB;

 void avanzar (int pwm) {
   analogWrite(_INA), pwm;
   analogWrite(_INB, 0);
 }

 void retroceder (int pwm) {
   analogWrite(_INA, 0);
   analogWrite(_INA, pwm);
 }

 void detener (){
   analogWrite(_INA, 0);
   analogWrite(_INA, 0);
 }

 public:
   Motor(int pinMotorA, int pinMotorB) {
   _INA = pinMotorA;
   _INB = pinMotorB;
   pinMode(_INA, OUTPUT);
   pinMode(_INA, OUTPUT);
 }

  void mover (int velocidad) {
  if (velocidad > 0) {
    avanzar (velocidad);
  } else if (velocidad < 0) {
    retroceder (velocidad * (-1));
  } else {
    detener ();
  } 

 } 

 void info () {
  Serial.println("los pines asignados a los motores son;");
  Serial.print("INA:");
  Serial.println(_INA);
  Serial.print("INB:");
  Serial.println(_INB);
 }

class Robot{
  private:
  Motor _motorIzq;
  Motor _motorDer;
  int _velocidadBase;
}

public:

Robot (int INA, int INAB, int INA2, int INB2) {

}
void mover (int velocidad, int velocidad2){
    _motorIzq.mover (velocidad);
    _motorDer.mover (velocidad2);
}

void info () {
  _motorIzq.info();
  _motorDer.info ();

};

Robot robot = Robot (9, 10, 11, 12);

void setup() {
Serial.begin(9500);
Robot.info(){

}

void loop(){

}
