# Brazalete magico 
[![Contribuidores][contribuidores-shield]][contributors-url]

## contenido
<details>
  <summary>Tabla contenidos</summary>
  <ol>
    <li>
      <a href="#acerca-del-proyecto">Acerca Del Proyecto</a>
      <ul>
        <li><a href="#nombre-del-proyecto">Nombre del proyecto</a></li>
        <li><a href="#descripcion-general-del-proyecto">Descripción general del proyecto</a></li>
      </ul>
    </li>
    <li>
        <a href="#objetivo-del-proyecto">Objetivo del proyecto</a>
    </li>
    <li>
        <a href="#vision-del-proyecto">Visión del proyecto</a>
    </li>
        <li>
        <a href="#librerias">Librerías</a>
    </li>
        <li>
        <a href="#software">Software</a>
    </li>
    <li>
        <a href="#hardware">Hardware</a>
    </li>
    <li>
        <a href="#epicas">Épicas</a>
    </li>
    <li>
        <a href="#requerimientos">Requerimientos</a>
    </li>
    <li>
        <a href="#diagrama-inicial">Diagrama (Arquitectura)</a>
    </li>
    <li>
        <a href="#prototipo-de-pulsera-multiusos">Prototipo Inicial de Pulsera Multiusos</a>
    </li>
    <li>
        <a href="#tablero">Tablero</a>
    </li>
    <li>
        <a href="#resultados">Resultados</a>
    </li>
    <li>
      <a href="#participantes">Participantes</a>
    </li>
  </ol>
</details>

<br><br><br>

<!-- Acerca del proyecto -->
## Acerca del proyecto

### Nombre del proyecto
**Brazalete Magico**

### Descripción general del proyecto
> En este proyecto se genero un prototipo que propone ser un accesorio tecnológico para las personas mayores de edad, de forma que recolecte datos a través de los distintos sensores, y posteriormente análisar su estado con los datos recolectados y tomar decisiones del usuario.

## Objetivo del proyecto
> El objetivo del proyecto es desarrollar un accesorio de uso personal el cual es un brazalete tecnológico que permita a los usuarios medir la temperatura, ritmo cardiaco y de igual manera mostrar la hora en tiempo real, guardando uno de estos datos y mostrandolos en una pequeña pantalla, de la misma forma el usuario podrá acceder a un sitio wey para poder ver los datos y   en la cual podrá visualizar los datos mencionados en tiempo real.

## Visión del proyecto
> Es poder llegar a muchos mas usuarios de a nivel regional de esta idea tecnologica tambien ser una empresa lider de fabricación y así mismo después expandirnos a nivel estatal en el estado de Guanajuato y por consecuencia a nivel nacional ne México.


<br><br><br>
## Librerías
* Adafruit_GFX.h
* Adafruit_SSD1306.h
* DHTesp.h
* EasyBuzzer.h
* Esp_camera.h
* FirebaseESP32.h
* HeartRate.h
* MAX30105.h
* Pgmspace.h
* Soc.h
* WiFiClientSecure.h
* WiFi.h

<br><br><br>
## Software
<table>
  <tr>
    <th>Software</th>
      <th>Licencia</th>
  </tr>
  <tr>
    <td>Arduino</td>
    <td>Licencia Pública General</td>
  </tr>
  
  <tr>
    <td>Firebase</td>
    <td>Modelo de precios de pago por uso.  
      <ul>
        <li>Almacenamiento en base de datos $0.18 por GB</li>
        <li>Almacenamiento $0.026 por GB </li>
      </ul>
    </td>
  </tr>
</table>

