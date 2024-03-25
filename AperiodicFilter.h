/*
 * AperiodicFilter.h
 *
 *  Created on: 16 мар. 2024 г.
 *      Author: Oleg Volkov
 *
 * Библиотека выполняет функцию фильтра (апериодического звена)
 * Передаточная функция имеет вид:
 * W(p) = 1/(TF*p+1);
 * Почитать в википедии:
 * https://ru.wikipedia.org/wiki/%D0%90%D0%BF%D0%B5%D1%80%D0%B8%D0%BE%D0%B4%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%BE%D0%B5_%D0%B7%D0%B2%D0%B5%D0%BD%D0%BE
 *
 */

#ifndef INC_APERIODICFILTER_H_
#define INC_APERIODICFILTER_H_

//Апериодический фильтр первого порядка
#include "main.h"

struct AFilter_structure{
	float T_filter; //Постоянная времени фильтра (сек.)
	float T_dt; //Шаг дискретизации по времени (сек.)
	float outData; //Выходной сигнал с фильтра
};

void AperiodicFilterInit(float T_filter, float T_dt, struct AFilter_structure *p);
float AperiodicFilter(float *inputData, struct AFilter_structure *p);

#endif /* INC_APERIODICFILTER_H_ */
