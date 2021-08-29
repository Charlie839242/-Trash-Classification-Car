/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-04-01     liqiwen      the first version
 */

#include <backend_cubeai.h>
#include <rt_ai_common.h>
#include <rt_ai.h>
/**********CUBE.AI****************/
#ifdef RT_AI_USE_CUBE

#undef cube_ai_get_info
#undef cube_ai_get_error
#undef cube_ai_create
#undef cube_ai_destory
#undef cube_ai_init
#undef cube_ai_run
#undef cube_ai_forward

#define cube_ai_get_info  (CUBE_AI_T(ai)->get_info)
#define cube_ai_get_error (CUBE_AI_T(ai)->get_error)
#define cube_ai_create    (CUBE_AI_T(ai)->create)
#define cube_ai_destory   (CUBE_AI_T(ai)->destroy)
#define cube_ai_init      (CUBE_AI_T(ai)->init)
#define cube_ai_run       (CUBE_AI_T(ai)->run)
#define cube_ai_forward   (CUBE_AI_T(ai)->forward)

#define CUBE_AI_ERROR ai_error

static int cubeai_config(rt_ai_t ai, int cmd, rt_ai_buffer_t *args);

static inline void _io_buffer_map(rt_ai_t ai)
{
  int i = 0;
  for (i = 0; i < ai->info.input_n; i++)
  {
    CUBE_AI_T(ai)->report.inputs[i].data = AI_HANDLE_PTR(ai->input[i]);
  }
  for (i = 0; i < ai->info.output_n; i++)
  {
    CUBE_AI_T(ai)->report.outputs[i].data = AI_HANDLE_PTR(ai->output[i]);
  }
}

static int cubeai_backend_init(rt_ai_t ai, rt_ai_buffer_t *work_buf)
{
  CUBE_AI_ERROR err;

  /* 1 - Create an instance of the model */
  err = cube_ai_create(&CUBE_AI_T(ai)->handle, AI_HANDLE_NULL);
  if (err.type != AI_ERROR_NONE)
  {
    //    ai_log_err(err, "ai_mnist_create");
    return -1;
  }

  /* 2 - Initialize the instance */
  // const PLAYFORM_AI_PARAMS_T params = {
  //     PLATFORM_AI_DATA_WEIGHTS(PLATFORM_AI_DATA_WEIGHTS_GET_F()),
  //     PLATFORM_AI_DATA_ACTIVATIONS(work_buf) };
  cubeai_config(ai, RT_AI_CFG_DEFAULT, NULL);
  CUBE_AI_T(ai)->params.params.data = CUBE_AI_T(ai)->weights_get();

  if (!cube_ai_init(CUBE_AI_T(ai)->handle, &(CUBE_AI_T(ai)->params)))
  {
    err = cube_ai_get_error(CUBE_AI_T(ai)->handle);
    //      ai_log_err(err, "ai_mnist_init");
    return -1;
  }

  /* 3 - Retrieve the network info of the created instance */
  if (!cube_ai_get_info(CUBE_AI_T(ai)->handle, &CUBE_AI_T(ai)->report))
  {
    err = cube_ai_get_error(CUBE_AI_T(ai)->handle);
    //    ai_log_err(err, "ai_mnist_get_error");
    cube_ai_destory(CUBE_AI_T(ai)->handle);
    CUBE_AI_T(ai)->handle = AI_HANDLE_NULL;
    return -3;
  }
  _io_buffer_map(ai);

  return 0;
}

static int cubeai_backend_run(rt_ai_t ai, void (*callback)(void *arg), void *arg)
{
  CUBE_AI_ERROR err;
  ai_i32 batch;

  batch = cube_ai_run(CUBE_AI_T(ai)->handle, &CUBE_AI_T(ai)->report.inputs[0], &CUBE_AI_T(ai)->report.outputs[0]);

  if (batch != 1)
  {
    //    ai_log_err(ai_mnist_get_error(CUBE_AI_T(ai)->handle),
    //        "ai_mnist_run");
    err = cube_ai_get_error(CUBE_AI_T(ai)->handle);
    (void)err;
    return -1;
  }
  callback(arg);
  return 0;
}

static int cubeai_backend_get_output(rt_ai_t ai, rt_ai_uint32_t index)
{
  if (index >= ai->info.output_n)
  {
    return -1;
  }
  RT_ASSERT(index < ai->info.output_n);

  return 0;
}

static int cubeai_config(rt_ai_t ai, int cmd, rt_ai_buffer_t *args)
{
  switch (cmd)
  {
  case RT_AI_CFG_DEFAULT:
    rt_ai_allocate_buffer(ai, ai->workbuffer);
    CUBE_AI_T(ai)->params.activations.data = AI_HANDLE_PTR(ai->workbuffer);
    break;
  case CFG_ACTIVATIONS_ADDR:
    CUBE_AI_T(ai)->params.activations.data = ai->workbuffer = AI_HANDLE_PTR(args);
    break;
  case CFG_INPUT_0_ADDR:
    CUBE_AI_T(ai)->report.inputs[0].data = ai->input[0] = AI_HANDLE_PTR(args);
    break;
  case CFG_INPUT_1_ADDR:
    CUBE_AI_T(ai)->report.inputs[1].data = ai->input[1] = AI_HANDLE_PTR(args);
    break;
  case CFG_INPUT_2_ADDR:
    CUBE_AI_T(ai)->report.inputs[2].data = ai->input[2] = AI_HANDLE_PTR(args);
    break;
  case CFG_INPUT_3_ADDR:
    CUBE_AI_T(ai)->report.inputs[3].data = ai->input[3] = AI_HANDLE_PTR(args);
    break;
  case CFG_INPUT_4_ADDR:
    CUBE_AI_T(ai)->report.inputs[4].data = ai->input[4] = AI_HANDLE_PTR(args);
    break;
  case CFG_OUTPUT_0_ADDR:
    CUBE_AI_T(ai)->report.outputs[0].data = ai->output[0] = AI_HANDLE_PTR(args);
    break;
  case CFG_OUTPUT_1_ADDR:
    CUBE_AI_T(ai)->report.outputs[1].data = ai->output[1] = AI_HANDLE_PTR(args);
    break;
  case CFG_OUTPUT_2_ADDR:
    CUBE_AI_T(ai)->report.outputs[2].data = ai->output[2] = AI_HANDLE_PTR(args);
    break;
  case CFG_OUTPUT_3_ADDR:
    CUBE_AI_T(ai)->report.outputs[3].data = ai->output[3] = AI_HANDLE_PTR(args);
    break;
  case CFG_OUTPUT_4_ADDR:
    CUBE_AI_T(ai)->report.outputs[4].data = ai->output[4] = AI_HANDLE_PTR(args);
    break;

  default:
    break;
  }
  // todo
  return 0;
}
int backend_cubeai(void *cube_handle)
{
  RT_AI_T(cube_handle)->init = cubeai_backend_init;
  RT_AI_T(cube_handle)->run = cubeai_backend_run;
  RT_AI_T(cube_handle)->get_output = cubeai_backend_get_output;
  RT_AI_T(cube_handle)->config = cubeai_config;
  RT_AI_T(cube_handle)->mem_flag = ALLOC_INPUT_BUFFER_FLAG | ALLOC_OUTPUT_BUFFER_FLAG | ALLOC_WORK_BUFFER_FLAG;
  return 0;
}

#endif //RT_AI_USE_CUBE
/**********CUBE.AI end****************/
