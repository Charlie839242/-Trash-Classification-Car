/**
  ******************************************************************************
  * @file    person_yolo.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Oct 30 08:59:35 2021
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
#define AI_PERSON_YOLO_MODEL_SIGNATURE     "9a6dcd784aeb5a7d8cdf309d178a4f0b"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sat Oct 30 08:59:35 2021"

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
  NULL, NULL, 1524, AI_STATIC)

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
  NULL, NULL, 50, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

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
  NULL, NULL, 1250, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conversion_40_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1250, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 50,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.9904644179623574e-05f, 3.187700713169761e-05f, 2.4481834770995192e-05f, 3.393361112102866e-05f, 0.00012944884656462818f, 7.704197923885658e-05f, 8.269007958006114e-05f, 0.00011184591858182102f, 9.283402323490009e-05f, 9.971190593205392e-05f, 3.295972419437021e-05f, 3.809797635767609e-05f, 1.968540163943544e-05f, 2.7855310690938495e-05f, 9.426478936802596e-05f, 7.726089097559452e-05f, 7.727265619905666e-05f, 0.0001500240177847445f, 8.569067722419277e-05f, 9.993631829274818e-05f, 2.6571167836664245e-05f, 2.984048842336051e-05f, 2.4285982362926006e-05f, 3.1048391974763945e-05f, 9.327980660600588e-05f, 8.141178113874048e-05f, 7.593800546601415e-05f, 0.00013189656601753086f, 7.816628931323066e-05f, 9.467075142310932e-05f, 2.3695334675721824e-05f, 3.151415512547828e-05f, 2.7534722903510556e-05f, 2.5570903744664975e-05f, 9.042860619956627e-05f, 7.902724610175937e-05f, 7.229580660350621e-05f, 0.00012691502342931926f, 8.328486001119018e-05f, 8.939637336879969e-05f, 2.0760635379701853e-05f, 3.4713630157057196e-05f, 2.7961683372268453e-05f, 2.5608331270632334e-05f, 0.00014756711607333273f, 7.045515667414293e-05f, 5.722893911297433e-05f, 9.65363797149621e-05f, 6.932333781151101e-05f, 7.09140149410814e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 50,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013519913190975785f, 0.0014411620795726776f, 0.0011068256571888924f, 0.001534141250886023f, 0.005852392874658108f, 0.0034830740187317133f, 0.0037384252063930035f, 0.0050565628334879875f, 0.00419703358784318f, 0.004507983103394508f, 0.001490111812017858f, 0.0017224125331267715f, 0.0008899786043912172f, 0.0012593407882377505f, 0.004261718597263098f, 0.0034929709509015083f, 0.0034935029689222574f, 0.006782597862184048f, 0.003874082351103425f, 0.004518128931522369f, 0.00120128458365798f, 0.0013490908313542604f, 0.0010979712242260575f, 0.0014037002110853791f, 0.004217187408357859f, 0.003680633148178458f, 0.0034331632778048515f, 0.005963054019957781f, 0.0035339039750397205f, 0.004280072171241045f, 0.001071267994120717f, 0.001424757530912757f, 0.0012448469642549753f, 0.0011560625862330198f, 0.004088284447789192f, 0.0035728279035538435f, 0.0032684991601854563f, 0.005737838335335255f, 0.0037653150502592325f, 0.0040416172705590725f, 0.0009385899757035077f, 0.0015694060130044818f, 0.0012641499051824212f, 0.0011577546829357743f, 0.006671520881354809f, 0.0031852831598371267f, 0.0025873249396681786f, 0.004364417400211096f, 0.003134113736450672f, 0.0032060283701866865f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.8231163267046213e-05f, 1.2292020983295515e-05f, 1.7540703993290663e-05f, 1.6776935808593407e-05f, 1.6670677723595873e-05f, 2.5493072826066054e-05f, 1.5583926142426208e-05f, 1.9917804820579477e-05f, 1.7248223230126314e-05f, 1.2111781870771665e-05f, 1.4827165614406113e-05f, 1.772557334334124e-05f, 1.4146674402581993e-05f, 1.738505125103984e-05f, 1.9278284526080824e-05f, 2.4287572159664705e-05f, 1.3311690054251812e-05f, 2.743603181443177e-05f, 1.1051832188968547e-05f, 4.714831447927281e-05f, 1.2384124602249358e-05f, 2.2104901290731505e-05f, 1.7860364096122794e-05f, 1.1395677574910223e-05f, 1.6918549590627663e-05f, 1.9370427253306843e-05f, 2.298853905813303e-05f, 2.2297117538983002e-05f, 1.839656943047885e-05f, 1.1013135917892214e-05f, 1.7390289940522052e-05f, 1.403866281179944e-05f, 2.560835491749458e-05f, 1.3235845472081564e-05f, 4.640021870727651e-05f, 1.430589418305317e-05f, 2.050723196589388e-05f, 1.7525318980915472e-05f, 2.5345605536131188e-05f, 1.3796219718642533e-05f, 1.2294391126488335e-05f, 1.8913749954663217e-05f, 9.556484656059183e-06f, 2.2547897970071062e-05f, 1.0445075531606562e-05f, 2.076091550407e-05f, 1.7534584912937135e-05f, 2.163021417800337e-05f, 1.4470152564172167e-05f, 2.7388627131585963e-05f, 2.7915462851524353e-05f, 1.1974413610005286e-05f, 1.952300954144448e-05f, 2.1001664208597504e-05f, 1.63712084031431e-05f, 2.7911653887713328e-05f, 1.5530382370343432e-05f, 1.4150018614600413e-05f, 1.7860371372080408e-05f, 1.4453682524617761e-05f, 2.1511885279323906e-05f, 2.6852278097067028e-05f, 1.8867584003601223e-05f, 1.4985470443207305e-05f, 1.8930995793198235e-05f, 1.4233423826226499e-05f, 1.7050782844307832e-05f, 2.8335571187199093e-05f, 2.2206149878911674e-05f, 1.5964404155965894e-05f, 1.8232945876661688e-05f, 1.6952981241047382e-05f, 1.2676041478698608e-05f, 1.879593764897436e-05f, 1.3999658222019207e-05f, 1.449041155865416e-05f, 2.4738617867114954e-05f, 1.4170193935569841e-05f, 8.69038649398135e-06f, 1.932185114128515e-05f, 2.9972350603202358e-05f, 1.8249817003379576e-05f, 1.1153063496749382e-05f, 3.083968840655871e-05f, 1.0707161891332362e-05f, 2.4450144337606616e-05f, 1.915309258038178e-05f, 1.325429548160173e-05f, 2.5112747607636265e-05f, 2.2219017409952357e-05f, 1.5013381926110014e-05f, 1.5232019904942717e-05f, 1.62699943757616e-05f, 1.7698053852654994e-05f, 2.5793593522394076e-05f, 1.2482797501434106e-05f, 2.752182263066061e-05f, 4.406681182445027e-05f, 1.5033764611871447e-05f, 1.4087864656175952e-05f, 1.4667140931123868e-05f, 2.673347989912145e-05f, 1.4750715308764484e-05f, 2.007469993259292e-05f, 1.8479773643775843e-05f, 1.7906948414747603e-05f, 2.275534461659845e-05f, 2.352177216380369e-05f, 1.8294544133823365e-05f, 1.1632093446678482e-05f, 3.8349524402292445e-05f, 9.376706657349132e-06f, 3.3201944461325184e-05f, 1.7135287635028362e-05f, 1.8789671230479144e-05f, 1.9028422684641555e-05f, 1.0796519745781552e-05f, 3.359145557624288e-05f, 1.5491559679503553e-05f, 1.1234276826144196e-05f, 1.2784290447598323e-05f, 2.097600190609228e-05f, 1.1079021533078048e-05f, 2.1031588403275236e-05f, 1.665679519646801e-05f, 3.362730785738677e-05f, 2.3721619072603062e-05f, 1.2000719834759366e-05f, 1.6497109754709527e-05f, 1.6944468370638788e-05f, 2.9502105462597683e-05f, 1.3677245078724809e-05f, 1.5597641322528943e-05f, 1.2474144568841439e-05f, 1.6778725694166496e-05f, 1.7016885976772755e-05f, 3.24663778883405e-05f, 1.8722315871855244e-05f, 1.6313364540110342e-05f, 1.211628841701895e-05f, 2.539468368922826e-05f, 1.545592022011988e-05f, 1.4273630768002477e-05f, 1.0638997082423884e-05f, 1.630789483897388e-05f, 2.9894477847847156e-05f, 1.4518715033773333e-05f, 1.9771308870986104e-05f, 1.328722464677412e-05f, 1.2679760402534157e-05f, 1.634120781091042e-05f, 3.39568177878391e-05f, 1.9203553165425546e-05f, 1.876479473139625e-05f, 2.5321625798824243e-05f, 1.3556520571000874e-05f, 1.6188105291803367e-05f, 1.532395981485024e-05f, 1.2730986782116815e-05f, 1.9315384633955546e-05f, 1.7427344573661685e-05f, 1.7060421669157222e-05f, 1.5053975403134245e-05f, 1.3690069863514509e-05f, 2.4007473257370293e-05f, 9.689800208434463e-06f, 3.355301305418834e-05f, 1.0461788406246342e-05f, 1.593831075297203e-05f, 1.3501550711225718e-05f, 1.1965558769588824e-05f, 2.627741196192801e-05f, 1.652904575166758e-05f, 2.1331492462195456e-05f, 1.7643671526457183e-05f, 1.636322122067213e-05f, 2.028215203608852e-05f, 1.1448012628534343e-05f, 1.3523573215934448e-05f, 4.551722668111324e-05f, 2.968110129586421e-05f, 2.682159720279742e-05f, 1.77830588654615e-05f, 1.3491344361682422e-05f, 2.166771264455747e-05f, 1.470227653044276e-05f, 2.4702872906345874e-05f, 1.0634104910423048e-05f, 1.899849667097442e-05f, 2.603099164844025e-05f, 1.080417223420227e-05f, 1.1660206837404985e-05f, 1.393097591062542e-05f, 1.2440781574696302e-05f, 2.0716764993267134e-05f, 2.647771907504648e-05f, 1.4392792763828766e-05f, 1.6984891772153787e-05f, 1.2357261766737793e-05f, 2.4454539016005583e-05f, 8.681012332090177e-06f, 1.3539020983444061e-05f, 1.2234109817654826e-05f, 1.2852107829530723e-05f, 1.9900371626135893e-05f, 1.6979161955532618e-05f, 1.6690441043465398e-05f, 1.4140138773655053e-05f, 3.2362164347432554e-05f, 2.8093072614865378e-05f, 2.1700663637602702e-05f, 1.2868811609223485e-05f, 2.413371839793399e-05f, 2.0352512365207076e-05f, 1.3764539289695676e-05f, 1.2897353371954523e-05f, 1.5729592632851563e-05f, 1.7058524463209324e-05f, 1.5992080079740845e-05f, 1.1920401448151097e-05f, 8.329303454956971e-06f, 2.029593633778859e-05f, 1.5287729183910415e-05f, 2.3405717001878656e-05f, 2.272918209200725e-05f, 1.706600778561551e-05f, 1.8610509869176894e-05f, 1.0888608812820166e-05f, 3.763420681934804e-05f, 3.009545980603434e-05f, 1.582967524882406e-05f, 1.4213282156561036e-05f, 1.1392307897040155e-05f, 1.0407904483145103e-05f, 2.5758823539945297e-05f, 1.1549309419933707e-05f, 8.19479646452237e-06f, 1.6620779206277803e-05f, 1.7070820831577294e-05f, 1.9951132344431244e-05f, 1.9870607502525672e-05f, 1.8833028661902063e-05f, 1.2947251889272593e-05f, 3.395345265744254e-05f, 2.0674366169259883e-05f, 1.7274909623665735e-05f, 3.073433254030533e-05f, 2.94498404400656e-05f, 1.2956326827406883e-05f, 1.339123264187947e-05f, 1.537287243991159e-05f, 1.2194327609904576e-05f, 1.447912654839456e-05f, 2.027094342338387e-05f, 1.560067721584346e-05f, 2.2405965864891186e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006021601147949696f, 0.00040599520434625447f, 0.0005793548189103603f, 0.0005541282007470727f, 0.0005506186280399561f, 0.0008420149679295719f, 0.0005147241172380745f, 0.0006578685133717954f, 0.0005696944426745176f, 0.0004000420740339905f, 0.0004897289327345788f, 0.0005854609189555049f, 0.0004672528593800962f, 0.0005742137436755002f, 0.00063674570992589f, 0.0008021982503123581f, 0.0004396740405354649f, 0.0009061892633326352f, 0.0003650328144431114f, 0.001557269599288702f, 0.000409037311328575f, 0.0007301064906641841f, 0.0005899129319004714f, 0.0003763897402677685f, 0.0005588055937550962f, 0.0006397890974767506f, 0.000759292277507484f, 0.000736455200240016f, 0.0006076233694329858f, 0.00036375471972860396f, 0.0005743867950513959f, 0.00046368534094654024f, 0.0008458226220682263f, 0.000437168957432732f, 0.001532560563646257f, 0.0004725117760244757f, 0.0006773367640562356f, 0.0005788466660305858f, 0.0008371442672796547f, 0.0004556776548270136f, 0.0004060734936501831f, 0.0006247053970582783f, 0.0003156427410431206f, 0.0007447382668033242f, 0.00034499214962124825f, 0.0006857157568447292f, 0.0005791527219116688f, 0.0007144279661588371f, 0.00047793707926757634f, 0.0009046235354617238f, 0.0009220244828611612f, 0.00039550490328110754f, 0.0006448287167586386f, 0.000693667447194457f, 0.0005407274002209306f, 0.0009218986961059272f, 0.0005129555938765407f, 0.00046736333752050996f, 0.0005899131647311151f, 0.00047739309957250953f, 0.0007105196709744632f, 0.0008869083831086755f, 0.0006231805891729891f, 0.0004949576104991138f, 0.0006252750172279775f, 0.00047011813148856163f, 0.0005631731473840773f, 0.0009359003161080182f, 0.0007334506371989846f, 0.0005272909766063094f, 0.000602219020947814f, 0.0005599428550340235f, 0.00041867909021675587f, 0.0006208141567185521f, 0.0004623970598913729f, 0.00047860623453743756f, 0.000817095919046551f, 0.00046802969882264733f, 0.0002870362368412316f, 0.0006381846615113318f, 0.0009899617871269584f, 0.0006027762428857386f, 0.00036837640800513327f, 0.0010186092695221305f, 0.00035364864743314683f, 0.0008075679070316255f, 0.0006326106959022582f, 0.0004377783334348351f, 0.0008294531144201756f, 0.0007338756113313138f, 0.0004958795034326613f, 0.0005031009204685688f, 0.0005373843596316874f, 0.0005845519481226802f, 0.0008519408875145018f, 0.00041229641647078097f, 0.0009090228704735637f, 0.0014554901281371713f, 0.0004965527332387865f, 0.00046531044063158333f, 0.00048444344429299235f, 0.0008829845464788377f, 0.0004872038553003222f, 0.0006630506250075996f, 0.0006103715277276933f, 0.000591451593209058f, 0.0007515900651924312f, 0.0007769045187160373f, 0.0006042535533197224f, 0.00038419835618697107f, 0.0012666528346017003f, 0.00030970480293035507f, 0.0010966325644403696f, 0.000565964262932539f, 0.0006206071702763438f, 0.0006284929695539176f, 0.0003566000668797642f, 0.0011094978544861078f, 0.0005116733373142779f, 0.00037105882074683905f, 0.00042225446668453515f, 0.0006928198854438961f, 0.0003659308422356844f, 0.0006946558714844286f, 0.0005501600680872798f, 0.0011106819147244096f, 0.0007835053256712854f, 0.00039637376903556287f, 0.0005448858137242496f, 0.0005596616538241506f, 0.0009744299459271133f, 0.00045174802653491497f, 0.0005151770892553031f, 0.00041201061685569584f, 0.0005541873397305608f, 0.0005620535812340677f, 0.0010723373852670193f, 0.0006183824734762311f, 0.0005388168501667678f, 0.00040019091102294624f, 0.000838765234220773f, 0.0005104961455799639f, 0.0004714461392723024f, 0.00035139720421284437f, 0.0005386361735872924f, 0.000987389707006514f, 0.0004795410786755383f, 0.0006530298851430416f, 0.00043886597268283367f, 0.00041880193748511374f, 0.0005397364730015397f, 0.001121565350331366f, 0.0006342773558571935f, 0.0006197855691425502f, 0.0008363522356376052f, 0.0004477605689316988f, 0.0005346796242520213f, 0.0005061376141384244f, 0.00042049388866871595f, 0.0006379710393957794f, 0.0005756106693297625f, 0.000563491543289274f, 0.0004972202586941421f, 0.00045217160368338227f, 0.0007929468411020935f, 0.0003200460341759026f, 0.0011082281125709414f, 0.0003455441619735211f, 0.0005264291539788246f, 0.0004459449846763164f, 0.00039521243888884783f, 0.0008679210441187024f, 0.0005459405947476625f, 0.0007045614183880389f, 0.0005827557761222124f, 0.0005404635448940098f, 0.0006699025980196893f, 0.00037811833317391574f, 0.00044667234760709107f, 0.0015033960808068514f, 0.0009803420398384333f, 0.000885894987732172f, 0.0005873595946468413f, 0.00044560787500813603f, 0.0007156665087677538f, 0.0004856039595324546f, 0.0008159152930602431f, 0.0003512356197461486f, 0.0006275045452639461f, 0.0008597819833084941f, 0.0003568528045434505f, 0.00038512691389769316f, 0.00046012853272259235f, 0.00041090865852311254f, 0.0006842574803158641f, 0.000874536985065788f, 0.0004753819666802883f, 0.0005609968211501837f, 0.00040815005195327103f, 0.0008077130769379437f, 0.0002867266011890024f, 0.0004471825959626585f, 0.000404082442400977f, 0.0004244944138918072f, 0.0006572927231900394f, 0.000560807588044554f, 0.0005512713687494397f, 0.0004670369962695986f, 0.0010688953334465623f, 0.0009278907673433423f, 0.0007167548174038529f, 0.0004250461352057755f, 0.0007971166050992906f, 0.0006722265388816595f, 0.0004546312557067722f, 0.00042598883737809956f, 0.0005195353296585381f, 0.0005634288536384702f, 0.0005282050697132945f, 0.00039372092578560114f, 0.0002751099527813494f, 0.0006703578983433545f, 0.0005049409810453653f, 0.0007730713114142418f, 0.0007507259724661708f, 0.0005636760033667088f, 0.0006146896630525589f, 0.000359641679096967f, 0.0012430264614522457f, 0.0009940279414877295f, 0.0005228410009294748f, 0.0004694528761319816f, 0.00037627844722010195f, 0.00034376440453343093f, 0.00085079250857234f, 0.0003814640804193914f, 0.00027066731126978993f, 0.0005489704781211913f, 0.0005638349684886634f, 0.00065896927844733f, 0.0006563095957972109f, 0.0006220392533577979f, 0.00042763695819303393f, 0.0011214542901143432f, 0.0006828571204096079f, 0.0005705758812837303f, 0.0010151293827220798f, 0.0009727036813274026f, 0.00042793669854290783f, 0.0004423012724146247f, 0.0005077531677670777f, 0.00040276849176734686f, 0.00047823350178077817f, 0.0006695323972962797f, 0.000515277381055057f, 0.0007400503964163363f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.4313114408869296e-05f, 0.00010454450239194557f, 0.00014108994218986481f, 3.95579008909408e-05f, 3.4595585020724684e-05f, 4.179833922535181e-05f, 5.9238842368358746e-05f, 5.2063351176911965e-05f, 3.289276355644688e-05f, 3.379518966539763e-05f, 4.302775050746277e-05f, 3.1669551390223205e-05f, 3.777819074457511e-05f, 7.794902194291353e-05f, 3.455360638326965e-05f, 6.116100121289492e-05f, 5.210462404647842e-05f, 2.9333603379200213e-05f, 3.545077197486535e-05f, 4.6944966015871614e-05f, 3.7768943002447486e-05f, 3.0084092941251583e-05f, 3.5258774005342275e-05f, 4.5785978727508336e-05f, 7.24384663044475e-05f, 0.00010999381629517302f, 3.407617623452097e-05f, 2.774354288703762e-05f, 4.487640399020165e-05f, 3.688063952722587e-05f, 5.495651930687018e-05f, 5.464904825203121e-05f, 4.930907743982971e-05f, 6.470536754932255e-05f, 3.397760519874282e-05f, 4.5072090870235115e-05f, 4.718582204077393e-05f, 2.9975915822433308e-05f, 3.226225089747459e-05f, 3.701637251651846e-05f, 4.153595364186913e-05f, 6.793664942961186e-05f, 5.721787238144316e-05f, 3.7416779377963394e-05f, 8.474892820231616e-05f, 4.2394764022901654e-05f, 2.7768308427766897e-05f, 3.852956433547661e-05f, 6.001665678923018e-05f, 2.0435416445252486e-05f, 3.548718086676672e-05f, 4.787920988746919e-05f, 4.660894410335459e-05f, 4.9832469812827185e-05f, 0.00018530600937083364f, 5.9081379731651396e-05f, 3.4497748856665567e-05f, 2.680748548300471e-05f, 2.665996362338774e-05f, 6.670592847513035e-05f, 5.967212564428337e-05f, 3.4339434932917356e-05f, 6.211792060639709e-05f, 5.724091170122847e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012284565018489957f, 0.005282267462462187f, 0.0071287802420556545f, 0.0019987220875918865f, 0.001747993635945022f, 0.002111923648044467f, 0.0029931312892585993f, 0.0026305788196623325f, 0.0016619560774415731f, 0.0017075524665415287f, 0.0021740414667874575f, 0.001600151532329619f, 0.001908799633383751f, 0.003938490990549326f, 0.001745872781611979f, 0.0030902510043233633f, 0.0026326640509068966f, 0.0014821242075413465f, 0.0017912032781168818f, 0.002371964743360877f, 0.0019083324586972594f, 0.0015200438210740685f, 0.0017815023893490434f, 0.002313405042514205f, 0.003660061862319708f, 0.005557602271437645f, 0.0017217498971149325f, 0.0014017840148881078f, 0.0022674475330859423f, 0.0018634495791047812f, 0.0027767603751271963f, 0.0027612249832600355f, 0.00249141501262784f, 0.003269335487857461f, 0.0017167693004012108f, 0.0022773349191993475f, 0.0023841343354433775f, 0.0015145780052989721f, 0.0016300985589623451f, 0.0018703076057136059f, 0.0020986662711948156f, 0.0034326007589697838f, 0.0028910187538713217f, 0.0018905388424172997f, 0.004282066598534584f, 0.0021420589182525873f, 0.0014030353631824255f, 0.0019467639504000545f, 0.003032431472092867f, 0.0010325299808755517f, 0.001793042989447713f, 0.0024191688280552626f, 0.002354986732825637f, 0.00251786014996469f, 0.009362863376736641f, 0.002985175233334303f, 0.0017430504085496068f, 0.0013544883113354445f, 0.0013470345875248313f, 0.0033704168163239956f, 0.003015023423358798f, 0.0017350513953715563f, 0.0031386008486151695f, 0.0028921826742589474f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019642258121166378f, 0.0001834656432038173f, 5.001230601919815e-05f, 0.00013406676589511335f, 0.00015360055840574205f, 5.0212067435495555e-05f, 0.00014242400357034057f, 0.0003333727945573628f, 0.00014554278459399939f, 9.725464769871905e-05f, 0.00021449201449286193f, 8.008321310626343e-05f, 0.00029915134655311704f, 8.978623372968286e-05f, 0.00010012379061663523f, 0.00016905093798413873f, 8.661168249091133e-05f, 0.00017086671141441911f, 5.915897781960666e-05f, 7.927890692371875e-05f, 5.082658753963187e-05f, 9.983351628761739e-05f, 9.330159082310274e-05f, 0.00010320142609998584f, 9.938659059116617e-05f, 0.0001989996526390314f, 8.340754720848054e-05f, 4.258983244653791e-05f, 0.00010552998719504103f, 5.2489507652353495e-05f, 6.58425924484618e-05f, 5.6297812989214435e-05f, 7.20078096492216e-05f, 7.244451262522489e-05f, 0.00012730695016216487f, 0.0002131196961272508f, 0.00010785827180370688f, 4.2464274883968756e-05f, 0.000344018277246505f, 9.715482156025246e-05f, 5.6077518820529804e-05f, 0.0001788140507414937f, 8.710279507795349e-05f, 4.9303875130135566e-05f, 7.824337080819532e-05f, 4.128400541958399e-05f, 8.419125515501946e-05f, 0.00010706496686907485f, 7.969539001351222e-05f, 0.0007385644130408764f, 8.550399070372805e-05f, 4.873746001976542e-05f, 6.349733303068206e-05f, 0.00026013271417468786f, 9.625386155676097e-05f, 4.6149292757036164e-05f, 8.522051939507946e-05f, 0.00020304240752011538f, 4.125219857087359e-05f, 6.847317126812413e-05f, 0.00015186959353741258f, 0.00017103235586546361f, 0.00014491008187178522f, 9.257441706722602e-05f, 8.229925879277289e-05f, 8.169079228537157e-05f, 0.0001246730680577457f, 0.00010425614891573787f, 9.624109952710569e-05f, 0.00011983133299509063f, 0.00011306851956760511f, 0.00018613979045767337f, 5.3655374358640984e-05f, 5.105779200675897e-05f, 9.285532723879442e-05f, 7.968096906552091e-05f, 4.2789022700162604e-05f, 0.0002724910737015307f, 7.576184725621715e-05f, 8.351614815182984e-05f, 9.729707380756736e-05f, 0.00011824035755125806f, 2.817450149450451e-05f, 0.0004554239858407527f, 6.510344974230975e-05f, 0.00015866603644099087f, 5.634002081933431e-05f, 0.00011969766637776047f, 9.757252701092511e-05f, 0.00012602486822288483f, 0.00010977488273056224f, 8.558014815207571e-05f, 7.084412936819717e-05f, 5.99281738686841e-05f, 8.171146328095347e-05f, 7.011496199993417e-05f, 7.46943915146403e-05f, 4.47923484898638e-05f, 0.00011587191693251953f, 4.866534436587244e-05f, 6.690670124953613e-05f, 7.542156527051702e-05f, 0.00013129347644280642f, 0.00012578917085193098f, 6.344327994156629e-05f, 0.00010851088882191107f, 8.287980745080858e-05f, 3.925789860659279e-05f, 8.593721577199176e-05f, 0.00019568992138374597f, 0.000562158296816051f, 0.0001282755401916802f, 4.6995912271086127e-05f, 8.268786768894643e-05f, 0.00015733337204437703f, 5.7123732403852046e-05f, 6.118480087025091e-05f, 0.00023570698976982385f, 5.596519258688204e-05f, 5.1495706429705024e-05f, 0.00014691265823785216f, 5.941696872469038e-05f, 0.0001580960233695805f, 0.00012954161502420902f, 4.064750100951642e-05f, 0.0003018491552211344f, 7.870148692745715e-05f, 0.0001484098465880379f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013786748051643372f, 0.012877310626208782f, 0.0035103249829262495f, 0.009410042315721512f, 0.010781103745102882f, 0.0035243460442870855f, 0.009996630251407623f, 0.023399177938699722f, 0.010215534828603268f, 0.006826227996498346f, 0.015055027790367603f, 0.005620978306978941f, 0.020997200161218643f, 0.006302026100456715f, 0.007027611136436462f, 0.011865554377436638f, 0.006079206708818674f, 0.011993002146482468f, 0.00415232265368104f, 0.005564524792134762f, 0.003567478619515896f, 0.007007237058132887f, 0.006548766046762466f, 0.0072436281479895115f, 0.006975867785513401f, 0.013967631384730339f, 0.005854310933500528f, 0.0029893473256379366f, 0.007407067809253931f, 0.003684197785332799f, 0.004621440544724464f, 0.003951499704271555f, 0.00505417212843895f, 0.0050848242826759815f, 0.008935576304793358f, 0.014958705753087997f, 0.007570488378405571f, 0.002980534452944994f, 0.02414637617766857f, 0.006819221656769514f, 0.0039360374212265015f, 0.012550819665193558f, 0.006113677751272917f, 0.0034606007393449545f, 0.005491841584444046f, 0.0028976923786103725f, 0.005909319035708904f, 0.007514806929975748f, 0.00559375761076808f, 0.05183926224708557f, 0.006001458503305912f, 0.003420844441279769f, 0.004456828348338604f, 0.018258513882756233f, 0.0067559839226305485f, 0.0032391829881817102f, 0.005981562193483114f, 0.014251388609409332f, 0.0028954597655683756f, 0.004806078504770994f, 0.010659608989953995f, 0.012004627846181393f, 0.010171125642955303f, 0.006497726310044527f, 0.005776521284133196f, 0.005733813159167767f, 0.008750705979764462f, 0.007317658048123121f, 0.006755087990313768f, 0.008410868234932423f, 0.007936191745102406f, 0.013065007515251637f, 0.003766029141843319f, 0.003583706682547927f, 0.006517443340271711f, 0.005592745263129473f, 0.003003328340128064f, 0.019125936552882195f, 0.005317665170878172f, 0.005861933808773756f, 0.006829205900430679f, 0.008299198932945728f, 0.0019775463733822107f, 0.03196585550904274f, 0.004569560755044222f, 0.011136645451188087f, 0.003954462241381407f, 0.008401486091315746f, 0.006848539691418409f, 0.008845587261021137f, 0.007705013733357191f, 0.006006804294884205f, 0.004972494672983885f, 0.004206311888992786f, 0.0057352641597390175f, 0.004921314772218466f, 0.005242741201072931f, 0.00314394012093544f, 0.008132959716022015f, 0.003415782703086734f, 0.004696129355579615f, 0.005293780937790871f, 0.009215387515723705f, 0.008829044178128242f, 0.004453034605830908f, 0.007616295013576746f, 0.005817269440740347f, 0.002755481516942382f, 0.006031866185367107f, 0.013735323213040829f, 0.03945745527744293f, 0.009003560058772564f, 0.003298606490716338f, 0.005803797394037247f, 0.011043107137084007f, 0.004009470343589783f, 0.00429451372474432f, 0.01654409058392048f, 0.003928153309971094f, 0.003614443587139249f, 0.010311685502529144f, 0.004170430824160576f, 0.011096636764705181f, 0.009092424996197224f, 0.0028530166018754244f, 0.02118655852973461f, 0.00552399642765522f, 0.010416772216558456f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.577113188337535e-05f, 5.9708745538955554e-05f, 0.00010564066178631037f, 7.871485286159441e-05f, 0.00010611287143547088f, 0.00011628936772467569f, 3.865796679747291e-05f, 7.853785064071417e-05f, 8.127529872581363e-05f, 7.331206870730966e-05f, 8.625321788713336e-05f, 0.00010369099618401378f, 8.87807400431484e-05f, 9.489500371273607e-05f, 7.087357516866177e-05f, 8.67890557856299e-05f, 8.372340380446985e-05f, 8.330926357302815e-05f, 8.16749525256455e-05f, 5.681076072505675e-05f, 8.866628195391968e-05f, 9.507045615464449e-05f, 9.388683247379959e-05f, 0.00010731520160334185f, 7.278654084075242e-05f, 7.837790326448157e-05f, 7.663787982892245e-05f, 8.234866982093081e-05f, 6.5270098275505e-05f, 0.00012375382357276976f, 8.164254541043192e-05f, 0.0001149483141489327f, 4.791916944668628e-05f, 0.00010801117605296895f, 6.745299469912425e-05f, 0.00010179157106904313f, 8.961236017057672e-05f, 0.0001444327790522948f, 6.979915633564815e-05f, 5.8458408602746204e-05f, 4.909448398393579e-05f, 7.509923307225108e-05f, 0.00014482135884463787f, 9.607640095055103e-05f, 7.099045615177602e-05f, 8.369579882128164e-05f, 6.82010650052689e-05f, 0.00010472512076376006f, 0.00011095395893789828f, 3.518672747304663e-05f, 0.0001426664093742147f, 7.440215267706662e-05f, 8.993783558253199e-05f, 6.19581260252744e-05f, 7.423896749969572e-05f, 0.00012268254067748785f, 0.00010372745600761846f, 8.611752855358645e-05f, 7.594643830088899e-05f, 0.00010263524745823815f, 4.665756205213256e-05f, 8.842822717269883e-05f, 7.97580141806975e-05f, 8.041263208724558e-05f, 0.00010846149234566838f, 0.00013675251102540642f, 4.6289718738989905e-05f, 0.00010646291775628924f, 0.00010160011879634112f, 6.289612065302208e-05f, 0.00010688254405977204f, 0.00010121653031092137f, 9.238041820935905e-05f, 0.00013027132081333548f, 7.044110679998994e-05f, 9.322175174020231e-05f, 9.816962119657546e-05f, 3.6713110603159294e-05f, 9.471749945078045e-05f, 9.14500851649791e-05f, 5.850814704899676e-05f, 0.00010153456969419494f, 0.00012103406334063038f, 6.327254232019186e-05f, 0.00016147982387337834f, 9.106063225772232e-05f, 7.902450306573883e-05f, 7.416658627334982e-05f, 9.409615449840203e-05f, 6.797095556976274e-05f, 0.00010573835606919602f, 7.27542137610726e-05f, 0.00011088386963820085f, 9.125875658355653e-05f, 8.85576955624856e-05f, 0.00010454541188664734f, 8.911909390008077e-05f, 9.279364894609898e-05f, 7.00236123520881e-05f, 0.00011775968596339226f, 0.00010969962750095874f, 8.18993867142126e-05f, 9.629914711695164e-05f, 7.613248453708366e-05f, 9.479564323555678e-05f, 0.00010797296999953687f, 0.0001608038874110207f, 8.184841863112524e-05f, 7.793962868163362e-05f, 7.282193837454543e-05f, 6.697941716993228e-05f, 6.713536276947707e-05f, 0.00011347388499416411f, 6.693016621284187e-05f, 6.553892308147624e-05f, 0.00014157839177642018f, 7.392806583084166e-05f, 6.25689935986884e-05f, 0.00011140036804135889f, 6.70003573759459e-05f, 6.749766907887533e-05f, 8.972721843747422e-05f, 6.686736742267385e-05f, 9.938298899214715e-05f, 6.761967961210757e-05f, 9.04197950148955e-05f, 4.259033448761329e-05f, 8.300261106342077e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004740350996144116f, 0.0005075034569017589f, 0.0008979086414910853f, 0.0006690486916340888f, 0.0009019222925417125f, 0.000988418934866786f, 0.00032857918995432556f, 0.0006675442564301193f, 0.0006908116047270596f, 0.0006231269217096269f, 0.0007331221713684499f, 0.0008813372114673257f, 0.0007546052220277488f, 0.0008065743022598326f, 0.0006024005706422031f, 0.0007376766297966242f, 0.000711619621142745f, 0.000708099571056664f, 0.0006942085456103086f, 0.0004828715755138546f, 0.000753632397390902f, 0.0008080655825324357f, 0.0007980052032507956f, 0.0009121416369453073f, 0.0006186601240187883f, 0.0006661847583018243f, 0.0006513951811939478f, 0.0006999348988756537f, 0.0005547729670070112f, 0.001051864237524569f, 0.0006939330487512052f, 0.0009770204778760672f, 0.0004072961746715009f, 0.000918057223316282f, 0.0005733268335461617f, 0.0008651927346363664f, 0.0007616737275384367f, 0.0012276280904188752f, 0.0005932684289291501f, 0.0004968760185874999f, 0.00041728594806045294f, 0.0006383172003552318f, 0.0012309309095144272f, 0.0008166157640516758f, 0.0006033940589986742f, 0.0007113849860616028f, 0.0005796852055937052f, 0.0008901268593035638f, 0.0009430698119103909f, 0.00029907486168667674f, 0.0012126145884394646f, 0.0006323922425508499f, 0.0007644401048310101f, 0.0005266224034130573f, 0.0006310052704066038f, 0.0010427586967125535f, 0.0008816470508463681f, 0.0007319688447751105f, 0.0006455181282944977f, 0.0008723636856302619f, 0.00039657295565120876f, 0.0007516089826822281f, 0.0006779152317903936f, 0.000683479243889451f, 0.000921884726267308f, 0.001162348547950387f, 0.0003934464184567332f, 0.0009048975771293044f, 0.0008635654812678695f, 0.0005345949903130531f, 0.0009084642515517771f, 0.0008603050955571234f, 0.0007852012058719993f, 0.0011072605848312378f, 0.0005987247568555176f, 0.0007923522498458624f, 0.0008344074012711644f, 0.00031204859260469675f, 0.0008050656178966165f, 0.0007772936951369047f, 0.0004972987808287144f, 0.0008630083175376058f, 0.0010287471814081073f, 0.0005377944908104837f, 0.0013725219760090113f, 0.0007739834836684167f, 0.0006716806092299521f, 0.0006303900154307485f, 0.0007997843786142766f, 0.0005777293117716908f, 0.0008987390319816768f, 0.0006183853838592768f, 0.0009424741147086024f, 0.0007756674895063043f, 0.0007527093985117972f, 0.0008885994320735335f, 0.0007574810879305005f, 0.0007887135725468397f, 0.000595176185015589f, 0.0010009161196649075f, 0.0009324084385298193f, 0.0006961161270737648f, 0.0008185090846382082f, 0.0006470994558185339f, 0.0008057297673076391f, 0.0009177324827760458f, 0.0013667767634615302f, 0.0006956829456612468f, 0.0006624595844186842f, 0.00061896099941805f, 0.0005693015991710126f, 0.0005706271040253341f, 0.0009644883102737367f, 0.000568882969673723f, 0.0005570579087361693f, 0.0012033667881041765f, 0.0006283627008087933f, 0.0005318145267665386f, 0.0009468641364946961f, 0.000569479598198086f, 0.0005737065803259611f, 0.0007626499864272773f, 0.0005683492054231465f, 0.0008447206346318126f, 0.0005747436080127954f, 0.0007685366435907781f, 0.0003620029310695827f, 0.0007054931484162807f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010697630932554603f, 0.00010024035145761445f, 0.000136336573632434f, 0.00012218279880471528f, 0.00010395234130555764f, 0.00010087968257721514f, 9.711879101814702e-05f, 7.308405474759638e-05f, 0.00012938506552018225f, 9.662312368163839e-05f, 7.193585770437494e-05f, 0.00011308603279758245f, 0.00012304779374971986f, 9.860525460680947e-05f, 8.17500549601391e-05f, 9.733519982546568e-05f, 0.0001358575827907771f, 6.434085662476718e-05f, 0.00012903648894280195f, 0.00012942490866407752f, 8.568341581849381e-05f, 8.540946146240458e-05f, 0.00010027929238276556f, 9.184345981338993e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005600900389254093f, 0.00524822948500514f, 0.007138099987059832f, 0.006397058255970478f, 0.0054425764828920364f, 0.0052817026153206825f, 0.005084795877337456f, 0.0038264221511781216f, 0.006774143315851688f, 0.0050588445737957954f, 0.0037663066759705544f, 0.005920784082263708f, 0.0064423466101288795f, 0.005162621848285198f, 0.004280143417418003f, 0.005096126347780228f, 0.007113021798431873f, 0.0033686591777950525f, 0.006755893584340811f, 0.006776229478418827f, 0.0044860802590847015f, 0.0044717369601130486f, 0.005250268615782261f, 0.004808598197996616f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013026056694798172f, 0.000246945972321555f, 0.00014170247595757246f, 0.00011285758955636993f, 7.180761167546734e-05f, 0.00014956024824641645f, 0.00010011299309553578f, 0.00033261528005823493f, 7.262379949679598e-05f, 0.0002090445632347837f, 0.00021337482030503452f, 0.00018787563021760434f, 0.00016772045637480915f, 0.00010416909208288416f, 0.00010860369366127998f, 7.932789594633505e-05f, 0.00019618241640273482f, 0.00021301815286278725f, 0.00023610655625816435f, 0.00013214517093729228f, 0.00014822155935689807f, 0.00013478417531587183f, 0.00012510534725151956f, 0.0001754314434947446f, 9.514856355963275e-05f, 0.00011161298607476056f, 0.00010329541692044586f, 0.00017919100355356932f, 0.00010301778092980385f, 0.00014069987810216844f, 0.00011752732825698331f, 0.0001367748191114515f, 8.716122101759538e-05f, 0.00015999190509319305f, 0.0002677199663594365f, 0.00011313559662085027f, 6.633091106778011e-05f, 9.175470768241212e-05f, 0.00016642642731312662f, 0.0002107855398207903f, 0.00022937804169487208f, 8.690765389474109e-05f, 0.0002046961017185822f, 0.00011109084152849391f, 0.00023181724827736616f, 0.0001032352665788494f, 7.998266664799303e-05f, 6.52565504424274e-05f, 0.0001885004312498495f, 0.00016387522919103503f, 6.196486356202513e-05f, 0.00010225720325252041f, 9.730761667015031e-05f, 0.00010543053940637037f, 0.00012078502186341211f, 0.00016332970699295402f, 0.00010358376312069595f, 6.652882439084351e-05f, 9.464054164709523e-05f, 9.978497837437317e-05f, 0.00013571555609814823f, 0.00014608570199925452f, 0.00014719237515237182f, 0.0001650050689931959f, 0.00012388764298520982f, 0.0001778107398422435f, 0.00011662809265544638f, 0.0001726774062262848f, 0.00012057741696480662f, 0.00010444504005135968f, 0.00012846423487644643f, 0.0001201918421429582f, 0.00013775429397355765f, 9.379631956107914e-05f, 8.282857743324712e-05f, 9.893818787531927e-05f, 0.00012026524200337008f, 0.00015802786219865084f, 0.0001039136404870078f, 0.00013355740520637482f, 0.0001660143316257745f, 0.00013061158824712038f, 0.0002463445416651666f, 0.0002986254694405943f, 0.00013199305976741016f, 7.512149022659287e-05f, 0.00018279145297128707f, 7.772591925458983e-05f, 0.0004993384936824441f, 0.00016408335068263113f, 0.00020440708613023162f, 8.18703047116287e-05f, 0.00011052055197069421f, 8.055326907197013e-05f, 0.00013749176287092268f, 8.377525227842852e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008021090179681778f, 0.015206259675323963f, 0.008725651539862156f, 0.006949462462216616f, 0.004421716555953026f, 0.009209511801600456f, 0.006164684891700745f, 0.020481541752815247f, 0.00447197537869215f, 0.012872393243014812f, 0.013139039278030396f, 0.011568868532776833f, 0.010327767580747604f, 0.006414448376744986f, 0.0066875191405415535f, 0.004884795285761356f, 0.012080377899110317f, 0.013117075897753239f, 0.014538797549903393f, 0.008137138560414314f, 0.009127078577876091f, 0.00829964131116867f, 0.007703645620495081f, 0.010802589356899261f, 0.005858988966792822f, 0.006872822996228933f, 0.006360649596899748f, 0.011034092865884304f, 0.006343553774058819f, 0.008663914166390896f, 0.007237012032419443f, 0.00842222012579441f, 0.005367150064557791f, 0.009851864539086819f, 0.016485463827848434f, 0.006966581102460623f, 0.0040844762697815895f, 0.005650004372000694f, 0.010248085483908653f, 0.0129795977845788f, 0.014124473556876183f, 0.005351535975933075f, 0.012604626826941967f, 0.006840670946985483f, 0.014274673536419868f, 0.006356945727020502f, 0.00492511410266161f, 0.004018320236355066f, 0.011607342399656773f, 0.01009098906069994f, 0.00381562695838511f, 0.006296719424426556f, 0.005991937592625618f, 0.006492124870419502f, 0.007437611930072308f, 0.010057397186756134f, 0.006378405261784792f, 0.004096663556993008f, 0.005827706307172775f, 0.006144486367702484f, 0.008356993086636066f, 0.008995559066534042f, 0.009063704870641232f, 0.01016056165099144f, 0.007628662511706352f, 0.010949100367724895f, 0.0071816397830843925f, 0.01063300296664238f, 0.007424828130751848f, 0.006431440357118845f, 0.007910476997494698f, 0.0074010854586958885f, 0.008482533507049084f, 0.005775721278041601f, 0.005100357811897993f, 0.006092343479394913f, 0.0074056051671504974f, 0.009730923920869827f, 0.00639871833845973f, 0.008224100805819035f, 0.010222709737718105f, 0.008042705245316029f, 0.01516922377049923f, 0.018388541415333748f, 0.008127772249281406f, 0.004625776316970587f, 0.011255798861384392f, 0.004786150064319372f, 0.030747899785637856f, 0.010103804990649223f, 0.01258683018386364f, 0.005041349679231644f, 0.006805554032325745f, 0.004960250575095415f, 0.008466367609798908f, 0.005158651154488325f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.719712059246376e-05f, 8.99040896911174e-05f, 0.00012720060476567596f, 0.00011954704677918926f, 0.00011359908239683136f, 0.0001405813090968877f, 8.460800745524466e-05f, 7.545109110651538e-05f, 9.483403118792921e-05f, 0.00012039444845868275f, 0.00010189083695877343f, 0.00012597722525242716f, 8.502430864609778e-05f, 9.892140224110335e-05f, 0.00010001032933359966f, 0.0001189983740914613f, 6.640030187554657e-05f, 0.0001171277544926852f, 8.560578135075048e-05f, 0.00011679358431138098f, 8.746852108743042e-05f, 0.0001408954558428377f, 6.755913636879995e-05f, 0.0001262720033992082f, 0.00011499014362925664f, 0.00011972530046477914f, 0.00013949759886600077f, 7.789736991981044e-05f, 0.00010701624705689028f, 8.268704550573602e-05f, 0.00010548566933721304f, 7.012451533228159e-05f, 0.0001297786075156182f, 8.84189284988679e-05f, 0.00010247186583001167f, 0.00013579509686678648f, 0.0001170698888017796f, 9.229910938302055e-05f, 0.000113605463411659f, 7.538568752352148e-05f, 4.898759289062582e-05f, 0.00011756113963201642f, 0.00010744843893917277f, 8.41104774735868e-05f, 8.293391147162765e-05f, 8.118347614072263e-05f, 7.496742910007015e-05f, 0.00015039666322991252f, 8.798394264886156e-05f, 9.206619870383292e-05f, 0.00011858805373776704f, 0.00012246097321622074f, 0.00011534473014762625f, 0.00010906532406806946f, 8.944830915424973e-05f, 9.588687680661678e-05f, 0.00011819565406767651f, 8.955454541137442e-05f, 0.00015304842963814735f, 0.00015345943393185735f, 8.19995257188566e-05f, 0.0001554563787067309f, 0.00015546323265880346f, 9.666859114076942e-05f, 0.00010402768384665251f, 0.00010089167335536331f, 7.608984742546454e-05f, 7.410144462483004e-05f, 0.00011304578220006078f, 0.00010609029413899407f, 8.972825889941305e-05f, 9.633511945139617e-05f, 6.45202599116601e-05f, 9.258530189981684e-05f, 8.076430094661191e-05f, 0.0001272570079891011f, 0.00012215897731948644f, 0.00011310845729894936f, 8.564628660678864e-05f, 8.502394484821707e-05f, 8.37423067423515e-05f, 9.390620107296854e-05f, 8.527129102731124e-05f, 7.791445386828855e-05f, 9.73029964370653e-05f, 9.413797670276836e-05f, 0.00010212561028311029f, 0.00013793000834994018f, 6.323538400465623e-05f, 0.00016355288971681148f, 0.00011455339699750766f, 0.00010209839092567563f, 9.92378409137018e-05f, 9.000730642583221e-05f, 7.854609430069104e-05f, 0.00013317317643668503f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010509839048609138f, 0.0010836109286174178f, 0.0015331445029005408f, 0.0014408964198082685f, 0.001369205885566771f, 0.0016944216331467032f, 0.001019777380861342f, 0.00090940942754969f, 0.0011430312879383564f, 0.0014511101180687547f, 0.0012280867667868733f, 0.0015183991054072976f, 0.0010247951140627265f, 0.0011922962730750442f, 0.0012054210528731346f, 0.0014342833310365677f, 0.0008003205875866115f, 0.0014117368264123797f, 0.0010318035492673516f, 0.0014077090891078115f, 0.0010542550589889288f, 0.0016982080414891243f, 0.0008142879814840853f, 0.0015219521010294557f, 0.0013859722530469298f, 0.0014430449809879065f, 0.0016813597176223993f, 0.0009388943435624242f, 0.0012898631393909454f, 0.000996624119579792f, 0.0012714151525869966f, 0.0008452084148302674f, 0.0015642170328646898f, 0.0010657103266566992f, 0.0012350898468866944f, 0.0016367336502298713f, 0.0014110393822193146f, 0.0011124779703095555f, 0.0013692827196791768f, 0.000908621062990278f, 0.0005904457648284733f, 0.0014169603819027543f, 0.0012950723757967353f, 0.0010137807112187147f, 0.0009995995787903666f, 0.0009785016300156713f, 0.0009035798138938844f, 0.001812725909985602f, 0.0010604674462229013f, 0.0011096707312390208f, 0.0014293377753347158f, 0.0014760178746655583f, 0.0013902460923418403f, 0.0013145606499165297f, 0.0010781174059957266f, 0.0011557212565094233f, 0.001424608170054853f, 0.001079397858120501f, 0.0018446873873472214f, 0.001849641208536923f, 0.0009883374441415071f, 0.0018737104255706072f, 0.0018737930804491043f, 0.0011651432141661644f, 0.001253842143341899f, 0.0012160438345745206f, 0.0009171083220280707f, 0.0008931421907618642f, 0.0013625369174405932f, 0.0012787026353180408f, 0.0010814915876835585f, 0.0011611238587647676f, 0.0007776604616083205f, 0.0011159274727106094f, 0.0009734493214637041f, 0.0015338243683800101f, 0.0014723780332133174f, 0.0013632923364639282f, 0.0010322917951270938f, 0.001024790690280497f, 0.0010093431919813156f, 0.0011318481992930174f, 0.001027771970257163f, 0.000939100282266736f, 0.001172789721749723f, 0.0011346418177708983f, 0.0012309164740145206f, 0.0016624656273052096f, 0.0007621739059686661f, 0.0019712974317371845f, 0.0013807081850245595f, 0.0012305884156376123f, 0.0011961102718487382f, 0.0010848549427464604f, 0.0009467133786529303f, 0.0016051317797973752f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.864143117330968e-05f, 0.0001001616328721866f, 9.054018300957978e-05f, 9.237600897904485e-05f, 9.079387382371351e-05f, 7.541588274762034e-05f, 0.00010185895371250808f, 9.935938578564674e-05f, 8.020024688448757e-05f, 8.168214844772592e-05f, 8.932501805247739e-05f, 9.767981100594625e-05f, 9.590198169462383e-05f, 0.00010515155736356974f, 0.00011623201135080308f, 0.00012047826021444052f, 8.489880565321073e-05f, 7.558446668554097e-05f, 0.00010038151958724484f, 7.627889135619625e-05f, 9.677800699137151e-05f, 0.00011000898666679859f, 8.389015420107171e-05f, 8.84693581610918e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0035837050527334213f, 0.004564384929835796f, 0.00412593362852931f, 0.004209592472761869f, 0.004137494135648012f, 0.0034367162734270096f, 0.0046417322009801865f, 0.004527826327830553f, 0.0036547407507896423f, 0.0037222711835056543f, 0.0040705581195652485f, 0.0044512879103422165f, 0.004370271693915129f, 0.004791776649653912f, 0.005296715069562197f, 0.005490217357873917f, 0.0038688548374921083f, 0.0034443987533450127f, 0.004574405029416084f, 0.0034760436974465847f, 0.004410192370414734f, 0.005013130605220795f, 0.003822890343144536f, 0.004031565506011248f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001036565299727954f, 0.00019924833031836897f, 0.00018775281205307692f, 0.00021154325804673135f, 0.00013140917872078717f, 0.00020369526464492083f, 0.00012779734970536083f, 0.00016403908375650644f, 7.622015982633457e-05f, 0.00011751841520890594f, 0.00017788616241887212f, 0.00012324262934271246f, 0.00019801367307081819f, 0.00018840240954887122f, 0.00015864639135543257f, 8.259408787125722e-05f, 0.0003328507882542908f, 0.00015024370804894716f, 0.0001609212631592527f, 0.00010716285032685846f, 0.00013146000856067985f, 0.00013046646199654788f, 0.00019666958542075008f, 0.00017091885092668235f, 0.00016988147399388254f, 0.00011802465451182798f, 9.834700176725164e-05f, 0.00015264870307873935f, 0.00018935742264147848f, 0.0001355609274469316f, 0.0002323619555681944f, 0.00013122233212925494f, 0.000183060736162588f, 0.00014174802345223725f, 9.830061026150361e-05f, 0.00012924257316626608f, 0.00016000565665308386f, 0.0001084422183339484f, 0.00013549246068578213f, 0.0002724065852817148f, 0.0001379931636620313f, 0.00016010296531021595f, 0.0001706630428088829f, 0.00015344783605542034f, 0.00013265313464216888f, 0.00012298319779802114f, 9.217870683642104e-05f, 0.00019656980293802917f, 0.00018825678853318095f, 0.0003330635081510991f, 8.706856169737875e-05f, 0.00010970362927764654f, 0.00017248104268219322f, 0.00023061763204168528f, 0.00015509917284362018f, 7.437383465003222e-05f, 0.00012001678260276094f, 0.00012041599256917834f, 0.00010445903899380937f, 7.248223118949682e-05f, 0.00016196403885260224f, 0.00015906720364000648f, 0.00014391413424164057f, 0.0001194194337585941f, 0.00014861597446724772f, 0.0003350646875333041f, 9.589927503839135e-05f, 0.00013402696640696377f, 0.00013974460307508707f, 0.00012600405898410827f, 0.00016269105253741145f, 0.00027098911232315004f, 0.0001915796019602567f, 0.0001439509360352531f, 0.00016425870126113296f, 0.0001478283666074276f, 0.00010920129716396332f, 0.00016976386541500688f, 0.0002085460291709751f, 0.00010748011118266732f, 0.00013578927610069513f, 0.00012765414430759847f, 0.00013067950203549117f, 0.00019156571943312883f, 9.633343142922968e-05f, 0.00017561938147991896f, 0.00011541981803020462f, 0.00015568971866741776f, 0.00016832294932100922f, 0.00018372676277067512f, 0.00015455683751497418f, 0.00018304059631191194f, 0.0001557942305225879f, 0.00014372497389558703f, 0.0003097768931183964f, 0.00012258246715646237f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005589938722550869f, 0.010744966566562653f, 0.01012504193931818f, 0.011408001184463501f, 0.007086569909006357f, 0.01098477840423584f, 0.006891793105751276f, 0.008846219629049301f, 0.004110363312065601f, 0.006337475497275591f, 0.00959295779466629f, 0.006646167952567339f, 0.010678384453058243f, 0.010160072706639767f, 0.008555404841899872f, 0.004454093519598246f, 0.017949813976883888f, 0.008102268911898136f, 0.008678083308041096f, 0.005779025610536337f, 0.0070893107913434505f, 0.007035731803625822f, 0.01060590147972107f, 0.009217227809131145f, 0.009161285124719143f, 0.006364775821566582f, 0.005303609184920788f, 0.008231964893639088f, 0.010211574845016003f, 0.007310463115572929f, 0.012530702166259289f, 0.007076493464410305f, 0.009872009977698326f, 0.007644118275493383f, 0.005301107186824083f, 0.006969730369746685f, 0.008628706447780132f, 0.005848018918186426f, 0.007306771352887154f, 0.014690209180116653f, 0.0074416277930140495f, 0.00863395445048809f, 0.009203433059155941f, 0.00827505998313427f, 0.007153653539717197f, 0.0066321780905127525f, 0.00497096823528409f, 0.010600520297884941f, 0.010152219794690609f, 0.017961286008358f, 0.0046953908167779446f, 0.005916043650358915f, 0.009301473386585712f, 0.012436634860932827f, 0.008364112116396427f, 0.0040107956156134605f, 0.006472206208854914f, 0.006493734661489725f, 0.005633215885609388f, 0.003908786457031965f, 0.008734317496418953f, 0.008578098379075527f, 0.007760931272059679f, 0.006439992692321539f, 0.008014489896595478f, 0.018069203943014145f, 0.005171609111130238f, 0.007227740716189146f, 0.007536078337579966f, 0.006795085035264492f, 0.00877352338284254f, 0.014613769017159939f, 0.0103314109146595f, 0.007762915454804897f, 0.008858063258230686f, 0.007972015999257565f, 0.005888954270631075f, 0.009154942817986012f, 0.011246368288993835f, 0.005796134937554598f, 0.00732277799397707f, 0.0068840705789625645f, 0.007047220133244991f, 0.01033066213130951f, 0.005195022094994783f, 0.009470716118812561f, 0.0062243035063147545f, 0.008395958691835403f, 0.009077237918972969f, 0.009907927364110947f, 0.008334865793585777f, 0.009870924055576324f, 0.008401595056056976f, 0.007750730030238628f, 0.016705496236681938f, 0.006610567215830088f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.768153929850087e-05f, 0.00010606456635287032f, 0.0001326800702372566f, 7.127173739718273e-05f, 0.00010273121733916923f, 5.291727575240657e-05f, 0.00010721361468313262f, 0.00011753270518966019f, 0.00014760230260435492f, 6.999722972977906e-05f, 0.00015268639253918082f, 9.930685337167233e-05f, 0.00010662365093594417f, 0.00010172802285524085f, 0.00011964128498220816f, 8.686503861099482e-05f, 6.554002175107598e-05f, 6.165610830066726e-05f, 0.00010683818982215598f, 7.271746289916337e-05f, 0.00014198421558830887f, 0.00011057771189371124f, 0.00010193044727202505f, 8.697447628946975e-05f, 0.00011096966045442969f, 0.00011448487202869728f, 8.291311678476632e-05f, 0.00011748229735530913f, 0.00013432289415504783f, 7.750153599772602e-05f, 0.00011650471424218267f, 9.133033745456487e-05f, 8.22562724351883e-05f, 8.405529661104083e-05f, 9.222110384143889e-05f, 0.00014615383406635374f, 8.868810982676223e-05f, 0.00014443193504121155f, 9.981771290767938e-05f, 6.277598004089668e-05f, 8.191219967557117e-05f, 5.5038406571839005e-05f, 0.00011520964471856132f, 0.00010405135253677145f, 7.19031086191535e-05f, 8.179937867680565e-05f, 0.00011279698082944378f, 0.00010083126107929274f, 0.00012311016325838864f, 9.385463636135682e-05f, 9.434919047635049e-05f, 8.742992940824479e-05f, 6.878784188302234e-05f, 0.00012262848031241447f, 0.0001160870015155524f, 8.854792395140976e-05f, 0.00012548638915177435f, 0.00014176366676110774f, 0.00012866599718108773f, 0.0001365095522487536f, 9.214979218086228e-05f, 8.022900146897882e-05f, 8.397040801355615e-05f, 0.00011698000162141398f, 0.00010681432468118146f, 8.177410927601159e-05f, 0.00011296480806777254f, 9.665489051258191e-05f, 0.0001104376933653839f, 0.00010527582344366238f, 0.00010892756108660251f, 0.00013458220928441733f, 8.130492642521858e-05f, 7.360609743045643e-05f, 7.955745968502015e-05f, 9.536298603052273e-05f, 0.00011900010576937348f, 0.00012811757915187627f, 7.219970575533807e-05f, 0.0001469468988943845f, 0.0001078148270607926f, 9.847321780398488e-05f, 0.00013887342356611043f, 0.00012065849296050146f, 0.00011710146645782515f, 0.00014462240505963564f, 0.00014544792065862566f, 0.00010047569230664521f, 0.00012662440713029355f, 9.726511780172586e-05f, 0.00011938263924093917f, 0.00011855734192067757f, 6.984826904954389e-05f, 8.344109664903954e-05f, 0.00010401031613582745f, 0.00012057642743457109f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012466136831790209f, 0.0015079746954143047f, 0.0018863810691982508f, 0.001013307017274201f, 0.0014605827163904905f, 0.0007523521780967712f, 0.0015243112575262785f, 0.001671023084782064f, 0.0020985379815101624f, 0.0009951867396011949f, 0.002170821186155081f, 0.00141189678106457f, 0.001515923417173326f, 0.0014463197439908981f, 0.001701001892797649f, 0.0012350050965324044f, 0.0009318162919953465f, 0.000876596721354872f, 0.0015189736150205135f, 0.00103386165574193f, 0.002018662868067622f, 0.0015721403760835528f, 0.0014491977635771036f, 0.0012365609873086214f, 0.0015777129447087646f, 0.001627690508030355f, 0.0011788185220211744f, 0.0016703064320608974f, 0.001909737940877676f, 0.0011018792865797877f, 0.0016564076067879796f, 0.0012984905624762177f, 0.0011694798013195395f, 0.0011950575280934572f, 0.0013111550360918045f, 0.0020779443439096212f, 0.001260924618691206f, 0.002053463365882635f, 0.0014191599329933524f, 0.0008925184374675155f, 0.0011645880294963717f, 0.000782509392593056f, 0.0016379948938265443f, 0.001479351776652038f, 0.0010222835699096322f, 0.0011629839427769184f, 0.0016036928864195943f, 0.001433570054359734f, 0.0017503207782283425f, 0.0013343797763809562f, 0.0013414111454039812f, 0.001243036356754601f, 0.0009779921965673566f, 0.0017434724140912294f, 0.0016504687955603004f, 0.001258931471966207f, 0.0017841046210378408f, 0.002015527104958892f, 0.0018293107859790325f, 0.0019408267689868808f, 0.0013101411750540137f, 0.0011406571138650179f, 0.0011938506504520774f, 0.0016631650505587459f, 0.0015186343807727098f, 0.0011626246850937605f, 0.0016060789348557591f, 0.001374192419461906f, 0.0015701496740803123f, 0.0014967606402933598f, 0.0015486793126910925f, 0.0019134246977046132f, 0.0011559540871530771f, 0.0010464958613738418f, 0.0011311094276607037f, 0.0013558247592300177f, 0.001691885874606669f, 0.0018215137533843517f, 0.0010265004821121693f, 0.002089219866320491f, 0.0015328590525314212f, 0.0014000445371493697f, 0.001974435057491064f, 0.0017154640518128872f, 0.0016648919554427266f, 0.0020561714190989733f, 0.002067908179014921f, 0.0014285147190093994f, 0.0018002844881266356f, 0.00138286838773638f, 0.0016973245656117797f, 0.0016855908324941993f, 0.0009930689120665193f, 0.001186325098387897f, 0.0014787683030590415f, 0.0017142972210422158f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.171337347244844e-05f, 7.971231389092281e-05f, 7.770262891426682e-05f, 7.635548536200076e-05f, 5.616491398541257e-05f, 7.685994205530733e-05f, 8.092104690149426e-05f, 9.74724898696877e-05f, 9.096506255446002e-05f, 8.629875082988292e-05f, 8.898185478756204e-05f, 7.703543815296143e-05f, 9.426751057617366e-05f, 9.049700747709721e-05f, 7.509467104682699e-05f, 7.527838897658512e-05f, 6.007685442455113e-05f, 7.898354670032859e-05f, 9.80078912107274e-05f, 6.366075103869662e-05f, 9.383446740685031e-05f, 0.00010214274516329169f, 9.981082257581875e-05f, 9.217883052770048e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003511474933475256f, 0.0039031461346894503f, 0.003804741194471717f, 0.0037387777119874954f, 0.0027501380536705256f, 0.0037634787149727345f, 0.003962332382798195f, 0.00477278046309948f, 0.004454141482710838f, 0.004225653596222401f, 0.00435703294351697f, 0.003772071795538068f, 0.004615847487002611f, 0.004431223031133413f, 0.00367704126983881f, 0.0036860371474176645f, 0.002941687824204564f, 0.0038674618117511272f, 0.004798996727913618f, 0.003117174841463566f, 0.004594643134623766f, 0.00500146159902215f, 0.004887277726083994f, 0.004513574298471212f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012460649304557592f, 0.00010035731247626245f, 0.0001839543110691011f, 0.00023409286222886294f, 9.874645911622792e-05f, 0.0001203576975967735f, 0.00022433866979554296f, 0.00025499871117062867f, 0.00011347605322953314f, 0.00023005799448583275f, 0.00010161732643609866f, 0.0001841391931520775f, 0.0001361896429443732f, 0.00015021050057839602f, 0.00011058825475629419f, 0.00010492072760825977f, 0.00013766901975031942f, 0.00012395912199281156f, 0.00010109243157785386f, 0.00017108101746998727f, 0.00026446630363352597f, 0.00015482002345379442f, 0.0001518387725809589f, 0.0001656351232668385f, 0.00013531734293792397f, 0.00012509366206359118f, 9.495538688497618e-05f, 0.00016753935778979212f, 0.0002275741717312485f, 0.00017039159138221294f, 0.00013962019875179976f, 0.0001204271538881585f, 0.00010305568139301613f, 0.000308111630147323f, 0.00010431711416458711f, 0.00011121485295007005f, 0.00018212429131381214f, 0.00017056446813512594f, 0.00036085513420403004f, 0.00017864633991848677f, 0.0001265162427444011f, 0.0001331310922978446f, 0.00020056137873325497f, 0.00019051888375543058f, 0.0001214586227433756f, 0.00021824603027198464f, 0.00011365006503183395f, 0.00017774951993487775f, 0.00013463619688991457f, 0.0001693937520030886f, 0.00014243778423406184f, 0.0002071211056318134f, 0.0002743106451816857f, 0.00011349423584761098f, 0.00020334305008873343f, 0.00031427713111042976f, 0.00011290395923424512f, 0.00019379121658857912f, 0.0001806102809496224f, 0.00020695447165053338f, 0.00014816132897976786f, 0.0001460098719689995f, 0.00017998013936448842f, 0.00013742530427407473f, 0.0002728437539190054f, 0.0001513441529823467f, 0.00018180992628913373f, 8.014713239390403e-05f, 0.00019194225023966283f, 0.00020975097140762955f, 0.0002078833058476448f, 0.00030241868807934225f, 0.00017099000979214907f, 0.00015643061487935483f, 0.00012509668886195868f, 0.00018909068603534251f, 0.00022503883519675583f, 0.00012509606312960386f, 0.00025275058578699827f, 0.0001526095438748598f, 0.00023473077453672886f, 0.0001722952292766422f, 0.0001653148647164926f, 0.0002065540465991944f, 0.00022998335771262646f, 0.0001328022190136835f, 0.00019999934011138976f, 0.00020014200708828866f, 0.00013094312453176826f, 0.00015817180974408984f, 0.00011900930985575542f, 0.00012376595987007022f, 0.00025548969279043376f, 0.00013059026969131082f, 0.00012389749463181943f, 0.0002549602941144258f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006468336563557386f, 0.005209559109061956f, 0.009549088776111603f, 0.012151786126196384f, 0.005125939380377531f, 0.006247781217098236f, 0.011645444668829441f, 0.01323701161891222f, 0.005890554282814264f, 0.011942335404455662f, 0.005274966359138489f, 0.009558686055243015f, 0.007069619372487068f, 0.0077974433079361916f, 0.005740648601204157f, 0.005446446593850851f, 0.007146413903683424f, 0.006434731651097536f, 0.005247719120234251f, 0.008880834095180035f, 0.013728475198149681f, 0.008036724291741848f, 0.007881967350840569f, 0.008598137646913528f, 0.007024338468909264f, 0.006493625696748495f, 0.004929144401103258f, 0.008696986362338066f, 0.011813400313258171f, 0.008845046162605286f, 0.00724769989028573f, 0.00625138683244586f, 0.005349631886929274f, 0.015994109213352203f, 0.005415112711489201f, 0.0057731750421226025f, 0.009454092010855675f, 0.00885402038693428f, 0.01873202994465828f, 0.009273551404476166f, 0.006567471660673618f, 0.006910849828273058f, 0.010411162860691547f, 0.009889855980873108f, 0.006304930429905653f, 0.011329174973070621f, 0.00589958718046546f, 0.009226997382938862f, 0.006988979410380125f, 0.008793247863650322f, 0.00739396084100008f, 0.010751679539680481f, 0.014239495620131493f, 0.005891498178243637f, 0.010555559769272804f, 0.016314160078763962f, 0.005860856734216213f, 0.010059723630547523f, 0.009375499561429024f, 0.010743029415607452f, 0.0076910704374313354f, 0.007579388562589884f, 0.009342788718640804f, 0.00713376235216856f, 0.014163349755108356f, 0.007856291718780994f, 0.009437773376703262f, 0.004160446580499411f, 0.009963743388652802f, 0.010888195596635342f, 0.01079124491661787f, 0.015698587521910667f, 0.008876110427081585f, 0.008120330050587654f, 0.006493783090263605f, 0.009815718047320843f, 0.011681790463626385f, 0.006493750028312206f, 0.013120311312377453f, 0.007921977899968624f, 0.012184900231659412f, 0.008943864144384861f, 0.008581512607634068f, 0.01072224322706461f, 0.011938461102545261f, 0.006893777754157782f, 0.010381987318396568f, 0.01038939319550991f, 0.006797271780669689f, 0.008210715837776661f, 0.006177786272019148f, 0.0064247045665979385f, 0.013262498192489147f, 0.006778954993933439f, 0.006431532558053732f, 0.013235016725957394f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001331503299297765f, 0.0001303708995692432f, 0.0001017113245325163f, 9.252697782358155e-05f, 0.00013345527986530215f, 0.00010269023186992854f, 7.597147487103939e-05f, 7.065069075906649e-05f, 8.56778715387918e-05f, 6.753428897354752e-05f, 0.0001352763210888952f, 7.74955187807791e-05f, 7.952792657306418e-05f, 9.766877337824553e-05f, 0.00012088527728337795f, 9.725380368763581e-05f, 0.0001540403172839433f, 0.00013704504817724228f, 0.00013582216342911124f, 0.00013724293967243284f, 0.00016441743355244398f, 0.0001674399827606976f, 0.00015533206169493496f, 0.00013074140588287264f, 0.00010900661436608061f, 0.00014245431520976126f, 0.00015462130249943584f, 0.00013303980813361704f, 0.00012923851318191737f, 8.207253267755732e-05f, 0.00011520990665303543f, 0.0001311085798079148f, 0.00014929604367353022f, 9.118632442550734e-05f, 0.0001430291449651122f, 0.00012495277042035013f, 8.317885658470914e-05f, 0.00011461356916697696f, 7.372585969278589e-05f, 0.00010047520481748506f, 0.00013200529792811722f, 0.00012525108468253165f, 9.085684723686427e-05f, 0.00016287820471916348f, 9.004252206068486e-05f, 5.628395956591703e-05f, 8.705475920578465e-05f, 0.00016794765542726964f, 7.092641317285597e-05f, 0.00012442405568435788f, 0.00011450035526650026f, 5.9185069403611124e-05f, 5.542178769246675e-05f, 0.00012096105638192967f, 0.0001274083333555609f, 0.00010834678687388077f, 8.357399929082021e-05f, 7.411197293549776e-05f, 9.241027146345004e-05f, 0.00014436501078307629f, 0.00012809221516363323f, 0.00011822803207905963f, 9.773328201845288e-05f, 6.958977610338479e-05f, 4.734460526378825e-05f, 0.00013100681826472282f, 7.947489939397201e-05f, 0.00010364913032390177f, 0.00015192672435659915f, 9.364065044792369e-05f, 0.0001483282831031829f, 8.310574776260182e-05f, 0.00010953838500427082f, 8.716131560504436e-05f, 8.090266783256084e-05f, 0.00010857429879251868f, 0.00010867039964068681f, 0.00010835705325007439f, 7.455982267856598e-05f, 9.931813838193193e-05f, 0.00013558307546190917f, 0.00012875070387963206f, 5.585624967352487e-05f, 8.619664004072547e-05f, 8.636079292045906e-05f, 0.00015938813157845289f, 7.698219269514084e-05f, 0.000155165049363859f, 0.00013487262185662985f, 7.048292900435627e-05f, 0.00012832572974730283f, 0.00012434397649485618f, 0.00011787408584496006f, 0.0001303480821661651f, 9.899229189613834e-05f, 6.706860585836694e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002275985898450017f, 0.0022284758742898703f, 0.001738587743602693f, 0.0015815964434295893f, 0.002281198278069496f, 0.001755320467054844f, 0.0012986073270440102f, 0.0012076572747901082f, 0.001464522210881114f, 0.001154387486167252f, 0.002312326105311513f, 0.0013246583985164762f, 0.00135939905885607f, 0.0016694869846105576f, 0.002066334942355752f, 0.0016623936826363206f, 0.0026330656837671995f, 0.0023425596300512552f, 0.0023216563276946545f, 0.0023459421936422586f, 0.0028104453813284636f, 0.0028621109668165445f, 0.0026551459450274706f, 0.002234809100627899f, 0.0018632886931300163f, 0.002435022033751011f, 0.002642996609210968f, 0.0022740967106074095f, 0.0022091197315603495f, 0.0014028948498889804f, 0.0019693237263709307f, 0.0022410855162888765f, 0.0025519703049212694f, 0.001558680203743279f, 0.0024448479525744915f, 0.002135861897841096f, 0.0014218057040125132f, 0.0019591304007917643f, 0.001260222285054624f, 0.0017174582462757826f, 0.002256413223221898f, 0.0021409611217677593f, 0.0015530482633039355f, 0.0027841348201036453f, 0.0015391287161037326f, 0.0009620816563256085f, 0.0014880578964948654f, 0.002870788797736168f, 0.0012123703490942717f, 0.002126824576407671f, 0.0019571951124817133f, 0.0010116713820025325f, 0.0009473442332819104f, 0.0020676301792263985f, 0.0021778359077870846f, 0.0018520100275054574f, 0.00142856000456959f, 0.0012668222188949585f, 0.001579601550474763f, 0.0024676823522895575f, 0.0021895256359130144f, 0.002020913641899824f, 0.0016705896705389023f, 0.0011895226780325174f, 0.0008092781063169241f, 0.0022393460385501385f, 0.0013584926491603255f, 0.001771711278706789f, 0.0025969373527914286f, 0.0016006327932700515f, 0.0025354279205203056f, 0.001420555985532701f, 0.0018723784014582634f, 0.0014898792142048478f, 0.0013828979572281241f, 0.001855898997746408f, 0.001857541617937386f, 0.0018521854653954506f, 0.001274477457627654f, 0.0016976800980046391f, 0.002317569451406598f, 0.0022007813677191734f, 0.0009547706576995552f, 0.0014733896823599935f, 0.001476195640861988f, 0.0027244777884334326f, 0.0013158839428797364f, 0.0026522912085056305f, 0.0023054254706948996f, 0.0012047897325828671f, 0.0021935170516371727f, 0.0021254555322229862f, 0.0020148635376244783f, 0.00222808588296175f, 0.0016921103233471513f, 0.0011464274721220136f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021377218945417553f, 0.0001728487986838445f, 0.0001369360979879275f, 0.000216221553273499f, 0.00019767168851103634f, 0.00023782039352227002f, 0.00018532465037424117f, 0.00018959461885970086f, 0.00017925254360307008f, 0.00017079275858122855f, 0.00017732330888975412f, 0.00018411362543702126f, 0.00016675562073942274f, 0.00017687780200503767f, 0.0001924776443047449f, 0.00014680178719572723f, 0.00022545519459526986f, 0.00018947325588669628f, 0.00019823707407340407f, 0.00019982826779596508f, 0.0001676905230851844f, 0.0002222788898507133f, 0.0002055248332908377f, 0.00017110980115830898f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029581293929368258f, 0.0023918410297483206f, 0.001894889515824616f, 0.002992023015394807f, 0.002735334448516369f, 0.0032909028232097626f, 0.00256447889842093f, 0.0026235657278448343f, 0.002480454510077834f, 0.0023633900564163923f, 0.002453758381307125f, 0.0025477211456745863f, 0.00230752513743937f, 0.002447593491524458f, 0.0026634603273123503f, 0.002031408715993166f, 0.003119796048849821f, 0.002621886320412159f, 0.002743158023804426f, 0.002765176584944129f, 0.0023204621393233538f, 0.0030758429784327745f, 0.002844004426151514f, 0.002367777284234762f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00020233338000252843f, 0.00012517043796833605f, 0.00018967865617014468f, 0.00022712626378051937f, 0.00018808807362802327f, 0.00018082524184137583f, 0.0001567499275552109f, 0.00032138897222466767f, 0.00019590163719840348f, 0.000547608535271138f, 0.00019046125817112625f, 0.000218014043639414f, 0.00013641369878314435f, 0.0001707939081825316f, 0.0004163397243246436f, 0.00021578912856057286f, 0.0001660798880038783f, 0.00014728980022482574f, 0.00031484660576097667f, 0.00026077215443365276f, 0.0001824700302677229f, 0.00017729224055074155f, 0.00036677790922112763f, 0.00014563181321136653f, 0.0001678222033660859f, 0.0001922148949233815f, 0.0002918487589340657f, 0.00022792970412410796f, 0.0006449671927839518f, 0.0002102034050039947f, 0.00014276748697739094f, 0.0001212326023960486f, 0.00023157228133641183f, 0.00017842638771981f, 0.00039924876182340086f, 0.00025981239741668105f, 0.00029011076549068093f, 0.00020580447744578123f, 0.00017357620527036488f, 0.00018244459351990372f, 0.00013830351235810667f, 0.0007404931238852441f, 0.00031750850030221045f, 0.00015393935609608889f, 0.00014693265256937593f, 0.00015616744349244982f, 0.0001865130034275353f, 0.00019094451272394508f, 0.00016600142407696694f, 0.0001453435397706926f, 0.0003268797881901264f, 0.00025261673727072775f, 0.0003921528405044228f, 0.00013373783440329134f, 0.00016198010416701436f, 0.0001597940718056634f, 0.0003843409940600395f, 0.0005200521554797888f, 0.0002486055309418589f, 0.00023078864614944905f, 0.0004887552931904793f, 0.000410992099205032f, 0.000436970527516678f, 0.0004435475857462734f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007917828857898712f, 0.0048982431180775166f, 0.007422616705298424f, 0.00888803880661726f, 0.00736037315800786f, 0.007076160050928593f, 0.006134030409157276f, 0.012576783075928688f, 0.007666138466447592f, 0.021429339423775673f, 0.007453242316842079f, 0.008531454019248486f, 0.005338221322745085f, 0.006683608051389456f, 0.016292450949549675f, 0.008444387465715408f, 0.006499135866761208f, 0.005763831548392773f, 0.012320763431489468f, 0.01020468957722187f, 0.007140524685382843f, 0.00693790428340435f, 0.014352969825267792f, 0.005698950029909611f, 0.0065673175267875195f, 0.007521866355091333f, 0.011420797556638718f, 0.008919479325413704f, 0.025239236652851105f, 0.008225803263485432f, 0.0055868616327643394f, 0.004744145553559065f, 0.009062022902071476f, 0.006982286460697651f, 0.015623637475073338f, 0.010167132131755352f, 0.011352784931659698f, 0.00805366225540638f, 0.006792486645281315f, 0.007139529567211866f, 0.005412174388766289f, 0.0289774127304554f, 0.01242492999881506f, 0.006024045404046774f, 0.005749855190515518f, 0.006111236289143562f, 0.007298736833035946f, 0.007472153287380934f, 0.0064960652962327f, 0.0056876689195632935f, 0.012791652232408524f, 0.009885546751320362f, 0.015345956198871136f, 0.005233507603406906f, 0.006338701117783785f, 0.006253155879676342f, 0.015040257945656776f, 0.0203509870916605f, 0.009728577919304371f, 0.009031357243657112f, 0.01912626065313816f, 0.016083184629678726f, 0.017099788412451744f, 0.01735716499388218f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023512665939051658f, 0.00018997093138750643f, 0.00015682876983191818f, 0.00023167935432866216f, 0.0001661098503973335f, 0.00028093589935451746f, 0.00012877934204880148f, 0.0001296523550990969f, 0.00018581553013063967f, 0.00016028247773647308f, 0.00016051391139626503f, 0.00022604080731980503f, 0.00013712893996853381f, 0.00016326591139659286f, 0.00016476702876389027f, 0.00021980445308145136f, 0.0001599922397872433f, 0.00013173677143640816f, 0.00013775321713183075f, 0.0001273799716727808f, 0.0001585474528837949f, 0.00016882728959899396f, 0.00018228773842565715f, 0.00020353526633698493f, 0.0001538836513645947f, 0.0002466925070621073f, 0.0002628195798024535f, 0.00015754233754705638f, 0.0001714759855531156f, 0.00015290032024495304f, 0.0002131492947228253f, 0.00014659501903224736f, 0.0001174837670987472f, 0.00014205336628947407f, 0.00017121966811828315f, 8.858725777827203e-05f, 8.674291166244075e-05f, 0.0001228454348165542f, 0.00021056632976979017f, 0.00015878495469223708f, 0.00015838822582736611f, 3.668229328468442e-05f, 0.00017412350280210376f, 0.00016708177281543612f, 0.00016140934894792736f, 0.00018903653835877776f, 0.00017463219410274178f, 0.00023936991055961698f, 0.00019392503600101918f, 0.00016971846343949437f, 0.000158349284902215f, 0.00016239115211647004f, 0.0002926467277575284f, 0.00015208365221042186f, 0.00017077529628295451f, 0.00017982297868002206f, 0.00017660083540249616f, 0.00014201368321664631f, 0.0001674891827860847f, 0.0002827043063007295f, 0.0002175493718823418f, 0.00019516322936397046f, 0.00019579537911340594f, 7.217938400572166e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003105887910351157f, 0.002509406767785549f, 0.0020716178696602583f, 0.0030603508930653334f, 0.0021942155435681343f, 0.003711001481860876f, 0.0017011010786518455f, 0.0017126330640166998f, 0.0024545162450522184f, 0.0021172394044697285f, 0.0021202964708209038f, 0.0029858690686523914f, 0.0018113944679498672f, 0.0021566487848758698f, 0.002176477573812008f, 0.002903490327298641f, 0.00211340538226068f, 0.0017401670338585973f, 0.0018196407472714782f, 0.0016826161881908774f, 0.00209432072006166f, 0.002230111276730895f, 0.002407916123047471f, 0.0026885836850851774f, 0.002032714430242777f, 0.003258666256442666f, 0.003471695352345705f, 0.002081043552607298f, 0.0022650992032140493f, 0.002019725274294615f, 0.002815579529851675f, 0.0019364359322935343f, 0.001551892957650125f, 0.0018764432752504945f, 0.0022617133799940348f, 0.0011701866751536727f, 0.0011458239750936627f, 0.0016227175947278738f, 0.0027814600616693497f, 0.002097457880154252f, 0.0020922173280268908f, 0.00048455200158059597f, 0.002300071297213435f, 0.0022070540580898523f, 0.0021321247331798077f, 0.0024970639497041702f, 0.002306790789589286f, 0.003161938861012459f, 0.002561638131737709f, 0.0022418831940740347f, 0.0020917030051350594f, 0.002145093632861972f, 0.003865694859996438f, 0.0020089375320822f, 0.002255843486636877f, 0.0023753580171614885f, 0.002332795411348343f, 0.0018759190570563078f, 0.002212435705587268f, 0.003734361147508025f, 0.002873701974749565f, 0.002577994018793106f, 0.0025863442569971085f, 0.0009534481796436012f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018271182489115745f, 0.00011942924902541563f, 0.00011234162957407534f, 0.0001963285030797124f, 0.00013929069973528385f, 0.00012159074685769156f, 0.00013794784899801016f, 0.000164595854585059f, 0.00012278265785425901f, 0.00016276014503091574f, 0.00012865096505265683f, 0.00012558489106595516f, 0.00013974389003124088f, 0.00014056163490749896f, 0.00011706486839102581f, 0.00021550719975493848f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006026853807270527f, 0.003939441870898008f, 0.0037056528963148594f, 0.006476007867604494f, 0.004594583064317703f, 0.004010740201920271f, 0.0045502884313464165f, 0.005429288372397423f, 0.004050055984407663f, 0.005368736572563648f, 0.0042436253279447556f, 0.004142489284276962f, 0.004609532188624144f, 0.004636505618691444f, 0.0038614515215158463f, 0.007108628284186125f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000548623560462147f, 0.00030493357917293906f, 0.00028516518068499863f, 0.00046107167145237327f, 0.00038038354250602424f, 0.0001740653970045969f, 0.000278723135124892f, 0.00024113662948366255f, 0.00021543397451750934f, 0.00030964589677751064f, 0.000353788782376796f, 0.00024024189042393118f, 0.00023058970691636205f, 0.0002296397724421695f, 0.0001345455093542114f, 0.0003904442710336298f, 0.0003475526755210012f, 0.0002186248020734638f, 0.0006112590781413019f, 0.00025002253823913634f, 0.0005336480680853128f, 0.0002044279535766691f, 0.0002593528770375997f, 0.00021494652901310474f, 0.0005043306155130267f, 0.00032074577757157385f, 0.0008147521875798702f, 0.0006845788448117673f, 0.0005215597921051085f, 0.0004605001013260335f, 0.00016897644673008472f, 0.00041998724918812513f, 0.00023654167307540774f, 0.00046943550114519894f, 0.0004883960355073214f, 0.00013315757678356022f, 0.0003389621269889176f, 0.00017172539082821459f, 0.00037595952744595706f, 0.0003275204508099705f, 0.0002199827431468293f, 0.0004233731597196311f, 0.0004481435753405094f, 0.00015255539619829506f, 0.000493289961013943f, 0.0001693896483629942f, 0.00019564683316275477f, 0.0004976788768544793f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020486067980527878f, 0.011386477388441563f, 0.01064830832183361f, 0.01721680536866188f, 0.014203842729330063f, 0.006499749142676592f, 0.010407757014036179f, 0.009004245512187481f, 0.008044486865401268f, 0.011562439613044262f, 0.013210771605372429f, 0.008970835246145725f, 0.00861041434109211f, 0.00857494305819273f, 0.005024042911827564f, 0.01457951869815588f, 0.012977910228073597f, 0.008163634687662125f, 0.022824930027127266f, 0.009336053393781185f, 0.019926870241761208f, 0.007633512374013662f, 0.009684455581009388f, 0.008026285097002983f, 0.0188321303576231f, 0.011976918205618858f, 0.030423535034060478f, 0.025562752038240433f, 0.019475484266877174f, 0.017195463180541992f, 0.0063097234815359116f, 0.015682678669691086f, 0.008832666091620922f, 0.017529118806123734f, 0.018237121403217316f, 0.004972216673195362f, 0.012657131999731064f, 0.006412371061742306f, 0.014038646593689919f, 0.012229890562593937f, 0.008214341476559639f, 0.015809111297130585f, 0.016734059900045395f, 0.005696547217667103f, 0.018419863656163216f, 0.006325152702629566f, 0.007305617909878492f, 0.01858375035226345f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.111856343224645e-05f, 0.0001786883221939206f, 8.626720955362543e-05f, 9.167951066046953e-05f, 0.00013204911374486983f, 0.0002181079180445522f, 0.00020523802959360182f, 0.00013062790094409138f, 0.0001982303656404838f, 0.00024019618285819888f, 0.0002047371817752719f, 0.00025093904696404934f, 0.0002421828976366669f, 0.0002487946767359972f, 0.00015162627096287906f, 9.266199776902795e-05f, 0.0002146017795894295f, 0.0001078070854418911f, 7.060802454361692e-05f, 0.00038173282518982887f, 0.0001788200461305678f, 0.00010751753143267706f, 0.0002031495387200266f, 0.0001525792176835239f, 0.00014979386469349265f, 0.00012381773558445275f, 9.792530909180641e-05f, 0.00018794334027916193f, 0.00015070696827024221f, 0.00013664600555785f, 0.0001659427216509357f, 0.00017001474043354392f, 0.00020425659022293985f, 0.00014093046775087714f, 0.00021189409017097205f, 0.00019451748812571168f, 0.0001896142930490896f, 0.00024026317987591028f, 0.0001251554349437356f, 0.0002442883269395679f, 0.0001744538894854486f, 0.0001390789111610502f, 0.0001638183748582378f, 0.00024604087229818106f, 0.00011471696780063212f, 0.0002457873779349029f, 0.00031851715175434947f, 0.0001473157899454236f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017656695563346148f, 0.003462571417912841f, 0.001671661389991641f, 0.0017765394877642393f, 0.002558810170739889f, 0.004226433113217354f, 0.003977044019848108f, 0.0025312702637165785f, 0.003841251600533724f, 0.004654453136026859f, 0.00396733870729804f, 0.004862625151872635f, 0.004692951217293739f, 0.004821072332561016f, 0.0029381706845015287f, 0.0017955778166651726f, 0.00415849220007658f, 0.002089055022224784f, 0.0013682221760973334f, 0.007397110108286142f, 0.003465123940259218f, 0.0020834440365433693f, 0.00393657386302948f, 0.002956636715680361f, 0.0029026628471910954f, 0.0023993048816919327f, 0.001897568698041141f, 0.003641912480816245f, 0.0029203565791249275f, 0.002647887449711561f, 0.003215590724721551f, 0.003294497262686491f, 0.003958025947213173f, 0.0027309104334563017f, 0.004106023348867893f, 0.003769304370507598f, 0.0036742917727679014f, 0.004655751399695873f, 0.0024252263829112053f, 0.00473374966531992f, 0.0033805177081376314f, 0.002695031464099884f, 0.0031744258012622595f, 0.004767709877341986f, 0.002222952665761113f, 0.004762797616422176f, 0.006172134540975094f, 0.002854643389582634f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016975696780718863f, 0.00019550138677004725f, 0.00022944394731894135f, 0.00021464111341629177f, 0.00026460294611752033f, 0.00019182365213055164f, 0.00024032442888710648f, 0.00026347715174779296f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012395078083500266f, 0.0014274847926571965f, 0.0016753218369558454f, 0.0015672366134822369f, 0.0019320410210639238f, 0.0014006312703713775f, 0.001754767494276166f, 0.0019238208187744021f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005068046739324927f, 0.0010600066743791103f, 0.00042815934284590185f, 0.0007386620854958892f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005545354448258877f, 0.011598378419876099f, 0.004684832878410816f, 0.00808229111135006f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0021073431707918644f, 0.002063919324427843f, 0.00203781109303236f, 0.00026594704831950366f, 0.0007354901172220707f, 0.0007647614111192524f, 0.0003131020348519087f, 0.0005247167428024113f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0191357359290123f, 0.018741425126791f, 0.018504349514842033f, 0.0024149329401552677f, 0.006678619887679815f, 0.006944417953491211f, 0.002843123860657215f, 0.004764691926538944f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003758967504836619f, 0.00047600921243429184f, 0.00036818120861425996f, 0.0012152635026723146f, 0.0007694197702221572f, 0.0004596830112859607f, 0.0012685803230851889f, 0.0013382253237068653f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0038491624873131514f, 0.004874308593571186f, 0.0037701555993407965f, 0.01244423259049654f, 0.007878816686570644f, 0.004707129206508398f, 0.012990194372832775f, 0.013703355565667152f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002166415360989049f, 0.0003281958925072104f, 8.414224430453032e-05f, 0.00034699321258813143f, 0.00015046511543914676f, 0.0001937053893925622f, 9.076658898266032e-05f, 0.00032643400481902063f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0591895617544651f, 0.08966780453920364f, 0.02298886328935623f, 0.09480350464582443f, 0.04110921919345856f, 0.05292307958006859f, 0.02479872852563858f, 0.08918642997741699f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036601307801902294f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09765676409006119f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1101260632276535f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09139265865087509f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1369551420211792f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.051605671644210815f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.026780325919389725f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03031628578901291f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04513042792677879f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07570352405309677f),
    AI_PACK_INTQ_ZP(-47)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.025554148480296135f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07226600497961044f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05850226804614067f),
    AI_PACK_INTQ_ZP(37)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019264070317149162f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02042257972061634f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04305392503738403f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07033577561378479f),
    AI_PACK_INTQ_ZP(23)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018543411046266556f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021944168955087662f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03263593092560768f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0829671323299408f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01623975858092308f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01909984089434147f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.045018021017313004f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09043709188699722f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11765190213918686f),
    AI_PACK_INTQ_ZP(-30)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014247201383113861f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01979159563779831f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03027627058327198f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022118961438536644f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10105957835912704f),
    AI_PACK_INTQ_ZP(59)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1524, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1524, 1524),
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
  AI_SHAPE_INIT(4, 1, 50, 1, 1), AI_STRIDE_INIT(4, 4, 4, 200, 200),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 50), AI_STRIDE_INIT(4, 1, 256, 256, 256),
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
  AI_SHAPE_INIT(4, 1, 50, 5, 5), AI_STRIDE_INIT(4, 1, 1, 50, 250),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conversion_40_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 50, 5, 5), AI_STRIDE_INIT(4, 4, 4, 200, 1000),
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
                     1, 1, 78264, 1,
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
    conv2d_39_output_array.data = AI_PTR(activations + 1524);
    conv2d_39_output_array.data_start = AI_PTR(activations + 1524);
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
    conv2d_39_bias_array.data = AI_PTR(weights + 78064);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 78064);
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
      
      .n_macc            = 6404874,
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

