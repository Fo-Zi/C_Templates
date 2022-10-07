/* In this template it's defined the typical structure of a classical		*/
/* state machine implementation in C, in which you define states and		*/
/* transitions using enums, and handle the functionality using conditionals	*/
/* inside of the main.								*/

/* ---------- States & transition enums	---------- */
typedef enum state{
	STATE_1,
	STATE_2,
}state;

typedef enum transition{
	FROM_STATE_1,
	FROM_STATE_2,
}transition;

/* ---------- Transition functions definitions ---------- */
state_1_func(int transition){
   
	if(transition == FROM_STATE_1) {
     	// Transition handling, setting new_state 
   	}
   	if(transition == FROM_STATE_2) {
    	// Transition handling, setting new_state 
   	}
   
	return new_state;
}

state_2_func(int transition){
   
	if(transition == FROM_STATE_1) {
     	// Transition handling, setting new_state 
   	}
   	if(transition == FROM_STATE_2) {
    	// Transition handling, setting new_state 
   	}
   
	return new_state;
}

/* ---------- Main infinite loop example ---------- */
void main(){
	
	// Typical infinite loop for any embedded device	
	while(1){
		switch(state){
		  case STATE_1:
		     state = state_1_func(transition);
		     break;
		  case STATE_2:
		     state = state_2_func(transition);
		     break;
		}
	}

}

