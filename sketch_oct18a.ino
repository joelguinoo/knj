#define M_ENA  10
#define M_IN1  9
#define M_IN2  8
#define M_IN3  7
#define M_IN4  6
#define M_ENB  5       

void setup() 
{
  pinMode(M_ENA, OUTPUT);
  pinMode(M_IN1, OUTPUT);
  pinMode(M_IN2, OUTPUT);
  pinMode(M_IN3, OUTPUT);
  pinMode(M_IN4, OUTPUT);
  pinMode(M_ENB, OUTPUT);
}

void loop() {
  //gaucheAvance();
  //gaucheArriere();
  //droiteAvance();
  //droiteArriere();
  avanceTous();
  arriereTous();
  delay(1000);
}
void gaucheAvance() 
{
  digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN4, LOW);
  digitalWrite(M_ENB, HIGH); 
  delay(2000);  
  digitalWrite(M_ENB, LOW); 
}
void gaucheArriere()
{
  digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN4, HIGH);
  digitalWrite(M_ENB, HIGH); 
  delay(2000);  
  digitalWrite(M_ENB, LOW);
}
void droiteAvance()
{
  digitalWrite(M_IN1, HIGH);    
  digitalWrite(M_IN2, LOW);
  digitalWrite(M_ENA, HIGH); 
  delay(2000); 
  digitalWrite(M_ENA, LOW);
}
void droiteArriere()
{
  digitalWrite(M_IN1, LOW);    
  digitalWrite(M_IN2, HIGH);
  digitalWrite(M_ENA, HIGH); 
  delay(2000); 
  digitalWrite(M_ENA, LOW);
}
void avanceTous()
{
  //droiteAvance
  digitalWrite(M_IN3, HIGH);
  digitalWrite(M_IN4, LOW);
  //gaucheAvance
  digitalWrite(M_IN1, HIGH);    
  digitalWrite(M_IN2, LOW);
  //on
  digitalWrite(M_ENA, HIGH);
  digitalWrite(M_ENB, HIGH); 
  delay(2000);
  //off 
  digitalWrite(M_ENA, LOW);
  digitalWrite(M_ENB, LOW);
}
void arriereTous()
{
  //droiteArriere
  digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN4, HIGH);
  //gaucheArriere
  digitalWrite(M_IN1, LOW);    
  digitalWrite(M_IN2, HIGH);
  //on
  digitalWrite(M_ENA, HIGH);
  digitalWrite(M_ENB, HIGH); 
  delay(2000);
  //off 
  digitalWrite(M_ENA, LOW);
  digitalWrite(M_ENB, LOW);
}
