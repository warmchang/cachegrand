/**
 * Copyright (C) 2020-2021 Daniele Salvatore Albano
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 **/

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <arpa/inet.h>

#include "misc.h"
#include "exttypes.h"
#include "config.h"
#include "spinlock.h"
#include "network/protocol/network_protocol.h"
#include "network/io/network_io_common.h"
#include "network/channel/network_channel.h"
#include "data_structures/hashtable/mcmp/hashtable.h"
#include "worker/worker_stats.h"

#include "worker_context.h"

thread_local worker_context_t *thread_local_worker_context = NULL;

worker_context_t* worker_context_get() {
    return thread_local_worker_context;
}

void worker_context_set(
        worker_context_t *worker_context) {
    thread_local_worker_context = worker_context;
}

void worker_context_reset() {
    thread_local_worker_context = NULL;
}
