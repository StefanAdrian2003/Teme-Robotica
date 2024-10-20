#include <Arduino.h>

#define red_led_rgb 7
#define green_led_rgb 6
#define blue_led_rgb 5

#define red_led 9
#define yellow_led_1 10
#define yellow_led_2 11
#define green_led 12

#define buton_1 2
#define buton_2 3

void setup() {
    pinMode(red_led_rgb, OUTPUT);
    pinMode(green_led_rgb, OUTPUT);
    pinMode(blue_led_rgb, OUTPUT);

    pinMode(red_led, OUTPUT);
    pinMode(yellow_led_1, OUTPUT);
    pinMode(yellow_led_2, OUTPUT);
    pinMode(green_led, OUTPUT);

    pinMode(buton_1, INPUT_PULLUP);
    pinMode(buton_2, INPUT_PULLUP);
}

unsigned int PrevTime = 0;
unsigned int CurrentTime = 0;


bool debounce()
{
	int lastButtonState = LOW;
	unsigned long lastDebounceTime = 0;
	unsigned long debounceDelay = 50;

	int timp_initial = millis();

	while(1)
	{
		int reading = digitalRead(buton_2);

		if (reading != lastButtonState) {
    		lastDebounceTime = millis();
  		}

		if ((millis() - lastDebounceTime) > debounceDelay) {
			if(reading == LOW)
				return 1;
			else
				break;
    	}

		lastButtonState = reading;

		if(millis() - timp_initial > 200)
			break;
	}
	return 0;
}



bool Reset()
{
    PrevTime = millis();    
    while(digitalRead(buton_2) == LOW)
    {
        CurrentTime = millis();
        if(CurrentTime - PrevTime >= 1000){
      	    for(int i=1;i<=3;i++){
      	    	digitalWrite(red_led, LOW);
    	    	digitalWrite(yellow_led_1, LOW);
    	    	digitalWrite(yellow_led_2, LOW);
    	    	digitalWrite(green_led, LOW);
      	    	delay(500);

      	    	digitalWrite(red_led, HIGH);
    	    	digitalWrite(yellow_led_1, HIGH);
    	    	digitalWrite(yellow_led_2, HIGH);
    	    	digitalWrite(green_led, HIGH);
      	    	delay(500);
			}
            return 1;
        }
    }
    return 0;
}



void loop(){
start:
    digitalWrite(red_led_rgb, LOW);
    digitalWrite(green_led_rgb, HIGH);
    digitalWrite(blue_led_rgb, LOW);

    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led_1, LOW);
    digitalWrite(yellow_led_2, LOW);
    digitalWrite(green_led, LOW);

	//APAS PRIMUL BUTON
  	if (digitalRead(buton_1) == LOW) {

        digitalWrite(red_led_rgb, HIGH);
    	digitalWrite(green_led_rgb, LOW);
    	digitalWrite(blue_led_rgb, LOW);


		//CLIPESTE PRIMUL
		for(int i=1;i<=2;i++)
		{
      		digitalWrite(red_led, HIGH);
      		delay(750);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;

      		digitalWrite(red_led, LOW);
      		delay(750);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;
		}


      	//PRIMUL RAMANE APRINS
      	digitalWrite(red_led, HIGH);


      	//CLIPESTE AL DOILEA
		for(int i=1;i<=2;i++){
      		digitalWrite(yellow_led_1, HIGH);
      		delay(750);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;

      		digitalWrite(yellow_led_1, LOW);
      		delay(750);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;
		}


      	//AL DOILEA RAMANE APRINS
      	digitalWrite(yellow_led_1, HIGH);
      

      	//CLIPESTE AL TREILEA
		for(int i=1;i<=2;i++){
      		digitalWrite(yellow_led_2, HIGH);
      		delay(750);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
        	    	if(Reset())
        	       		goto start;

      		digitalWrite(yellow_led_2, LOW);
      		delay(750);

	        if(digitalRead(buton_2) == LOW)
				if(debounce())
        	    	if(Reset())
            	   		goto start;
		}

      
      	//AL TREILEA RAMANE APRINS
      	digitalWrite(yellow_led_2, HIGH);


      	//CLIPESTE AL PATRULEA
		for(int i=1;i<=2;i++){
      		digitalWrite(green_led, HIGH);
     		delay(750);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;

      		digitalWrite(green_led, LOW);
     		delay(750);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;
		}

      
      	//AL PATRULEA RAMANE APRINS
        digitalWrite(green_led, HIGH);
      	delay(750);

        if(digitalRead(buton_2) == LOW)
			if(debounce())
            	if(Reset())
               		goto start;

      
      	//CLIPESC TOATE DE 3 ORI
		for(int i=1;i<=3;i++){
      		digitalWrite(red_led, LOW);
    		digitalWrite(yellow_led_1, LOW);
    		digitalWrite(yellow_led_2, LOW);
    		digitalWrite(green_led, LOW);
      		delay(500);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;

      		digitalWrite(red_led, HIGH);
    		digitalWrite(yellow_led_1, HIGH);
    		digitalWrite(yellow_led_2, HIGH);
    		digitalWrite(green_led, HIGH);
      		delay(500);

        	if(digitalRead(buton_2) == LOW)
				if(debounce())
            		if(Reset())
               			goto start;
		}

      delay(1000);
    } 
}