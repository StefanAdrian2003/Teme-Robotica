#include <Arduino.h>

#define RED 13
#define GREEN 11
#define BLUE 10

#define START_STOP 8
#define DIFICULTATE 2



const char* cuvinte[] = {
  "alb", "apa", "arde", "aripi", "balon", "baza", "bec", "bine", "bloc", "boabe",
  "brad", "carte", "casa", "catel", "cald", "ceara", "cerc", "ceas", "chip", "cires",
  "cod", "colt", "drum", "dus", "elefant", "foc", "frig", "fulg", "gara", "greu",
  "grija", "iarna", "intreb", "jos", "lac", "lemn", "luna", "mic", "mere", "minge",
  "nor", "nota", "om", "oras", "pahar", "papa", "picior", "ploaie", "pom", "punct",
  "raul", "robot", "rost", "sapa", "sat", "scoala", "soare", "sol", "timp", "verde"
};


int numarCuvinte = sizeof(cuvinte) / sizeof(cuvinte[0]);
int dificultate = 0;
unsigned long intervalDificultate = 5000;
String dif = "Easy";


bool inGame = false;


unsigned long start = 0;
unsigned long lastWordTime = 0;
unsigned long durataJoc = 30000;


String userInput;
int cuv_corecte;
String cuvant;
char buffer[20];



void schimba_dificultate() 
{
    dificultate = (dificultate + 1) % 3;
    switch(dificultate)
    {
        case 0:
          Serial.println("Easy");
          dif = "Easy";
          intervalDificultate = 6000;
          break;
        case 1:
          Serial.println("Medium");
          dif = "Medium";
          intervalDificultate = 4000;
          break;
        case 2:
          Serial.println("Hard");
          dif = "Hard";
          intervalDificultate = 2500;
          break;
    }
}



bool debounce(int buton)
{
    int lastButtonState = LOW;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 100;


    while(1) {
        int reading = digitalRead(buton);

        if (reading != lastButtonState) {
          lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) {
          if(reading == HIGH)
            return 1;

        }
        lastButtonState = reading;
    }
    return 0;
}





void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(0));

    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    pinMode(START_STOP, INPUT_PULLUP);
    pinMode(DIFICULTATE, INPUT_PULLUP);

    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
}


void loop()
{
    if(digitalRead(DIFICULTATE) == LOW && !inGame) {
        if(debounce(DIFICULTATE) == 1)
            schimba_dificultate();
    }

    if(digitalRead(START_STOP) == LOW && !inGame) {
        if(debounce(START_STOP) == 1) {
            inGame = !inGame;
            for(int i = 3; i >= 1; i--) {
                Serial.println(i);
                digitalWrite(RED, HIGH);
                digitalWrite(GREEN, HIGH);
                digitalWrite(BLUE, HIGH);
                delay(500);

                digitalWrite(RED, LOW);
                digitalWrite(GREEN, LOW);
                digitalWrite(BLUE, LOW);
                delay(500);
            }

            digitalWrite(GREEN, HIGH);
            Serial.println("Start!");
            start = millis();
            lastWordTime = millis();
            cuv_corecte = 0;
            cuvant = cuvinte[random(numarCuvinte)];
            Serial.println(cuvant);
            userInput = "";
        }
    } else if(digitalRead(START_STOP) == LOW && inGame) {
        if(debounce(START_STOP) == 1) {
            inGame = !inGame;
            digitalWrite(RED, HIGH);
            digitalWrite(GREEN, HIGH);
            digitalWrite(BLUE, HIGH);
        }
    }

    if(inGame) {
        if(millis() - start > durataJoc) {
            inGame = !inGame;
            digitalWrite(RED, HIGH);
            digitalWrite(GREEN, HIGH);
            digitalWrite(BLUE, HIGH);
            Serial.println("Jocul s-a terminat!");
            Serial.println("Cuvinte scrise corect: ");
            Serial.println(cuv_corecte);
        }

        if ((millis() - lastWordTime >= intervalDificultate) && inGame) {
            lastWordTime = millis();
            cuvant = cuvinte[random(numarCuvinte)];
            Serial.println(cuvant);
            userInput = "";
        }

        if (Serial.available() > 0) {
            char caracter = Serial.read();

            if (caracter == '-') {
                if (userInput.length() > 0) {
                    userInput.remove(userInput.length() - 1);
                    Serial.print("\b \b"); 
                }
            } 
            else {
                userInput += caracter;
                Serial.print(caracter);

                
                int currentIndex = userInput.length() - 1;
                if (userInput[currentIndex] != cuvant[currentIndex]) {
                    digitalWrite(RED, HIGH);
                    digitalWrite(GREEN, LOW);
                } else {
                    digitalWrite(RED, LOW);
                    digitalWrite(GREEN, HIGH);
                }

                
                if (userInput.length() == cuvant.length()) {
                    if (userInput == cuvant) { 
                        Serial.println("\nCorrect!");
                        digitalWrite(GREEN, HIGH);
                        cuv_corecte++;
                    } else {
                        Serial.println("\nIncorrect!");
                        digitalWrite(RED, HIGH);
                    }

                    
                    userInput = "";
                    cuvant = cuvinte[random(numarCuvinte)];
                    Serial.println(cuvant);
                    lastWordTime = millis();
                }
            }
        }
    }
}