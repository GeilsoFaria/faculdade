# define ledR 2
# define ledG 3
# define ledB 4
# define botao 7
# define maximo 3

int btnclicado= 0;
int btnliberado= 0;
int ciclo= 0;

void vermelho ()
{
  digitalWrite (ledR, HIGH);
  digitalWrite (ledG, LOW);
  digitalWrite (ledB, LOW);
}
void verde ()
{
  digitalWrite (ledR, LOW);
  digitalWrite (ledG, HIGH);
  digitalWrite (ledB, LOW);
}
void azul ()
{
  digitalWrite (ledR, LOW);
  digitalWrite (ledG, LOW);
  digitalWrite (ledB, HIGH);
}
void trocaled()
{
  if(ciclo==0)
  {
    vermelho();
  }else if(ciclo==1)
  {
    verde();
  }else if(ciclo==2)
  {
    azul();
  }
  ciclo++;
  if (ciclo > maximo -1)
  {
    ciclo=0; 
  }
}
void verbtn ()
{
  if(digitalRead(botao)== HIGH)
  {
    btnclicado =1;
    btnliberado = 0;
  }else
  {
    btnliberado= 1;
  }
  if((btnclicado ==1)and (btnliberado ==1))
  {
    btnclicado =0;
    btnliberado =0;
    trocaled();
  }
}


void setup() 
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(botao, INPUT);

}

void loop() 
{
  verbtn ();
   
}
