#define pin_girouette A1
void setup() 
{
  Serial.begin(9600);
  
}
void loop() 
{
  int pos_girouette = analogRead(pin_girouette);
  Serial.println(pos_girouette);

  if(pos_girouette > 780 && pos_girouette<790)
  {
    Serial.println("Vent direction Nord");
  }
  if(pos_girouette > 280 && pos_girouette<290)
  {
    Serial.println("Vent direction Sud");
  }
  if(pos_girouette > 90 && pos_girouette<100)
  {
    Serial.println("Vent direction Est");
  }
  
  if(pos_girouette > 940 && pos_girouette<950)
  {
    Serial.println("Vent direction Ouest");
  }
  if(pos_girouette > 460 && pos_girouette<470)
  {
    Serial.println("Vent direction Nord-Est");
  }
  if(pos_girouette > 880 && pos_girouette<890)
  {
    Serial.println("Vent direction Nord-Ouest");
  }
  if(pos_girouette > 180 && pos_girouette<190)
  {
    Serial.println("Vent direction Sud-Est");
  }
  if(pos_girouette > 620 && pos_girouette<640)
  {
    Serial.println("Vent direction Sud-Ouest");
  }
  
  if(pos_girouette > 80 && pos_girouette<90)
  {
    Serial.println("Vent direction Est-Nord-Est");
  }
  if(pos_girouette > 120 && pos_girouette<130)
  {
    Serial.println("Vent direction Sud-Sud-Est");
  }
  if(pos_girouette > 590 && pos_girouette<610)
  {
    Serial.println("Vent direction Ouest-Sud-Ouest");
  }
  if(pos_girouette > 700 && pos_girouette<710)
  {
    Serial.println("Vent direction Nord-Nord-Ouest");
  }

  if(pos_girouette > 400 && pos_girouette<410)
  {
    Serial.println("Vent direction Nord-Nord-Est");
  }
  if(pos_girouette > 60 && pos_girouette<70)
  {
    Serial.println("Vent direction Est-Sud-Est");
  }
  if(pos_girouette > 240 && pos_girouette<250)
  {
    Serial.println("Vent direction Sud-Sud-Ouest");
  }
  if(pos_girouette > 1000 && pos_girouette<1024)
  {
    Serial.println("Vent direction Ouest-Nord-Ouest");
  }
  
}
