
#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
#include"EXTI1_inter.h"
#include"EXTI1_Config.h"
#include"EXTI1_reg.h"
#define nul    0

volatile void ((*pf_)(void))= nul;
ErrorStatus EXTI1_enumInit(void)
{
	ErrorStatus error=ES_NOK;
 #if 	SENSE_MODE1  ==  LOW
        CLR_BIT(MCUCR,2);
        CLR_BIT(MCUCR,3);
 #elif 	SENSE_MODE1  ==  LOGIC_CHANGE
        SET_BIT(MCUCR,2);
        CLR_BIT(MCUCR,3);
 #elif 	SENSE_MODE1  ==  FALLING
        CLR_BIT(MCUCR,2);
        SET_BIT(MCUCR,3);
 #elif 	SENSE_MODE1  ==  RISING
        SET_BIT(MCUCR,2);
        SET_BIT(MCUCR,3);
// #else
  //   #error "Wrong sense mode"
#endif
 error=ES_OK;
 return error;
}
ErrorStatus EXTI1_enumEnable (void)
{
	ErrorStatus error=ES_NOK;
	SET_BIT(GICR,7);
	return error;
}
ErrorStatus EXTI1_enumDisable (void)
{
	ErrorStatus error=ES_NOK;
	CLR_BIT(GICR,7);
	return error;
}
void EXTI1_enumSetCallBack (void(*x)(void))
{
	pf_=x;
}

void __vector_2()__attribute__((signal,used));
void __vector_2()
{
	pf_();
}
