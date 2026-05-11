/*
 * File:        project_config.h
 * Authors:     Girfanov.Ayrat@yandex.ru
 * Description: Project configuration main file
 * Revision history: 0.1
 */

#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H
/*add includes below */

/*add includes before */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//--------Defines--------

// Board type definitions
#define ESP32_DEVKITC   0x032C  // ESP32 DevKitC
#define ESP32_DEVKITV1  0x032D  // ESP32 DevKit v1

#define BOARD_TYPE      ESP32_DEVKITV1      // Select the board type used in the project

//--------Macro--------

//--------Typedefs-------

//-------External variables------

//-------Function prototypes----------

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // PROJECT_CONFIG_H