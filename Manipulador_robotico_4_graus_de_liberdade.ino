#include <Servo.h>
#include <stdlib.h>
const int pot1 = A0;   //eixos joysticks
const int pot2 = A1;
const int pot3 = A2;
const int pot4 = A3;
const int bot = 4;  // botão joystick
int w, x, y, z;
int a, b, c, d;
int e = 49, f = 180, g = 11, h = 68;  //variavel servo
long t1, t2;                          //millis
long tempoBot;
int auxiliar;
int aperto;
int quantidadeMovimentos;    
int *PrimeiroServoVetor;      //vetores para salvar movimentos
int *SegundoServoVetor;
int *TerceiroServoVetor;
int *QuartoServoVetor;
Servo s1;
Servo s2;
Servo s3;
Servo s4;

void setup() {
  s1.attach(11);
  s2.attach(10);
  s3.attach(9);
  s4.attach(6);
  s1.write(w);
  s2.write(x);
  s3.write(y);
  s4.write(z);
  pinMode(bot, INPUT_PULLUP);
  Serial.begin(9600);
  s1.write(e);  //Inicialização dos servos em posição inicial
  s2.write(f);
  s3.write(g);
  s4.write(h);
}
void loop() {
  //Chamada das subrotinas que controlam os servos
  W();
  X();
  Y();
  Z();
  botao();  //Subrotina que monitora botão do joystick
  delay(5);
  //Serial.println((String)analogRead(A0) + " / "+ (String)analogRead(A1) +" / " + (String)analogRead(A2)+" / "+ (String)analogRead(A3)+" / " );
  Serial.println((String)e + " / " + (String)(f) + " / " + (String)(g) + " / " + (String)h + " / ");
}
////////////////////////////////////////
///////////Subrotinas Servos////////////
////////////////////////////////////////
void W() {
  w = analogRead(pot1);
  if (w >= 900 && e < 57) {
    e++;
    s1.write(e);
  }
  if (w <= 100 && e > 0) {
    e--;
    s1.write(e);
  }
}
void X() {
  x = analogRead(pot2);
  if (x >= 900 && f < 180) {
    f++;
    s2.write(f);
  }
  if (x <= 100 && f > 110) {
    f--;
    s2.write(f);
  }
}
void Y() {
  y = analogRead(pot3);
  if (y >= 900 && g < 150) {
    g++;
    s3.write(g);
  }
  if (y <= 100 && g > 11) {
    g--;
    s3.write(g);
  }
}
void Z() {
  z = analogRead(pot4);
  if (z >= 900 && h < 180) {
    h++;
    s4.write(h);
  }
  if (z <= 100 && h > 0) {
    h--;
    s4.write(h);
  }
}
//////////////////////////
///////sequencias/////////
//////////////////////////
void botao() {
  aperto = digitalRead(bot);
  if (aperto == 0) {
    tempo();
    if (tempoBot > 5000 && tempoBot < 10000) {
      //programar garra
      Serial.println("MODO DE PROGRAMACAO!!!");
      // Quantidade de vezes botão pressionado
      Quantidade();
      free(PrimeiroServoVetor);
      free(SegundoServoVetor);
      free(TerceiroServoVetor);
      free(QuartoServoVetor);
      PrimeiroServoVetor = (int *)malloc(quantidadeMovimentos + 1);
      SegundoServoVetor = (int *)malloc(quantidadeMovimentos + 1);
      TerceiroServoVetor = (int *)malloc(quantidadeMovimentos + 1);
      QuartoServoVetor = (int *)malloc(quantidadeMovimentos + 1);
      Serial.println("Quantidade de movimentos " + (String)quantidadeMovimentos);
      for (int i = 0; i < quantidadeMovimentos; i++) {
        while (digitalRead(bot)) {
          W();
          X();
          Y();
          Z();
          delay(10);
        }
        while (!digitalRead(bot)) {}
        PrimeiroServoVetor[i] = e;
        SegundoServoVetor[i] = f;
        TerceiroServoVetor[i] = g;
        QuartoServoVetor[i] = h;
        //Serial.println
      }
      tempoBot = 0;
    }
    if (tempoBot > 10000) {
      a = 0;
      b = 0;
      c = 0;
      d = 0;
    }
    if (tempoBot > 2000 && tempoBot < 5000) {
      for (int ii = 0; ii < quantidadeMovimentos; ii++) {
        while (PrimeiroServoVetor[ii] != e) {
          if (PrimeiroServoVetor[ii] < e) {
            e -= 1;
            s1.write(e);
            delay(10);
          }
          if (PrimeiroServoVetor[ii] > e) {
            e += 1;
            s1.write(e);
            delay(10);
          }
        }
        while (SegundoServoVetor[ii] != f) {
          if (SegundoServoVetor[ii] < f) {
            f -= 1;
            s2.write(f);
            delay(10);
          }
          if (SegundoServoVetor[ii] > f) {
            f += 1;
            s2.write(f);
            delay(10);
          }
        }
        while (TerceiroServoVetor[ii] != g) {
          if (TerceiroServoVetor[ii] < g) {
            g -= 1;
            s3.write(g);
            delay(10);
          }
          if (TerceiroServoVetor[ii] > g) {
            g += 1;
            s3.write(g);
            delay(10);
          }
        }
        while (QuartoServoVetor[ii] != h) {
          if (QuartoServoVetor[ii] < h) {
            h -= 1;
            s4.write(h);
            delay(10);
          }
          if (QuartoServoVetor[ii] > h) {
            h += 1;
            s4.write(h);
            delay(10);
          }
        }
      }
    }
  }
}
void tempo() {                         //Rotina que verifica o tempo sempre que o botão do joystick é pressionado
  t1 = millis();
  while (digitalRead(bot) == 0) {
    tempoBot = millis() - t1;
    Serial.println(tempoBot);
  }
}
void Quantidade() {                    //Rotina que conta a quantidade de movimentos (tempo pressionado deve ser entre 100ms e 1000ms)
  quantidadeMovimentos = 0;
  tempoBot = 0;
  while (tempoBot < 1000) {
    tempo();
    if (tempoBot < 1000 && tempoBot > 100) {
      quantidadeMovimentos++;
      tempoBot = 0;
    }
  }
}