#include <iostream>
#include <wiringPi.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

using namespace std;


const int leftIR = 2;
const int rightIR = 3;

// motor A
const int IN1 = 4;
const int IN2 = 17;
// Motor B
const int IN3 = 14;
const int IN4 = 18;


int main()
{
	for (int i = 0; i < 2; i++) {
		printf("actuator testing");
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, HIGH);
		analogWrite(IN1, 500);
		analogWrite(IN2, 500);
		delay(1000);
	}


	// When initialize wiring failed, print message to screen
	if (wiringPiSetup() == -1) {
		printf("setup wiringPi failed !");

		return 1;
		return 0;
	}
}


	void setup() {
		

		delay(750);
		pinMode(leftIR, INPUT);
		pinMode(rightIR, INPUT);
		pinMode(IN1, OUTPUT);
		pinMode(IN2, OUTPUT);
		pinMode(IN3, OUTPUT);
		pinMode(IN4, OUTPUT);
		
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
		digitalWrite(IN4, LOW);
	}


	void line_follower_loop() {
		wiringPiSetupPhys();

		int x = 1;
		for (int i = 0; i < x; i++) { // Loop for making the motors rolling
			++x;
			
			delayMicroseconds(10);
			int l = digitalRead(leftIR);
			int r = digitalRead(rightIR);

			if (l == HIGH and r == HIGH) // MOVES FORWORD
			{
				digitalWrite(IN1, HIGH);
				digitalWrite(IN2, HIGH);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, LOW);
				printf("2low" );
			}
			

			else if (l == LOW and r == HIGH) // TURN RIGHT
			{
				digitalWrite(IN1, HIGH);
				digitalWrite(IN2, HIGH);
				digitalWrite(IN3, HIGH);
				digitalWrite(IN4, LOW);
				printf("L high");

			}


			else if (l == HIGH and r == LOW) // TURN LEFT
			{
				digitalWrite(IN1, HIGH);
				digitalWrite(IN2, HIGH);
				digitalWrite(IN3, LOW);
				digitalWrite(IN4, HIGH);
				printf("R high");
			}

			
			else   {						 // STAND STILL
				digitalWrite(IN1, HIGH);
				digitalWrite(IN2, HIGH);
				digitalWrite(IN3, HIGH);
				digitalWrite(IN4, HIGH);
				printf("2 high");
				
			}
			

		}
	}
