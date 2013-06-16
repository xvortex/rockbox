/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2011 by Amaury Pouly
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/
#include "audioin-imx233.h"

void imx233_audioin_preinit(void)
{
    /* Enable AUDIOIN block */
    imx233_reset_block(&HW_AUDIOIN_CTRL);
    /* Enable ADC */
    BF_SET(AUDIOIN_CTRL, CLKGATE);
    /* Set word-length to 16-bit */
    BF_SET(AUDIOIN_CTRL, WORD_LENGTH);
}

void imx233_audioin_postinit(void)
{
}

void imx233_audioin_close(void)
{
    /* TODO mute */
    /* Gate off ADC */
    BF_SET(AUDIOIN_ANACLKCTRL, CLKGATE);
    /* will also gate off the module */
    BF_CLR(AUDIOIN_CTRL, RUN);
}
