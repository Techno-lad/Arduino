POINTS TO NOTE 
green=2,amber=3,red=4,pedamber=5,pedgreen=6,pedred=7,pushbutton=8
*/

// variable Declaration
unsigned long time_counter,prev_counter=0;
int state,pushbutton=8,current_duration,cross;
unsigned long* prevptr=&prev_counter;
unsigned long* timeptr=&time_counter;
int* buttonptr=&pushbutton; 
int* durationptr=&current_duration;
int*crossptr=&cross;

void setup()  // purpose to set pins to either input or output and intializes state to 1.
{
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8,  INPUT);
   state=1;
}

void loop()
{
  *durationptr=*timeptr-*prevptr; //keeps track of how long a state has been active in milli seconds.
  *crossptr=digitalRead(*buttonptr); // assigns to cross the value from pushbutton.
  time_counter=millis(); //keeps track of the running time of the system.
  nextState();	// function for monitoring when and how long a state is active for.
  Let_There_Be_Light();//function for changing value of pedestrian and traffic lights in accordance with state changes.
}

void nextState()
{
  switch(state){
    case 1:
    if(*durationptr>=15000){  
      state=2; //if string is E state changes state to 2.
      *prevptr=*timeptr; // 
    }else{
      if(*crossptr==HIGH){   
        state=4;//if string is 1 then changes state to 4
      }
    }
    break;
    
    case 2:
    if(*durationptr>=5000){
      state=3;//if string is E state changes state to 3
      *prevptr=*timeptr;
    }else{
      if(*crossptr==HIGH){ 
        state=5;//if string is 1 then changes state to 5
      }
    }
    break;
    
    case 3:
    if(*durationptr>=10000){
      state=1;//if string is E then changes state to 1
      *prevptr=*timeptr;
    }else{
      if(*crossptr==HIGH){
        state=6; //if string is 1 then changes state to 6
      }
    }
    break;
    
    case 4:
    if(*durationptr>=7500){
      state=5;//if string is E then changes state to 5
      *prevptr=*timeptr;
    }
    break;
    
    case 5:
    if(*durationptr>=5000){ 
      state=6; //if string is E then changes state to 6
      *prevptr=*timeptr;
    }
    break;
    
    case 6:
    if(*durationptr>=2000){
      state=7;//if string is E then changes state to 7
      *prevptr=*timeptr;
    }  
    break; 
    
    case 7:
    if(*durationptr>=10000){
      state=1;//if string is E then changes state to 1
      *prevptr=*timeptr;
    }
  }
}

  void Let_There_Be_Light(){
    switch(state){
      case 1:
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
    break;
      
      case 2:
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
    break;
      
      case 3:
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
    break;
      
      case 4:
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    break;
      
      case 5:
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    break;
      
      case 6:
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    break;  
      
      case 7:
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
    break;  
    }
  }
  
