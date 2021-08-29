#ifndef __TB_DELAY_H__
#define __TB_DELAY_H__

#include "z_type.h"

#define mdelay(x) tb_delay_ms(x)

void tb_delay_init(void);
void tb_delay(u16 t);
void tb_delay_ns(u16 t);
void tb_delay_us(u16 t);
void tb_delay_ms(u16 t);




#endif