<br><br><br>
## Hardware
<table> <tr> <th>Componente</th><th>Imagen</th><th>Descripción</th><th>Cantidad</th></tr> 
  <tr>
    <td>ESP8266 Cam</td>
    <td>
    <img src="https://user-images.githubusercontent.com/56412490/190190128-f62d3238-3a85-434e-9b9f-ec942da3b759.png"  alt="ESP32 Cam" width="100"/>
    </td>
    <td><ul><li>Voltaje: 5 V<li>CPU de 32 bits de doble núcleo de baja potencia para procesadores de aplicaciones<li>Frecuencia principal de hasta 240 MHz<li>Potencia de cálculo de hasta 600 DMIPS<li>SRAM integrado de 520 KB<li>PSRAM externo de 4 M<li>Es ideal para interfaces como: UART. SPI. I2C. PWM. ADC. DAC<li>Soporta cámaras OV2640 y OV7670 (flash incorporado)<li>Apoyo imagen WiFi subir<li>Apoyo TF tarjeta</ul></td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Sensor De Pulso Y Frecuencia Cardiaca</td>
    <td>
    <img src="https://http2.mlstatic.com/D_NQ_NP_972186-MLM31229048423_062019-O.webp" alt="PCFC" width="100"/>
    </td>
    <td> <ul><li>Material: FR4<li>Voltaje: 5V<li>Factor de amplificación: 330<li>Longitud de onda: 609 nm<li></ul></td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Pantalla OLED SSD1306</td>
    <td>
    <img src="https://user-images.githubusercontent.com/28987470/173898074-3669ca53-a985-4243-b21e-d4180c152393.png" alt="OLED" width="100"/>
    </td>
    <td> <ul><li>Resolucion: 128X64<li>Tamaño: 0.96 " - 26x14mm<li>Interface: I2C<li>Voltaje de Operacion: 3.3-5v<li>Angulo de Vision: 160°</ul></td>
    <td>1</td>
  </tr> 
  <tr>
    <td>Sensor De Temperatura Infrarrojo Gy-906 Mlx90614 </td>
    <td>
    <img src="https://http2.mlstatic.com/D_NQ_NP_2X_638694-MLM31417461843_072019-F.webp" width="100"/>
    </td>
    <td> <ul><li>Tipo de interfaz digital: IIC (modo esclavo) o PWM<li>Rango de medición de temperatura: -70℃~382℃<li>
