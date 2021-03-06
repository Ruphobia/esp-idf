// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* Notes:
 * 1. Put all task priority and stack size definition in this file
 * 2. If the task priority is less than 10, use ESP_TASK_PRIO_MIN + X style,
 *    otherwise use ESP_TASK_PRIO_MIN - X style
 * 3. If this is a daemon task, the macro prifix is ESP_TASKD_, otherwise
 *    it's ESP_TASK_
 * 4. If the configMAX_PRIORITIES is modified, please make all prority are 
 *    greater than 0
 * 5. Make sure esp_task.h is consistent between wifi lib and idf
 */

#ifndef _ESP_TASK_H_
#define _ESP_TASK_H_

#include "sdkconfig.h"

#define ESP_TASK_PRIO_MAX (configMAX_PRIORITIES)
#define ESP_TASK_PRIO_MIN (0)

/* Wifi library task */
#define ESP_TASKD_WATCHDOG_PRIO       (ESP_TASK_PRIO_MAX - 1)
#define ESP_TASKD_WATCHDOG_STACK      2048
#define ESP_TASK_WPA2_PRIO            (ESP_TASK_PRIO_MAX - 1)
#define ESP_TASK_WPA2_STACK           2048
#define ESP_TASKD_WIFI_PRIO           (ESP_TASK_PRIO_MAX - 2)
#define ESP_TASKD_WIFI_STACK          8196
#define ESP_TASKD_WIFI_TIMER_PRIO     (ESP_TASK_PRIO_MAX - 3)
#define ESP_TASKD_WIFI_TIMER_STACK    2048
#define ESP_TASK_WPS_PRIO             (ESP_TASK_PRIO_MIN + 2)
#define ESP_TASK_WPS_STACK            2048

/* idf task */
#define ESP_TASKD_EVENT_PRIO          (ESP_TASK_PRIO_MAX - 5)
#define ESP_TASKD_EVENT_STACK         CONFIG_SYSTEM_EVENT_TASK_STACK_SIZE
#define ESP_TASK_WIFI_STARTUP_PRIO    (ESP_TASK_PRIO_MAX - 7)
#define ESP_TASK_WIFI_STARTUP_STACK   4096
#define ESP_TASK_TCPIP_PRIO           (ESP_TASK_PRIO_MAX - 7)
#define ESP_TASK_TCPIP_STACK          2048

#endif
