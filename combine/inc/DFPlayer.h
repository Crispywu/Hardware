#ifndef _DFPLAYER_H_
#define _DFPLAYER_H_

#include "hx_drv_uart.h"
//#include "hx_drv_spi_s.h"
#include "board_config.h" //for board_delay_ms();

#include "DFPlayer.h"
#include <stdlib.h>

#include "hx_drv_uart.h"

#include "SC16IS750_Bluepacket.h"

//#include "hx_drv_spi_s.h"
#include "board_config.h" //for board_delay_ms();

struct __dfplayer {
  void (*play)();
  void (*playNum)(uint16_t song_num);
  void (*playNext)();
  void (*playPrev)();
  void (*pause)();
  void (*set_vol)(uint8_t volume);
  void (*sendCmd)(uint8_t, uint8_t, uint8_t);
  bool (*isBusy)();
};
typedef struct __dfplayer dfplayer;

void execute_cmd(uint8_t, uint8_t, uint8_t);
void pause();
void play();
void playNext();
void playPrev();
void set_vol(uint8_t vol);
void playNum(uint16_t song_num);
bool playerBusy();
dfplayer Init_DFPlayer();
#endif