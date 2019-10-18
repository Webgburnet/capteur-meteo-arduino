#define pinILS 2
#define pi 3.14159265359
#define RayonDesBras    0.091 // en mètre de l'anénomètre

unsigned long millis_old = 0;
float delta_temps = 0;
float vitesseVentms = 0;
float vitesseVentkmh = 0;
float NombreTourSec = 0;
float NombreTour = 0;
float FEtalonage = 1;
float NombreDAimant = 0;
/* NB : La fonction d'étalonnage traduit les propriétés aérodynamiques de
l'anémomètre et les frottements qui altèrent le mouvement de rotation de l'anémomètre.
Elle dépend des dimensions et matériaux de l'anémomètre et de sa vitesse de rotation.
Seuls des essais en soufflerie à différents régimes de vent permettent de la déterminer précisément. */
bool etat_ILS=false;
bool etat=0;
 
void setup()
{
  pinMode(pinILS, INPUT);
  Serial.begin(9600);
}

 
void loop()
{
     etat_ILS = digitalRead(pinILS);
     
    if(etat_ILS==HIGH && etat==1)
    {
//      Serial.println(etat_ILS);
        NombreDAimant=NombreDAimant+1;
//        Serial.println(NombreDAimant);
        etat=0;
    }
    if(etat_ILS==LOW)
    {
      etat=1;
    }
    
    delta_temps = (millis() - millis_old)/1000;
    if(delta_temps == 1)
    {
      //Periode de temps
      Serial.print("La periode de temps  du vent est de ");
      Serial.print(delta_temps);
      Serial.println(" s.");
      
      //Nombre d'Aimant
      Serial.print("Le nombre d'aimant detecte est de ");
      Serial.print(NombreDAimant);
      Serial.println(" aimants.");

      //Nombre de tours
      NombreTour=NombreDAimant/3;
      //affichage du nombre de tours
      Serial.print("Le nombre de tours  est de ");
      Serial.print(NombreTour);
      Serial.println(" tours/s.");
      
      //convertion periode -> fréquense
      NombreTourSec = (NombreTour / delta_temps);
      //affichage du nombre de tours/s
      Serial.print("Le nombre de tours en 1 sec est de ");
      Serial.print(NombreTourSec);
      Serial.println(" tours/s.");
      
      //vitesse du vent
      vitesseVentms = 2*pi*RayonDesBras*NombreTourSec*FEtalonage;
      vitesseVentkmh=vitesseVentms*3600/1000;
      //affichage de la vitesse
      Serial.print("La vitesse du vent est de ");
      Serial.print(vitesseVentms);
      Serial.print(" m/s soit ");
      Serial.print(vitesseVentkmh);
      Serial.println(" km/h.");
      
      NombreDAimant=0;
      millis_old = millis(); // remise à 0 du compteur pour capturé la différence de temps au prochain tour
      
    }
    

    
    

}
