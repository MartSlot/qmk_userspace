#pragma once

#include "shared/keymap.h"

// clang-format off
#define SHARED_LAYOUT( \
    r0L, r01, r02, r03, r04, r05, r06, r07, r08, r09, r00, r0R,\
    r1L, r11, r12, r13, r14, r15, r16, r17, r18, r19, r10, r1R,\
    r2L, r21, r22, r23, r24, r25, r26, r27, r28, r29, r20, r2R,\
    r3L, r31, r32, r33, r34, r35, r36, r37, r38, r39, r30, r3R,\
                        tlG, tlF, trF, trG,\
         tlE, tlD, tlC, tlB, tlA, trA, trB, trC, trD, trE) \
    LAYOUT(\
        r0L,    r01,    r02,    r03,    r04,    r05,          __NOP__,__NOP__,          r06,    r07,    r08,    r09,    r00,    r0R,  \
        r1L,    r11,    r12,    r13,    r14,    r15,          __NOP__,__NOP__,          r16,    r17,    r18,    r19,    r10,    r1R,  \
        r2L,    r21,    r22,    r23,    r24,    r25,          __NOP__,__NOP__,          r26,    r27,    r28,    r29,    r20,    r2R,  \
        r3L,    r31,    r32,    r33,    r34,    r35,    tlG,    tlF,    trF,    trG,    r36,    r37,    r38,    r39,    r30,    r3R,  \
                                tlE,    tlD,    tlB,    tlA,    tlC,    trC,    trA,    trB,    trD,    trE      \
    )
// clang-format on
