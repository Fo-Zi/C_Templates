/* This state machine implementation is based in the use of a table of function pointers. 	
 * Which is populated by a corresponding function for each possible state
 * The main advantage of this pattern is that in the main we only have a function with
 * arguments corresponding to the current state and the las event that ocurred. This way we can
 * even have multiple FSM and in the main we would need to only add its corresponding handle
 * function										
 * 
 * NOTES 										
 * 	- Both states and events have their corresponding enum type
 *  	- state_handler refers to a function that process some event, for a certain current
 *  	state.											
 *	- The handlers are just defined and not implemented. Each one of them needs to 
 *	implement conditionals and return the desired state.
 *	- The function "update_event" is just a dummy function to represent the fact that
 *	some piece of code needs to set the corresponding last_event in order to be able
 *	to run handle_State.
 *
*/


#define NUM_STATES 2
#define NUM_EVENTS 2

typedef enum State{ 
	STATE_1, 
	STATE_2, 
} State;

typedef enum {
	EVENT1,
	EVENT2,
} Event;

typedef State state_handler(Event last_event);

State state_1_handler (Event last_event);
State state_2_handler (Event last_event);

state_handler* const state_handlers_table [NUM_STATES] = {
	state_1_handler,
	state_2_handler,
};

State handle_state (State current_state , Event last_event){
	return state_handlers_table [ current_state  ](last_event);
}

void main (){
	State current_state = STATE_1;
	while(1){
		last_event = update_event();
		current_state = handle_state(current_state,last_event);
		
		/*OTHER FUNCTIONALITIES*/

	}
}

