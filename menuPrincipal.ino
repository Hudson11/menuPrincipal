
void setup() {
  Serial.begin(115200);
}

/**
   Função que lê uma string da Serial
   e retorna-a
*/
String leStringSerial() {
  String conteudo = "";
  char caractere;

  // Enquanto receber algo pela serial
  while (Serial.available() > 0) {
    // Lê byte da serial
    caractere = Serial.read();
    // Ignora caractere de quebra de linha
    if (caractere != '\n') {
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }

  //Serial.print("Recebi: ");
  //Serial.println(conteudo);

  return conteudo;
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {

  String modo;
  String direcao;
  
  // Se receber algo pela serial
  if (Serial.available() > 0) {
    // Lê toda string recebida
    String recebido = leStringSerial();

    modo = getValue(recebido, ';', 0);
    direcao = getValue(recebido, ';', 1);
    //String direcao2 = getValue(recebido, ';', 2);

    //Serial.println("Y:" + modo);
    //Serial.print("X:" + direcao);
    //Serial.print("X:" + direcao2);
    
  }

  /*
  //Serial.print("teste");
  Serial.print(direcao);
  //Serial.println("teste");
  delay(3000);
  if(direcao == "frente"){
    Serial.println("VRAAAU");
  }
  */

  
  if(modo == "manual"){
    //Serial.println("manuaaaal");
    //Serial.println(direcao);
    if(direcao == "direita"){
      //andar para direita
      Serial.println("andar para direita");
    }
    if(direcao == "esquerda"){
      //andar para esquerda
      Serial.println("andar para esquerda");
    }
    if(direcao == "frente"){
      //andar para frente
      Serial.println("andar para frente");
    }
    if(direcao == "parar"){
      //parar ou dar re
      Serial.println("parar");
    }
  }else if(modo == "mapeamento"){
    //implementar mapeamento
  }else if(modo == "estacionamento"){
    //implementar estacionamento
  }
  
}
