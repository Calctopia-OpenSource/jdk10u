#ifndef OBLIV_OH
#define OBLIV_OH

typedef unsigned char obool;
#include<obliv_bits.h>

#ifdef __cplusplus
extern "C" {
#endif 
	// Runtime type info: these functions are no longer used anywhere. Remove?
	// All the protoType fields and DYN_FUN macros will also be unnecessary.
	obool ocInDebugProto(void);
	obool ocInNpProto(void);
	void ocNpSetBroadcast1(obool v);
	obool ocNpGetBroadcast1(void);

	void setupOblivBool(OblivInputs *spec , __obliv_c__bool *dest , obool v ) ;
	void setupOblivChar(OblivInputs *spec , __obliv_c__char *dest , char v ) ;
	void setupOblivInt(OblivInputs *spec , __obliv_c__int *dest , int v ) ;
	void setupOblivShort(OblivInputs *spec , __obliv_c__short *dest , short v ) ;
	void setupOblivLong(OblivInputs *spec , __obliv_c__long *dest , long v ) ;
	void setupOblivLLong(OblivInputs *spec , __obliv_c__lLong *dest , long long v ) ;

	void feedOblivInputs(OblivInputs *spec , size_t count , int party );

	__obliv_c__bool feedOblivBool(obool v , int party ) ;
	__obliv_c__char feedOblivChar(char v , int party ) ;
	__obliv_c__short feedOblivShort(short v , int party ) ;
	__obliv_c__int feedOblivInt(int v , int party ) ;
	__obliv_c__long feedOblivLong(long v , int party ) ;
	__obliv_c__lLong feedOblivLLong(long long v , int party ) ;
	
	void feedOblivBoolArray(__obliv_c__bool *dest , obool const *src , size_t n , int party ) ;
	void feedOblivCharArray(__obliv_c__char *dest , char const *src , size_t n , int party ) ;
	void feedOblivShortArray(__obliv_c__short *dest , short const *src , size_t n , int party ) ;
	void feedOblivIntArray(__obliv_c__int *dest , int const *src , size_t n , int party ) ;
	void feedOblivLongArray(__obliv_c__long *dest , long const *src , size_t n , int party ) ;
	void feedOblivLLongArray(__obliv_c__lLong *dest , long long const *src , size_t n , int party ) ;
	
	// Return value true means 'dest' was actually written to.
	//   Write may not occur if I am not the intended party, or this is
	//   a multithreaded protocol where only one thread writes
	obool revealOblivBool(obool *dest , __obliv_c__bool src , int party ) ;
	obool revealOblivChar(char *dest , __obliv_c__char src , int party ) ;
	obool revealOblivInt(int *dest , __obliv_c__int src , int party ) ;
	obool revealOblivShort(short *dest , __obliv_c__short src , int party ) ;
	obool revealOblivLong(long *dest , __obliv_c__long src , int party ) ;
	obool revealOblivLLong(long long *dest , __obliv_c__lLong src , int party ) ;
	
	obool  ocBroadcastBool(obool v , int source ) ;
	char ocBroadcastChar(char v , int source ) ;
	int ocBroadcastInt(int v , int source ) ;
	short ocBroadcastShort(short v , int source ) ;
	long ocBroadcastLong(long v , int source ) ;
	long long ocBroadcastLLong(long long v , int source ) ;
	
	unsigned int yaoGateCount(void) ;

void obliv_float_neg_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);
void obliv_float_add_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);
void obliv_float_sub_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);
void obliv_float_mult_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);
void obliv_float_div_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);
void obliv_float_eq_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);
void obliv_float_le_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);
void obliv_float_lt_circuit(OblivBit* dest, const OblivBit* op1, const OblivBit* op2);

//from jdkmethodsoc.oc
__obliv_c__lLong float64_add(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a,__obliv_c__lLong b);
__obliv_c__lLong float64_sub(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a,__obliv_c__lLong b);
__obliv_c__lLong float64_mul(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a,__obliv_c__lLong b);
__obliv_c__lLong float64_div(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong x,__obliv_c__lLong y);
__obliv_c__lLong float64_rem(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a,__obliv_c__lLong b);
__obliv_c__int float32_rem(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a,__obliv_c__int b);
__obliv_c__lLong float64_round_to_int(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__lLong float64_fmodf(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong x,__obliv_c__lLong y);

__obliv_c__int intLeftShift(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__lLong longLeftShift(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a, __obliv_c__lLong b);
__obliv_c__int intRightShift(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int intURightShift(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__lLong longRightShift(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a, __obliv_c__lLong b);
__obliv_c__lLong longURightShift(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a, __obliv_c__lLong b);
__obliv_c__int float32_neg(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__lLong float64_neg(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__lLong long2Double(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__int long2Float(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__int long2Int(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__int double2Float(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__lLong float2Double(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__lLong int2Double(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__int int2Float(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__lLong int2Long(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__char int2Char(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__short int2Short(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__char int2Byte(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__int longCompare(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a, __obliv_c__lLong b);
__obliv_c__int floatCompare(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int doubleCompare(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a, __obliv_c__lLong b);

__obliv_c__int float32_to_int(__obliv_c__bool const *__obliv_c__en,  __obliv_c__int a);
__obliv_c__lLong float32_to_int64(__obliv_c__bool const *__obliv_c__en,  __obliv_c__int a);
__obliv_c__lLong float32_to_int64_round_to_zero(__obliv_c__bool const *__obliv_c__en,  __obliv_c__int a);
__obliv_c__int float64_to_oint32(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__lLong float64_to_oint64(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);
__obliv_c__lLong float64_to_oint64_round_to_zero(__obliv_c__bool const *__obliv_c__en, __obliv_c__lLong a);

__obliv_c__int lessThan(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int lessThanZero(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__int greaterThan(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int greaterThanZero(__obliv_c__bool const *__obliv_c__en,  __obliv_c__int a);
__obliv_c__int lessEqual(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int lessEqualZero(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__int greaterEqual(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int greaterEqualZero(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__int equal(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int equalZero(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__int notEqual(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a, __obliv_c__int b);
__obliv_c__int notEqualZero(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);
__obliv_c__int flip1and0(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);

__obliv_c__bool convertIntToBool(__obliv_c__bool const *__obliv_c__en, __obliv_c__int a);

#ifdef __cplusplus
}
#endif

#endif
