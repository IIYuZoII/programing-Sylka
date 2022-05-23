/**
 * @file list.h
 * @brief Файл з описом функцій для механізму вводу/виведення
 *
 * @author Sylka Michael
 * @date 23-may-2022
 * @version 1.0
 */

#ifndef list

#include "entity.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Функція для отримання від користувача інформації для заповнення об'єктів
 * 
 * @param array масив структур
 * @param k позиція об'єкта з якого починати заповнення
 * @param count загальна кількість об'єктів
 */
void printer_scanner(struct mail *array, int k, int count);

/**
 * @brief Функція виведення усіх єлементів
 * 
 * @param array масив структур
 * @param count загальна кількість об'єктів
 */
void printer (struct mail *array, int count);

#define list
#endif