Error de medición de temperatura: ± 0,5 ℃ (a temperatura biente) resolución 0,02 ℃<li>Voltaje de funcioniento: 3.3 V ~ 5 V<li>Temperatura ambiente de funciomiento: -40 ~ 125 ℃</ul></td>
    <td>1</td>
  </tr>
  <tr>
    <td>Sensor DHT 11</td>
    <td>
    <img src="https://user-images.githubusercontent.com/56412490/190190920-131170f8-a7f5-4fbf-9a9a-215a4bc4eac8.png" alt="OLED" width="100"/>
    </td>
    <td> <ul><li>Muy barato. <li>Funciona con 3,3 y 5V de alimentación. <li>Rango de temperatura: de 0º a 50º con 5% de precisión (pero solo mide por grados, no fracciones. <li>Rango de humedad: de 20% al 80% con 5% de precisión. <li>1 Muestra por segundo (No es el más rápido del oeste)</ul></td>
    <td>1</td>
  </tr>
  <tr>
    <td>Sensor MH Real Time</td>
    <td>
    <img src="https://user-images.githubusercontent.com/56412490/190192427-724d7d59-fc3c-421a-a407-030f7fd4c5c9.png" alt="OLED" width="100"/>
    </td>
    <td> <ul><li>Chip principal: DS1302. <li>Voltaje de alimentación mínimo: 3.3 V. <li>Tipo de batería: CR2032 de litio
 <li>RAM para el almacenamiento de datos: 31 X 8 <li>Dimensiones: 43 mm X 22 mm X 11 mm <li>Número de pines: 5. </ul></td>
    <td>1</td>
  </tr>
  <tr>
    <td>Sensor de sonido</td>
    <td>
    <img src="https://store.prometec.net/wp-content/uploads/2019/06/HTB1VBw.KFXXXXcIXXXXq6xXFXXXH-768x768.jpg" alt="OLED" width="100"/>
    </td>
    <td> <ul><li>Alimentación: 5  VDC. <li>Salida analógica. <li>Salida digital de nivel de umbral.
 <li>Micrófono de alta sensibilidad. <li>Indicador luminoso de encendido</ul></td>
    <td>1</td>
  </tr>
  <tr>
    <td>Buzzer</td>
    <td>
    <img src="https://www.iberobotics.com/wp-content/uploads/2018/01/buzzer_zumbador_activo_5v-1.jpg" alt="OLED" width="100"/>
    </td>
    <td> <ul><li>Voltaje de entrada: 4V a 7V <li>Diámetro: 12mm. <li>Altura: 9,5mm
 <li>Efecto – sonido continuo <li>Intensidad de sonido: 85dB a 10cm</ul></td>
    <td>1</td>
  </tr>
  <tr>
    <td>Button push</td>
    <td>
    <img src="https://http2.mlstatic.com/D_NQ_NP_988216-MLM29364237192_022019-O.jpg" alt="OLED" width="100"/>
    </td>
    <td> <ul><li>Utilizado como switch o interruptor al momento de ser presionado. <li>Funciona como contacto normalmente abierto (NA). <li>Voltaje: 120 VDC/ 220 VAC.
 <li>4 pines amigables para usar en el protoboard. </ul></td>
    <td>1</td>
  </tr>
</table>

<br><br><br>
## Épicas
<p>Brazalete de uso personal con funciones que recopilan información relevante para el usuario.</p>
<p>Esta contendrá las siguientes funcionalidades:</p>
<ol>
  <li>Detección de temperatura</li>
    <ul>
        <li>Mostrar datos capturados en pantalla OLED.</li>
        <li>Guardado de datos en Base de Datos.</li>
        <li>Desarrollo de aplicación web para mostrar datos.</li>
        <li>Mostrar datos en el sitio Web.</li>
    </ul>
  <li>Pantalla OLED.</li>
    <ul>
      <li>Mostrar de datos obtenidos de los sensores en pantalla.</li>
    </ul>
  <li>Ritmo cardiaco.</li>
      <ul>
        <li>Mostrar datos capturados en pantalla OLED.</li>
        <li>Guardado de datos en Base de Datos.</li>
        <li>Desarrollo de aplicación web para mostrar datos.</li>
        <li>Mostrar datos en el sitio Web.</li>
    </ul>
  
  <li>Sensor de Humedad.</li>
    <ul>
        <li>Mostrar datos capturados en pantalla OLED.</li>
        <li>Tomar la temperatura y la Humedad del exterior.</li>
        <li>Guardado de datos en Base de Datos.</li>
        <li>Mostrar datos en el sitio Web.</li>
    </ul>
  
  <li>Sensor de Reloj.</li>
    <ul>
        <li>Mostrar datos capturados en pantalla OLED.</li>
        <li>Mostrar la hora en tiempo Real.</li>
    </ul>
     <li>Sensor de sonido.</li>
    <ul>
        <li>Cambiar de interfaz de panatalla oled para mostrar otros datos al dectetar sonido</li>
        <li>Mostrar datos tiempo Real.</li>
    </ul>
    <li>Sensor de sonido.</li>
    <ul>
        <li>Cambiar de interfaz de panatalla oled para mostrar otros datos al presionar el button</li>
        <li>activar el buzzer con el cambio de datos.</li>
    </ul>
  
</ol>


<br><br><br>
## Requerimientos
<table>
  <tr>
    <th>No.</th>
      <th>Requerimiento</th>
  </tr>
  <tr>
    <td>1</td>
    <td>Medición de variables a partir de sensores de temperatura</td>
  </tr>
  
  <tr>
    <td>2</td>
    <td>Almacenamiento de datos de manera continua y permanente.</td>
  </tr>
  
  <tr>
    <td>3</td>
    <td>Mostrar los datos en una panta OLED</td>
  </tr>
</table>

<br><br><br>
## Diagrama (Arquitectura)
<img width="100%" height="auto" alt="Diagrama_Pulsera Multiusos" src="https://user-images.githubusercontent.com/56412490/190197049-684855ad-4abe-4a8c-9ad5-38b9f28b6ad4.PNG">

<br><br><br>
## Prototipo Inicial de Brazalette magico
![image](https://user-images.githubusercontent.com/56412490/190201526-aca25e4f-6d46-40d8-a002-d6409451f961.png)

<br><br><br>
## Tablero
https://trello.com/b/qvzCt7Np/pulsera-multiusos
### Sprint 1
![Sprint1](https://user-images.githubusercontent.com/75550479/173165506-6048e54b-22a5-425e-b668-ffc520e343b1.png)
### Sprint 2
![Spring2](https://user-images.githubusercontent.com/56412490/190197527-61a73bf3-3741-4004-9062-b6376212be82.PNG)

### Sprint 3
![Spring3](https://user-images.githubusercontent.com/56412490/190197609-bee35473-930d-4e25-8c94-7bf8b3f6fd3f.PNG)

<br><br><br>
## Resultados
![ResultadoUno](https://user-images.githubusercontent.com/56412490/190198688-ad46e63e-18b0-4006-bbbc-bd4e41be200f.jpg)
![ResultadoDos](https://user-images.githubusercontent.com/56412490/190198733-3a81dee7-77f4-4814-97d1-ce531c15ace3.jpg)
![ResultadoTres](https://user-images.githubusercontent.com/56412490/190198775-e87a85e1-1a43-42aa-b14f-3585665bc724.jpg)
![image](https://user-images.githubusercontent.com/56412490/190237078-d7742ba4-5323-495c-b0f0-8c0e7f34cbf6.png)

VIDEO: https://drive.google.com/file/d/1NB_aTRbiswZk5bO6xLjl_fWAyNpkNXjw/view?usp=sharing
<br>
[]()

<br><br><br>
## Participantes
* [Cabello Salas Juan Carlos]()
* [Cruz Medina Jose Alejandro]()
* [Chimal Villafuerte Kevin Michelle]()
* [Méndez López Jonathan Anselmo]()
