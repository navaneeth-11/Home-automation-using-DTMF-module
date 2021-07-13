const int Q1 = 8;  // Defining Digital Input Pins from DTMF Module
const int Q2 = 9;
const int Q3 = 10;
const int Q4 = 11;

const int D1 = 4;  // Defining Digital output Pins for Relay Board
const int D2 = 5;
const int D3 = 6;
const int D4 = 7;


int SoQ1 = 0;     // Defining variable to store the status(HIGH/LOW) of above inputs.
int SoQ2 = 0;
int SoQ3 = 0;
int SoQ4 = 0;
int oldCon = 0;  //  Variable to know what was the last button pressed.  

void setup(){ 
   pinMode(Q1, INPUT);  // Defining pins as input.
   pinMode(Q2, INPUT);
   
   pinMode(Q3, INPUT);
   pinMode(Q4, INPUT);
   
   pinMode(D1, OUTPUT);  // Defining pins as output.
   pinMode(D2, OUTPUT);
   pinMode(D3, OUTPUT);
   pinMode(D4, OUTPUT);
 
}

void loop(){
  SoQ1 = digitalRead(Q1);  // Reading status of Input Pins. It can be LOW or HIGH
  SoQ2 = digitalRead(Q2);
  SoQ3 = digitalRead(Q3);
  SoQ4 = digitalRead(Q4);
  
   if(SoQ4==LOW && SoQ3==LOW && SoQ2==LOW && SoQ1==HIGH )  // Condition for Button 1. It is equal to Binary - 0001 
    {
      if (oldCon!=1){
        digitalWrite(D1, LOW);
       }
      oldCon=1;  
    }
  
  else if(SoQ4==LOW && SoQ3==LOW && SoQ2==HIGH && SoQ1==LOW )  // Condition for Button 2. It is equal to Binary - 0010 
    {
      if (oldCon!=2){
        digitalWrite(D2, LOW);
       }
      oldCon=2;  
    }
  else if(SoQ4==LOW && SoQ3==LOW && SoQ2==HIGH && SoQ1==HIGH )  // Condition for Button 3. It is equal to Binary - 0011 
        {
      if (oldCon!=3){
         digitalWrite(D3, LOW);
       }
      oldCon=3;  
    }
 
  else if(SoQ4==LOW && SoQ3==HIGH && SoQ2==LOW && SoQ1==LOW )   // Condition for Button 4. It is equal to Binary - 0100 
    {
      if (oldCon!=4){
           digitalWrite(D4, LOW);   
       }
      oldCon=4;  
    } 
  else if(SoQ4==LOW && SoQ3==HIGH && SoQ2==LOW && SoQ1==HIGH )   // Condition for Button 5. It is equal to Binary - 0101 
    {
      if (oldCon!=5){
           digitalWrite(D1, HIGH);
       }
      oldCon=5;  
    }    

  else if(SoQ4==LOW && SoQ3==HIGH && SoQ2==HIGH && SoQ1==LOW )   // Condition for Button 6. It is equal to Binary - 0110 
    {
      if (oldCon!=6){
           digitalWrite(D2, HIGH);
       }
      oldCon=6;  
    }
    
  else if(SoQ4==LOW && SoQ3==HIGH && SoQ2==HIGH && SoQ1==HIGH )   // Condition for Button 7. It is equal to Binary - 0111 
    {
      if (oldCon!=7){
       digitalWrite(D3, HIGH);
       }
      oldCon=7;  
    } 

  else if(SoQ4==HIGH && SoQ3==LOW && SoQ2==LOW && SoQ1==LOW )   // Condition for Button 8. It is equal to Binary - 1000 
    {
      if (oldCon!=8){
       digitalWrite(D4, HIGH);
       }
      oldCon=8;  
    } 
  else if(SoQ4==HIGH && SoQ3==LOW && SoQ2==LOW && SoQ1==HIGH )   // Condition for Button 9. It is equal to Binary - 1001 
    {
      if (oldCon!=9){
         digitalWrite(D1, LOW);
         digitalWrite(D2, LOW);
         digitalWrite(D3, LOW);
         digitalWrite(D4, LOW);  
       }
      oldCon=9;  
    }
  
    else if(SoQ4==HIGH && SoQ3==HIGH && SoQ2==LOW && SoQ1==LOW )   // Condition for Button #. It is equal to Binary - 110 
    {
      if (oldCon!=11){
         digitalWrite(D1, HIGH);
         digitalWrite(D2, HIGH);
         digitalWrite(D3, HIGH);
         digitalWrite(D4, HIGH);  
       }
      oldCon=11;  
    }
     
   
delay(50);   // Debounce Delay.
  
}
