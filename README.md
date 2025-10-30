# proyecto-MiniSumo-Sheer-heart-attack
Este proyecto es de el robot Mini Sumo el cual esta diseñado con la finalidad de ser mostrado en una muestra de fin de año donde se muestre las cosas que podría hacer

--Autores--

 * Vazquez Elias
 * Rodriguez Thiago
 * Uriel Ramirez

 --02/10/2025--

 <---------------------------------------->

-Descripcion tecnica: El Mini Sumo es un robot hecho mas que nada para las competencias de robots, tiene una medida de 10x10 (ancho y largo) y un peso limite de 350 gramos en amateur y 500 gramos en competiciones, usualmente el robot mini sumo no tiene un consumo de energia fijo, ya que depende de sus componentes, sin embargo tomando de ejemplo al robot de Arduino que consume unos 46 mA en reposo y 0,03–0,05 kWh por hora con carga, seria considerado como un consumo mensual bajo de 2–4 kWh.

-Objetivos del proyecto: El objetivo de nuestro proyecto es poder enseñar nuestro robot en la muestra de fin de año y que la gente vea como quedo el resultado final de nuestro proyecto

<----------------------------------------->

--Lista de componentes utilizados--

-Sensores-
Modelo: AD32
Detalles técnicos:
– Voltaje de funcionamiento CC: 3.3 V-5 V.
– Corriente de funcionamiento: 20 mAh
– Temperatura de funcionamiento: -10°C a + 50°C
– Distancia de detección: 2 a 40 cm
– Interfaz IO: 4 líneas (- / + / S / EN)
– Señal de salida: nivel TTL
– Dimensiones: 4.5 x 1.1 cm (aprox.)
– Tipo de sensor: Emisor y receptor infrarrojo (IR)
– Número de pines: 4 pines para conexión.
– Ajuste de sensibilidad: Incluye potenciómetro para calibrar la sensibilidad del sensor.

-Sensores de piso-
Características:
- Usando sensores de reflexión infrarroja TCRT5000
- Distancia de reflexión de prueba: 1mm a 25mm
- Limpio y 3, la salida del comparador, Onda de senal,
- La capacidad de conducción es fuerte, por mas de 15 ma.
- Con muchos potenciómetros de precisión ajustables para ajustar la sensibilidad
- Voltaje de funcionamiento de 3,3 V a 5V
- Forma de salida: salida de interruptor digital (0 y 1)
- Tiene un agujero de perno fijo, instalación conveniente
- Tablero pequeño tamaño de PCB: 3,2 cm x 1,4 cm
- LM393, uso de comparador de amplio voltaje
- Tamaño: 3,1×1,3 cm (aprox.)

-Motores-
Modelo: N30 500RPM
Detalles tecnicos:
- Diámetro de 15 mm y longitud total de 47 mm. 
- Corriente: 120 mA en funcionamiento, 3,2 A en parada.
- Par: 3,9 kg-cm , 1,2 kg-cm .
- Peso: 21 gramos.

-Switch-
Llave Palanca Switch Spdt On-on 6a 125v Mts-102 3pin
Modelo: MTS-102
Detalles tecnicos:
- Tipo: DPDT
- Número de pines: 3 pines
- Posición: 2 Posiciones (ON / ON)
- Tamaño: aprox. 31 * 13 * 12 mm
- Voltaje y corriente nominales: CA 125V, 6A

-Circuito del Motor-
Modelo: DIP8
-Tipo de circuito: Integrado
-Tipo TA6586

-Placa-
Modelo: Nodemcu ESP-325 USB-C 38 pines
Detalles tecnicos:
- Voltaje de Alimentación: 5V (USB-C)
- Voltaje de Entrada / Salida: 3.3V
- Puerto USB: USB-C
- SoC: ESP32
- CPU principal: Tensilica Xtensa 32-bit LX6
- Frecuencia de Reloj: hasta 240Mhz
- Desempeño: Hasta 600 DMIPS
- WiFi: 802.11 b/g/n/e/i
- Bluetooth:v4.2 BR/EDR y Bluetooth Low Energy (BLE)
- Pines Digitales GPIO: 24 
- Convesor Analogolico Digital
- UART: 2
- Chip USB-Serial: CP2102
- Antena en PCB
- 38 PINES
- DIMENSIONES: 51 x 25 mm (Largo y Ancho)

  -Seguridad-
