int leds[5] = {8, 9, 10, 11, 12};
int pulsador[5] = {2, 3, 4, 5, 6};
int i;
void setup() {
  // put your setup code here, to run once:
  for (i = 0; i < 5; i++)
  {
    pinMode(pulsador[i], INPUT_PULLUP);//recibimos los datos de los pulsadores configurandolos como entradas
  }
  for (i = 0; i < 5; i++)
  {
    pinMode(leds[i], OUTPUT);//se escriben los datos de salida a los pines
  }
  Serial.begin(9600);
}
int val[5] = {1, 1, 1, 1, 1};
String datos = "";
void loop() {
  datos = "";
  val[0] = digitalRead(pulsador[0]);
  val[1] = digitalRead(pulsador[1]);
  val[2] = digitalRead(pulsador[2]);
  val[3] = digitalRead(pulsador[3]);
  val[4] = digitalRead(pulsador[4]);
  for (i = 0; i < 5; i++)
  {
    datos += String(val[i]) + " ";
  }
  Serial.println(datos);
  int btnPres = -1;
  for (i = 0; i < 5; i++)
  {
    if (val[i] == 0)
      btnPres = i;//busca que boton fue presionado
  }
  switch (btnPres)
  {
      if (btnPres == 0) {
        digitalWrite(leds[0], 1);
      } else if (btnPres == 1) {
        digitalWrite(leds[1], 1);
      } else if (btnPres == 2) {
        digitalWrite(leds[2], 1);
      } else if (btnPres == 3) {
        digitalWrite(leds[3], 1);
      } else if (btnPres == 4) {
        digitalWrite(leds[4], 1);
      }
  }
  limpiar();
  delay(1000);
}
  void limpiar()
  {
    for (i = 0; i < 5; i++)
    {
      digitalWrite(leds[i], 0);
    }
  }
