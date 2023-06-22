#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
	const char* ssid = "xxxxxxxxxx";
	const char* password = "xxxxxxxxxx";
	
WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000); // winter
// NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 7200, 60000);// sommer
int ziffer[10] = {25, 14, 15, 16, 17, 18, 19, 21, 22, 23 }; // 0 - 9
int zeit[4] = { 26, 27, 32, 33 };
int warte = 2;

void setup() {
	Serial.begin(115200);
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	timeClient.begin();
	for (int i = 0; i < 11; i++)
	{
		pinMode(ziffer[i], OUTPUT);
		delay(warte);
	}
	for (int i = 0; i < 5; i++)
	{
		pinMode(zeit[i], OUTPUT);
		delay(warte);
	}
}

void loop() {
	timeClient.update();
	delay(warte);
	int A = (timeClient.getHours() / 10);
	int B = (timeClient.getHours() % 10);
	int C = (timeClient.getMinutes() / 10);
	int D = (timeClient.getMinutes() % 10);
	/*
	Serial.print(A);
	Serial.print(B);
	Serial.print(":");
	Serial.print(C);
	Serial.println(D);
	Serial.print(ziffer[A]);
	Serial.print(ziffer[B]);
	Serial.print(":");
	Serial.print(ziffer[C]);
	Serial.println(ziffer[D]);
	*/
	digitalWrite(zeit[0], HIGH);
	digitalWrite(ziffer[A], HIGH);
	delay(warte);
	digitalWrite(zeit[0], LOW);
	digitalWrite(ziffer[A], LOW);
	digitalWrite(zeit[1], HIGH);
	digitalWrite(ziffer[B], HIGH);
	delay(warte);
	digitalWrite(zeit[1], LOW);
	digitalWrite(ziffer[B], LOW);
	digitalWrite(zeit[2], HIGH);
	digitalWrite(ziffer[C], HIGH);
	delay(warte);
	digitalWrite(zeit[2], LOW);
	digitalWrite(ziffer[C], LOW);
	digitalWrite(zeit[3], HIGH);
	digitalWrite(ziffer[D], HIGH);
	delay(warte);
	digitalWrite(zeit[3], LOW);
	digitalWrite(ziffer[D], LOW);
}