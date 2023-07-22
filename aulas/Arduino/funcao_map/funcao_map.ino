int vetor []={2,3,4,5,6,7};
#define pot A5
int val;



void acender (int x)
{ int i; 
  for(i=0; i<x;i++)
  {
    digitalWrite(vetor[i], HIGH) ;
  }
   for(i=x; i<6;i++)
  {
    digitalWrite(vetor[i], LOW);  
  }
}


void setup() 
{ int i;
  for(i=0; i<6;i++)
  {
    pinMode(vetor[i], OUTPUT);
  }
 pinMode(pot, INPUT);


}

void loop() 
{
  val= analogRead(pot);
  acender( map(val,0,1023,0,6));
   

}
