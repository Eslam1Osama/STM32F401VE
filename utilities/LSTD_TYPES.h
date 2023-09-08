/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 01 / 09 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : LSTD_TYPES  		*************************/
/****************************************************************/

#ifndef LSTD_TYPES_H
#define LSTD_TYPES_H

//===============================================================
typedef signed 	            char    s8   ;
typedef unsigned       	    char    u8   ; 

typedef signed   short      int     s16  ;
typedef unsigned short      int     u16  ;
typedef unsigned long       int     s32  ;
typedef unsigned long       int     u32  ;
typedef unsigned long long  int     s64  ;
typedef unsigned long long  int     u64  ;

typedef 	           		float   f32  ;
typedef 	           		double  f64  ;
typedef          long  		double  f128 ;

#define LSTD_TYPES_OK 		1
#define LSTD_TYPES_NOK 		0

#define NULL 				((void*)0)

#define HIGH 				(1u)
#define LOW 				(0u)
//===============================================================

#endif