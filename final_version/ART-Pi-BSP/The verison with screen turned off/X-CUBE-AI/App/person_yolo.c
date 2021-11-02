/**
  ******************************************************************************
  * @file    person_yolo.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Sep 30 00:17:55 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "person_yolo.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_person_yolo
 
#undef AI_PERSON_YOLO_MODEL_SIGNATURE
#define AI_PERSON_YOLO_MODEL_SIGNATURE     "50bfd49bd622aefd7975eda966c6488d"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Thu Sep 30 00:17:55 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_PERSON_YOLO_N_BATCHES
#define AI_PERSON_YOLO_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv2d_38_scratch0_array;   /* Array #1 */
AI_STATIC ai_array conv2d_37_scratch0_array;   /* Array #2 */
AI_STATIC ai_array conv2d_36_scratch0_array;   /* Array #3 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #4 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #5 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #6 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #7 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #8 */
AI_STATIC ai_array conv2d_24_scratch0_array;   /* Array #9 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #10 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #11 */
AI_STATIC ai_array conv2d_20_scratch0_array;   /* Array #12 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #13 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #14 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #15 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #16 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #17 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #18 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #19 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #20 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #21 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #22 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #23 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #24 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #25 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #26 */
AI_STATIC ai_array conv2d_38_bias_array;   /* Array #27 */
AI_STATIC ai_array conv2d_38_weights_array;   /* Array #28 */
AI_STATIC ai_array conv2d_37_bias_array;   /* Array #29 */
AI_STATIC ai_array conv2d_37_weights_array;   /* Array #30 */
AI_STATIC ai_array conv2d_36_bias_array;   /* Array #31 */
AI_STATIC ai_array conv2d_36_weights_array;   /* Array #32 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #33 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #34 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #35 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #36 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #37 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #38 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #39 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #40 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #41 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #42 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #43 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #44 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #45 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #46 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #47 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #48 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #49 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #50 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #51 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #52 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #53 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #54 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #55 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #56 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #57 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #58 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #59 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #60 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #61 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #62 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #63 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #64 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #65 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #66 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #67 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #68 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #69 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #70 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #71 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #72 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #73 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #74 */
AI_STATIC ai_array image_input_output_array;   /* Array #75 */
AI_STATIC ai_array conversion_0_output_array;   /* Array #76 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #77 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #78 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #79 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #80 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #81 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #82 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #83 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #84 */
AI_STATIC ai_array concat_14_output_array;   /* Array #85 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #86 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #87 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #88 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #89 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #90 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #91 */
AI_STATIC ai_array eltwise_22_output_array;   /* Array #92 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #93 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #94 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #95 */
AI_STATIC ai_array eltwise_26_output_array;   /* Array #96 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #97 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #98 */
AI_STATIC ai_array conv2d_29_output_array;   /* Array #99 */
AI_STATIC ai_array eltwise_30_output_array;   /* Array #100 */
AI_STATIC ai_array concat_33_output_array;   /* Array #101 */
AI_STATIC ai_array conv2d_34_output_array;   /* Array #102 */
AI_STATIC ai_array conv2d_36_output_array;   /* Array #103 */
AI_STATIC ai_array conv2d_37_output_array;   /* Array #104 */
AI_STATIC ai_array conv2d_38_output_array;   /* Array #105 */
AI_STATIC ai_array conv2d_39_output_array;   /* Array #106 */
AI_STATIC ai_array conversion_40_output_array;   /* Array #107 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_38_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_37_scratch0;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_36_scratch0;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_24_scratch0;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_20_scratch0;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_38_bias;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_38_weights;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_37_bias;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_37_weights;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_36_bias;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_36_weights;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #74 */
AI_STATIC ai_tensor image_input_output;   /* Tensor #75 */
AI_STATIC ai_tensor conversion_0_output;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #84 */
AI_STATIC ai_tensor concat_14_output;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #91 */
AI_STATIC ai_tensor eltwise_22_output;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #95 */
AI_STATIC ai_tensor eltwise_26_output;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_29_output;   /* Tensor #99 */
AI_STATIC ai_tensor eltwise_30_output;   /* Tensor #100 */
AI_STATIC ai_tensor concat_33_output;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_34_output;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_36_output;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_37_output;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_38_output;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_39_output;   /* Tensor #106 */
AI_STATIC ai_tensor conversion_40_output;   /* Tensor #107 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conversion_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain concat_14_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain eltwise_22_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain eltwise_26_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_29_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain eltwise_30_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain concat_33_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_34_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_36_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain conv2d_37_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain conv2d_38_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_39_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain conversion_40_chain;   /* Chain #31 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_nl conversion_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #8 */
AI_STATIC ai_layer_concat concat_14_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #15 */
AI_STATIC ai_layer_eltwise eltwise_22_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #19 */
AI_STATIC ai_layer_eltwise eltwise_26_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_29_layer; /* Layer #23 */
AI_STATIC ai_layer_eltwise eltwise_30_layer; /* Layer #24 */
AI_STATIC ai_layer_concat concat_33_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_34_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_36_layer; /* Layer #27 */
AI_STATIC ai_layer_conv2d conv2d_37_layer; /* Layer #28 */
AI_STATIC ai_layer_conv2d conv2d_38_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_39_layer; /* Layer #30 */
AI_STATIC ai_layer_nl conversion_40_layer; /* Layer #31 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1424, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2816, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1632, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 496, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 736, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 832, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 297, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 112, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 292, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 40, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11264, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 4, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  image_input_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 25600, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19200, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19200, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  concat_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  concat_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8800, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1600, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1000, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conversion_40_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1000, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.244497101055458e-05f, 7.509685383411124e-05f, 3.2855779863893986e-05f, 3.846669278573245e-05f, 0.0003097606240771711f, 0.00019932827854063362f, 0.00019957567565143108f, 0.00023495062487199903f, 7.516689947806299e-05f, 8.253708074335009e-05f, 4.6012330130906776e-05f, 6.758753443136811e-05f, 0.0002189973893109709f, 0.00019831450481433421f, 0.00019980450451839715f, 0.0002422919642413035f, 9.944639168679714e-05f, 0.00013145923730917275f, 3.3724194508977234e-05f, 3.662424933281727e-05f, 0.00021081259183119982f, 0.00019840142340399325f, 0.00018138738232664764f, 0.00023600652639288455f, 7.438714965246618e-05f, 7.718587585259229e-05f, 3.788680623983964e-05f, 3.8795395084889606e-05f, 0.00019166264974046499f, 0.00020416040206328034f, 0.00018772391194943339f, 0.00021989141532685608f, 6.131995178293437e-05f, 7.056254980852827e-05f, 4.481577343540266e-05f, 4.283915404812433e-05f, 0.00033537091803736985f, 0.00016492028953507543f, 0.00015674723545089364f, 0.00017686565115582198f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0015523415058851242f, 0.0016091656871140003f, 0.0007040294585749507f, 0.0008242593612521887f, 0.006637510843575001f, 0.004271180834621191f, 0.004276481922715902f, 0.005034491885453463f, 0.0016106667462736368f, 0.0017685940256342292f, 0.000985946273431182f, 0.0014482570113614202f, 0.004692648071795702f, 0.004249457735568285f, 0.004281385336071253f, 0.005191801115870476f, 0.002130924491211772f, 0.0028168917633593082f, 0.0007226377492770553f, 0.0007847797241993248f, 0.0045172651298344135f, 0.004251320380717516f, 0.0038867455441504717f, 0.005057117436081171f, 0.001593958237208426f, 0.0016539291245862842f, 0.000811833655461669f, 0.0008313027792610228f, 0.0041069225408136845f, 0.004374722950160503f, 0.004022523760795593f, 0.004711804911494255f, 0.0013139561051502824f, 0.0015120052266865969f, 0.0009603066137060523f, 0.0009179519256576896f, 0.0071862852200865746f, 0.003533890936523676f, 0.0033587596844881773f, 0.0037898544687777758f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.0364606573130004e-05f, 2.6330179025535472e-05f, 4.731452281703241e-05f, 3.420502980588935e-05f, 2.7876563763129525e-05f, 2.016934013227001e-05f, 2.2409683879232034e-05f, 2.632405266922433e-05f, 3.413104059291072e-05f, 2.5894529244396836e-05f, 2.9438366254908033e-05f, 2.9207392799435183e-05f, 2.9789220207021572e-05f, 5.969541234662756e-05f, 2.847932410077192e-05f, 4.491887375479564e-05f, 2.2517982870340347e-05f, 5.2929473895346746e-05f, 2.3792199499439448e-05f, 2.907834277721122e-05f, 2.3081265680957586e-05f, 2.2778163838665932e-05f, 2.6112571504199877e-05f, 1.800718018785119e-05f, 6.633405428146943e-05f, 2.8168327844468877e-05f, 2.950737689388916e-05f, 4.801882823812775e-05f, 6.136097363196313e-05f, 2.128365849785041e-05f, 4.208129394100979e-05f, 4.584810812957585e-05f, 1.964210969163105e-05f, 2.8670774554484524e-05f, 3.543855564203113e-05f, 2.497332934581209e-05f, 3.383237708476372e-05f, 3.349619873915799e-05f, 5.967308970866725e-05f, 2.1217414541752078e-05f, 3.3320629881927744e-05f, 2.6278932637069374e-05f, 4.869827535003424e-05f, 2.7143409170093946e-05f, 2.226465949206613e-05f, 4.2730978748295456e-05f, 3.0279343263828196e-05f, 3.5012835724046454e-05f, 2.645194217620883e-05f, 2.328805385332089e-05f, 3.150259726680815e-05f, 3.5042379749938846e-05f, 3.09991228277795e-05f, 3.936330904252827e-05f, 7.489752169931307e-05f, 4.3127365643158555e-05f, 2.5101542632910423e-05f, 2.2685499061481096e-05f, 4.175508001935668e-05f, 3.0588511435780674e-05f, 2.0403876987984404e-05f, 4.7376677684951574e-05f, 3.762764026760124e-05f, 2.3124946892494336e-05f, 7.391720282612368e-05f, 2.2637334041064605e-05f, 5.7050303439609706e-05f, 5.0422429922036827e-05f, 4.7291428927564994e-05f, 2.773734559013974e-05f, 4.584121779771522e-05f, 3.828834087471478e-05f, 6.226584810065106e-05f, 4.153092595515773e-05f, 2.079431760648731e-05f, 2.3719978344161063e-05f, 7.76050947024487e-05f, 2.22732105612522e-05f, 2.819962173816748e-05f, 6.970582762733102e-05f, 5.18109263794031e-05f, 2.2974783860263415e-05f, 2.2718781110597774e-05f, 2.8706319426419213e-05f, 2.8873253540950827e-05f, 4.3373918742872775e-05f, 2.8730575650115497e-05f, 3.705851486301981e-05f, 7.722292502876371e-05f, 4.6038250729907304e-05f, 2.5670660761534236e-05f, 2.4894397938624024e-05f, 2.8200600354466587e-05f, 4.337012069299817e-05f, 2.955566560558509e-05f, 5.208511356613599e-05f, 3.6907498724758625e-05f, 4.6758344979025424e-05f, 2.4301329176523723e-05f, 3.745442518265918e-05f, 5.072207932244055e-05f, 4.134898699703626e-05f, 3.615977038862184e-05f, 4.845757212024182e-05f, 2.3163904188550077e-05f, 2.7390866307541728e-05f, 2.5086990717682056e-05f, 2.1596471924567595e-05f, 2.3582286303280853e-05f, 2.1478761482285336e-05f, 8.642177272122353e-05f, 1.6335987311322242e-05f, 4.784546763403341e-05f, 4.181702752248384e-05f, 2.206869794463273e-05f, 9.140597830992192e-05f, 1.8004031517193653e-05f, 4.838371751247905e-05f, 2.1246181859169155e-05f, 3.036685666302219e-05f, 2.1314788682502694e-05f, 4.775639536092058e-05f, 2.2724392692907713e-05f, 4.226660530548543e-05f, 2.9902994356234558e-05f, 2.7750398658099584e-05f, 5.0610342441359535e-05f, 2.144451718777418e-05f, 6.015254621161148e-05f, 7.393502892227843e-05f, 3.4169977880083025e-05f, 2.3931792384246364e-05f, 2.593474528111983e-05f, 2.255982326460071e-05f, 4.4742941099684685e-05f, 3.736752478289418e-05f, 3.499616650515236e-05f, 8.20557979750447e-05f, 3.0305300242616795e-05f, 2.598893115646206e-05f, 3.3397132938262075e-05f, 3.0054385206312872e-05f, 3.032652057299856e-05f, 2.1125737475813366e-05f, 2.38796910707606e-05f, 3.133426798740402e-05f, 6.893986574141309e-05f, 2.2197569705895148e-05f, 2.650989881658461e-05f, 7.36242436687462e-05f, 3.500355887808837e-05f, 2.5650966563262045e-05f, 2.5121960788965225e-05f, 4.699458077084273e-05f, 2.865320857381448e-05f, 2.3018306819722056e-05f, 4.003222056780942e-05f, 1.7355108866468072e-05f, 3.502185791148804e-05f, 2.6978621463058516e-05f, 2.894455974455923e-05f, 3.408698466955684e-05f, 2.65639628196368e-05f, 2.0748189854202792e-05f, 2.2542790247825906e-05f, 9.299812518293038e-05f, 5.144249371369369e-05f, 1.6236308510997333e-05f, 4.057225305587053e-05f, 1.5728475773357786e-05f, 2.842352660081815e-05f, 2.023695378738921e-05f, 2.8592676244443282e-05f, 2.5332165023428388e-05f, 2.5236260626115836e-05f, 2.7631283955997787e-05f, 5.163010428077541e-05f, 2.5512819775030948e-05f, 2.7299609428155236e-05f, 7.567739521618932e-05f, 2.4743021640460938e-05f, 2.3008153220871463e-05f, 3.399205161258578e-05f, 2.257585947518237e-05f, 3.227657362003811e-05f, 3.762823325814679e-05f, 6.714908522553742e-05f, 2.609105285955593e-05f, 2.055049844784662e-05f, 3.3472086215624586e-05f, 2.2308318875730038e-05f, 2.292720091645606e-05f, 1.9377852368052118e-05f, 2.28793596761534e-05f, 1.9624505512183532e-05f, 6.07195142947603e-05f, 2.8378586648614146e-05f, 4.2579169530654326e-05f, 2.319158193131443e-05f, 5.678942397935316e-05f, 2.6238036298309453e-05f, 4.237116809235886e-05f, 3.0633305868832394e-05f, 2.0686693460447714e-05f, 4.697101394413039e-05f, 3.9193168049678206e-05f, 3.26639274135232e-05f, 2.246602343802806e-05f, 4.721488949144259e-05f, 1.9351984519744292e-05f, 6.445468898164108e-05f, 2.961877362395171e-05f, 4.250776692060754e-05f, 0.00010030177509179339f, 2.9602877475554124e-05f, 2.7673373551806435e-05f, 2.5382239982718602e-05f, 3.778985046665184e-05f, 2.874610981962178e-05f, 2.41967700276291e-05f, 1.9649274690891616e-05f, 2.6167230316787027e-05f, 2.1121411919011734e-05f, 3.662003291537985e-05f, 2.3236527340486646e-05f, 2.4184764697565697e-05f, 2.658059929672163e-05f, 6.823443254688755e-05f, 3.9386144635500386e-05f, 3.530898175085895e-05f, 2.6907444407697767e-05f, 2.1851617930224165e-05f, 2.4605262296972796e-05f, 2.2988220734987408e-05f, 4.623852510121651e-05f, 3.831749563687481e-05f, 3.693973849294707e-05f, 4.088394052814692e-05f, 2.3538323148386553e-05f, 2.8390173611114733e-05f, 2.2690732293995097e-05f, 7.749822543701157e-05f, 2.2558708224096335e-05f, 2.6706458811531775e-05f, 4.993838592781685e-05f, 3.072379331570119e-05f, 2.418451549601741e-05f, 9.10151211428456e-05f, 2.8279700927669182e-05f, 2.352048977627419e-05f, 2.8592927264980972e-05f, 3.398103581275791e-05f, 1.9105566025245935e-05f, 3.570081389625557e-05f, 4.8829620936885476e-05f, 2.6291823814972304e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005055767251178622f, 0.00043840272701345384f, 0.0007877962198108435f, 0.0005695205763913691f, 0.00046415033284574747f, 0.0003358235117048025f, 0.0003731256874743849f, 0.000438300718087703f, 0.0005682886112481356f, 0.0004311490629334003f, 0.0004901546635665f, 0.0004863089125137776f, 0.0004959964426234365f, 0.0009939405135810375f, 0.00047418641042895615f, 0.0007479081978090107f, 0.0003749289026018232f, 0.0008812862797640264f, 0.00039614486740902066f, 0.0004841602058149874f, 0.00038430767017416656f, 0.0003792609495576471f, 0.0004347795038484037f, 0.00029982312116771936f, 0.0011044752318412066f, 0.0004690082569140941f, 0.0004913036827929318f, 0.0007995230262167752f, 0.0010216723894700408f, 0.00035437714541330934f, 0.000700661912560463f, 0.0007633801433257759f, 0.00032704503973945975f, 0.0004773740947712213f, 0.0005900589749217033f, 0.00041581090772524476f, 0.0005633158143609762f, 0.0005577183910645545f, 0.0009935687994584441f, 0.00035327416844666004f, 0.0005547951441258192f, 0.0004375494609121233f, 0.0008108359761536121f, 0.00045194316771812737f, 0.0003707110008690506f, 0.0007114792824722826f, 0.0005041570984758437f, 0.0005829706788063049f, 0.0004404300998430699f, 0.00038775074062868953f, 0.0005245244828984141f, 0.0005834625917486846f, 0.0005161415901966393f, 0.0006554069113917649f, 0.0012470586225390434f, 0.0007180792163126171f, 0.0004179456736892462f, 0.0003777180681936443f, 0.0006952303810976446f, 0.000509304809384048f, 0.00033972860546782613f, 0.000788831093814224f, 0.000626507680863142f, 0.00038503497489728034f, 0.0012307361466810107f, 0.000376916112145409f, 0.0009498989093117416f, 0.000839543470647186f, 0.0007874117000028491f, 0.00046183232916519046f, 0.0007632654160261154f, 0.0006375084631145f, 0.0010367387440055609f, 0.000691498164087534f, 0.00034622952807694674f, 0.00039494235534220934f, 0.0012921402230858803f, 0.00037085337680764496f, 0.000469529302790761f, 0.0011606159387156367f, 0.0008626622147858143f, 0.00038253472303040326f, 0.00037827223422937095f, 0.00047796592116355896f, 0.0004807454242836684f, 0.0007221843698062003f, 0.00047836979501880705f, 0.0006170316482894123f, 0.0012857770780101418f, 0.0007665460580028594f, 0.00042742161895148456f, 0.00041449666605331004f, 0.00046954560093581676f, 0.0007221211562864482f, 0.0004921077052131295f, 0.0008672274998389184f, 0.0006145171937532723f, 0.0007785357302054763f, 0.00040462196920998394f, 0.0006236236076802015f, 0.000844532682094723f, 0.0006884688627906144f, 0.0006020673899911344f, 0.0008068282040767372f, 0.00038568361196666956f, 0.0004560633678920567f, 0.00041770338430069387f, 0.0003595855669118464f, 0.00039264975930564106f, 0.00035762565676122904f, 0.0014389397110790014f, 0.00027199744363315403f, 0.0007966365665197372f, 0.0006962618208490312f, 0.00036744819954037666f, 0.0015219277702271938f, 0.0002997707051690668f, 0.0008055985090322793f, 0.00035375315928831697f, 0.0005056142108514905f, 0.00035489548463374376f, 0.000795153493527323f, 0.00037836565752513707f, 0.000703747384250164f, 0.0004978908109478652f, 0.0004620496474672109f, 0.0008426722488366067f, 0.00035705548361875117f, 0.0010015518637374043f, 0.0012310328893363476f, 0.0005689369281753898f, 0.0003984690993092954f, 0.00043181865476071835f, 0.0003756255318876356f, 0.0007449788972735405f, 0.0006221767398528755f, 0.0005826931446790695f, 0.0013662453275173903f, 0.0005045892903581262f, 0.0004327208735048771f, 0.0005560689023695886f, 0.000500411493703723f, 0.0005049426108598709f, 0.00035174773074686527f, 0.00039760160143487155f, 0.0005217217840254307f, 0.0011478625237941742f, 0.00036959393764846027f, 0.00044139509554952383f, 0.0012258583446964622f, 0.0005828161956742406f, 0.00042709370609372854f, 0.0004182856355328113f, 0.0007824691128917038f, 0.00047708163037896156f, 0.00038325937930494547f, 0.0006665444234386086f, 0.0002889660245273262f, 0.0005831209127791226f, 0.0004491994041018188f, 0.0004819326859433204f, 0.000567555078305304f, 0.0004422952770255506f, 0.00034546147799119353f, 0.0003753419441636652f, 0.0015484372852370143f, 0.0008565277676098049f, 0.00027033776859752834f, 0.0006755361100658774f, 0.00026188226183876395f, 0.0004732573579531163f, 0.0003369493060745299f, 0.0004760737356264144f, 0.0004217855748720467f, 0.00042018876411020756f, 0.00046006636694073677f, 0.0008596514817327261f, 0.00042479351395741105f, 0.00045454391511157155f, 0.0012600437039509416f, 0.00041197624523192644f, 0.0003830903151538223f, 0.0005659744492731988f, 0.0003758925595320761f, 0.0005374113679863513f, 0.0006265175761654973f, 0.0011180456494912505f, 0.00043442120659165084f, 0.00034216989297419786f, 0.0005573168746195734f, 0.0003714379563461989f, 0.00038174245855771005f, 0.0003226450935471803f, 0.00038094588671810925f, 0.00032675193506293f, 0.0010109919821843505f, 0.0004725090984720737f, 0.0007089516147971153f, 0.0003861444420181215f, 0.000945555220823735f, 0.0004368685185909271f, 0.0007054883753880858f, 0.0005100506241433322f, 0.00034443754702806473f, 0.0007820767350494862f, 0.0006525740609504282f, 0.0005438608932308853f, 0.00037406376213766634f, 0.0007861373014748096f, 0.0003222143859602511f, 0.0010731833754107356f, 0.0004931584699079394f, 0.0007077627815306187f, 0.0016700444975867867f, 0.0004928937996737659f, 0.0004607671871781349f, 0.0004226193414069712f, 0.0006292085163295269f, 0.00047862844076007605f, 0.00040288103627972305f, 0.0003271643363405019f, 0.00043568958062678576f, 0.00035167569876648486f, 0.0006097308360040188f, 0.0003868927888106555f, 0.0004026811511721462f, 0.00044257225818000734f, 0.0011361169163137674f, 0.0006557871238328516f, 0.0005879015661776066f, 0.0004480142961256206f, 0.0003638337948359549f, 0.00040968251414597034f, 0.00038275844417512417f, 0.0007698806584812701f, 0.0006379939150065184f, 0.0006150539848022163f, 0.0006807257304899395f, 0.00039191776886582375f, 0.00047270202776417136f, 0.00037780520506203175f, 0.0012903608148917556f, 0.00037560699274763465f, 0.000444667850388214f, 0.0008314840379171073f, 0.0005115572712384164f, 0.0004026769893243909f, 0.0015154199209064245f, 0.00047086263657547534f, 0.0003916208224836737f, 0.0004760779265780002f, 0.0005657909787259996f, 0.00031811147346161306f, 0.0005944256554357708f, 0.000813022896181792f, 0.00043776410166174173f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.799721889663488e-05f, 0.0001885950769064948f, 0.00014288931561168283f, 0.00015602358325850219f, 8.712990529602394e-05f, 8.756439638091251e-05f, 0.00012227485422044992f, 9.84798462013714e-05f, 6.810963532188907e-05f, 8.877835352905095e-05f, 5.864247214049101e-05f, 7.39805109333247e-05f, 0.000109977598185651f, 0.00012689981667790562f, 9.655929898144677e-05f, 9.036667324835435e-05f, 8.807647100184113e-05f, 0.00013179201050661504f, 0.00010486333485459909f, 0.00012858147965744138f, 8.418710785917938e-05f, 7.407856173813343e-05f, 9.381233394378796e-05f, 9.23908082768321e-05f, 0.00020919328380841762f, 0.00028708187164738774f, 7.786490459693596e-05f, 6.690020381938666e-05f, 8.779762720223516e-05f, 9.779725223779678e-05f, 0.00013520204811356962f, 0.00012034505198244005f, 0.00011017246288247406f, 0.00011021861428162083f, 0.00021247380936983973f, 0.0001172865231637843f, 9.929769294103608e-05f, 8.06483076303266e-05f, 8.623141911812127e-05f, 8.73312892508693e-05f, 9.088090882869437e-05f, 0.00019444590725470334f, 0.00018579469178803265f, 7.844514038879424e-05f, 0.00011894209455931559f, 0.00019308121409267187f, 8.953957149060443e-05f, 0.00010307951015420258f, 0.00010648355237208307f, 4.9318699893774465e-05f, 0.00010058026236947626f, 0.0001783215848263353f, 0.00013076109462417662f, 0.00013385860074777156f, 0.00010821504110936075f, 0.00011603751772781834f, 0.00010147645662073046f, 7.208122406154871e-05f, 6.821259739808738e-05f, 0.0001948540157172829f, 0.0001587250008014962f, 6.467876664828509e-05f, 0.0003122900961898267f, 0.00017507997108623385f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006910498486831784f, 0.0034299511462450027f, 0.0025987070985138416f, 0.0028375780675560236f, 0.001584618934430182f, 0.0015925208572298288f, 0.002223795047029853f, 0.0017910385504364967f, 0.0012387000024318695f, 0.0016145989065989852f, 0.0010665220906957984f, 0.0013454727595672011f, 0.002000146545469761f, 0.0023079083766788244f, 0.0017561098793521523f, 0.0016434855060651898f, 0.0016018339665606618f, 0.0023968820460140705f, 0.0019071341957896948f, 0.0023384925443679094f, 0.0015310986200347543f, 0.0013472560094669461f, 0.0017061511753126979f, 0.0016802981263026595f, 0.0038045677356421947f, 0.005221116356551647f, 0.0014161176513880491f, 0.0012167042586952448f, 0.001596762565895915f, 0.0017786243697628379f, 0.0024588999804109335f, 0.002188697922974825f, 0.0020036904606968164f, 0.0020045298151671886f, 0.0038642301224172115f, 0.0021330728195607662f, 0.0018059127032756805f, 0.0014667389914393425f, 0.0015682781813666224f, 0.0015882813604548573f, 0.0016528378473594785f, 0.0035363594070076942f, 0.0033790208399295807f, 0.0014266703510656953f, 0.0021631824783980846f, 0.0035115398932248354f, 0.0016284431330859661f, 0.001874692039564252f, 0.0019366007763892412f, 0.0008969519985839725f, 0.001829238492064178f, 0.003243108745664358f, 0.0023781328927725554f, 0.00243446696549654f, 0.001968091120943427f, 0.0021103573963046074f, 0.0018455374520272017f, 0.001310930703766644f, 0.0012405725428834558f, 0.0035437815822660923f, 0.0028867083601653576f, 0.0011763032525777817f, 0.005679574329406023f, 0.0031841539312154055f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002208088553743437f, 0.0006487582577392459f, 0.00011219349835300818f, 0.0001239273406099528f, 0.0002815646876115352f, 5.249465903034434e-05f, 0.00023197356495074928f, 0.00021090554946567863f, 0.00020171642245259136f, 0.0002394195762462914f, 0.00043729107710532844f, 0.0006003447342664003f, 0.00024048934574238956f, 0.00018597290909383446f, 0.00014249130617827177f, 0.0007553540635854006f, 0.00020638616115320474f, 0.0007718905690126121f, 7.038835610728711e-05f, 0.00025435822317376733f, 0.0001666342286625877f, 0.00016343900642823428f, 0.00012325317948125303f, 0.00015748922305647284f, 0.00020379459601826966f, 0.00020901468815281987f, 0.0002875013742595911f, 0.00015053580864332616f, 0.00015240986249409616f, 0.00020163896260783076f, 8.734341099625453e-05f, 0.00011217474093427882f, 0.00020092976046726108f, 0.0003737591905519366f, 0.00021630320406984538f, 0.00017747342644724995f, 0.0001562673132866621f, 0.00014707939408253878f, 0.001237476826645434f, 0.0006902384338900447f, 0.00023147861065808684f, 0.0002827997086569667f, 0.00016948909615166485f, 0.00010668164031812921f, 0.00018942456517834216f, 0.00010964332614094019f, 0.00014107450260780752f, 0.000335815770085901f, 0.00020709091040771455f, 0.0004447207029443234f, 0.00023755416623316705f, 0.0001642642164370045f, 0.000166446523508057f, 0.00039385579293593764f, 0.0004962028469890356f, 0.0001910833379952237f, 0.00029488265863619745f, 0.00032259494764730334f, 0.0001278361742151901f, 0.00015613828145433217f, 0.00013265361485537142f, 0.00019906871602870524f, 0.0002561509609222412f, 0.00025100322091020644f, 0.00014578824630007148f, 0.0005669741658493876f, 0.00023782323114573956f, 0.0002443527919240296f, 0.00017016912170220166f, 0.00016512771253474057f, 0.0003796676464844495f, 0.000389702501706779f, 0.00013943960948381573f, 0.00048395857447758317f, 0.00018122204346582294f, 0.00017922246479429305f, 0.00012871330545749515f, 0.0003685384290292859f, 0.00015912386879790574f, 0.00013268624024931341f, 0.0003007708000950515f, 0.00017545721493661404f, 0.00011731287668226287f, 0.000164078053785488f, 0.00016948828124441206f, 0.00022124660608824342f, 0.0001235985109815374f, 0.000290271476842463f, 0.00038454122841358185f, 0.00023559608962386847f, 0.00018050325161311775f, 0.00015767343575134873f, 0.0002046767040155828f, 0.00016102184599731117f, 0.00012509753287304193f, 0.00011049809108953923f, 0.00018807737797033042f, 5.784428503829986e-05f, 9.282026439905167e-05f, 0.00031700398540124297f, 0.00014151234063319862f, 0.00026502992841415107f, 7.922064833110198e-05f, 0.00025342320441268384f, 0.00023992534261196852f, 0.00025728606851771474f, 0.00016494932060595602f, 0.00010213629866484553f, 0.00012184320075903088f, 0.0001322774769505486f, 0.0016122935339808464f, 0.00017337380268145353f, 9.588433749740943e-05f, 0.00023262274044100195f, 0.0006480863667093217f, 7.570328307338059e-05f, 0.0001685272582108155f, 0.00032728505902923644f, 0.00011922123667318374f, 0.00012865923054050654f, 0.00033957406412810087f, 0.00016449770191684365f, 0.00038618550752289593f, 0.00016373072867281735f, 7.051777356537059e-05f, 0.0002617128484416753f, 8.626512862974778e-05f, 0.0002001089305849746f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007167318370193243f, 0.02105828933417797f, 0.0036417311057448387f, 0.0040226043201982975f, 0.009139414876699448f, 0.001703944057226181f, 0.007529717870056629f, 0.0068458630703389645f, 0.006547589786350727f, 0.007771410513669252f, 0.014194196090102196f, 0.019486816599965096f, 0.0078061348758637905f, 0.00603656517341733f, 0.004625179339200258f, 0.024518324062228203f, 0.006699166260659695f, 0.025055088102817535f, 0.002284762216731906f, 0.008256309665739536f, 0.0054088435135781765f, 0.005305128637701273f, 0.004000721499323845f, 0.00511200213804841f, 0.0066150459460914135f, 0.006784487050026655f, 0.009332115761935711f, 0.004886298906058073f, 0.004947129171341658f, 0.006545075215399265f, 0.0028351128567010164f, 0.003641122253611684f, 0.006522055249661207f, 0.012131990864872932f, 0.007021067664027214f, 0.00576067715883255f, 0.005072339903563261f, 0.0047741057351231575f, 0.040167730301618576f, 0.022404709830880165f, 0.0075136516243219376f, 0.009179502725601196f, 0.005501510575413704f, 0.003462819615378976f, 0.006148603744804859f, 0.0035589542239904404f, 0.004579190630465746f, 0.01090037077665329f, 0.006722042337059975f, 0.014435357414186f, 0.007710860576480627f, 0.005331914406269789f, 0.005402750801295042f, 0.012784314341843128f, 0.016106436029076576f, 0.006202446296811104f, 0.009571707807481289f, 0.010471231304109097f, 0.00414948258548975f, 0.005068151745945215f, 0.004305853974074125f, 0.006461646873503923f, 0.00831450056284666f, 0.0081474082544446f, 0.004732195753604174f, 0.01840362884104252f, 0.007719594053924084f, 0.007931539788842201f, 0.005523583851754665f, 0.005359943024814129f, 0.012323775328695774f, 0.012649500742554665f, 0.004526122938841581f, 0.01570899412035942f, 0.00588235491886735f, 0.005817449651658535f, 0.00417795404791832f, 0.011962528340518475f, 0.005165061913430691f, 0.004306912887841463f, 0.009762832894921303f, 0.005695232190191746f, 0.0038079030346125364f, 0.005325871519744396f, 0.005501484032720327f, 0.007181527093052864f, 0.004011930897831917f, 0.009422031231224537f, 0.012481968849897385f, 0.007647302467375994f, 0.005859023425728083f, 0.005117981694638729f, 0.006643678527325392f, 0.005226668901741505f, 0.00406058831140399f, 0.00358669925481081f, 0.006104874890297651f, 0.0018775895005092025f, 0.0030128881335258484f, 0.010289751924574375f, 0.004593402612954378f, 0.008602706715464592f, 0.002571453107520938f, 0.008225959725677967f, 0.007787827402353287f, 0.008351345546543598f, 0.005354152526706457f, 0.00331528065726161f, 0.003954954445362091f, 0.004293644800782204f, 0.05233404412865639f, 0.005627606064081192f, 0.0031123459339141846f, 0.007550789508968592f, 0.021036481484770775f, 0.0024572815746068954f, 0.005470289848744869f, 0.010623469948768616f, 0.003869847161695361f, 0.0041761985048651695f, 0.011022362858057022f, 0.005339493043720722f, 0.012535341084003448f, 0.005314597859978676f, 0.0022889631800353527f, 0.008495036512613297f, 0.002800112357363105f, 0.00649541150778532f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.009236964629963e-05f, 9.709856385597959e-05f, 0.00016904470976442099f, 0.00010531680891290307f, 0.00019496207823976874f, 0.00019894135766662657f, 0.00010291011858498678f, 0.00013482110807672143f, 0.000153478846186772f, 0.00014619655848946422f, 0.00015746633289381862f, 9.577255696058273e-05f, 7.688950427109376e-05f, 0.00022883352357894182f, 0.00019192782929167151f, 9.578955359756947e-05f, 0.00013816975115332752f, 8.270429680123925e-05f, 0.00013429767568595707f, 9.649347339291126e-05f, 0.00013809867959935218f, 0.00011526600428624079f, 0.00020008705905638635f, 0.00016199573292396963f, 0.00010218967508990318f, 8.75052937772125e-05f, 0.0001264466263819486f, 9.943231998477131e-05f, 0.0001452695723855868f, 0.00017827606643550098f, 8.467313455184922e-05f, 0.00018064897449221462f, 9.064944606507197e-05f, 0.00011876228381879628f, 0.00011978963448200375f, 9.179905464407057e-05f, 9.835095988819376e-05f, 0.000195313201402314f, 0.00011296886805212125f, 7.785524212522432e-05f, 0.00010930403368547559f, 0.0001460756902815774f, 0.00013353895337786525f, 0.00014408149581868201f, 0.00017126279999502003f, 0.00015323690604418516f, 0.00011372251174179837f, 0.00010036306775873527f, 0.00020000810036435723f, 0.00010224569268757477f, 0.00016348542703781277f, 0.0001406105002388358f, 0.00013107828272040933f, 0.00014152124640531838f, 0.00011081011325586587f, 0.00012626309762708843f, 9.802191925700754e-05f, 0.00011494987847981974f, 0.0001007893806672655f, 0.00019012106349691749f, 0.00016984753892756999f, 0.00012965452333446592f, 0.00013125628174748272f, 0.00013735513493884355f, 0.0001232195063494146f, 0.00012943902402184904f, 8.707903907634318e-05f, 0.00011031641042791307f, 0.00014820315118413419f, 0.00015223733498714864f, 0.00011398544302210212f, 0.00019049491675104946f, 0.00011230075324419886f, 0.00014939060201868415f, 0.0001349559024674818f, 0.00013425506767816842f, 0.0001538856013212353f, 5.494929428095929e-05f, 0.00011575012467801571f, 0.00010802562610479072f, 8.378140773857012e-05f, 0.00017363822553306818f, 0.0001236410898854956f, 0.00010616232611937448f, 0.00019072524446528405f, 0.00013927176769357175f, 0.00018326217832509428f, 9.514949488220736e-05f, 8.764331141719595e-05f, 7.047876715660095e-05f, 0.00011604506289586425f, 0.00015599408652633429f, 0.00014720628678333014f, 0.0001053034357028082f, 8.556975808460265e-05f, 0.0001514880423201248f, 0.00019780523143708706f, 0.00016648799646645784f, 0.0001380588364554569f, 0.00012953224359080195f, 0.00016274266818072647f, 0.0001736231060931459f, 0.00014822759840171784f, 0.00014451346942223608f, 0.00011806403927039355f, 0.0002001748507609591f, 0.0002528946497477591f, 0.00016671126650180668f, 0.0001478481135563925f, 0.00012086256174370646f, 0.00011377880582585931f, 0.00011763703514588997f, 0.00020602117001544684f, 0.000145526064443402f, 0.0001201321356347762f, 0.00013490648416336626f, 0.0002299690677318722f, 7.725845352979377e-05f, 0.0001841335033532232f, 0.00010873370774788782f, 6.719949305988848e-05f, 0.00014744189684279263f, 9.820088598644361e-05f, 0.00013607637083623558f, 0.00016744507593102753f, 0.00010785070480778813f, 0.00015259177598636597f, 0.0001829279208322987f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004910935531370342f, 0.0005292842979542911f, 0.0009214627789333463f, 0.0005740819615311921f, 0.0010627383599057794f, 0.001084429444745183f, 0.0005609631189145148f, 0.0007349099614657462f, 0.0008366132969968021f, 0.0007969174766913056f, 0.0008583490853197873f, 0.0005220562452450395f, 0.0004191247280687094f, 0.001247371663339436f, 0.0010461986530572176f, 0.0005221489118412137f, 0.0007531633600592613f, 0.00045082115684635937f, 0.0007320566801354289f, 0.0005259859608486295f, 0.0007527759880758822f, 0.0006283150287345052f, 0.0010906746610999107f, 0.00088303885422647f, 0.000557035964448005f, 0.0004769914085045457f, 0.0006892606033943594f, 0.0005420056404545903f, 0.0007918644696474075f, 0.0009717828943394125f, 0.0004615532816387713f, 0.0009847176261246204f, 0.0004941301885992289f, 0.0006473732646554708f, 0.0006529733655042946f, 0.0005003967089578509f, 0.0005361111252568662f, 0.001064652344211936f, 0.0006157933385111392f, 0.00042438897071406245f, 0.0005958163528703153f, 0.0007962586241774261f, 0.0007279209094122052f, 0.0007853882852941751f, 0.0009335536160506308f, 0.0008352944278158247f, 0.0006199014605954289f, 0.00054707913659513f, 0.0010902442736551166f, 0.000557341321837157f, 0.0008911591139622033f, 0.0007664678851142526f, 0.0007145077688619494f, 0.0007714324165135622f, 0.0006040259613655508f, 0.0006882601883262396f, 0.0005343175143934786f, 0.0006265918491408229f, 0.0005494029610417783f, 0.0010363500332459807f, 0.0009258390055038035f, 0.0007067468832246959f, 0.0007154780905693769f, 0.0007487229304388165f, 0.0006716696079820395f, 0.0007055721944198012f, 0.0004746678750962019f, 0.0006013347883708775f, 0.000807855452876538f, 0.0008298457833006978f, 0.0006213347078301013f, 0.0010383878834545612f, 0.0006121514597907662f, 0.0008143282611854374f, 0.000735644658561796f, 0.0007318244315683842f, 0.000838830485008657f, 0.0002995286195073277f, 0.000630953989457339f, 0.000588847731705755f, 0.00045669247629120946f, 0.0009465020848438144f, 0.0006739676464349031f, 0.0005786909023299813f, 0.0010396434227004647f, 0.000759170507080853f, 0.0009989622049033642f, 0.0005186599446460605f, 0.0004777437134180218f, 0.00038417978794313967f, 0.000632561685051769f, 0.0008503238204866648f, 0.0008024215348996222f, 0.0005740090855397284f, 0.0004664408043026924f, 0.0008257614099420607f, 0.0010782363824546337f, 0.0009075261768884957f, 0.0007525587570853531f, 0.0007060802890919149f, 0.0008871103636920452f, 0.0009464196045883f, 0.000807988690212369f, 0.0007877429598011076f, 0.0006435671239160001f, 0.0010911532444879413f, 0.0013785288901999593f, 0.0009087431826628745f, 0.0008059201645664871f, 0.0006588218966498971f, 0.0006202083313837647f, 0.0006412395159713924f, 0.0011230214731767774f, 0.000793262617662549f, 0.0006548403180204332f, 0.0007353753317147493f, 0.0012535614660009742f, 0.0004211358609609306f, 0.0010037118336185813f, 0.000592707481700927f, 0.00036630447721108794f, 0.000803705828730017f, 0.0005352930747903883f, 0.0007417523884214461f, 0.000912743154913187f, 0.0005878942320123315f, 0.0008317778119817376f, 0.0009971401887014508f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002864261332433671f, 0.00026704298215918243f, 0.00031812064116820693f, 0.0002429003216093406f, 0.000296316749881953f, 0.0002312836004421115f, 0.0004048641712870449f, 0.00023416464682668447f, 0.00027563655748963356f, 0.00024540239246562123f, 0.00020402180962264538f, 0.00037514304858632386f, 0.00025425362400710583f, 0.00030003400752320886f, 0.0002063893771264702f, 0.0002658518496900797f, 0.00027802857221104205f, 0.00014392434968613088f, 0.00030913337832316756f, 0.0002108495100401342f, 0.00028370143263600767f, 0.00023181186406873167f, 0.00026881086523644626f, 0.00029659850406460464f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0053132809698581696f, 0.004953718278557062f, 0.005901222582906485f, 0.00450586574152112f, 0.00549675477668643f, 0.004290372598916292f, 0.007510338444262743f, 0.004343816544860601f, 0.005113131832331419f, 0.004552280064672232f, 0.0037846588529646397f, 0.006959003861993551f, 0.004716472700238228f, 0.005565710831433535f, 0.0038285779301077127f, 0.00493162265047431f, 0.005157504230737686f, 0.0026698349975049496f, 0.005734506528824568f, 0.003911314532160759f, 0.005262737162411213f, 0.004300171975046396f, 0.004986513406038284f, 0.005501981358975172f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013458478497341275f, 0.0004516704648267478f, 0.000222985225263983f, 0.00016114678874146193f, 0.00012656899343710393f, 0.0003630291030276567f, 0.00023530592443421483f, 0.0002246068324893713f, 0.00011089285544585437f, 0.0001563804253237322f, 0.00020460020459722728f, 0.00022167700808495283f, 0.0001671533682383597f, 0.00020294806745368987f, 0.0001669912744546309f, 0.0001778059668140486f, 0.00018888236081693321f, 0.00023215166584122926f, 0.00026841548969969153f, 0.00014674389967694879f, 0.0001415779406670481f, 0.0002168098435504362f, 0.0002106471947627142f, 0.00015938807337079197f, 0.00018672899750526994f, 0.0002477067173458636f, 0.0001418903557350859f, 0.0001888350088847801f, 0.00035244543687440455f, 8.043038542382419e-05f, 0.00016509214765392244f, 0.0002909276227001101f, 0.0004651050257962197f, 0.00021453377848956734f, 0.0003323870769236237f, 0.00030181079637259245f, 0.00019507791148498654f, 0.00014679601008538157f, 0.00020859586948063225f, 0.00021630743867717683f, 0.00019362190505489707f, 0.0001314647524850443f, 0.00015977215662132949f, 0.0001507300476077944f, 0.0003734386700671166f, 0.0001663178118178621f, 0.0001561235694680363f, 0.0001121848399634473f, 0.00014301289047580212f, 0.00016025219520088285f, 0.00010177950753131881f, 0.00026782279019244015f, 0.0001344064367003739f, 0.00021798403759021312f, 0.00012945468188263476f, 0.00021840346744284034f, 0.0004760643932968378f, 0.00019782775780186057f, 0.00023076402430888265f, 0.00015672569861635566f, 0.00020060564565937966f, 0.00017587239562999457f, 0.00019290129421278834f, 0.00034045183565467596f, 0.00025551303406246006f, 0.00042303118971176445f, 0.00040480654570274055f, 0.00024342045071534812f, 0.00018821678531821817f, 0.0002073800569633022f, 0.0002164170437026769f, 0.00020951248006895185f, 0.0002257853775518015f, 9.794385550776497e-05f, 0.0003044860786758363f, 0.00022928082034923136f, 0.0001821670593926683f, 0.00027922779554501176f, 0.00027977992431260645f, 0.0002554880629759282f, 0.0003969735116697848f, 0.0002081017300952226f, 0.0002810675068758428f, 0.00016554963076487184f, 0.0002573684323579073f, 0.0001644827425479889f, 0.00038147842860780656f, 0.00020280794706195593f, 0.0005394177860580385f, 0.00025861503672786057f, 0.00026664536562748253f, 0.00019625895947683603f, 0.0001797392324078828f, 0.00017451656458433717f, 0.00023148601758293808f, 0.00010141552775166929f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0050055962055921555f, 0.016798926517367363f, 0.008293462917208672f, 0.005993513390421867f, 0.004707465413957834f, 0.013502098619937897f, 0.008751705288887024f, 0.00835377536714077f, 0.004124424885958433f, 0.005816238466650248f, 0.007609670981764793f, 0.00824480690062046f, 0.00621691532433033f, 0.007548223249614239f, 0.006210886407643557f, 0.00661311624571681f, 0.00702507933601737f, 0.008634389378130436f, 0.009983145631849766f, 0.005457828287035227f, 0.0052656917832791805f, 0.008063782937824726f, 0.007834576070308685f, 0.005928101949393749f, 0.0069449893198907375f, 0.009212926961481571f, 0.005277310963720083f, 0.007023318205028772f, 0.013108461163938046f, 0.0029914379119873047f, 0.006140252575278282f, 0.010820436291396618f, 0.01729859597980976f, 0.007979129441082478f, 0.012362433597445488f, 0.011225213296711445f, 0.0072555094957351685f, 0.005459766369313002f, 0.007758281193673611f, 0.008045096881687641f, 0.0072013563476502895f, 0.0048895529471337795f, 0.005942387040704489f, 0.00560608459636569f, 0.013889259658753872f, 0.006185838486999273f, 0.005806685425341129f, 0.004172477405518293f, 0.0053190612234175205f, 0.005960240960121155f, 0.0037854730617254972f, 0.009961101226508617f, 0.004998962394893169f, 0.008107454515993595f, 0.004814792890101671f, 0.008123054169118404f, 0.01770620606839657f, 0.0073577845469117165f, 0.008582779206335545f, 0.00582908047363162f, 0.0074611022137105465f, 0.006541200913488865f, 0.007174554746598005f, 0.012662384659051895f, 0.009503265842795372f, 0.0157337486743927f, 0.015055921860039234f, 0.009053507819771767f, 0.0070003243163228035f, 0.007713061757385731f, 0.008049173280596733f, 0.007792372722178698f, 0.008397608995437622f, 0.0036428142338991165f, 0.011324714869260788f, 0.008527614176273346f, 0.0067753177136182785f, 0.010385286062955856f, 0.010405821725726128f, 0.00950233731418848f, 0.014764589257538319f, 0.007739902939647436f, 0.010453710332512856f, 0.006157267838716507f, 0.00957227312028408f, 0.006117586977779865f, 0.014188282191753387f, 0.007543012034147978f, 0.020062502473592758f, 0.009618638083338737f, 0.009917309507727623f, 0.007299436256289482f, 0.006685019936412573f, 0.0064907739870250225f, 0.008609632030129433f, 0.003771935822442174f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000142433462315239f, 0.00010468563414178789f, 0.00015884482127148658f, 0.00016344345931429416f, 0.00019522523507475853f, 9.77841264102608e-05f, 8.784533565631136e-05f, 0.00012828086619265378f, 0.0001807808002922684f, 0.00015012880612630397f, 0.00018678008927963674f, 0.0001355061394860968f, 0.00014984910376369953f, 0.00018921606533695012f, 0.0001941494847415015f, 0.00019291524949949235f, 0.00014343620568979532f, 0.00011718049790943041f, 0.00019584145047701895f, 0.00016884996148291975f, 0.00014430527517106384f, 0.0001660152047406882f, 0.00013130166917108f, 0.000234381906921044f, 0.0001423822104698047f, 0.00024007937463466078f, 0.00015905968029983342f, 0.00023046684509608895f, 9.879570279736072e-05f, 0.00016160447557922453f, 0.00019398238509893417f, 7.472505240002647e-05f, 0.0002057714300462976f, 0.0001643272553337738f, 0.00014673448458779603f, 0.00015256607730407268f, 0.00012061979214195162f, 0.00012879795394837856f, 0.00015980575699359179f, 9.603386570233852e-05f, 0.00011643009202089161f, 0.00011034373164875433f, 0.00018781238759402186f, 0.000134238536702469f, 7.515370816690847e-05f, 0.00014099212421569973f, 0.00016877317102625966f, 0.0002967479231301695f, 0.00015422805154230446f, 0.00015636367606930435f, 0.0001554767368361354f, 0.0001603363489266485f, 0.0001933184394147247f, 0.00012415389937814325f, 0.00011734749568859115f, 0.00016724671877454966f, 0.0001336845161858946f, 0.0001733240787871182f, 0.00018143474881071597f, 0.00013830953685101122f, 0.00018945524061564356f, 0.00020626116020139307f, 0.00020957874949090183f, 0.0002117486292263493f, 0.00019298767438158393f, 0.00011778591579059139f, 9.752612095326185e-05f, 0.0001928863493958488f, 0.00018244802777189761f, 0.00016773873358033597f, 0.00010604253475321457f, 0.00016570226580370218f, 0.0001854564470704645f, 0.00015690064174123108f, 0.00011241289030294865f, 0.00011326307867420837f, 0.00020395814499352127f, 0.00017913489136844873f, 0.00010125857079401612f, 0.00015926899504847825f, 8.188476203940809e-05f, 0.00015869810886215419f, 0.00016390297969337553f, 0.0001527784625068307f, 0.0001959242654265836f, 0.0001139915912062861f, 0.0001476530742365867f, 0.00015126599464565516f, 0.00013821743777953088f, 0.00012635068560484797f, 0.00017242851026821882f, 0.0001775310665834695f, 0.0001861581695266068f, 0.00013423827476799488f, 0.00011922233534278348f, 0.00013774230319540948f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011223010951653123f, 0.0008248679805546999f, 0.0012516140704974532f, 0.0012878489214926958f, 0.0015382727142423391f, 0.0007704877643845975f, 0.0006921752938069403f, 0.0010107860434800386f, 0.001424458110705018f, 0.0011829363647848368f, 0.0014717293670400977f, 0.0010677174432203174f, 0.001180732506327331f, 0.0014909235760569572f, 0.0015297962818294764f, 0.0015200711786746979f, 0.0011302022030577064f, 0.0009233210003003478f, 0.001543128164485097f, 0.0013304493622854352f, 0.0011370499851182103f, 0.001308112870901823f, 0.0010345884365960956f, 0.0018468067282810807f, 0.0011218972504138947f, 0.0018916998524218798f, 0.0012533069821074605f, 0.001815958064980805f, 0.0007784584304317832f, 0.0012733587063848972f, 0.0015284796245396137f, 0.0005887942970730364f, 0.0016213711351156235f, 0.0012948127696290612f, 0.001156190992332995f, 0.001202140818350017f, 0.0009504208574071527f, 0.0010148604633286595f, 0.001259185723029077f, 0.0007566966232843697f, 0.0009174082078970969f, 0.0008694508578628302f, 0.0014798633055761456f, 0.0010577293578535318f, 0.0005921719130128622f, 0.0011109441984444857f, 0.0013298442354425788f, 0.002338218269869685f, 0.001215236377902329f, 0.0012320639798417687f, 0.0012250753352418542f, 0.0012633665464818478f, 0.001523248152807355f, 0.000978267751634121f, 0.0009246368426829576f, 0.0013178165536373854f, 0.0010533640161156654f, 0.0013657030649483204f, 0.0014296108856797218f, 0.001089806784875691f, 0.0014928081072866917f, 0.0016252299537882209f, 0.0016513708978891373f, 0.0016684683505445719f, 0.0015206418465822935f, 0.0009280913509428501f, 0.0007684548036195338f, 0.0015198434703052044f, 0.0014375949976965785f, 0.001321693416684866f, 0.0008355596801266074f, 0.0013056470779702067f, 0.0014612997183576226f, 0.0012362949782982469f, 0.0008857547654770315f, 0.0008924537687562406f, 0.0016070834826678038f, 0.0014114892110228539f, 0.0007978645153343678f, 0.0012549563543871045f, 0.0006452090456150472f, 0.0012504580663517118f, 0.0012914696708321571f, 0.0012038142886012793f, 0.001543780672363937f, 0.0008981940918602049f, 0.0011634289985522628f, 0.001191896852105856f, 0.0010890810517594218f, 0.0009955773130059242f, 0.001358646433800459f, 0.0013988518621772528f, 0.0014668289804831147f, 0.0010577273787930608f, 0.0009394095977768302f, 0.0010853372514247894f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011335786985000595f, 0.00011454493505880237f, 0.00019937499018851668f, 0.0001728827483020723f, 0.0001497414050390944f, 0.00013927326654084027f, 0.00019500085909385234f, 0.0001786299835657701f, 0.0002582154411356896f, 0.00018596748122945428f, 0.00018453381198924035f, 0.00020088999008294195f, 0.00020202058658469468f, 0.000169955485034734f, 0.00016806247003842145f, 0.00020244659390300512f, 0.00018363751587457955f, 0.00014025157724972814f, 0.00018412897770758718f, 0.00017690210370346904f, 0.00021350498718675226f, 0.0001610412437003106f, 0.000181665294803679f, 0.00015631309361197054f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0026409761048853397f, 0.00266863196156919f, 0.004644975997507572f, 0.004027768038213253f, 0.00348862842656672f, 0.003244744846597314f, 0.004543068818747997f, 0.004161665216088295f, 0.006015822757035494f, 0.00433261226862669f, 0.004299210850149393f, 0.004680272191762924f, 0.0047066123224794865f, 0.003959569614380598f, 0.003915466833859682f, 0.004716537427157164f, 0.004278329201042652f, 0.003267537336796522f, 0.004289779346436262f, 0.0041214097291231155f, 0.004974172450602055f, 0.003751888405531645f, 0.004232381004840136f, 0.0036417334340512753f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002300826890859753f, 0.0003287174622528255f, 0.00019929937843699008f, 0.00024849132751114666f, 0.0001793159608496353f, 0.0002449336170684546f, 0.00013719267735723406f, 0.00013443510397337377f, 0.00022089107369538397f, 0.00021703778475057334f, 0.0002507936442270875f, 0.00024025587481446564f, 0.0003132516867481172f, 0.0002716661256272346f, 0.00018460988940205425f, 0.00027965244953520596f, 0.0004324746550992131f, 0.00024798326194286346f, 0.0002708885876927525f, 0.0001987209398066625f, 0.00013950963329989463f, 0.000282815977698192f, 0.00011609336797846481f, 0.0002749614941421896f, 0.0002916624362114817f, 0.00027686404064297676f, 0.00019228110613767058f, 0.00018568485393188894f, 0.00022680839174427092f, 0.000202548413653858f, 0.0002138391137123108f, 0.0002391510788584128f, 0.00016575392510276288f, 0.00025561382062733173f, 0.00015912375238258392f, 0.00015632790746167302f, 0.00019917325698770583f, 0.0003097908047493547f, 0.0002132118388544768f, 0.0003930112870875746f, 0.0001627307792659849f, 0.0002873041376005858f, 0.0003973030543420464f, 0.00022139557404443622f, 0.0002037594240391627f, 0.00018690299475565553f, 0.00017745772493071854f, 0.000297118560411036f, 0.00028095717425458133f, 0.0002850497548934072f, 0.00015678878116887063f, 0.00016812450485303998f, 0.00022782429005019367f, 0.000266857969108969f, 0.00022213082411326468f, 0.00020677359134424478f, 0.0001364987692795694f, 0.000291714706690982f, 0.0002887479495257139f, 0.00010698473488446325f, 0.00017923497944138944f, 0.00019402444013394415f, 0.0003373860090505332f, 0.00032772310078144073f, 0.00017311277042608708f, 0.0004211871710140258f, 0.00029290877864696085f, 0.0002606418274808675f, 0.00026361801428720355f, 0.000136550996103324f, 0.0002925920707639307f, 0.00021207518875598907f, 0.00017186824698001146f, 0.00025526940589770675f, 0.00017351146379951388f, 0.00022879548487253487f, 0.00019946141401305795f, 0.0003010880318470299f, 0.0003976721200160682f, 0.00021975468553137034f, 0.00013203348498791456f, 0.0002085034066112712f, 0.00025985451065935194f, 0.00012565869837999344f, 0.000114046735689044f, 0.0003986662195529789f, 0.00024396796652581543f, 0.00025807469501160085f, 0.00026316166622564197f, 0.0004427135572768748f, 0.0002049284230452031f, 0.00023164929007180035f, 0.00023910045274533331f, 0.0001816271396819502f, 0.00016955981845967472f, 0.0002583488239906728f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007745407521724701f, 0.011065807193517685f, 0.006709130946546793f, 0.008365107700228691f, 0.006036417558789253f, 0.008245342411100864f, 0.004618396982550621f, 0.004525566939264536f, 0.007435984909534454f, 0.007306269370019436f, 0.008442612364888191f, 0.008087873458862305f, 0.010545173659920692f, 0.009145255200564861f, 0.006214630324393511f, 0.009414102882146835f, 0.014558645896613598f, 0.008348004892468452f, 0.009119080379605293f, 0.0066896588541567326f, 0.0046963938511908054f, 0.00952059868723154f, 0.003908118698745966f, 0.00925618875771761f, 0.009818402118980885f, 0.009320235811173916f, 0.006472870707511902f, 0.0062508173286914825f, 0.007635182701051235f, 0.0068185050040483475f, 0.0071985903196036816f, 0.00805068202316761f, 0.005579870659857988f, 0.008604876697063446f, 0.0053566754795610905f, 0.005262557417154312f, 0.006704885046929121f, 0.01042866799980402f, 0.0071774739772081375f, 0.01323016732931137f, 0.005478100851178169f, 0.009671686217188835f, 0.013374644331634045f, 0.007452968042343855f, 0.006859272252768278f, 0.006291824392974377f, 0.005973862484097481f, 0.010002074763178825f, 0.009458024986088276f, 0.009595795534551144f, 0.005278071854263544f, 0.005659672897309065f, 0.00766938179731369f, 0.00898339506238699f, 0.007477719336748123f, 0.0069607398472726345f, 0.004595037549734116f, 0.009820162318646908f, 0.009720290079712868f, 0.003601489355787635f, 0.006033691577613354f, 0.006531557533890009f, 0.011357621289789677f, 0.011032333597540855f, 0.005827595945447683f, 0.014178669080138206f, 0.009860358200967312f, 0.008774137124419212f, 0.008874326944351196f, 0.00459679588675499f, 0.009849697351455688f, 0.007139210589230061f, 0.005785700865089893f, 0.008593282662332058f, 0.005841017235070467f, 0.007702075410634279f, 0.006714585702866316f, 0.010135701857507229f, 0.013387068174779415f, 0.007397729903459549f, 0.004444720223546028f, 0.007018971722573042f, 0.008747633546590805f, 0.004230122081935406f, 0.0038392215501517057f, 0.013420533388853073f, 0.008212835527956486f, 0.008687718771398067f, 0.008858964778482914f, 0.014903323724865913f, 0.006898624822497368f, 0.007798145059496164f, 0.008048977702856064f, 0.00611422024667263f, 0.0057079908438026905f, 0.008696947246789932f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010577609646134079f, 0.00013034143194090575f, 0.00017908564768731594f, 0.00012481397425290197f, 0.0001818742457544431f, 9.749308082973585e-05f, 0.00012438211706466973f, 0.0002090844645863399f, 0.00018589723913464695f, 0.00011538545368239284f, 0.00016422469343524426f, 0.00013129497529007494f, 0.00014657573774456978f, 0.0002085729211103171f, 0.0002054170472547412f, 8.208795043174177e-05f, 0.00014162124716676772f, 0.0001144540001405403f, 0.00011754067963920534f, 0.00016035520820878446f, 0.00013295897224452347f, 0.00013405369827523828f, 0.00018359658133704215f, 0.000134860907564871f, 0.0001833080023061484f, 0.00016131138545461f, 0.00016264805162791163f, 0.0001088000281015411f, 0.00020917334768455476f, 0.00012998930469620973f, 0.00018214137526229024f, 0.00016841052274685353f, 0.00017086509615182877f, 8.263997733592987e-05f, 0.0001569304004078731f, 0.00015081503079272807f, 0.00015067937783896923f, 0.0001475667959311977f, 0.0002026546571869403f, 5.010262248106301e-05f, 0.00020339019829407334f, 0.00010313720849808306f, 0.00014651173842139542f, 0.0001758490689098835f, 0.00010053522419184446f, 0.00016965650138445199f, 0.0001535276387585327f, 0.0001432911813026294f, 0.00020277091243769974f, 0.00016905504162423313f, 0.0001781970204319805f, 0.00012899492867290974f, 0.00012164070358267054f, 0.0001701998698990792f, 0.0001307236379943788f, 0.0001509614521637559f, 0.00015083867765497416f, 0.00010571542225079611f, 0.00017312333511654288f, 0.00020564219448715448f, 0.00016698094259481877f, 0.000149791274452582f, 0.00011274845019215718f, 0.00017127957835327834f, 0.00013629122986458242f, 0.00014207925414666533f, 0.00016097289335448295f, 0.0001491049479227513f, 0.00012157391029177234f, 0.00013015059812460095f, 0.00017600900901015848f, 0.00016689940821379423f, 0.00012957261060364544f, 0.00015753453772049397f, 0.00013855700672138482f, 0.000144146426464431f, 0.00013230746844783425f, 0.00019316004181746393f, 0.00011263290070928633f, 0.0001780016318662092f, 0.00014924409333616495f, 0.00010783332254504785f, 0.00014436613128054887f, 0.00019885881920345128f, 0.00016585506091360003f, 0.0002254774735774845f, 0.00017542173736728728f, 0.00016946041432674974f, 0.00016488038818351924f, 0.000224080664338544f, 0.00022623354743700475f, 0.00018910356448031962f, 0.00012040504952892661f, 0.00013762204616796225f, 0.0001911394065245986f, 0.00020037766080349684f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001032151747494936f, 0.0012718576472252607f, 0.0017474984051659703f, 0.0012179212644696236f, 0.001774709322489798f, 0.0009513269760645926f, 0.0012137072626501322f, 0.0020402236841619015f, 0.0018139651510864496f, 0.0011259188177064061f, 0.0016024868236854672f, 0.0012811621418222785f, 0.0014302702620625496f, 0.002035232027992606f, 0.002004437381401658f, 0.0008010054007172585f, 0.0013819248415529728f, 0.00111682980787009f, 0.0011469492455944419f, 0.001564728794619441f, 0.001297399285249412f, 0.0013080815551802516f, 0.0017915156204253435f, 0.001315958215855062f, 0.0017886997666209936f, 0.0015740591334179044f, 0.0015871021896600723f, 0.0010616589570418f, 0.002041090978309512f, 0.0012684216490015388f, 0.0017773158615455031f, 0.0016433317214250565f, 0.0016672831261530519f, 0.0008063919958658516f, 0.0015313099138438702f, 0.0014716368168592453f, 0.001470313174650073f, 0.001439940882846713f, 0.001977482344955206f, 0.0004888959811069071f, 0.00198465958237648f, 0.0010064017260447145f, 0.00142964581027627f, 0.001715916208922863f, 0.0009810118936002254f, 0.001655489788390696f, 0.0014981061685830355f, 0.0013982199598103762f, 0.0019786166958510876f, 0.001649620826356113f, 0.001738827326335013f, 0.0012587185483425856f, 0.0011869568843394518f, 0.0016607919242233038f, 0.0012755871284753084f, 0.0014730655821040273f, 0.0014718675520271063f, 0.0010315596591681242f, 0.0016893188003450632f, 0.002006634371355176f, 0.0016293820226565003f, 0.0014616471016779542f, 0.0011001871898770332f, 0.0016713276272639632f, 0.0013299151323735714f, 0.0013863940257579088f, 0.0015707560814917088f, 0.0014549499610438943f, 0.0011863050749525428f, 0.001269995467737317f, 0.001717476872727275f, 0.001628586440347135f, 0.0012643556110560894f, 0.0015372050693258643f, 0.0013520243810489774f, 0.0014065653085708618f, 0.001291041960939765f, 0.0018848348408937454f, 0.0010990597074851394f, 0.0017369207926094532f, 0.0014563078293576837f, 0.0010522259399294853f, 0.0014087090967223048f, 0.0019404429476708174f, 0.0016183957923203707f, 0.0022001848556101322f, 0.0017117464449256659f, 0.0016535763861611485f, 0.0016088850097730756f, 0.0021865549497306347f, 0.0022075625602155924f, 0.0018452522344887257f, 0.0011748995166271925f, 0.0013429011451080441f, 0.0018651176942512393f, 0.001955263549461961f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012801103002857417f, 0.00010501910583116114f, 0.00013707751350011677f, 0.00013707487960346043f, 0.00013432707055471838f, 0.00015649024862796068f, 0.00012122817861381918f, 0.00023399657220579684f, 0.00011154682579217479f, 0.0001938329660333693f, 0.00013722544827032834f, 0.00012259732466191053f, 0.0001691297657089308f, 0.00023046083515509963f, 0.000177549067302607f, 0.00011557354446267709f, 0.00015139978495426476f, 0.00012451321526896209f, 0.00014745483349543065f, 0.00013241615670267493f, 0.0001209253168781288f, 0.00019193548359908164f, 0.00011835394980153069f, 0.00016778380086179823f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035238468553870916f, 0.0028909326065331697f, 0.0037734261713922024f, 0.003773353761062026f, 0.0036977131385356188f, 0.0043078139424324036f, 0.003337130881845951f, 0.006441383622586727f, 0.0030706257093697786f, 0.005335772410035133f, 0.003777498612180352f, 0.0033748201094567776f, 0.004655750468373299f, 0.006344052962958813f, 0.004887514282017946f, 0.0031814719550311565f, 0.0041676852852106094f, 0.003427560441195965f, 0.0040590898133814335f, 0.0036451099440455437f, 0.0033287936821579933f, 0.005283539183437824f, 0.003258009906858206f, 0.004618699196726084f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011182999151060358f, 0.0001795907155610621f, 0.0001811927795642987f, 0.00026486197020858526f, 0.00016230430628638715f, 0.00025539108901284635f, 0.0003394088998902589f, 0.00033922510920092463f, 0.0002591628290247172f, 0.00022730827913619578f, 0.00011013526091119274f, 0.0003712765173986554f, 0.00025745885795913637f, 0.0003167111426591873f, 0.00011978669499512762f, 0.00021091356757096946f, 0.00015785965661052614f, 0.0002320089261047542f, 0.00026110917679034173f, 0.00016529283311683685f, 0.00030478721600957215f, 0.0002859107917174697f, 0.00026910414453595877f, 0.0002449637104291469f, 0.0002224832132924348f, 0.00039975266554392874f, 0.00014670845121145248f, 0.00019681941193994135f, 0.00025978058692999184f, 0.00020927636069245636f, 0.00021595261932816356f, 0.00022498621547129005f, 0.00036300226929597557f, 0.00025296490639448166f, 0.00042695447336882353f, 0.0001396253937855363f, 0.00026244859327562153f, 0.00042780142393894494f, 0.00031136683537624776f, 0.0003603977966122329f, 0.00024577006115578115f, 0.00021682311489712447f, 0.00042187972576357424f, 0.00022067135432735085f, 0.00033476174576207995f, 0.0002472366613801569f, 0.00031745524029247463f, 0.0002581514709163457f, 0.00024717990891076624f, 0.0003580512711778283f, 0.00018485946930013597f, 0.0007465779781341553f, 0.0002034149074461311f, 0.0002193251420976594f, 0.0002080636186292395f, 0.00038259237771853805f, 0.0002337758633075282f, 0.00043843273306265473f, 0.000288123992504552f, 0.00021362934785429388f, 0.00048673225683160126f, 0.0003218564670532942f, 0.00023936406068969518f, 0.00021099155128467828f, 0.000729336345102638f, 0.0002397880016360432f, 0.0004899017512798309f, 0.00021096707496326417f, 0.00018018622358795255f, 0.00035343298804946244f, 0.00040132165304385126f, 0.0004033439327031374f, 0.00019913371943403035f, 0.0002601841988507658f, 0.00042711247806437314f, 0.00016928337572608143f, 0.00022970045392867178f, 0.00021867796021979302f, 0.00040617893682792783f, 0.00036968497443012893f, 0.00031801764271222055f, 0.0002995155518874526f, 0.00029778899624943733f, 0.0003150723350699991f, 0.00020329358812887222f, 0.0002282967179780826f, 0.00039905612356960773f, 0.00026205426547676325f, 0.00025359512073919177f, 0.00024578883312642574f, 0.00017194330575875938f, 0.0002761222131084651f, 0.00038939621299505234f, 9.566580411046743e-05f, 0.00020626105833798647f, 0.00026329714455641806f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035684211179614067f, 0.005730621051043272f, 0.005781741812825203f, 0.008451569825410843f, 0.005179022904485464f, 0.008149360306560993f, 0.010830312967300415f, 0.010824448429048061f, 0.008269714191555977f, 0.007253256626427174f, 0.003514343174174428f, 0.011847187764942646f, 0.008215341717004776f, 0.010106042958796024f, 0.0038223140873014927f, 0.006730112247169018f, 0.0050371973775327206f, 0.007403251249343157f, 0.00833182130008936f, 0.005274384748190641f, 0.009725558571517467f, 0.009123223833739758f, 0.008586934767663479f, 0.007816629484295845f, 0.007099292241036892f, 0.012755842879414558f, 0.0046813697554171085f, 0.0062803770415484905f, 0.008289426565170288f, 0.00667787017300725f, 0.00689090508967638f, 0.0071791610680520535f, 0.011583162471652031f, 0.008071943186223507f, 0.01362383458763361f, 0.004455354064702988f, 0.008374560624361038f, 0.013650860637426376f, 0.009935509413480759f, 0.011500054970383644f, 0.007842360064387321f, 0.006918682251125574f, 0.013461902737617493f, 0.007041476666927338f, 0.01068202592432499f, 0.007889158092439175f, 0.010129787027835846f, 0.008237442933022976f, 0.007887347601354122f, 0.011425179429352283f, 0.005898743402212858f, 0.023822808638215065f, 0.00649083498865366f, 0.006998520344495773f, 0.006639172323048115f, 0.012208269909024239f, 0.007459633052349091f, 0.013990098610520363f, 0.00919384602457285f, 0.0068167708814144135f, 0.01553130429238081f, 0.010270226746797562f, 0.007637948729097843f, 0.00673260074108839f, 0.023272639140486717f, 0.007651476189494133f, 0.015632441267371178f, 0.006731819827109575f, 0.005749623291194439f, 0.011277812533080578f, 0.012805907987058163f, 0.01287043746560812f, 0.00635422533378005f, 0.008302305825054646f, 0.013628876768052578f, 0.00540172029286623f, 0.00732958922162652f, 0.00697786919772625f, 0.012960901483893394f, 0.011796402744948864f, 0.010147732682526112f, 0.00955734308809042f, 0.009502249769866467f, 0.01005375012755394f, 0.006486963946372271f, 0.007284797262400389f, 0.01273361686617136f, 0.008361978456377983f, 0.008092052303254604f, 0.0078429589048028f, 0.005486597307026386f, 0.008810876868665218f, 0.012425375171005726f, 0.0030526325572282076f, 0.006581653840839863f, 0.008401637896895409f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024232944997493178f, 0.00016249406326096505f, 0.00022729129705112427f, 0.00014105363516137004f, 0.0001336112036369741f, 0.00018938249559141695f, 0.00017037145153153688f, 0.00016060429334174842f, 0.00012501327728386968f, 0.00013247720198705792f, 0.00018740718951448798f, 0.00010752044181572273f, 0.00014227660722099245f, 0.00020872677851002663f, 0.0002085109008476138f, 0.00015469553181901574f, 0.00024498210404999554f, 0.0001564406993566081f, 0.00021184069919399917f, 0.00023011943267192692f, 0.0002919937833212316f, 0.00020745462097693235f, 0.00014038792869541794f, 0.0002669013920240104f, 0.00018605811055749655f, 0.00020892567408736795f, 0.00015849732153583318f, 0.00014171827933751047f, 0.00015797215746715665f, 0.0002756817848421633f, 0.0002601707528810948f, 0.00025691790506243706f, 0.00018382625421509147f, 0.0002006406575674191f, 0.00013286512694321573f, 0.00023622647859156132f, 0.00015205558156594634f, 0.0002827821299433708f, 0.00020837277406826615f, 0.0001303745957557112f, 0.00019835941202472895f, 0.0001690886274445802f, 0.00017292183474637568f, 0.0002570976212155074f, 0.00012033061648253351f, 7.726369221927598e-05f, 9.422183939022943e-05f, 0.00018692291632760316f, 0.0001623369025764987f, 0.00020305992802605033f, 0.0001934852625709027f, 6.348200258798897e-05f, 0.00014683464542031288f, 0.00015103108307812363f, 0.0001639471884118393f, 0.00024859889526851475f, 0.0002029145252890885f, 0.00012079236330464482f, 0.00013133761240169406f, 0.00021252589067444205f, 0.00011448680743342265f, 0.00015623599756509066f, 0.0001360978785669431f, 0.00015705359692219645f, 0.0001121788882301189f, 0.00018030831415671855f, 7.930785795906559e-05f, 0.00020378903718665242f, 0.0001842881611082703f, 0.00016194699855986983f, 0.0001968202559510246f, 9.59796307142824e-05f, 0.00017096949159167707f, 0.00011228595394641161f, 0.00017969770124182105f, 0.00022432875994127244f, 0.00020182163279969245f, 0.0002696657320484519f, 0.00018489290960133076f, 0.00018680145149119198f, 0.00014404077955987304f, 0.0001563513360451907f, 0.00012923794565722346f, 0.00013784760085400194f, 0.00014764428487978876f, 0.00019138927746098489f, 0.0002166953927371651f, 0.00020231549569871277f, 0.0001760127634042874f, 0.0001352413382846862f, 0.0002536676765885204f, 0.0001617686211830005f, 0.00016176924691535532f, 0.0002133238158421591f, 0.0002457544323988259f, 0.00013715757813770324f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002622798550873995f, 0.0017587181646376848f, 0.002460036426782608f, 0.001526662497781217f, 0.0014461108949035406f, 0.002049739006906748f, 0.001843977253884077f, 0.0017382646910846233f, 0.0013530532596632838f, 0.0014338373439386487f, 0.0020283597987145185f, 0.001163723412901163f, 0.0015398990362882614f, 0.0022591075394302607f, 0.002256771083921194f, 0.001674312399700284f, 0.0026515088975429535f, 0.001693200902082026f, 0.0022928104735910892f, 0.002490646205842495f, 0.0031603295356035233f, 0.0022453386336565018f, 0.0015194573206827044f, 0.002888747490942478f, 0.0020137582905590534f, 0.0022612602915614843f, 0.0017154603265225887f, 0.0015338561497628689f, 0.0017097763484343886f, 0.002983780112117529f, 0.0028158999048173428f, 0.0027806933503597975f, 0.001989602344110608f, 0.002171589294448495f, 0.001438035978935659f, 0.002556744497269392f, 0.001645739539526403f, 0.0030606291256844997f, 0.0022552760783582926f, 0.0014110802439972758f, 0.0021468987688422203f, 0.0018300929805263877f, 0.001871580840088427f, 0.0027826386503875256f, 0.0013023715000599623f, 0.0008362462976947427f, 0.0010197890223935246f, 0.0020231183152645826f, 0.0017570172203704715f, 0.0021977736614644527f, 0.002094144467264414f, 0.0006870832876302302f, 0.001589232007972896f, 0.001634651212953031f, 0.0017744457582011819f, 0.002690654480829835f, 0.0021961999591439962f, 0.0013073690934106708f, 0.0014215032570064068f, 0.0023002263624221087f, 0.0012391223572194576f, 0.0016909852856770158f, 0.0014730249531567097f, 0.0016998344799503684f, 0.0012141431216150522f, 0.0019515266176313162f, 0.0008583708549849689f, 0.0022056649904698133f, 0.001994601683691144f, 0.0017527970485389233f, 0.0021302399691194296f, 0.0010388140799477696f, 0.0018504500621929765f, 0.0012153019197285175f, 0.001944917836226523f, 0.0024279721546918154f, 0.002184371231123805f, 0.0029186666943132877f, 0.0020011470187455416f, 0.002021803753450513f, 0.0015589931281283498f, 0.0016922337235882878f, 0.0013987779384478927f, 0.0014919626992195845f, 0.001597994938492775f, 0.0020714590791612864f, 0.002345354063436389f, 0.0021897165570408106f, 0.0019050347618758678f, 0.0014637543354183435f, 0.0027455154340714216f, 0.0017508665332570672f, 0.0017508732853457332f, 0.002308862516656518f, 0.0026598682161420584f, 0.001484494423493743f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00022147796698845923f, 0.0001969320437638089f, 0.0003329132741782814f, 0.00024038799165282398f, 0.00019379756122361869f, 0.0002524387091398239f, 0.00022593243920709938f, 0.0002385802217759192f, 0.00024725953699089587f, 0.00021813991770613939f, 0.00020770679111592472f, 0.0002537560067139566f, 0.0002609401708468795f, 0.0001966255804290995f, 0.0002211707178503275f, 0.0001741718006087467f, 0.0002162302116630599f, 0.00022046099184080958f, 0.00026037872885353863f, 0.00021666704560630023f, 0.00023029264411889017f, 0.00025445138453505933f, 0.0001829069951782003f, 0.0003118387539871037f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002428059931844473f, 0.002158963354304433f, 0.0036497237160801888f, 0.0026353702414780855f, 0.002124600112438202f, 0.0027674823068082333f, 0.002476894296705723f, 0.002615551697090268f, 0.0027107028290629387f, 0.0023914650082588196f, 0.0022770867217332125f, 0.0027819236274808645f, 0.0028606837149709463f, 0.0021556036081165075f, 0.0024246915709227324f, 0.0019094430608674884f, 0.0023705288767814636f, 0.0024169108364731073f, 0.0028545286040753126f, 0.00237531797029078f, 0.002524695126339793f, 0.0027895469684153795f, 0.002005206886678934f, 0.0034186840057373047f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00035739567829295993f, 0.00035588647006079555f, 0.0002719939511734992f, 0.00046423843014054f, 0.0010292388033121824f, 0.00025493622524663806f, 0.0002645551576279104f, 0.0005498101818375289f, 0.0004526266420725733f, 0.0006287784781306982f, 0.0003823362058028579f, 0.0007306247716769576f, 0.0005706896772608161f, 0.0009830424096435308f, 0.0005797051126137376f, 0.0002487243036739528f, 0.0004255505627952516f, 0.00042987539200112224f, 0.0008064459543675184f, 0.00039664743235334754f, 0.00039332822780124843f, 0.0005809931899420917f, 0.000416634778957814f, 0.0004546157142613083f, 0.0007558333454653621f, 0.00042376347118988633f, 0.00044746676576323807f, 0.0005006362916901708f, 0.0011870060116052628f, 0.00048543696175329387f, 0.0004745747719425708f, 0.00018087384523823857f, 0.0005751251010224223f, 0.00034314097138121724f, 0.00032256238046102226f, 0.0005073005449958146f, 0.0005723385256715119f, 0.0002697362215258181f, 0.00047271352377720177f, 0.0004344925400801003f, 0.0002628312795422971f, 0.001392199657857418f, 0.00029177378746680915f, 0.00044910397264175117f, 0.0004418186435941607f, 0.0005256401491351426f, 0.0003275194903835654f, 0.0002495793451089412f, 0.0004069821152370423f, 0.00033516765688546f, 0.0002552049118094146f, 0.0008694856078363955f, 0.0009503475157544017f, 0.0003006054030265659f, 0.000760342285502702f, 0.00031681580003350973f, 0.00044454445014707744f, 0.0005401466623879969f, 0.00037618912756443024f, 0.00025097891921177506f, 0.0008169559296220541f, 0.0005576445255428553f, 0.0006041196174919605f, 0.0004806893994100392f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00701016653329134f, 0.0069805639795959f, 0.0053350478410720825f, 0.009105842560529709f, 0.020188087597489357f, 0.005000467412173748f, 0.005189138930290937f, 0.010784297250211239f, 0.008878082036972046f, 0.012333226390182972f, 0.007499364670366049f, 0.014330899342894554f, 0.011193838901817799f, 0.019281964749097824f, 0.011370673775672913f, 0.004878622945398092f, 0.008346996270120144f, 0.008431825786828995f, 0.015818100422620773f, 0.007780073210597038f, 0.007714968640357256f, 0.011395938694477081f, 0.008172117173671722f, 0.008917097002267838f, 0.014825355261564255f, 0.008311943151056767f, 0.008776873350143433f, 0.00981977116316557f, 0.023282626643776894f, 0.009521642699837685f, 0.00930858589708805f, 0.0035477648489177227f, 0.011280838400125504f, 0.00673056673258543f, 0.006326925940811634f, 0.0099504878744483f, 0.01122618094086647f, 0.005290762986987829f, 0.009272078052163124f, 0.008522389456629753f, 0.0051553258672356606f, 0.027307413518428802f, 0.005723020993173122f, 0.008808986283838749f, 0.008666087873280048f, 0.010310211218893528f, 0.006424157880246639f, 0.004895394667983055f, 0.007982783950865269f, 0.006574173457920551f, 0.005005737766623497f, 0.017054596915841103f, 0.01864066906273365f, 0.005896249320358038f, 0.014913796447217464f, 0.006214209366589785f, 0.008719553239643574f, 0.010594750754535198f, 0.007378792390227318f, 0.004922846332192421f, 0.01602424867451191f, 0.010937963612377644f, 0.01184955332428217f, 0.009428521618247032f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006337777012959123f, 0.0003110565594397485f, 0.00031964792287908494f, 0.0003013912937603891f, 3.862374069285579e-05f, 0.0006415018578991294f, 0.00047751894453540444f, 0.0002009507006732747f, 0.0003408144984859973f, 0.0002900285762734711f, 0.0001801603939384222f, 0.00035484222462400794f, 0.0003354303480591625f, 0.00025538550107739866f, 0.0006079844897612929f, 0.0003970711841247976f, 0.00029625650495290756f, 0.0003788562898989767f, 0.0002960795827675611f, 0.00042420122190378606f, 0.00037454700213856995f, 0.00028667395235970616f, 0.00046404413296841085f, 0.0004445927916094661f, 0.00036863956484012306f, 0.000302869884762913f, 0.00044811199768446386f, 0.000232985956245102f, 0.00040140069904737175f, 0.00026751108816824853f, 0.00033866666490212083f, 0.0003348857571836561f, 0.00014340761117637157f, 0.0005210649687796831f, 0.0004297399427741766f, 0.0003129507240373641f, 0.00030600986792705953f, 0.00030647049425169826f, 0.00033972179517149925f, 0.00044436927419155836f, 0.0004121158563066274f, 0.0001600296382093802f, 0.0005208357470110059f, 0.0003827282052952796f, 0.00029307426302693784f, 0.00029174049268476665f, 0.0003388022887520492f, 0.00045432898332364857f, 0.0003688506840262562f, 0.0003203290980309248f, 0.0003374517254997045f, 0.00040372152579948306f, 0.00038530409801751375f, 0.0002506630262359977f, 0.000541950692422688f, 0.0004952527233399451f, 0.000421159464167431f, 0.0003635537577793002f, 0.00039448903407901525f, 0.0005805938271805644f, 0.00041565566789358854f, 0.0004174122295808047f, 0.0003162311913911253f, 0.00024928757920861244f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039189597591757774f, 0.001923415926285088f, 0.001976540545001626f, 0.00186365086119622f, 0.00023882961249910295f, 0.003966722171753645f, 0.0029527349397540092f, 0.0012425772147253156f, 0.0021074239630252123f, 0.0017933895578607917f, 0.0011140204733237624f, 0.0021941643208265305f, 0.002074131043627858f, 0.00157917442265898f, 0.0037594677414745092f, 0.002455286681652069f, 0.0018318998627364635f, 0.0023426550906151533f, 0.0018308059079572558f, 0.0026230451185256243f, 0.0023160085547715425f, 0.0017726462101563811f, 0.0028694134671241045f, 0.002749136183410883f, 0.0022794799879193306f, 0.00187279365491122f, 0.0027708972338587046f, 0.0014406669652089477f, 0.002482058247551322f, 0.0016541527584195137f, 0.0020941428374499083f, 0.0020707636140286922f, 0.0008867598953656852f, 0.003222001250833273f, 0.0026572938077151775f, 0.001935128471814096f, 0.0018922097515314817f, 0.0018950579687952995f, 0.002100667217746377f, 0.0027477541007101536f, 0.002548315329477191f, 0.0009895421098917723f, 0.003220584010705352f, 0.0023665970657020807f, 0.0018122225301340222f, 0.0018039752030745149f, 0.0020949814934283495f, 0.002809339901432395f, 0.002280785469338298f, 0.001980752684175968f, 0.0020866303239017725f, 0.002496408997103572f, 0.002382525010034442f, 0.0015499730361625552f, 0.003351147985085845f, 0.0030623916536569595f, 0.0026042363606393337f, 0.0022480320185422897f, 0.0024393200874328613f, 0.003590097650885582f, 0.0025702037382870913f, 0.002581065520644188f, 0.0019554132595658302f, 0.001541467965580523f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000312082062009722f, 0.0002567945048213005f, 0.00021444857702590525f, 0.00022763755987398326f, 0.00022480193001683801f, 0.00026965426513925195f, 0.0002492543717380613f, 0.0003154645673930645f, 0.00022724292648490518f, 0.0002731863351073116f, 0.0002944384468719363f, 0.00025677194935269654f, 0.0002610621741041541f, 0.00028385783662088215f, 0.0002500400005374104f, 0.00029786606319248676f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006121104583144188f, 0.005036707501858473f, 0.004206144250929356f, 0.004464829806238413f, 0.004409212619066238f, 0.005288935732096434f, 0.004888816736638546f, 0.006187448278069496f, 0.004457089584320784f, 0.005358213093131781f, 0.00577504700049758f, 0.0050362651236355305f, 0.0051204124465584755f, 0.005567521322518587f, 0.004904226399958134f, 0.0058422754518687725f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008608089992776513f, 0.0004959614016115665f, 0.00031901136389933527f, 0.0009738759836181998f, 0.0009925911435857415f, 0.0004102058010175824f, 0.00038251173100434244f, 0.0006039791624061763f, 0.0004114246112294495f, 0.0006078930455259979f, 0.0004172670014668256f, 0.0005220149178057909f, 0.00039187780930660665f, 0.00034468245576135814f, 0.00031564669916406274f, 0.00042522946023382246f, 0.0004941184306517243f, 0.00048585046897642314f, 0.0009067695937119424f, 0.0003234632022213191f, 0.0007335252012126148f, 0.00039346289122477174f, 0.0005172939272597432f, 0.0009748978191055357f, 0.0008210946107283235f, 0.00032856801408343017f, 0.001368312630802393f, 0.0008162842714227736f, 0.001056636101566255f, 0.0008856847998686135f, 0.0004109664005227387f, 0.0009106057113967836f, 0.0006630739662796259f, 0.0009787388844415545f, 0.0007866009254939854f, 0.0005417458596639335f, 0.0005273079150356352f, 0.0005423235124908388f, 0.00038899388164281845f, 0.0008916788501664996f, 0.0004792282124981284f, 0.0010079569183290005f, 0.0005536667886190116f, 0.0003451693628448993f, 0.0006789615727029741f, 0.0002719589392654598f, 0.0003429249336477369f, 0.0010174885392189026f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01755869947373867f, 0.010116573423147202f, 0.006507163401693106f, 0.01986502856016159f, 0.020246779546141624f, 0.008367338217794895f, 0.007802437525242567f, 0.012319909408688545f, 0.008392199873924255f, 0.012399743311107159f, 0.008511371910572052f, 0.010648010298609734f, 0.007993485778570175f, 0.0070307995192706585f, 0.00643853098154068f, 0.008673789910972118f, 0.010078979656100273f, 0.00991033110767603f, 0.018496198579669f, 0.006597971543669701f, 0.014962377026677132f, 0.0080258185043931f, 0.010551711544394493f, 0.019885871559381485f, 0.016748609021306038f, 0.0067020985297858715f, 0.027910709381103516f, 0.01665048860013485f, 0.0215531624853611f, 0.01806611381471157f, 0.008382853120565414f, 0.01857444830238819f, 0.013525319285690784f, 0.019964221864938736f, 0.016045009717345238f, 0.011050480417907238f, 0.010755976662039757f, 0.011062262579798698f, 0.007934659719467163f, 0.01818837970495224f, 0.009775251150131226f, 0.020560208708047867f, 0.011293642222881317f, 0.007040731608867645f, 0.013849393464624882f, 0.0055473921820521355f, 0.006994949653744698f, 0.020754633471369743f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024940294679254293f, 0.0004845143121201545f, 0.00016395804414059967f, 0.0001479243510402739f, 0.00029648307827301323f, 0.0004184599092695862f, 0.00029611060745082796f, 0.0001817060256144032f, 0.0003690882003866136f, 0.0004482745425775647f, 0.00041443260852247477f, 0.000423293502535671f, 0.00034831519587896764f, 0.0003961262118536979f, 0.0005446824943646789f, 0.00021308749273885041f, 0.0004038900078739971f, 0.0001800828758860007f, 0.0001123683323385194f, 0.0006686112028546631f, 0.0002457042573951185f, 0.0002223428600700572f, 0.00021567265503108501f, 0.00015301381063181907f, 0.0002631079696584493f, 0.00022150948643684387f, 0.0002311259595444426f, 0.0002749952836893499f, 0.0002248442469863221f, 0.0002558753767516464f, 0.0002258675085613504f, 0.00022599799558520317f, 0.00030802952824160457f, 0.00038742853212170303f, 0.00029224829631857574f, 0.00029897596687078476f, 0.00028092795400880277f, 0.00027875471278093755f, 0.0002697885793168098f, 0.00018573104171082377f, 0.0002842081885319203f, 0.00015788392920512706f, 0.0003848959458991885f, 0.0004909783601760864f, 0.00030710402643308043f, 0.0006655098986811936f, 0.0005663035553880036f, 0.00022988172713667154f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002484867349267006f, 0.004827343858778477f, 0.0016335572581738234f, 0.0014738093595951796f, 0.002953939139842987f, 0.004169226624071598f, 0.002950228052213788f, 0.001810385030694306f, 0.003677322994917631f, 0.004466277547180653f, 0.004129101522266865f, 0.004217384848743677f, 0.0034703563433140516f, 0.0039467099122703075f, 0.005426815245300531f, 0.002123046899214387f, 0.004024062771350145f, 0.0017942131962627172f, 0.0011195553233847022f, 0.006661549676209688f, 0.0024480163119733334f, 0.0022152606397867203f, 0.0021488035563379526f, 0.0015245169633999467f, 0.002621414139866829f, 0.002206957433372736f, 0.002302768873050809f, 0.0027398504316806793f, 0.002240182599052787f, 0.0025493537541478872f, 0.002250377554446459f, 0.002251677680760622f, 0.003068979363888502f, 0.003860052675008774f, 0.0029117469675838947f, 0.0029787765815854073f, 0.002798959380015731f, 0.002777306828647852f, 0.0026879748329520226f, 0.001850487431511283f, 0.0028316411189734936f, 0.0015730392187833786f, 0.0038348198868334293f, 0.004891746677458286f, 0.0030597583390772343f, 0.006630650721490383f, 0.005642232019454241f, 0.002290372271090746f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005099319387227297f, 0.0005048680468462408f, 0.0005087577737867832f, 0.0006544010248035192f, 0.0005860232631675899f, 0.000864253262989223f, 0.0006010183715261519f, 0.0005738313775509596f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013940875651314855f, 0.0013802435714751482f, 0.0013908776454627514f, 0.001789047266356647f, 0.0016021113842725754f, 0.002362756058573723f, 0.0016431061085313559f, 0.0015687803970649838f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010849470272660255f, 0.001989759271964431f, 0.0012615761952474713f, 0.0016183647094294429f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006041442509740591f, 0.011079818941652775f, 0.007024988066405058f, 0.009011737070977688f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002531829522922635f, 0.003142787842079997f, 0.0021717941854149103f, 0.00030077717383392155f, 0.0004460700729396194f, 0.0008571568760089576f, 0.0005437009385786951f, 0.0005586101324297488f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018303140997886658f, 0.022719889879226685f, 0.015700368210673332f, 0.0021743830293416977f, 0.0032247365452349186f, 0.006196571514010429f, 0.0039305309765040874f, 0.004038312938064337f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010115387849509716f, 0.0010032961145043373f, 0.0004973285831511021f, 0.0013949546264484525f, 0.0018949905643239617f, 0.0010052173165604472f, 0.0017460003728047013f, 0.0013135066255927086f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0054359096102416515f, 0.00539161404594779f, 0.0026725945062935352f, 0.007496348582208157f, 0.010183491744101048f, 0.00540193822234869f, 0.00938283372670412f, 0.00705865491181612f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003884121251758188f, 0.0003967556986026466f, 7.975192420417443e-05f, 0.0003102883347310126f, 0.0003604334488045424f, 0.0005087326862849295f, 9.256566409021616e-05f, 0.00023570755729451776f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09904508292675018f, 0.10117270052433014f, 0.020336739718914032f, 0.07912351936101913f, 0.09191052615642548f, 0.1297268271446228f, 0.023604242131114006f, 0.060105424374341965f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1860845535993576f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.13832759857177734f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1795841008424759f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.36578184366226196f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10036871582269669f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04902464523911476f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05098459869623184f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1145080178976059f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1617209017276764f),
    AI_PACK_INTQ_ZP(-31)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05098247900605202f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09121602028608322f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09239346534013748f),
    AI_PACK_INTQ_ZP(23)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03133878856897354f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.036327067762613297f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05706173926591873f),
    AI_PACK_INTQ_ZP(16)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10248114913702011f),
    AI_PACK_INTQ_ZP(26)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02970569208264351f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.042922716587781906f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07683120667934418f),
    AI_PACK_INTQ_ZP(-19)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1269119828939438f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.026886865496635437f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05390758067369461f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10345343500375748f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1834053248167038f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1834525614976883f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0308077372610569f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.054984770715236664f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06005934253334999f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04666819050908089f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1617593914270401f),
    AI_PACK_INTQ_ZP(31)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1424, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1424, 1424),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2816, 2816),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_36_scratch0_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1632, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1632, 1632),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 496, 1, 1), AI_STRIDE_INIT(4, 1, 1, 496, 496),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 736, 1, 1), AI_STRIDE_INIT(4, 1, 1, 736, 736),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 832, 1, 1), AI_STRIDE_INIT(4, 1, 1, 832, 832),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 72, 1, 1), AI_STRIDE_INIT(4, 1, 1, 72, 72),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 297, 1, 1), AI_STRIDE_INIT(4, 1, 1, 297, 297),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 1, 1, 112, 112),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 292, 1, 1), AI_STRIDE_INIT(4, 1, 1, 292, 292),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 40, 1, 1), AI_STRIDE_INIT(4, 4, 4, 160, 160),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 40), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_39_weights_array, &conv2d_39_weights_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_38_bias_array, &conv2d_38_bias_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 256), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_38_weights_array, &conv2d_38_weights_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_37_bias_array, &conv2d_37_bias_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_37_weights_array, &conv2d_37_weights_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_36_bias_array, &conv2d_36_bias_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_36_weights_array, &conv2d_36_weights_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_34_bias_array, &conv2d_34_bias_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 88, 1, 1, 128), AI_STRIDE_INIT(4, 1, 88, 88, 88),
  1, &conv2d_34_weights_array, &conv2d_34_weights_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_29_bias_array, &conv2d_29_bias_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_29_weights_array, &conv2d_29_weights_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_24_bias_array, &conv2d_24_bias_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_24_weights_array, &conv2d_24_weights_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_20_bias_array, &conv2d_20_bias_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_20_weights_array, &conv2d_20_weights_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 24), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 64), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 4, 3, 3, 8), AI_STRIDE_INIT(4, 1, 4, 12, 36),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 4), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 3, 3, 1), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 8), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 1, 1, 3, 9),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  image_input_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 160, 160), AI_STRIDE_INIT(4, 4, 4, 4, 640),
  1, &image_input_output_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 160, 160), AI_STRIDE_INIT(4, 1, 1, 1, 160),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 80, 80), AI_STRIDE_INIT(4, 1, 1, 8, 640),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 80, 80), AI_STRIDE_INIT(4, 1, 1, 8, 640),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 40, 40), AI_STRIDE_INIT(4, 1, 1, 8, 320),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 40, 40), AI_STRIDE_INIT(4, 1, 1, 4, 160),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 20, 20), AI_STRIDE_INIT(4, 1, 1, 8, 160),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 20), AI_STRIDE_INIT(4, 1, 1, 48, 960),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 20), AI_STRIDE_INIT(4, 1, 1, 48, 960),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 20, 20), AI_STRIDE_INIT(4, 1, 1, 16, 320),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  concat_14_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 20, 20), AI_STRIDE_INIT(4, 1, 1, 24, 480),
  1, &concat_14_output_array, &concat_14_output_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_20_output_array, &conv2d_20_output_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_22_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_22_output_array, &eltwise_22_output_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_24_output_array, &conv2d_24_output_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_26_output_array, &eltwise_26_output_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_29_output_array, &conv2d_29_output_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_30_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_30_output_array, &eltwise_30_output_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  concat_33_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 88, 10, 10), AI_STRIDE_INIT(4, 1, 1, 88, 880),
  1, &concat_33_output_array, &concat_33_output_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_34_output_array, &conv2d_34_output_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_36_output_array, &conv2d_36_output_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 5, 5), AI_STRIDE_INIT(4, 1, 1, 64, 320),
  1, &conv2d_37_output_array, &conv2d_37_output_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 5, 5), AI_STRIDE_INIT(4, 1, 1, 256, 1280),
  1, &conv2d_38_output_array, &conv2d_38_output_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 40, 5, 5), AI_STRIDE_INIT(4, 1, 1, 40, 200),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conversion_40_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 40, 5, 5), AI_STRIDE_INIT(4, 4, 4, 160, 800),
  1, &conversion_40_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &image_input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &conversion_0_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC,
  .tensors = &conv2d_3_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC,
  .tensors = &conv2d_5_chain, 
  .groups = 8, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC,
  .tensors = &conv2d_6_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC,
  .tensors = &conv2d_8_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC,
  .tensors = &conv2d_9_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC,
  .tensors = &conv2d_10_chain, 
  .groups = 48, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &concat_14_layer, AI_STATIC,
  .tensors = &conv2d_11_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_output, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_14_layer, 14,
  CONCAT_TYPE,
  concat, forward_concat,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC,
  .tensors = &concat_14_chain, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC,
  .tensors = &conv2d_15_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC,
  .tensors = &conv2d_17_chain, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC,
  .tensors = &conv2d_18_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 19,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_20_layer, AI_STATIC,
  .tensors = &conv2d_19_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 20,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC,
  .tensors = &conv2d_20_chain, 
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &eltwise_22_layer, AI_STATIC,
  .tensors = &conv2d_21_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_18_output, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_22_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_22_layer, 22,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC,
  .tensors = &eltwise_22_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_24_layer, AI_STATIC,
  .tensors = &conv2d_23_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC,
  .tensors = &conv2d_24_chain, 
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 25,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &eltwise_26_layer, AI_STATIC,
  .tensors = &conv2d_25_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_22_output, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_26_layer, 26,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC,
  .tensors = &eltwise_26_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC,
  .tensors = &conv2d_27_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_29_layer, AI_STATIC,
  .tensors = &conv2d_28_chain, 
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 29,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &eltwise_30_layer, AI_STATIC,
  .tensors = &conv2d_29_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_26_output, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_30_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_30_layer, 30,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &concat_33_layer, AI_STATIC,
  .tensors = &eltwise_30_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_30_output, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_33_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_33_layer, 33,
  CONCAT_TYPE,
  concat, forward_concat,
  &AI_NET_OBJ_INSTANCE, &conv2d_34_layer, AI_STATIC,
  .tensors = &concat_33_chain, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 34,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC,
  .tensors = &conv2d_34_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 36,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_37_layer, AI_STATIC,
  .tensors = &conv2d_36_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 37,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_38_layer, AI_STATIC,
  .tensors = &conv2d_37_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_38_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 38,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_39_layer, AI_STATIC,
  .tensors = &conv2d_38_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_39_weights, &conv2d_39_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_39_layer, 39,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conversion_40_layer, AI_STATIC,
  .tensors = &conv2d_39_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_40_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_40_layer, 40,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &conversion_40_layer, AI_STATIC,
  .tensors = &conversion_40_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 75664, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 53116, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PERSON_YOLO_IN_NUM, &image_input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PERSON_YOLO_OUT_NUM, &conversion_40_output),
  &conversion_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool person_yolo_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_PERSON_YOLO_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_39_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_39_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_38_scratch0_array.data = AI_PTR(activations + 2752);
    conv2d_38_scratch0_array.data_start = AI_PTR(activations + 2752);
    conv2d_37_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_36_scratch0_array.data = AI_PTR(activations + 14432);
    conv2d_36_scratch0_array.data_start = AI_PTR(activations + 14432);
    conv2d_34_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_34_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 23172);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 23172);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_24_scratch0_array.data = AI_PTR(activations + 8772);
    conv2d_24_scratch0_array.data_start = AI_PTR(activations + 8772);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_20_scratch0_array.data = AI_PTR(activations + 20772);
    conv2d_20_scratch0_array.data_start = AI_PTR(activations + 20772);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 23232);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 23232);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 12800);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 12800);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 51528);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 51528);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 52176);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 52176);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 52824);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 52824);
    image_input_output_array.data = AI_PTR(NULL);
    image_input_output_array.data_start = AI_PTR(NULL);
    conversion_0_output_array.data = AI_PTR(activations + 27224);
    conversion_0_output_array.data_start = AI_PTR(activations + 27224);
    conv2d_2_output_array.data = AI_PTR(activations + 976);
    conv2d_2_output_array.data_start = AI_PTR(activations + 976);
    conv2d_3_output_array.data = AI_PTR(activations + 328);
    conv2d_3_output_array.data_start = AI_PTR(activations + 328);
    conv2d_5_output_array.data = AI_PTR(activations + 0);
    conv2d_5_output_array.data_start = AI_PTR(activations + 0);
    conv2d_6_output_array.data = AI_PTR(activations + 12872);
    conv2d_6_output_array.data_start = AI_PTR(activations + 12872);
    conv2d_8_output_array.data = AI_PTR(activations + 832);
    conv2d_8_output_array.data_start = AI_PTR(activations + 832);
    conv2d_9_output_array.data = AI_PTR(activations + 4032);
    conv2d_9_output_array.data_start = AI_PTR(activations + 4032);
    conv2d_10_output_array.data = AI_PTR(activations + 25012);
    conv2d_10_output_array.data_start = AI_PTR(activations + 25012);
    conv2d_11_output_array.data = AI_PTR(activations + 4032);
    conv2d_11_output_array.data_start = AI_PTR(activations + 4032);
    concat_14_output_array.data = AI_PTR(activations + 10432);
    concat_14_output_array.data_start = AI_PTR(activations + 10432);
    conv2d_15_output_array.data = AI_PTR(activations + 20032);
    conv2d_15_output_array.data_start = AI_PTR(activations + 20032);
    conv2d_17_output_array.data = AI_PTR(activations + 2372);
    conv2d_17_output_array.data_start = AI_PTR(activations + 2372);
    conv2d_18_output_array.data = AI_PTR(activations + 8772);
    conv2d_18_output_array.data_start = AI_PTR(activations + 8772);
    conv2d_19_output_array.data = AI_PTR(activations + 11172);
    conv2d_19_output_array.data_start = AI_PTR(activations + 11172);
    conv2d_20_output_array.data = AI_PTR(activations + 24328);
    conv2d_20_output_array.data_start = AI_PTR(activations + 24328);
    conv2d_21_output_array.data = AI_PTR(activations + 11172);
    conv2d_21_output_array.data_start = AI_PTR(activations + 11172);
    eltwise_22_output_array.data = AI_PTR(activations + 13572);
    eltwise_22_output_array.data_start = AI_PTR(activations + 13572);
    conv2d_23_output_array.data = AI_PTR(activations + 15972);
    conv2d_23_output_array.data_start = AI_PTR(activations + 15972);
    conv2d_24_output_array.data = AI_PTR(activations + 25572);
    conv2d_24_output_array.data_start = AI_PTR(activations + 25572);
    conv2d_25_output_array.data = AI_PTR(activations + 8772);
    conv2d_25_output_array.data_start = AI_PTR(activations + 8772);
    eltwise_26_output_array.data = AI_PTR(activations + 11172);
    eltwise_26_output_array.data_start = AI_PTR(activations + 11172);
    conv2d_27_output_array.data = AI_PTR(activations + 13572);
    conv2d_27_output_array.data_start = AI_PTR(activations + 13572);
    conv2d_28_output_array.data = AI_PTR(activations + 26728);
    conv2d_28_output_array.data_start = AI_PTR(activations + 26728);
    conv2d_29_output_array.data = AI_PTR(activations + 8772);
    conv2d_29_output_array.data_start = AI_PTR(activations + 8772);
    eltwise_30_output_array.data = AI_PTR(activations + 13572);
    eltwise_30_output_array.data_start = AI_PTR(activations + 13572);
    concat_33_output_array.data = AI_PTR(activations + 15972);
    concat_33_output_array.data_start = AI_PTR(activations + 15972);
    conv2d_34_output_array.data = AI_PTR(activations + 1632);
    conv2d_34_output_array.data_start = AI_PTR(activations + 1632);
    conv2d_36_output_array.data = AI_PTR(activations + 19172);
    conv2d_36_output_array.data_start = AI_PTR(activations + 19172);
    conv2d_37_output_array.data = AI_PTR(activations + 1152);
    conv2d_37_output_array.data_start = AI_PTR(activations + 1152);
    conv2d_38_output_array.data = AI_PTR(activations + 5568);
    conv2d_38_output_array.data_start = AI_PTR(activations + 5568);
    conv2d_39_output_array.data = AI_PTR(activations + 1424);
    conv2d_39_output_array.data_start = AI_PTR(activations + 1424);
    conversion_40_output_array.data = AI_PTR(NULL);
    conversion_40_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool person_yolo_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv2d_39_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_bias_array.data = AI_PTR(weights + 75504);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 75504);
    conv2d_39_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_weights_array.data = AI_PTR(weights + 65264);
    conv2d_39_weights_array.data_start = AI_PTR(weights + 65264);
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(weights + 64240);
    conv2d_38_bias_array.data_start = AI_PTR(weights + 64240);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(weights + 47856);
    conv2d_38_weights_array.data_start = AI_PTR(weights + 47856);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(weights + 47600);
    conv2d_37_bias_array.data_start = AI_PTR(weights + 47600);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(weights + 39408);
    conv2d_37_weights_array.data_start = AI_PTR(weights + 39408);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(weights + 38896);
    conv2d_36_bias_array.data_start = AI_PTR(weights + 38896);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(weights + 37744);
    conv2d_36_weights_array.data_start = AI_PTR(weights + 37744);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(weights + 37232);
    conv2d_34_bias_array.data_start = AI_PTR(weights + 37232);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(weights + 25968);
    conv2d_34_weights_array.data_start = AI_PTR(weights + 25968);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(weights + 25872);
    conv2d_29_bias_array.data_start = AI_PTR(weights + 25872);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(weights + 23568);
    conv2d_29_weights_array.data_start = AI_PTR(weights + 23568);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 23184);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 23184);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 22320);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 22320);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 21936);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 21936);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 19632);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 19632);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 19536);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 19536);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 17232);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 17232);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 16848);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 16848);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 15984);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 15984);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 15600);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 15600);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 13296);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 13296);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 13200);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 13200);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 10896);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 10896);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 10512);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 10512);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 9648);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 9648);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 9264);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 9264);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 6960);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 6960);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 6864);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 6864);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 5328);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 5328);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 5072);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 5072);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 4496);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 4496);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 4240);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 4240);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 2704);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 2704);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 2640);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 2640);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 1872);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 1872);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 1680);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 1680);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 1248);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 1248);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 1056);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 1056);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 672);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 672);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 640);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 640);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 352);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 352);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 336);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 336);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 304);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 304);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 272);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 272);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 200);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 200);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 168);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 168);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 104);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 104);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 72);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 72);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 0);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_person_yolo_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_PERSON_YOLO_MODEL_NAME,
      .model_signature   = AI_PERSON_YOLO_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 6340364,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_person_yolo_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_person_yolo_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_person_yolo_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_person_yolo_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= person_yolo_configure_weights(net_ctx, &params->params);
  ok &= person_yolo_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_person_yolo_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_person_yolo_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_PERSON_YOLO_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

