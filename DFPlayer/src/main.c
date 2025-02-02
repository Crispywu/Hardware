#include <stdio.h>
#include <stdlib.h>
#include "embARC.h"
#include "embARC_debug.h"
#include "board_config.h"
#include "arc_timer.h"
#include "hx_drv_spi_s.h"
#include "spi_slave_protocol.h"
#include "hardware_config.h"

#include "hx_drv_iic_m.h"
#include "hx_drv_iomux.h"
#include "SC16IS750_Bluepacket.h"

#include "DFPlayer.h"
#define ARDUINO

// This example code shows how to Setup a DFPlayer
// And play mp3 files.
// Note that sometimes DFP sometimes have a collision with printf funct
// If the obj is created dynamically (via malloc)

int main(void) {

  HX_GPIOSetup();
  IRQSetup();
  UartInit(SC16IS750_PROTOCOL_SPI);
  GPIOSetPinMode(SC16IS750_PROTOCOL_SPI, CH_A, GPIO1, INPUT);
  GPIOSetPinMode(SC16IS750_PROTOCOL_SPI, CH_A, GPIO5, OUTPUT);
  GPIOSetPinMode(SC16IS750_PROTOCOL_SPI, CH_A, GPIO6, OUTPUT);
  GPIOSetPinState(SC16IS750_PROTOCOL_SPI, CH_A, GPIO5, HIGH);
  GPIOSetPinState(SC16IS750_PROTOCOL_SPI, CH_A, GPIO6, LOW);

  board_delay_ms(1000); // Wait for setting SPI
  printf("Setting DFPlayer...\n");
  dfplayer Player = Init_DFPlayer();
  Player.set_vol(5);
  board_delay_ms(500);
  if (!playerBusy())
    Player.play();
  board_delay_ms(500);
  int i = 1;
  while (1) {
    printf("%d PP state %d\n", i, playerBusy()); // PP: Player Port
    board_delay_ms(1000);
    i++;
    if (i % 25 == 0)
      if (i & 1)
        Player.playNext();
      else
        Player.playPrev();
  }

  return 0;
}
