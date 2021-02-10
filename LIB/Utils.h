/*
 * Utils.h
 *
 * Created: 12/1/2020 11:18:45 AM
 *  Author: Sarah
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define  GET_BIT(reg,bit)          ((reg>>bit)&1)
#define  SET_BIT(reg,bit)          (reg=(reg|(1<<bit)))
#define  CLR_BIT(reg,bit)          (reg=(reg&(~(1<<bit))))
#define  TOG_BIT(reg,bit)          (reg=(reg^(1<<bit)))
#define  WRT_BIT(reg,bit,value)    (reg=SET_BIT(reg,bit)&(value<<bit))


#endif /* UTILS_H_ */