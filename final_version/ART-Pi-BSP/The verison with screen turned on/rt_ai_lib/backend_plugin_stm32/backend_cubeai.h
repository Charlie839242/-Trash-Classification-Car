/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-04-01     liqiwen      the first version
 */

#ifndef __BECKEND_CUBE_AI_H__
#define __BECKEND_CUBE_AI_H__
#include <rt_ai.h>
#ifdef RT_AI_USE_CUBE
#include <ai_platform.h>
struct cube_ai
{
    struct rt_ai parent;

    ai_handle handle;
    ai_network_report report;
    ai_network_params params;

    ai_bool     (*get_info)     (ai_handle network, ai_network_report *report);
    ai_error    (*get_error)    (ai_handle network);
    ai_error    (*create)       (ai_handle *network, const ai_buffer *network_config);
    ai_handle   (*destroy)      (ai_handle network);
    ai_bool     (*init)         (ai_handle network, const ai_network_params *params);
    ai_i32      (*run)          (ai_handle network, const ai_buffer *input, ai_buffer *output);
    ai_i32      (*forward)      (ai_handle network, const ai_buffer *input);
    ai_handle   (*weights_get)  (void);
};
typedef struct cube_ai *cubeai_ai_t;
#define CUBE_AI_T(h) ((cubeai_ai_t)(h))

#define CFG_ACTIVATIONS_ADDR (RT_AI_CFG_DEFAULT + 1)

#define CFG_INPUT_0_ADDR (RT_AI_CFG_DEFAULT + 2)
#define CFG_INPUT_1_ADDR (RT_AI_CFG_DEFAULT + 3)
#define CFG_INPUT_2_ADDR (RT_AI_CFG_DEFAULT + 4)
#define CFG_INPUT_3_ADDR (RT_AI_CFG_DEFAULT + 5)
#define CFG_INPUT_4_ADDR (RT_AI_CFG_DEFAULT + 6)

#define CFG_OUTPUT_0_ADDR (RT_AI_CFG_DEFAULT + 7)
#define CFG_OUTPUT_1_ADDR (RT_AI_CFG_DEFAULT + 8)
#define CFG_OUTPUT_2_ADDR (RT_AI_CFG_DEFAULT + 9)
#define CFG_OUTPUT_3_ADDR (RT_AI_CFG_DEFAULT + 10)
#define CFG_OUTPUT_4_ADDR (RT_AI_CFG_DEFAULT + 11)

int backend_cubeai(void *cube_handle);
#endif //end
#endif //RT_AI_USE_CUBE