- Estándares IEEE 802.11: WFA, WPA/WPA2 y WAPI
- 1,024-bit OTP
- Aceleración Criptográfica por Hardware: AES, HASH (SHA-2), RSA, ECC, RNG

  -Driver de motores-
Características:
- Baja corriente en espera: ≦2 µA
- Amplio rango de tensión de alimentación
- Función de freno integrada
- Protección contra apagado térmico
- Límite de sobrecorriente y protección contra cortocircuitos
- Encapsulado DIP8 sin plomo.

  -Resistencias-
- Cantidad: 6
- Valores: 3 resistencias de 1k y 3 resistencias de 2.2k

  -Capacitores-
- Tipo de capacitores: Electrolitico y Marmol
- Cantidad: 2 capacitores Electroliticos y 4 capacitores de Marmol
- Valores Electroliticos: 470uf
- Valores Marmol: 2 de 0.1uf y 2 de 10nf

  -Diseño del circuito-

ESQ:
<img width="301" height="278" alt="image" src="https://github.com/user-attachments/assets/155ef281-f9eb-4c68-abff-61a7057bf248" />



PCB:
<img width="960" height="538" alt="image" src="https://github.com/user-attachments/assets/9bef04cd-6200-4d7e-a18a-2db067cb19d0" />



  -Descripcion del funcionamiento-
- Detección de límites: El robot incorpora un sensor infrarrojo ubicado en la parte inferior del chasis, cuya función principal es identificar el borde de la superficie de combate (arena). Ante la detección de un cambio en el color o textura del suelo que indique el límite, el sistema activa una rutina de evasión para evitar que el robot lo cruce.

- Localización del oponente: El robot está equipado con sensores de proximidad, infrarrojos frontales, que permiten detectar la presencia de un contrincante en su campo de acción. Una vez identificado un objetivo, el robot inicia una secuencia de ataque orientada a la intercepción directa.

- Comportamiento ofensivo: El algoritmo de combate prioriza la ofensiva continua. El robot mantiene su trayectoria de ataque hasta que logra desplazar al oponente fuera de los límites del área de combate, momento en el cual se reinicia el ciclo de búsqueda de nuevos objetivos.

  -Montaje-
lijar la placa de cobre
luego conseguir el sticker del pcb 
acto siguiente planchar el sticker en la placa hasta ver que el tóner haya quedado perfectamente adherido a la placa
luego bañar la placa en percloruro por varios minutos
luego sacar la placa del percloruro después de revisar que no haya excedente de cobre
lijar nuevamente para sacar el tóner excedente
agujerear la placa luego de revisar que el cobre innecesario haya sido comido correctamente por el percloruro
iniciar montaje de componentes electrónicos
luego soldar cada componente a la placa (se recomienda usar el material de soldadura Flux) usar estaño para soldar (usar estaño 60% estaño 40% plomo)
luego verificar que no haya cortos
montaje terminado

  -herramientas-
un soldador de punta fina (de 60W)
estaño (60% estaño 40% plomo)
pinzas(de punta y alicate)
flux
chupa estaño y o cinta desoldante

- precauciones: al manejar herramientas peligrosas en manos inexpertas recomendamos el uso de guantes de seguridad y delantal, aunque estos no son obligatorios

-tipo de soldadura: 
Soldadura con aleación de estaño-plomo  

-Datasheet-

AD32: [E3S-A.PDF](https://github.com/user-attachments/files/23096925/E3S-A.PDF)

ESP32: [ESP32.PDF](https://github.com/user-attachments/files/23096990/ESP32.PDF)

TCRT5000:[TCRT5000.PDF](https://github.com/user-attachments/files/23097029/TCRT5000.PDF)

TA6586:[TA6586.PDF](https://github.com/user-attachments/files/23097099/TA6586.PDF)

-Tareas de cada integrante-
- Rodriguez Thiago: PCB, Esquematico
- Elias Vazquez: Carroceria (3D)
- Uriel Ramirez: Montaje de la placa y programacion

