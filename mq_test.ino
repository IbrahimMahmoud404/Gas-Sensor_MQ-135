int buzz = 8;
int ana = A5;
int an;
int normal = 0;
int steam = 0;
int smoke = 0;
int alcohol = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ana,INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 an = analogRead(ana);    //read analog read “sensor read”
// Serial.println(an);
  if(an > 0 && an <= 200){ //Noraml air levels
    normal++;
    steam = 0;
    smoke = 0;
    alcohol = 0;
    if(normal == 5000){
    Serial.println("noraml air ^_^");
    Serial.println(an);
    normal = 0;
    }
//hardware delay
    delay(1);
   // an = analogRead(ana);
  }
  
  if(an > 200 && an <= 350){ //Steam levels
    steam++;
    normal = 0;
    smoke = 0;
    alcohol = 0;
    if(steam == 5000){
    Serial.println("Steam ^_-");
    Serial.println(an);
    tone(buzz,200,2000);
    steam = 0;
    }
    delay(1);
  //  an = analogRead(ana);
  }
  
  if(an > 350 && an <= 550){ //Smoke levels
    smoke++;
    normal = 0;
    steam = 0;
    alcohol = 0;
    if(smoke == 5000){
    Serial.println("Smoke -_-");
    tone(buzz,750,2000);
    Serial.println(an);
    smoke = 0;
    }
    delay(1);
   // an = analogRead(ana);
  }
  
  if(an > 700 && an <= 900){ //Alcohol levels
    alcohol++;
    normal = 0;
    steam = 0;
    smoke = 0;
    if(alcohol == 5000){
    Serial.println("Alchohol 0_0");
    tone(buzz,1000,5000);
    Serial.println(an);
    alcohol = 0;
    }
    delay(1);
    //an = analogRead(ana);
  }
}


/*
 * Results
 * Noraml Air under 200
 * Smoke From 350 to 550
 * Alcohol From 700 to 900
 * Steam From 200 to 350
 */
