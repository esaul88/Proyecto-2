// C++ code
//
void setup()
{
  //Mientras el botón correspondiente no sea presionado,
  //el pin leerá una señal de 5V (HIGH).
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  
  //Estas son las conexiones a los pines A del L293D.
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  //Entre cada presionamiento del botón se apagan los dos motores
  //con tal de evitar que un estado se sobreponga sobre otro y
  //cause un posible cortocircuito.
  digitalWrite(3, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  //Cada while loop espera que se presione solamente el botón
  //correspondiente.
  while(digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH && digitalRead(7) == LOW){
    //Con base en el código de referencia, se mandan señales
    //de 5V o 0V a los pines correspondientes.
    digitalWrite(3, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  
  while(digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == LOW && digitalRead(7) == HIGH){
    digitalWrite(3, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  
  while(digitalRead(4) == HIGH && digitalRead(5) == LOW && digitalRead(6) == HIGH && digitalRead(7) == HIGH){
    //Para los estados donde uno de los motores se mueve a velocidad
    //media, se utiliza analogWrite para mandar una señal PWM (analogWrite(), 2025).
    analogWrite(3, 128);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  
  while(digitalRead(4) == LOW && digitalRead(5) == HIGH && digitalRead(6) == HIGH && digitalRead(7) == HIGH){
    digitalWrite(3, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    analogWrite(11, 128);
  }
}