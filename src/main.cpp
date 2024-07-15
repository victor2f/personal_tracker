// Area para as inclusões de biblioteca
// Core Arduino
#include <Arduino.h>


// Criando a porta de comunicação para o modulo GPS
// Utilizando a UART 2 com parametros padrão
HardwareSerial gpsPort(2);


// Declarando as funções que seram utilizadas
int processGPSData();


// Alocando as variaveis que seram utilizadas
char gpsData[128];


// Configurando os a comunicação entre o ESP32 e os dispositivos externos
void setup() {
    Serial.begin(115200);
    Serial.print("Serial start!\n");

    gpsPort.begin(9600);
    Serial.print("Reading GPS!\n");
}


// Executando o código em LOOP
void loop() {
    while (Serial2.available()) {
        char c = Serial2.read();
            Serial.print(c);
    }
}


// Função que processa e interpreta os dados do GPS recebidos
// Se a mensagem for do tipo RMC ($GPRMC), identifica e indica a recepção dessa mensagem específica.
int processGPSData() {
    // Para a funcao de Timeout
    // unsigned long startTime = millis();
    
    bool starMessage = false;
    int indexMessage = 0;

    while (true) {
        if (gpsPort.available()) {
            char c = gpsPort.read();
            
            if (indexMessage < sizeof(gpsData) - 1) {
                if (c == '$') {
                    starMessage = true;
                }

                if (c == '\n') {
                    starMessage = false;
                    c = '\0';
                }

                gpsData[indexMessage] = c;
                Serial.println(gpsData);
            }
        }
    }
}