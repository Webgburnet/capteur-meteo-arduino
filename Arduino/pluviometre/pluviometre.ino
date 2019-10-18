//godet de 0.2794 mm3

#define pin_pluviometre 4

boolean etat_pluie = 0;
unsigned long compte_volume=0;
double volume_pluie=0;
const float volume_godet=0.2794;

void setup() 
{
  Serial.begin(9600);
  pinMode(pin_pluviometre, INPUT);
}
// Boucle principale:
void loop() 
{
  int BP = digitalRead(pin_pluviometre); // Lecture du capteur
  if (BP == LOW && etat_pluie==0) 
  {
    Serial.println("En cours de remplissage des godets");
    etat_pluie=1;
    
  }
  if(BP == HIGH && etat_pluie==1) 
  {
    Serial.println("Vidange des godets");
    etat_pluie=0;
    compte_volume=compte_volume+1;
    
  }
  volume_pluie=volume_godet*compte_volume;
  Serial.print("le volume de pluie est de ");
  Serial.print(volume_pluie,4);
  Serial.println(" mm3.");
  
} 
