/*****************************************************************************
 *   Copyright 2013 - 2013 Yichao Yu <yyc1992@gmail.com>                     *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU Lesser General Public License as          *
 *   published by the Free Software Foundation; either version 2.1 of the    *
 *   License, or (at your option) version 3, or any later version accepted   *
 *   by the membership of KDE e.V. (or its successor approved by the         *
 *   membership of KDE e.V.), which shall act as a proxy defined in          *
 *   Section 6 of version 3 of the license.                                  *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU       *
 *   Lesser General Public License for more details.                         *
 *                                                                           *
 *   You should have received a copy of the GNU Lesser General Public        *
 *   License along with this library. If not,                                *
 *   see <http://www.gnu.org/licenses/>.                                     *
 *****************************************************************************/

#ifndef _QTC_UTILS_TIMER_H_
#define _QTC_UTILS_TIMER_H_

#include "log.h"
#include <inttypes.h>

QTC_BEGIN_DECLS

#define PRTime PRIu64
uint64_t qtcGetTime();
uint64_t qtcGetElapse(uint64_t prev);
#define qtcGetElapse(prev...)                                   \
    QTC_SWITCH(prev, qtcGetElapse(prev), qtcGetElapse(0))
#define qtcPrintTime(time)                      \
    qtcInfo("Time: " PRTime "\n", time)
#define qtcPrintElapse(prev...)                 \
    qtcPrintTime(qtcGetElapse(prev))

QTC_END_DECLS

#endif
