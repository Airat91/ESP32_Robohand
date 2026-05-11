/*
 * File:        pin_map.h
 * Authors:     Girfanov.Ayrat@yandex.ru
 * Description: Description of board pins
 * Revision history: 0.1
 */

#ifndef PIN_MAP_H
#define PIN_MAP_H
/*add includes below */
#include "project_config.h"
#include "driver/gpio.h"
/*add includes below */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*add includes before */

//--------Defines--------

#if( BOARD_TYPE == ESP32_DEVKITC)
// ESP32 DevKitC pin definitions
#define PIN_LED     2   // On-board LED
#define PIN_BUTTON  0   // On-board button
#elif( BOARD_TYPE == ESP32_DEVKITV1)
// ESP32 DevKit v1 pin definitions
#define PIN_BTN_EN  0   // On-board button EN
#define PIN_LED     2   // On-board LED
// J1 pins on-board named
#define PIN_D13     13  // On-board D13 pin
#define PIN_D12     12  // On-board D12 pin
#define PIN_D14     14  // On-board D14 pin
#define PIN_D27     27  // On-board D27 pin
#define PIN_D26     26  // On-board D26 pin
#define PIN_D25     25  // On-board D25 pin
#define PIN_D33     33  // On-board D33 pin
#define PIN_D32     32  // On-board D32 pin
#define PIN_D35     35  // On-board D35 pin
#define PIN_D34     34  // On-board D34 pin
#define PIN_VN      39  // On-board D39 pin
#define PIN_VP      36  // On-board D36 pin
// J2 pins on-board named
#define PIN_D15     15  // On-board D15 pin
#define PIN_D2      2   // On-board D2 pin
#define PIN_D4      4   // On-board D4 pin
#define PIN_RX2     16  // On-board RX2 pin
#define PIN_TX2     17  // On-board TX2 pin
#define PIN_D5      5   // On-board D5 pin
#define PIN_D18     18  // On-board D18 pin
#define PIN_D19     19  // On-board D19 pin
#define PIN_D21     21  // On-board D21 pin
#define PIN_RX0     3   // On-board RX0 pin
#define PIN_TX0     1   // On-board TX0 pin
#define PIN_D22     22  // On-board D22 pin
#define PIN_D23     23  // On-board D23 pin
#endif // BOARD_TYPE

//--------Macro--------

//--------Typedefs-------

//-------External variables------

//-------Function prototypes----------

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // PROJECT_CONFIG_H