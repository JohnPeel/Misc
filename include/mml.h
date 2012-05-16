#ifndef __mml_h_
#define __mml_h_

#define constructor(x) __attribute__((constructor(x)))
#define destructor(x) __attribute__((destructor(x)))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#include "types.h"
#include "version.h"
#include "os.h"
#include "mouse.h"
#include "keyboard.h"
#include "target.h"
#include "color.h"

#ifdef HUMAN
#include "human.h"
#endif

#endif
