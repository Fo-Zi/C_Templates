/* This header contains some basic bitwise operations and function like-macros */
/* Note:*/
/* - For the "Sign_extend" macros, 'x' must be casted to the desired size. Example: I want to convert 'x' */
/*   that has 16 bits to 'y' of size 32, mantaining the sign (CA2):*/
/*   int16_t x = -10;*/
/*   int32_t y = (int32_t) (Sign_extend_16_32(x)); */

#ifndef BIT_MASKS_H
#define BIT_MASKS_H
    
//----------------Single bit manipulation----------------//	

    #define Set_bit(x,nbit) 		( x |=  ( 1 << nbit ) )
    
    #define Clear_bit(x,nbit) 		( x &= ~( 1 << nbit ) )
    
    #define Toggle_bit(x,nbit) 		( x ^=  ( 1 << nbit ) )
    
    #define Check_bit(x,nbit) 		( x &   ( 1 << nbit ) )
    
//----------------Bitfields & masks----------------//
    
    #define Set_all(x) 			( x = ~( x & 0 ) )

    #define Clear_all(x) 		( x = ( x & 0 ) )
    
    #define Sign_extend_8_to_16(x) 	( x = ((x & 0x80) ?  0xFF00 : 0 ) | (x & 0xFF) ) 

    #define Sign_extend_16_to_32(x) 	( x = ((x & 0x8000) ?  0xFFFF0000 : 0 ) | (x & 0xFFFF) ) 

    #define Sign_extend_32_to_64(x) 	( x = ((x & 0x80000000) ?  0xFFFFFFFF00000000 : 0 ) | (x & 0xFFFFFFFF) ) 

#endif
