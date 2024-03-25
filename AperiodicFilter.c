/*
 * AperiodicFilter.c
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

#include "AperiodicFilter.h"

//struct AFilter_structure AFilter; //Обьявляем структуру данных фильтра

/**
 ******************************************************************************
 *  @breif AperiodicFilterInit
 *  @param T_filter - Постоянная времени фильтра (сек).
 *  Чем больше постоянная времени фильтра, тем дольше длится переходный процесс.
 *  @param T_dt - Шаг дескритизации по времени (сек)
    @param *p - структура фильтра, который инициализируем
 ******************************************************************************
 */
void AperiodicFilterInit(float T_filter, float T_dt, struct AFilter_structure *p){
	p->T_filter = T_filter;
	p->T_dt = T_dt;
	p->outData = 0;
}


/**
 ******************************************************************************
 *  @breif AperiodicFilter
 *  @param *inputData - Вход фильтра
 *  @param *p - структура фильтра, где
 *  T_filter - Постоянная времени фильтра (сек).
 *  Чем больше постоянная времени фильтра, тем дольше длится переходный процесс.
 *  T_dt - Шаг дескритизации по времени (сек)
 *  outData - Выход фильтра
 *  @preturn OutData
 ******************************************************************************
 */
float AperiodicFilter(float *inputData, struct AFilter_structure *p) {
	float Temp_data; //Входная переменная интегратора
	if (p->T_filter <= 0.0f) {
		p->outData = *inputData;
	} else {
		Temp_data = (*inputData - p->outData) / p->T_filter;
		p->outData = p->outData + Temp_data * p->T_dt;
	}
	return p->outData;
}



