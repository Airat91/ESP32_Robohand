/*
 * File:        main.h
 * Authors:     Girfanov.Ayrat@yandex.ru
 * Description: System debug functions and control
 * Revision history: 0.1
 */

#ifndef MAIN_H
#define MAIN_H
/*add includes below */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "project_config.h"
#include "pin_map.h"
#include "led.h"
/*add includes before */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @defgroup main
 * @brief Main system functions
 */

//--------Defines--------

//--------Macro--------

//--------Typedefs-------

//-------External variables------

//-------Function prototypes----------

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // MAIN_H