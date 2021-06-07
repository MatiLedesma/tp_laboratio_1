/*
 * sEmployee.h
 *
 *  Created on: 14 may. 2021
 *      Author: matia
 */

#ifndef SEMPLOYEE_H_
#define SEMPLOYEE_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} sEmployee;

#endif /* SEMPLOYEE_H_ */
