// CLASE MOTOR
class Motor {
  private:
    int _inA;
    int _inB;
  public:
    Motor(int inA, int inB) : _inA(inA), _inB(inB) {
      pinMode(_inA, OUTPUT);
      pinMode(_inB, OUTPUT);
    }
    void mover(int velocidad) {
      // Limitar velocidad entre -255 y 255
      velocidad = constrain(velocidad, -255, 255);
      if (velocidad > 0) {
        analogWrite(_inA, velocidad);
        analogWrite(_inB, 0);
      } else if (velocidad < 0) {
        analogWrite(_inA, 0);
        analogWrite(_inB, -velocidad);
      } else {
        analogWrite(_inA, 0);
        analogWrite(_inB, 0);
      }
    }
    void detener() {
      analogWrite(_inA, 0);
      analogWrite(_inB, 0);
    }
};

// CLASE ROBOT (VELOCISTA)
class Robot {
  private:
    Motor _motorIzq;
    Motor _motorDer;
    int _velocidadBase;
  public:
    Robot(int inA_izq, int inB_izq, int inA_der, int inB_der, int velocidadBase = 150) : _motorIzq(inA_izq, inB_izq), _motorDer(inA_der, inB_der), _velocidadBase(velocidadBase) {
    }
    void setVelocidadBase(int vel) {
      _velocidadBase = constrain(vel, 0, 255);
    }
    // Mover con velocidades independientes
    void mover(int velIzq, int velDer) {
      _motorIzq.mover(velIzq);
      _motorDer.mover(velDer);
    }
    // Avanzar recto
    void avanzar() {
      mover(_velocidadBase, _velocidadBase);
    }
    // Girar con corrección
    void girar(int correccion) {
      int velIzq = _velocidadBase + correccion;
      int velDer = _velocidadBase - correccion;
      mover(velIzq, velDer);
    }
    void detener() {
      _motorIzq.detener();
      _motorDer.detener();
    }
    void info() {
      Serial.println("=== CONFIGURACIÓN ROBOT ===");
      Serial.print("Velocidad base: ");
      Serial.println(_velocidadBase);
    }
};

// CONFIGURACIÓN DE PINES
#define MOTOR_IZQ_A 9
#define MOTOR_IZQ_B 10
#define MOTOR_DER_A 11
#define MOTOR_DER_B 12
// Pines del sensor QTR
#define NUM_SENSORES 8
const int pinesSensores[NUM_SENSORES] = {2, 3, 4, 5, 6, 7, 8, A0};

// VARIABLES GLOBALES
Robot robot(MOTOR_IZQ_A, MOTOR_IZQ_B, MOTOR_DER_A, MOTOR_DER_B, 150);
// PID
float Kp = 0.15;
float Ki = 0.02;
float Kd = 0.8;
int ultimoError = 0;
int integral = 0;

// FUNCIONES DEL SENSOR QTR
void inicializarSensores() {
  for (int i = 0; i < NUM_SENSORES; i++) {
    pinMode(pinesSensores[i], INPUT);
  }
}

int leerLinea() {
  int valores[NUM_SENSORES];
  int suma = 0;
  int sumaPonderada = 0;
  // Leer sensores
  for (int i = 0; i < NUM_SENSORES; i++) {
    valores[i] = digitalRead(pinesSensores[i]);
    suma += valores[i];
    sumaPonderada += valores[i] * i * 1000;
  }
  // Calcular posición (-3500 a 3500 para 8 sensores)
  if (suma == 0) {
    return ultimoError; // Mantener último error si no detecta línea
  }
  int posicion = (sumaPonderada / suma) - ((NUM_SENSORES - 1) * 500);
  return posicion;
}

void seguirLinea() {
  int posicion = leerLinea();
  int error = posicion;
  integral += error;
  int proporcional = error;
  int derivativo = error - ultimoError;
  int correccion = (Kp * proporcional) + (Ki * integral) + (Kd * derivativo);
  // Limitar la corrección para evitar sobreajustes
  correccion = constrain(correccion, -100, 100);
  robot.girar(correccion);
  ultimoError = error;
}

void setup() {
  Serial.begin(9600);
  inicializarSensores();
  robot.info();
  int led = 1;
  Serial.println("Robot listo. Esperando 2 segundos...");
  delay(2000);
}

void loop() {
  seguirLinea();
}
