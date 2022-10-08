/* In this template it's defined the typical structure of a classical		*/
/* state machine implementation in C, in which you define states and		*/
/* Events using enums, and handle the functionality using conditionals	*/
/* inside of the main.								*/

/* ---------- States & Event enums	---------- */
typedef enum State{
	STATE_1,
	STATE_2,
}State;

typedef enum Event{
	FROM_STATE_1,
	FROM_STATE_2,
}Event;

/* ---------- Event functions definitions ---------- */
State state_1_func(int Event){
   
	if(Event == FROM_STATE_1) {
     	// Event handling, setting new_state 
   	}
   	if(Event == FROM_STATE_2) {
    	// Event handling, setting new_state 
   	}
   
	return new_state;
}

State state_2_func(int Event){
   
	if(Event == FROM_STATE_1) {
     	// Event handling, setting new_state 
   	}
   	if(Event == FROM_STATE_2) {
    	// Event handling, setting new_state 
   	}
   
	return new_state;
}

/* ---------- Main infinite loop example ---------- */
void main(){
	
	// Typical infinite loop for any embedded device	
	while(1){
		switch(State){
		  case STATE_1:
		     State = state_1_func(Event);
		     break;
		  case STATE_2:
		     State = state_2_func(Event);
		     break;
		}
	}

}

