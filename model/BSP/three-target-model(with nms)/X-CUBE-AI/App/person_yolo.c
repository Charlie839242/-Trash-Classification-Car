/**
  ******************************************************************************
  * @file    person_yolo.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Aug 25 19:51:07 2021
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
#define AI_PERSON_YOLO_MODEL_SIGNATURE     "11777eee9023c8830125668e89729a54"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Aug 25 19:51:07 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_PERSON_YOLO_N_BATCHES
#define AI_PERSON_YOLO_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_38_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv2d_37_scratch0_array;   /* Array #1 */
AI_STATIC ai_array conv2d_36_scratch0_array;   /* Array #2 */
AI_STATIC ai_array conv2d_35_scratch0_array;   /* Array #3 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #4 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #5 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #6 */
AI_STATIC ai_array conv2d_26_scratch0_array;   /* Array #7 */
AI_STATIC ai_array conv2d_24_scratch0_array;   /* Array #8 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #9 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #10 */
AI_STATIC ai_array conv2d_20_scratch0_array;   /* Array #11 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #12 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #13 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #14 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #15 */
AI_STATIC ai_array conv2d_14_scratch0_array;   /* Array #16 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #17 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #18 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #19 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #20 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #21 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #22 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #23 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #24 */
AI_STATIC ai_array conv2d_38_bias_array;   /* Array #25 */
AI_STATIC ai_array conv2d_38_weights_array;   /* Array #26 */
AI_STATIC ai_array conv2d_37_bias_array;   /* Array #27 */
AI_STATIC ai_array conv2d_37_weights_array;   /* Array #28 */
AI_STATIC ai_array conv2d_36_bias_array;   /* Array #29 */
AI_STATIC ai_array conv2d_36_weights_array;   /* Array #30 */
AI_STATIC ai_array conv2d_35_bias_array;   /* Array #31 */
AI_STATIC ai_array conv2d_35_weights_array;   /* Array #32 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #33 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #34 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #35 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #36 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #37 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #38 */
AI_STATIC ai_array conv2d_26_bias_array;   /* Array #39 */
AI_STATIC ai_array conv2d_26_weights_array;   /* Array #40 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #41 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #42 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #43 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #44 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #45 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #46 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #47 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #48 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #49 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #50 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #51 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #52 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #53 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #54 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #55 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #56 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #57 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #58 */
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
AI_STATIC ai_array concat_13_output_array;   /* Array #85 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #86 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #87 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #88 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #89 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #90 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #91 */
AI_STATIC ai_array eltwise_21_output_array;   /* Array #92 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #93 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #94 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #95 */
AI_STATIC ai_array eltwise_25_output_array;   /* Array #96 */
AI_STATIC ai_array conv2d_26_output_array;   /* Array #97 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #98 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #99 */
AI_STATIC ai_array eltwise_29_output_array;   /* Array #100 */
AI_STATIC ai_array concat_32_output_array;   /* Array #101 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #102 */
AI_STATIC ai_array conv2d_35_output_array;   /* Array #103 */
AI_STATIC ai_array conv2d_36_output_array;   /* Array #104 */
AI_STATIC ai_array conv2d_37_output_array;   /* Array #105 */
AI_STATIC ai_array conv2d_38_output_array;   /* Array #106 */
AI_STATIC ai_array conversion_39_output_array;   /* Array #107 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_38_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_37_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_36_scratch0;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_35_scratch0;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_26_scratch0;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_24_scratch0;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_20_scratch0;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_14_scratch0;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_38_bias;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_38_weights;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_37_bias;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_37_weights;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_36_bias;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_36_weights;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_35_bias;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_35_weights;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_26_bias;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_26_weights;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #58 */
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
AI_STATIC ai_tensor concat_13_output;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #91 */
AI_STATIC ai_tensor eltwise_21_output;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #95 */
AI_STATIC ai_tensor eltwise_25_output;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_26_output;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #99 */
AI_STATIC ai_tensor eltwise_29_output;   /* Tensor #100 */
AI_STATIC ai_tensor concat_32_output;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_35_output;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_36_output;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_37_output;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_38_output;   /* Tensor #106 */
AI_STATIC ai_tensor conversion_39_output;   /* Tensor #107 */


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
AI_STATIC_CONST ai_tensor_chain concat_13_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain eltwise_21_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain eltwise_25_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_26_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain eltwise_29_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain concat_32_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_35_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain conv2d_36_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain conv2d_37_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_38_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain conversion_39_chain;   /* Chain #31 */


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
AI_STATIC ai_layer_concat concat_13_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #15 */
AI_STATIC ai_layer_eltwise eltwise_21_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #19 */
AI_STATIC ai_layer_eltwise eltwise_25_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_26_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #23 */
AI_STATIC ai_layer_eltwise eltwise_29_layer; /* Layer #24 */
AI_STATIC ai_layer_concat concat_32_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_35_layer; /* Layer #27 */
AI_STATIC ai_layer_conv2d conv2d_36_layer; /* Layer #28 */
AI_STATIC ai_layer_conv2d conv2d_37_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_38_layer; /* Layer #30 */
AI_STATIC ai_layer_nl conversion_39_layer; /* Layer #31 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1424, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2816, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1632, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 496, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
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
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 40, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11264, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
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
  concat_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  concat_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8800, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1600, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1000, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conversion_39_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1000, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.9242022972321138e-05f, 2.4682580260559916e-05f, 9.735646926856134e-06f, 1.5213880942610558e-05f, 0.00010269103950122371f, 5.6935874454211444e-05f, 6.416017276933417e-05f, 7.210709736682475e-05f, 1.978795262402855e-05f, 2.354257958359085e-05f, 2.4354676497750916e-05f, 2.360148027946707e-05f, 8.075005462160334e-05f, 5.440986933535896e-05f, 6.37881166767329e-05f, 8.125253953039646e-05f, 2.7052918085246347e-05f, 3.728763840626925e-05f, 1.1648372492345516e-05f, 1.3215209946793038e-05f, 6.79605727782473e-05f, 5.4542862926609814e-05f, 5.5519729357911274e-05f, 7.139168155845255e-05f, 2.10093057830818e-05f, 2.376428892603144e-05f, 1.0523186574573629e-05f, 1.2994949429412372e-05f, 7.514250319218263e-05f, 5.741335917264223e-05f, 6.310412572929636e-05f, 6.893659883644432e-05f, 1.694561433396302e-05f, 2.3314487407333218e-05f, 1.814640017983038e-05f, 1.2363571840978693e-05f, 6.166453385958448e-05f, 4.997266660211608e-05f, 5.864265403943136e-05f, 5.175991464057006e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012329048477113247f, 0.0015815007500350475f, 0.000623797532171011f, 0.000974807480815798f, 0.006579780485481024f, 0.003648084122687578f, 0.004110970534384251f, 0.004620158579200506f, 0.0012678845087066293f, 0.001508456887677312f, 0.0015604908112436533f, 0.0015122308395802975f, 0.005173943471163511f, 0.0034862339962273836f, 0.004087131470441818f, 0.005206139292567968f, 0.0017333767609670758f, 0.0023891516029834747f, 0.0007463527144864202f, 0.0008467455627396703f, 0.004354475997388363f, 0.0034947553649544716f, 0.003557346761226654f, 0.00457431934773922f, 0.0013461409835144877f, 0.0015226625837385654f, 0.0006742580444552004f, 0.0008326326496899128f, 0.004814647603780031f, 0.0036786783020943403f, 0.00404330575838685f, 0.004417013376951218f, 0.0010857657762244344f, 0.0014938422245904803f, 0.001162704429589212f, 0.0007921780343167484f, 0.0039510661736130714f, 0.0032019265927374363f, 0.0037574435118585825f, 0.0033164420165121555f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.074303877947386e-06f, 8.374585377168842e-06f, 1.3823593690176494e-05f, 1.5193960280157626e-05f, 7.5888865467277355e-06f, 1.154809524450684e-05f, 6.576371561095584e-06f, 1.2447553672245704e-05f, 1.0093109267472755e-05f, 8.679230631969403e-06f, 9.665641300671268e-06f, 8.288144272228237e-06f, 9.757599400472827e-06f, 1.4147462024993729e-05f, 1.3034635230724234e-05f, 1.372346559946891e-05f, 7.762495442875661e-06f, 1.6430105461040512e-05f, 9.106550351134501e-06f, 7.321221346501261e-06f, 1.0814493180077989e-05f, 8.99309634405654e-06f, 7.395625289063901e-06f, 5.989642886561342e-06f, 1.8924074538517743e-05f, 1.267767402168829e-05f, 1.3117643902660348e-05f, 1.1048351552744862e-05f, 9.32708917389391e-06f, 6.326451966742752e-06f, 1.3444388059724588e-05f, 1.8019405615632422e-05f, 5.943189989920938e-06f, 8.099166734609753e-06f, 9.346933438791893e-06f, 1.0603520422591828e-05f, 1.3601049431599677e-05f, 1.2166376109234989e-05f, 1.3151713574188761e-05f, 7.855968760850374e-06f, 8.735414667171426e-06f, 6.924457011336926e-06f, 9.790276635612827e-06f, 6.802635198255302e-06f, 7.503718279622262e-06f, 1.2437026271072682e-05f, 1.2537112525023986e-05f, 8.402328603551723e-06f, 9.288894034398254e-06f, 1.3523793313652277e-05f, 7.626596016052645e-06f, 1.35100572151714e-05f, 9.804627552512102e-06f, 1.3104821846354753e-05f, 1.7414329704479314e-05f, 1.68372080224799e-05f, 7.515833203797229e-06f, 8.505414371029474e-06f, 9.829956979956478e-06f, 9.231752301275264e-06f, 6.657927315245615e-06f, 2.026842048508115e-05f, 1.225141477334546e-05f, 1.0288782505085692e-05f, 1.7261947505176067e-05f, 8.98880261956947e-06f, 1.9961173165938817e-05f, 1.5681140212109312e-05f, 7.507992904720595e-06f, 8.764925041759852e-06f, 1.166182028100593e-05f, 1.0670722076611128e-05f, 1.612227970326785e-05f, 1.4416398698813282e-05f, 7.931867003208026e-06f, 6.33698255114723e-06f, 1.2251302905497141e-05f, 9.260052138415631e-06f, 9.938442417478655e-06f, 2.7632184355752543e-05f, 1.6023439457057975e-05f, 6.748684882040834e-06f, 6.27622421234264e-06f, 9.958261216524988e-06f, 9.335967661172617e-06f, 1.1215942322451156e-05f, 9.914720067172311e-06f, 1.1275960787315853e-05f, 1.592931403138209e-05f, 1.1129727681691293e-05f, 8.90421597432578e-06f, 9.971925464924425e-06f, 8.101613275357522e-06f, 1.6371846868423745e-05f, 8.09163975645788e-06f, 1.8116781575372443e-05f, 8.208935469156131e-06f, 1.1658748007903341e-05f, 1.0348875548515934e-05f, 8.130419701046776e-06f, 7.721336260146927e-06f, 1.207577224704437e-05f, 8.873460501490626e-06f, 1.2134317330492195e-05f, 7.564005045423983e-06f, 6.671988103335025e-06f, 8.84815108292969e-06f, 5.9628237067954615e-06f, 9.182511348626576e-06f, 8.058646017161664e-06f, 1.6093354133772664e-05f, 5.99168379267212e-06f, 1.4801311408518814e-05f, 1.2442425941117108e-05f, 1.0744421160779893e-05f, 1.9136734408675693e-05f, 6.156994004413718e-06f, 1.4100504813541193e-05f, 6.438512173190247e-06f, 1.2377551684039645e-05f, 7.388549875031458e-06f, 9.829237569647375e-06f, 9.744773706188425e-06f, 9.340111319033895e-06f, 1.2104154848202597e-05f, 8.08263666840503e-06f, 1.4163681953505147e-05f, 7.180992724897806e-06f, 9.540768587612547e-06f, 1.3467244571074843e-05f, 1.2372902347124182e-05f, 7.231854851852404e-06f, 6.860843313916121e-06f, 7.286288109753514e-06f, 9.939387382473797e-06f, 1.1717634151864331e-05f, 8.72757300385274e-06f, 1.8587252270663157e-05f, 1.2692252312263008e-05f, 8.34816000860883e-06f, 9.46712043514708e-06f, 1.0615645805955864e-05f, 9.848129593592603e-06f, 6.900039352331078e-06f, 8.705098480277229e-06f, 1.0039378139481414e-05f, 1.4837144590273965e-05f, 5.638586571876658e-06f, 8.858030923875049e-06f, 1.9015777070308104e-05f, 1.0950794603559189e-05f, 6.956893685128307e-06f, 7.695279236941133e-06f, 1.69362156157149e-05f, 1.093608807423152e-05f, 9.16902172320988e-06f, 1.0746017323981505e-05f, 6.988847871980397e-06f, 9.182432222587522e-06f, 7.675085726077668e-06f, 1.0531396583246533e-05f, 1.0922827641479671e-05f, 1.3041129932389595e-05f, 9.376277375849895e-06f, 9.40556674322579e-06f, 1.2439399142749608e-05f, 1.0913477126450744e-05f, 7.848886525607668e-06f, 1.110067023546435e-05f, 7.092369287420297e-06f, 8.897120096662547e-06f, 6.422089882107684e-06f, 7.602958248753566e-06f, 9.945630154106766e-06f, 8.646075912110973e-06f, 1.2529082596302032e-05f, 1.1366268154233694e-05f, 7.116914730431745e-06f, 7.7448175943573e-06f, 1.9184488337486982e-05f, 9.49237983149942e-06f, 7.626734713994665e-06f, 1.077041270036716e-05f, 1.0122605090145953e-05f, 1.1752381396945566e-05f, 1.3144564945832826e-05f, 1.5313091353164054e-05f, 7.0193823376030196e-06f, 9.919475814967882e-06f, 9.76489536697045e-06f, 6.3648571995145176e-06f, 7.414063020405592e-06f, 6.025612037774408e-06f, 7.064301371428883e-06f, 6.858942924736766e-06f, 1.425926893716678e-05f, 7.514634944527643e-06f, 1.0519034731260035e-05f, 7.5094317253388e-06f, 1.122957473853603e-05f, 7.365656983893132e-06f, 1.123926540458342e-05f, 8.169395186996553e-06f, 7.513650416512974e-06f, 1.2106672329537105e-05f, 1.1102800272055902e-05f, 5.758785846410319e-06f, 7.424818250001408e-06f, 1.0734320312622003e-05f, 7.628612820553826e-06f, 1.578364026499912e-05f, 9.508835319138598e-06f, 1.60284798766952e-05f, 2.06876102311071e-05f, 9.408544428879395e-06f, 1.0916021892626304e-05f, 6.836165994172916e-06f, 1.2435611097316723e-05f, 8.255507054855116e-06f, 7.602558980579488e-06f, 9.132782906817738e-06f, 7.982956958585419e-06f, 7.210451713035582e-06f, 1.3396625945460983e-05f, 1.345768578175921e-05f, 1.327677000517724e-05f, 6.496110927400878e-06f, 1.4860697774565779e-05f, 9.578826393408235e-06f, 1.4417722923099063e-05f, 9.40791051107226e-06f, 4.586572686093859e-06f, 7.379618637060048e-06f, 8.032902769627981e-06f, 1.4591253602702636e-05f, 6.4879450292210095e-06f, 8.828917998471297e-06f, 1.1402045856812038e-05f, 7.682546311116312e-06f, 7.960712537169456e-06f, 8.852905011735857e-06f, 1.3679572475666646e-05f, 6.7049932113150135e-06f, 1.3055377166892868e-05f, 1.2096612408640794e-05f, 8.59383635543054e-06f, 1.1249520866840612e-05f, 2.8062153432983905e-05f, 8.153873750416096e-06f, 1.0058864063466899e-05f, 8.78650007507531e-06f, 1.1534672012203373e-05f, 9.95423488348024e-06f, 1.1881427781190723e-05f, 9.530728675599676e-06f, 7.912289220257662e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00042179273441433907f, 0.0004374791169539094f, 0.0007221293053589761f, 0.0007937157643027604f, 0.00039643506170250475f, 0.0006032597739249468f, 0.00034354240051470697f, 0.0006502465112134814f, 0.000527252908796072f, 0.0004533934697974473f, 0.0005049224710091949f, 0.0004329635121393949f, 0.0005097262328490615f, 0.0007390478276647627f, 0.0006809149635955691f, 0.000716898706741631f, 0.00040550422272644937f, 0.0008582905866205692f, 0.00047571613686159253f, 0.00038245253381319344f, 0.0005649371887557209f, 0.00046978946193121374f, 0.00038633932126685977f, 0.0003128923417534679f, 0.0009885728359222412f, 0.0006622677319683135f, 0.0006852512597106397f, 0.0005771536962129176f, 0.0004872368590440601f, 0.00033048688783310354f, 0.000702320015989244f, 0.0009413139196112752f, 0.0003104656934738159f, 0.0004230915510561317f, 0.0004882735083810985f, 0.0005539162084460258f, 0.0007105038384906948f, 0.0006355580990202725f, 0.0006870310171507299f, 0.0004103871760889888f, 0.00045632844557985663f, 0.0003617260081227869f, 0.0005114332889206707f, 0.0003553621645551175f, 0.00039198598824441433f, 0.000649696565233171f, 0.0006549249519594014f, 0.00043892840039916337f, 0.0004852415877394378f, 0.0007064680685289204f, 0.00039840498357079923f, 0.0007057504844851792f, 0.0005121829453855753f, 0.0006845814641565084f, 0.000909705413505435f, 0.0008795571629889309f, 0.000392618851037696f, 0.0004443134821485728f, 0.0005135061219334602f, 0.0004822565824724734f, 0.0003478027938399464f, 0.0010587999131530523f, 0.0006400003912858665f, 0.0005374746397137642f, 0.0009017451666295528f, 0.0004695651587098837f, 0.0010427497327327728f, 0.0008191654924303293f, 0.0003922092728316784f, 0.00045787004637531936f, 0.000609200622420758f, 0.000557426770683378f, 0.0008422101382166147f, 0.0007530967704951763f, 0.0004143519909121096f, 0.00033103697933256626f, 0.0006399945705197752f, 0.00048373494064435363f, 0.0005191732780076563f, 0.0014434749027714133f, 0.0008370468276552856f, 0.0003525438660290092f, 0.0003278630319982767f, 0.0005202086176723242f, 0.0004877006867900491f, 0.0005859084776602685f, 0.0005179340369068086f, 0.0005890437751077116f, 0.0008321297937072814f, 0.0005814047181047499f, 0.00046514644054695964f, 0.000520922418218106f, 0.00042321934597566724f, 0.0008552472572773695f, 0.0004226983292028308f, 0.000946400745306164f, 0.0004288257332518697f, 0.0006090401438996196f, 0.0005406138370744884f, 0.0004247241886332631f, 0.00040335411904379725f, 0.0006308250594884157f, 0.00046353982179425657f, 0.0006338833482004702f, 0.000395135284634307f, 0.00034853731631301343f, 0.0004622176638804376f, 0.00031149134156294167f, 0.00047968426952138543f, 0.00042097477125935256f, 0.0008406990673393011f, 0.00031299894908443093f, 0.0007732041995041072f, 0.0006499786395579576f, 0.0005612767417915165f, 0.0009996818844228983f, 0.00032163457944989204f, 0.0007365948404185474f, 0.00033634077408351004f, 0.0006465896731242537f, 0.00038596970262005925f, 0.0005134685197845101f, 0.0005090562626719475f, 0.00048791710287332535f, 0.0006323077250272036f, 0.00042222804040648043f, 0.0007398951565846801f, 0.0003751271578948945f, 0.0004983992548659444f, 0.0007035140297375619f, 0.0006463467725552619f, 0.00037778413388878107f, 0.00035840290365740657f, 0.0003806276654358953f, 0.000519222638104111f, 0.0006121163023635745f, 0.0004559188091661781f, 0.0009709775913506746f, 0.0006630292627960443f, 0.0004360986640676856f, 0.0004945519613102078f, 0.0005545496242120862f, 0.000514455430675298f, 0.00036045044544152915f, 0.00045474476064555347f, 0.0005244460771791637f, 0.0007750760996714234f, 0.0002945535525213927f, 0.00046273379120975733f, 0.0009933632100000978f, 0.0005720574408769608f, 0.00036342046223580837f, 0.0004019929328933358f, 0.0008847292046993971f, 0.0005712892161682248f, 0.00047897957847453654f, 0.0005613600951619446f, 0.00036508971243165433f, 0.00047968016588129103f, 0.0004009380063507706f, 0.0005501485429704189f, 0.0005705964867956936f, 0.0006812542560510337f, 0.0004898064071312547f, 0.0004913364537060261f, 0.0006498204893432558f, 0.0005701080081053078f, 0.0004100172081962228f, 0.0005798867787234485f, 0.00037049755337648094f, 0.0004647757741622627f, 0.00033548290957696736f, 0.00039717016625218093f, 0.0005195487756282091f, 0.0004516615008469671f, 0.000654505449347198f, 0.0005937613314017653f, 0.00037177978083491325f, 0.0004045807581860572f, 0.0010021765483543277f, 0.0004958714707754552f, 0.00039841223042458296f, 0.0005626344936899841f, 0.0005287937237881124f, 0.0006139314500615001f, 0.00068665761500597f, 0.0007999390363693237f, 0.00036668480606749654f, 0.0005181824672035873f, 0.0005101073766127229f, 0.000332493131281808f, 0.0003873024834319949f, 0.00031477134325541556f, 0.00036903133150190115f, 0.00035830363049171865f, 0.0007448885007761419f, 0.00039255624869838357f, 0.0005495027871802449f, 0.00039228444802574813f, 0.0005866205901838839f, 0.0003847737971227616f, 0.0005871268222108483f, 0.00042676020530052483f, 0.0003925048222299665f, 0.0006324392161332071f, 0.0005799980717711151f, 0.00030083261663094163f, 0.00038786433287896216f, 0.000560749089345336f, 0.0003985103394370526f, 0.0008245199569500983f, 0.0004967310815118253f, 0.0008373101009055972f, 0.0010806979844346642f, 0.0004914919845759869f, 0.0005702409544028342f, 0.000357113778591156f, 0.0006496226415038109f, 0.0004312586097512394f, 0.00039714929880574346f, 0.0004770865198224783f, 0.00041702089947648346f, 0.00037666605203412473f, 0.0006998250028118491f, 0.0007030146662145853f, 0.0006935638375580311f, 0.00033934967359527946f, 0.0007763064932078123f, 0.0005003873375244439f, 0.0007531659794040024f, 0.0004914588644169271f, 0.00023959750251378864f, 0.00038550313911400735f, 0.00041962999966926873f, 0.0007622310076840222f, 0.0003389230987522751f, 0.0004612129705492407f, 0.0005956303211860359f, 0.0004013277357444167f, 0.00041585887083783746f, 0.0004624660068657249f, 0.0007146057905629277f, 0.0003502614563331008f, 0.0006819984992034733f, 0.0006319137173704803f, 0.00044893252197653055f, 0.0005876625655218959f, 0.0014659359585493803f, 0.0004259494016878307f, 0.0005254639545455575f, 0.0004589970631059259f, 0.0006025585462339222f, 0.0005199982551857829f, 0.0006206727121025324f, 0.0004978747456334531f, 0.00041332925320602953f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.6614356354693882e-05f, 6.749547173967585e-05f, 4.948691639583558e-05f, 5.5825621529947966e-05f, 3.4846001653932035e-05f, 4.5714605221292004e-05f, 4.7131674364209175e-05f, 2.474003122188151e-05f, 3.4169665013905615e-05f, 3.207866393495351e-05f, 2.8568074412760325e-05f, 2.3823678930057213e-05f, 3.307673614472151e-05f, 7.351458043558523e-05f, 2.988709820783697e-05f, 3.4244669222971424e-05f, 3.6508259654510766e-05f, 3.532650589477271e-05f, 2.7806390789919533e-05f, 4.5236673031467944e-05f, 2.9838949558325112e-05f, 2.345557550142985e-05f, 2.9058941436233e-05f, 2.3082546249497682e-05f, 3.708961230586283e-05f, 7.557713252026588e-05f, 2.4023391233640723e-05f, 2.267943818878848e-05f, 2.6345487640355714e-05f, 2.6413186787976883e-05f, 3.670248042908497e-05f, 3.08527160086669e-05f, 3.691413439810276e-05f, 2.580973341537174e-05f, 5.7355973694939166e-05f, 3.224551983294077e-05f, 4.6453635150101036e-05f, 2.937422141258139e-05f, 3.232280505471863e-05f, 2.8354264941299334e-05f, 3.4343076549703255e-05f, 4.502146475715563e-05f, 6.207291880855337e-05f, 3.5249628126621246e-05f, 4.993424590793438e-05f, 3.9882539567770436e-05f, 2.8709710022667423e-05f, 3.145591836073436e-05f, 2.128319647454191e-05f, 2.1859057596884668e-05f, 3.1966079404810444e-05f, 4.5650296669919044e-05f, 3.870030923280865e-05f, 4.7747693315614015e-05f, 6.519525777548552e-05f, 5.5457170674344525e-05f, 2.792631676129531e-05f, 2.2764579625800252e-05f, 2.3962496925378218e-05f, 3.21801271638833e-05f, 2.6329353204346262e-05f, 2.8381218726281077e-05f, 0.00010922896763077006f, 6.914213736308739e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008735309820622206f, 0.0035487012937664986f, 0.0026018675416707993f, 0.002935136901214719f, 0.001832093927077949f, 0.0024035312235355377f, 0.002478036331012845f, 0.0013007535599172115f, 0.0017965342849493027f, 0.001686595962382853f, 0.0015020201681181788f, 0.0012525746133178473f, 0.001739071449264884f, 0.0038651670329272747f, 0.0015713702887296677f, 0.00180047785397619f, 0.001919490285217762f, 0.0018573574488982558f, 0.0014619731809943914f, 0.002378402976319194f, 0.001568838837556541f, 0.0012332209153100848f, 0.0015278283972293139f, 0.0012136081932112575f, 0.0019500560592859983f, 0.003973609767854214f, 0.0012630749261006713f, 0.001192414085380733f, 0.0013851635158061981f, 0.0013887229142710567f, 0.0019297018880024552f, 0.0016221394762396812f, 0.001940830028615892f, 0.0013569951988756657f, 0.0030155980493873358f, 0.0016953687882050872f, 0.0024423871655017138f, 0.001544404891319573f, 0.0016994322650134563f, 0.0014907787553966045f, 0.0018056518165394664f, 0.0023670881055295467f, 0.003263600170612335f, 0.0018533153925091028f, 0.0026253866963088512f, 0.0020968993194401264f, 0.0015094669070094824f, 0.001653853920288384f, 0.0011190039804205298f, 0.0011492810444906354f, 0.0016806765925139189f, 0.0024001500569283962f, 0.0020347414538264275f, 0.002510424703359604f, 0.0034277632366865873f, 0.0029157649260014296f, 0.0014682785840705037f, 0.0011968904873356223f, 0.001259873271919787f, 0.0016919305780902505f, 0.0013843151973560452f, 0.0014921958791092038f, 0.005742918234318495f, 0.0036352777387946844f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010179428500123322f, 0.00011330985580570996f, 6.596439925488085e-05f, 0.00010826172365341336f, 0.00030228582909330726f, 4.508594429353252e-05f, 0.00010697286779759452f, 8.949703624239191e-05f, 0.00026234061806462705f, 0.00016360549489036202f, 0.0003222134546376765f, 0.00010971916344715282f, 0.00011788486153818667f, 0.00013338201097212732f, 6.182392098708078e-05f, 0.0003985804505646229f, 8.559483103454113e-05f, 0.00012802537821698934f, 4.194506982457824e-05f, 7.890605047577992e-05f, 4.074995740666054e-05f, 0.00010278425179421902f, 7.564498810097575e-05f, 7.659933908144012e-05f, 7.390789687633514e-05f, 0.00014660644228570163f, 0.00017176367691718042f, 6.460237636929378e-05f, 8.185573824448511e-05f, 0.00011244507186347619f, 5.597864219453186e-05f, 6.629544077441096e-05f, 8.982654981082305e-05f, 0.00012630785931833088f, 0.00014407357957679778f, 9.909499203786254e-05f, 0.00010667796595953405f, 3.499389276839793e-05f, 0.0005194921977818012f, 0.0001513513852842152f, 9.147263335762545e-05f, 7.341118907788768e-05f, 0.00010384020424680784f, 6.0301834309939295e-05f, 7.281082798726857e-05f, 5.792333831777796e-05f, 8.522139978595078e-05f, 0.00012601865455508232f, 0.00011179621651535854f, 0.00029489237931557f, 0.00013027236855123192f, 9.597311145626009e-05f, 7.717071275692433e-05f, 0.0002725391532294452f, 0.00018232691218145192f, 6.833886436652392e-05f, 9.473144018556923e-05f, 0.00019019041792489588f, 2.9762413760181516e-05f, 0.00010329687938792631f, 5.085895463707857e-05f, 0.0001326822821283713f, 0.00013537649647332728f, 9.01370876817964e-05f, 9.460335422772914e-05f, 0.00016636333020869642f, 0.00020649384532589465f, 6.622334331041202e-05f, 0.00011779254418797791f, 8.074647485045716e-05f, 0.0001890959101729095f, 0.00020620619761757553f, 8.315472223330289e-05f, 6.72131500323303e-05f, 0.0001822453341446817f, 7.37777299946174e-05f, 6.306626892182976e-05f, 0.00017585331806913018f, 7.408158853650093e-05f, 0.00017735696746967733f, 0.00013686736929230392f, 0.00010741048026829958f, 4.503505988395773e-05f, 0.00011056175571866333f, 7.287754124263301e-05f, 0.00028402890893630683f, 7.838845340302214e-05f, 0.00011237067519687116f, 0.0001599606330273673f, 0.00019019562751054764f, 8.611399243818596e-05f, 5.996816253173165e-05f, 8.865987183526158e-05f, 5.318744297255762e-05f, 6.407289038179442e-05f, 5.502651401911862e-05f, 8.90882292878814e-05f, 2.255624895042274e-05f, 8.922523556975648e-05f, 8.207540668081492e-05f, 6.151807610876858e-05f, 0.00011182284652022645f, 6.940772436792031e-05f, 0.00010274095257045701f, 9.234279423253611e-05f, 0.00010843410564120859f, 9.920197771862149e-05f, 4.6018936700420454e-05f, 6.243489042390138e-05f, 0.0001282443554373458f, 0.0007785295601934195f, 0.00015310951857827604f, 4.5394786866381764e-05f, 0.0001413340214639902f, 0.00010562536044744775f, 4.91733371745795e-05f, 7.524936518166214e-05f, 0.0002023558918153867f, 6.995297007961199e-05f, 7.177966472227126e-05f, 0.0001960095250979066f, 2.8960543204448186e-05f, 0.0001043004376697354f, 0.00010844474309124053f, 2.0359546397230588e-05f, 0.00016547899576835334f, 3.905304038198665e-05f, 8.829859871184453e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006095175165683031f, 0.006784697528928518f, 0.003949775360524654f, 0.0064824288710951805f, 0.018100084736943245f, 0.0026996282394975424f, 0.006405255291610956f, 0.005358848255127668f, 0.01570826955139637f, 0.009796269237995148f, 0.019293298944830894f, 0.006569696124643087f, 0.007058636751025915f, 0.007986566051840782f, 0.00370185449719429f, 0.02386595495045185f, 0.005125194322317839f, 0.007665824610739946f, 0.0025115609169006348f, 0.004724687896668911f, 0.0024400008842349052f, 0.006154451984912157f, 0.004529424011707306f, 0.0045865681022405624f, 0.004425411578267813f, 0.008778410032391548f, 0.010284759104251862f, 0.003868221305310726f, 0.0049013071693480015f, 0.006732916459441185f, 0.0033518546260893345f, 0.00396959763020277f, 0.005378578789532185f, 0.007562984246760607f, 0.00862674880772829f, 0.005933548789471388f, 0.006387597415596247f, 0.0020953426137566566f, 0.031105833128094673f, 0.009062524884939194f, 0.005477142054587603f, 0.004395669791847467f, 0.006217679474502802f, 0.0036107159685343504f, 0.004359721671789885f, 0.0034682978875935078f, 0.005102834198623896f, 0.0075456672348082066f, 0.006694064941257238f, 0.017657384276390076f, 0.007800368592143059f, 0.005746618844568729f, 0.004620780237019062f, 0.016318930312991142f, 0.010917258448898792f, 0.004091952461749315f, 0.0056722708977758884f, 0.011388104408979416f, 0.0017820954089984298f, 0.006185146979987621f, 0.0030453011859208345f, 0.007944667711853981f, 0.0081059904769063f, 0.00539717311039567f, 0.00566460145637393f, 0.009961401112377644f, 0.012364311143755913f, 0.00396528048440814f, 0.007053109351545572f, 0.004834887571632862f, 0.0113225681707263f, 0.012347087264060974f, 0.0049790870398283005f, 0.004024547524750233f, 0.010912373661994934f, 0.004417617339640856f, 0.003776242956519127f, 0.010529636405408382f, 0.004435811657458544f, 0.01061967108398676f, 0.008195259608328342f, 0.00643145851790905f, 0.002696581417694688f, 0.006620148662477732f, 0.004363716579973698f, 0.017006907612085342f, 0.004693695344030857f, 0.006728461943566799f, 0.009578024037182331f, 0.011388416402041912f, 0.005156280472874641f, 0.003590736538171768f, 0.005308721214532852f, 0.0031847248319536448f, 0.0038365169893950224f, 0.003294843714684248f, 0.0053343698382377625f, 0.0013506091199815273f, 0.005342573393136263f, 0.004914460703730583f, 0.003683541202917695f, 0.00669565936550498f, 0.004155952949076891f, 0.006151859182864428f, 0.0055292448960244656f, 0.0064927502535283566f, 0.00593995489180088f, 0.002755493391305208f, 0.0037384380120784044f, 0.007678936701267958f, 0.046616312116384506f, 0.009167796932160854f, 0.0027181210462003946f, 0.008462711237370968f, 0.006324570160359144f, 0.0029443707317113876f, 0.004505734890699387f, 0.012116541154682636f, 0.004188600927591324f, 0.0042979782447218895f, 0.011736537329852581f, 0.001734081539325416f, 0.006245237309485674f, 0.0064933872781693935f, 0.0012190763372927904f, 0.009908448904752731f, 0.002338393824175f, 0.005287088919430971f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.772935300134122e-05f, 7.86117889219895e-05f, 0.00015096450806595385f, 6.738983211107552e-05f, 0.00011909446038771421f, 8.013220212887973e-05f, 4.234646985423751e-05f, 0.00011625228216871619f, 5.268897439236753e-05f, 6.906726775923744e-05f, 8.838592475512996e-05f, 7.733472739346325e-05f, 6.357852544169873e-05f, 0.00011167834600200877f, 0.00012189819972263649f, 8.541838906239718e-05f, 7.903873483883217e-05f, 8.952376083470881e-05f, 0.00011288614041404799f, 6.356246012728661e-05f, 8.355906174983829e-05f, 9.767022856976837e-05f, 0.0001002451463136822f, 6.588042015209794e-05f, 0.00010241190466331318f, 0.00010636566003086045f, 9.750092431204394e-05f, 0.00012746843276545405f, 7.470443233614787e-05f, 0.00011073412315454334f, 6.0205213230801746e-05f, 0.00017473574553150684f, 0.0001008830004138872f, 0.00012975450954400003f, 8.444190461887047e-05f, 5.393147876020521e-05f, 0.00010214110079687089f, 0.00013848667731508613f, 9.875088289845735e-05f, 6.0896923969266936e-05f, 9.74386784946546e-05f, 9.923009929480031e-05f, 0.0001258045667782426f, 8.147003973135725e-05f, 9.472158853895962e-05f, 5.8719946537166834e-05f, 7.666418241569772e-05f, 9.643728844821453e-05f, 0.00012617799802683294f, 9.171696729026735e-05f, 9.422795847058296e-05f, 9.350242908112705e-05f, 8.418125798925757e-05f, 0.00010093275341205299f, 6.0831142036477104e-05f, 8.468830492347479e-05f, 7.62492636567913e-05f, 7.870405534049496e-05f, 0.00011223212641198188f, 8.986608736449853e-05f, 0.0001126064162235707f, 0.0001231513306265697f, 9.758881788002327e-05f, 8.320857887156308e-05f, 8.186155173461884e-05f, 8.075987716438249e-05f, 7.447855750797316e-05f, 0.00012691944721154869f, 8.638178405817598e-05f, 9.03085820027627e-05f, 0.00010660481348168105f, 8.030989556573331e-05f, 7.358847506111488e-05f, 0.0001070073849405162f, 8.309006807394326e-05f, 7.940433715702966e-05f, 8.131154027068987e-05f, 5.941639392403886e-05f, 9.604223305359483e-05f, 8.71570737217553e-05f, 8.253284613601863e-05f, 9.880650031846017e-05f, 0.00011557582183741033f, 7.94723819126375e-05f, 9.688497084425762e-05f, 6.559387838933617e-05f, 8.586474723415449e-05f, 5.886621511308476e-05f, 7.988921424839646e-05f, 5.443526970339008e-05f, 0.00010240835399599746f, 9.522586333332583e-05f, 0.0001380321482429281f, 8.397068449994549e-05f, 0.00011934086796827614f, 7.986978744156659e-05f, 7.928393461043015e-05f, 0.00012146342487540096f, 9.199540363624692e-05f, 0.00011424640979385003f, 6.958989251870662e-05f, 7.04813064658083e-05f, 0.00010699921404011548f, 8.407726272707805e-05f, 6.2078885093797e-05f, 0.00016935121675487608f, 0.00014969432959333062f, 9.996239532483742e-05f, 7.732534140814096e-05f, 0.0001233630027854815f, 8.449970482615754e-05f, 7.109994476195425e-05f, 9.511807729722932e-05f, 6.510367529699579e-05f, 0.00010482065408723429f, 0.0002017198858084157f, 9.565577784087509e-05f, 7.590616587549448e-05f, 0.00012214548769406974f, 5.94159537286032e-05f, 0.00014230988745111972f, 7.260551501531154e-05f, 7.416999142151326e-05f, 9.055267582880333e-05f, 7.914954767329618e-05f, 8.173973765224218e-05f, 6.732248584739864e-05f, 0.00010203746205661446f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000867827155161649f, 0.0006980650941841304f, 0.001340550254099071f, 0.0005984152085147798f, 0.0010575472842901945f, 0.0007115661865100265f, 0.000376032548956573f, 0.0010323090245947242f, 0.0004678729746956378f, 0.0006133106653578579f, 0.0007848584209568799f, 0.000686724903061986f, 0.0005645711207762361f, 0.0009916928829625249f, 0.0010824442142620683f, 0.0007585069979541004f, 0.0007018563337624073f, 0.0007949623395688832f, 0.0010024179937317967f, 0.0005644284537993371f, 0.0007419963367283344f, 0.0008673021802678704f, 0.0008901671972125769f, 0.0005850117304362357f, 0.0009094077977351844f, 0.0009445167379453778f, 0.0008657987345941365f, 0.0011319073382765055f, 0.0006633680895902216f, 0.0009833083022385836f, 0.0005346164689399302f, 0.0015516364946961403f, 0.0008958312682807446f, 0.0011522074928507209f, 0.000749835919123143f, 0.0004789062950294465f, 0.0009070030646398664f, 0.0012297482462599874f, 0.0008768982370384037f, 0.0005407587741501629f, 0.0008652459946461022f, 0.0008811536827124655f, 0.0011171323712915182f, 0.0007234460790641606f, 0.0008411185117438436f, 0.0005214274278841913f, 0.0006807704921811819f, 0.0008563537849113345f, 0.0011204483453184366f, 0.0008144377497956157f, 0.000836735125631094f, 0.0008302925270982087f, 0.0007475214079022408f, 0.0008962730644270778f, 0.0005401746602728963f, 0.0007520239450968802f, 0.0006770860636606812f, 0.0006988843670114875f, 0.0009966103825718164f, 0.0007980021182447672f, 0.0009999340400099754f, 0.0010935718892142177f, 0.0008665792411193252f, 0.0007388840895146132f, 0.0007269226480275393f, 0.0007171398610807955f, 0.0006613623700104654f, 0.0011270323302596807f, 0.0007670618942938745f, 0.0008019314846023917f, 0.0009466403862461448f, 0.0007131440797820687f, 0.0006534585263580084f, 0.0009502152097411454f, 0.0007378317532129586f, 0.000705102807842195f, 0.0007220386178232729f, 0.0005276118172332644f, 0.0008528457256034017f, 0.000773946347180754f, 0.0007328836945816875f, 0.0008773921290412545f, 0.0010263021104037762f, 0.0007057070615701377f, 0.0008603291353210807f, 0.0005824672989547253f, 0.0007624706486240029f, 0.0005227262736298144f, 0.0007094084867276251f, 0.0004833799321204424f, 0.0009093762491829693f, 0.0008455964270979166f, 0.0012257121270522475f, 0.0007456515450030565f, 0.0010597353102639318f, 0.0007092359592206776f, 0.0007040336495265365f, 0.0010785834165289998f, 0.0008169102948158979f, 0.0010144970146939158f, 0.0006179515039548278f, 0.0006258671637624502f, 0.0009501426247879863f, 0.0007465979433618486f, 0.0005512544885277748f, 0.0015038223937153816f, 0.0013292711228132248f, 0.0008876564097590744f, 0.0006866415496915579f, 0.0010954515310004354f, 0.0007503491942770779f, 0.0006313606281764805f, 0.0008446393185295165f, 0.0005781143554486334f, 0.0009307972504757345f, 0.001791252987459302f, 0.0008494140347465873f, 0.0006740394164808095f, 0.001084640040062368f, 0.0005276079173199832f, 0.001263697980903089f, 0.0006447299383580685f, 0.0006586223025806248f, 0.0008040989632718265f, 0.0007028403342701495f, 0.0007258409168571234f, 0.0005978171247988939f, 0.0009060827433131635f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010217802628176287f, 0.00011985294258920476f, 8.953407814260572e-05f, 0.00013493475853465497f, 9.52758127823472e-05f, 9.936620335793123e-05f, 6.218014459591359e-05f, 7.750944496365264e-05f, 9.153692371910438e-05f, 8.63333698362112e-05f, 7.635758811375126e-05f, 0.00012123177293688059f, 0.00010406037472421303f, 0.00010804974590428174f, 7.918468327261508e-05f, 0.0001409919059369713f, 8.267888915725052e-05f, 5.86005553486757e-05f, 0.00012917899584863335f, 9.225879330188036e-05f, 5.7955392549047247e-05f, 7.586726133013144e-05f, 7.64584619901143e-05f, 7.68988102208823e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005083048716187477f, 0.00596232246607542f, 0.004454050678759813f, 0.006712597794830799f, 0.004739684518426657f, 0.004943169187754393f, 0.003093274775892496f, 0.003855861257761717f, 0.004553685896098614f, 0.0042948247864842415f, 0.003798560006543994f, 0.006030915305018425f, 0.005176689941436052f, 0.005375149194151163f, 0.003939199261367321f, 0.007013922557234764f, 0.00411302549764514f, 0.0029152010101825f, 0.006426265463232994f, 0.004589596763253212f, 0.002883106004446745f, 0.00377416773699224f, 0.003803577972576022f, 0.0038254838436841965f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010932207078440115f, 9.219462663168088e-05f, 0.0001701894507277757f, 0.00011874369374709204f, 6.950109673198313e-05f, 0.00019599826191551983f, 0.0001335000852122903f, 0.00045385025441646576f, 7.282795559149235e-05f, 6.472090899478644e-05f, 0.00016389979282394052f, 0.00017548359755892307f, 0.00018348406592849642f, 0.00010180216486332938f, 0.00017240646411664784f, 0.00012234527093824f, 0.00016551815497223288f, 0.00010302717419108376f, 0.00010621225374052301f, 9.541256440570578e-05f, 7.178028317866847e-05f, 9.847377805272117e-05f, 0.00014519286924041808f, 0.00010984043910866603f, 7.90244375821203e-05f, 0.0001489169808337465f, 0.00012208065891172737f, 0.00017364753875881433f, 0.00016406632494181395f, 6.605006637983024e-05f, 0.00012713586329482496f, 0.00016509552369825542f, 0.00015529259690083563f, 0.0001867790997494012f, 0.00020164622401352972f, 0.0001275333052035421f, 0.00012057764251949266f, 9.721436799736694e-05f, 0.0001433397555956617f, 0.0001044494056259282f, 9.090475941775367e-05f, 9.585495718056336e-05f, 0.00012159412290202454f, 6.331205804599449e-05f, 0.00028938299510627985f, 0.0001237862161360681f, 7.898981857579201e-05f, 6.079767626943067e-05f, 0.00018398025713395327f, 0.0001353540428681299f, 7.725384057266638e-05f, 0.00012519859592430294f, 0.0001347801589872688f, 0.00013559404760599136f, 0.00011360612552380189f, 0.00016366109775844961f, 0.00022067403187975287f, 9.326185681857169e-05f, 0.00011030398309230804f, 9.569235407980159e-05f, 8.412580064032227e-05f, 8.903812704375014e-05f, 0.00015140706091187894f, 0.0001307268685195595f, 0.00012756783689837903f, 0.00023191449872683734f, 0.00016733058146201074f, 0.00015579276077914983f, 0.00011373187589924783f, 0.00013882388884667307f, 0.0001286935730604455f, 0.00015008135233074427f, 0.00014128637849353254f, 7.446806557709351e-05f, 0.00015107028593774885f, 9.722094546305016e-05f, 0.00010364382615080103f, 0.0002251618425361812f, 0.00015682101366110146f, 0.00016676672385074198f, 0.00016003222845029086f, 0.00020394951570779085f, 0.000251338176894933f, 0.00014596633263863623f, 0.00013691211643163115f, 8.295020961668342e-05f, 0.00014497128722723573f, 0.0001228666224051267f, 0.00022938349866308272f, 0.0001810564281186089f, 0.0002619721635710448f, 0.00016411641263402998f, 0.0001309818180743605f, 0.00013834565470460802f, 0.00016895346925593913f, 8.83555767359212e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006399190053343773f, 0.005396631546318531f, 0.00996207445859909f, 0.006950686685740948f, 0.004068261012434959f, 0.011472798883914948f, 0.007814454846084118f, 0.026566218584775925f, 0.004262999165803194f, 0.003788451896980405f, 0.009593907743692398f, 0.010271968320012093f, 0.010740277357399464f, 0.005959010683000088f, 0.010091847740113735f, 0.0071615055203437805f, 0.00968863908201456f, 0.006030716933310032f, 0.006217156071215868f, 0.005584993865340948f, 0.004201673436909914f, 0.005764182657003403f, 0.008498894050717354f, 0.006429532542824745f, 0.004625711590051651f, 0.008716885931789875f, 0.007146016228944063f, 0.010164494626224041f, 0.009603655897080898f, 0.0038662543520331383f, 0.00744192348793149f, 0.00966390036046505f, 0.00909008365124464f, 0.010933153331279755f, 0.011803403496742249f, 0.007465187925845385f, 0.007058036979287863f, 0.00569046288728714f, 0.008390421979129314f, 0.006113967392593622f, 0.005321128759533167f, 0.005610889755189419f, 0.007117536850273609f, 0.0037059844471514225f, 0.01693909242749214f, 0.007245851214975119f, 0.004623685032129288f, 0.003558804513886571f, 0.010769322514533997f, 0.007922976277768612f, 0.0045220693573355675f, 0.007328525651246309f, 0.007889384403824806f, 0.007937025278806686f, 0.006649957969784737f, 0.009579936042428017f, 0.012917200103402138f, 0.0054591018706560135f, 0.00645666616037488f, 0.005601371638476849f, 0.004924321081489325f, 0.005211865063756704f, 0.008862643502652645f, 0.007652123924344778f, 0.007467209827154875f, 0.01357516273856163f, 0.009794729761779308f, 0.009119361639022827f, 0.00665731867775321f, 0.008126084692776203f, 0.007533105090260506f, 0.00878504291176796f, 0.00827022735029459f, 0.004359003622084856f, 0.00884293019771576f, 0.005690847989171743f, 0.006066812667995691f, 0.013179894536733627f, 0.009179550223052502f, 0.00976172462105751f, 0.009367519058287144f, 0.011938226409256458f, 0.014712131582200527f, 0.00854416936635971f, 0.008014178834855556f, 0.004855507519096136f, 0.008485924452543259f, 0.007192022632807493f, 0.01342700980603695f, 0.01059817522764206f, 0.015334594063460827f, 0.009606587700545788f, 0.0076670474372804165f, 0.008098090998828411f, 0.009889725595712662f, 0.005171911790966988f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011393809108994901f, 8.831066224956885e-05f, 0.00011433846520958468f, 9.940468589775264e-05f, 0.00013793184189125896f, 0.0001222624268848449f, 0.00013370891974773258f, 7.953459135023877e-05f, 9.280800441047177e-05f, 0.00011489592725411057f, 9.022410813486204e-05f, 9.634425077820197e-05f, 0.00010577700595604256f, 0.00011586879554670304f, 6.372309144353494e-05f, 0.00012366824375931174f, 6.422621663659811e-05f, 9.178181062452495e-05f, 9.74599170149304e-05f, 9.482180757913738e-05f, 0.00011357876792317256f, 0.00012314433115534484f, 0.00011847540736198425f, 0.00011817393533419818f, 0.0001018824550556019f, 0.00014096223458182067f, 9.310748282587156e-05f, 8.865087875165045e-05f, 9.358369425171986e-05f, 8.037414954742417e-05f, 0.00011514664220158011f, 7.557922799605876e-05f, 0.00011815092148026451f, 0.00010426182416267693f, 0.00010909506818279624f, 0.0001223470753757283f, 0.0001014152803691104f, 0.00012100947060389444f, 0.0001137747458415106f, 8.85703630046919e-05f, 0.00012972592958249152f, 0.00012493168469518423f, 0.00012711493764072657f, 0.00010805716010509059f, 8.365214307559654e-05f, 7.998738874448463e-05f, 8.894867642084137e-05f, 0.0001333351101493463f, 8.705305663170293e-05f, 0.0001195674849441275f, 0.00013077986659482121f, 0.00010452515562064946f, 0.0001059057904058136f, 8.292966958833858e-05f, 0.00010143173130927607f, 0.00010199906682828441f, 0.00014317382010631263f, 0.0001008751496556215f, 0.00011797482147812843f, 9.208717528963462e-05f, 7.023943908279762e-05f, 0.00015022189472801983f, 0.00012509309453889728f, 9.753370977705345e-05f, 8.182102465070784e-05f, 0.00010792012471938506f, 8.949412585934624e-05f, 0.0001483078667661175f, 0.00010082379594678059f, 0.00010048819240182638f, 9.2402653535828e-05f, 7.8306817158591e-05f, 0.00010606265277601779f, 0.0001300294097745791f, 5.388212957768701e-05f, 8.434251503786072e-05f, 0.0001180810431833379f, 0.00010527075210120529f, 0.00010281400318490341f, 0.00010535608453210443f, 4.908153277938254e-05f, 0.00010466767707839608f, 0.0001095336556318216f, 0.00011578109842957929f, 9.322789992438629e-05f, 5.437678919406608e-05f, 9.404544107383117e-05f, 0.00011380205251043662f, 0.00010670072515495121f, 8.390173024963588e-05f, 0.00011377248301869258f, 9.49504756135866e-05f, 9.004228195408359e-05f, 9.854133531916887e-05f, 9.210089774569497e-05f, 7.901774370111525e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0015373568749055266f, 0.0011915682116523385f, 0.0015427591279149055f, 0.0013412588741630316f, 0.0018611025298014283f, 0.0016496763564646244f, 0.0018041229341179132f, 0.001073153456673026f, 0.0012522503966465592f, 0.0015502808382734656f, 0.0012173861032351851f, 0.0012999647296965122f, 0.0014272400876507163f, 0.001563407713547349f, 0.0008598102140240371f, 0.0016686449525877833f, 0.000866598857101053f, 0.0012384040746837854f, 0.0013150182785466313f, 0.0012794225476682186f, 0.0015325085259974003f, 0.0016615758650004864f, 0.0015985785285010934f, 0.0015945107443258166f, 0.0013746912591159344f, 0.0019019914325326681f, 0.001256291288882494f, 0.0011961587006226182f, 0.0012627167161554098f, 0.0010844814823940396f, 0.0015536637511104345f, 0.001019784016534686f, 0.0015942002646625042f, 0.0014067958109080791f, 0.001472010393626988f, 0.0016508186236023903f, 0.0013683877186849713f, 0.001632770407013595f, 0.001535152900032699f, 0.0011950723128393292f, 0.0017503808485344052f, 0.0016856924630701542f, 0.0017151510110124946f, 0.0014580059796571732f, 0.001128711155615747f, 0.0010792629327625036f, 0.0012001768918707967f, 0.0017990792402997613f, 0.0011745993979275227f, 0.0016133137978613377f, 0.0017646015621721745f, 0.001410348922945559f, 0.0014289777027443051f, 0.001118962885811925f, 0.0013686096062883735f, 0.0013762646121904254f, 0.0019318320555612445f, 0.0013610997702926397f, 0.0015918241115286946f, 0.0012425243621692061f, 0.0009477347484789789f, 0.0020269311498850584f, 0.0016878703609108925f, 0.0013160139787942171f, 0.001104004099033773f, 0.001456156955100596f, 0.0012075365521013737f, 0.0020011053420603275f, 0.0013604068662971258f, 0.0013558785431087017f, 0.001246781088411808f, 0.0010565872071310878f, 0.0014310942497104406f, 0.0017544756410643458f, 0.0007270269561558962f, 0.0011380263604223728f, 0.0015932574169710279f, 0.0014204091858118773f, 0.0013872605049982667f, 0.0014215606497600675f, 0.0006622528890147805f, 0.0014122719876468182f, 0.0014779282500967383f, 0.0015622244682163f, 0.0012579160975292325f, 0.0007337013375945389f, 0.0012689470313489437f, 0.0015355213545262814f, 0.0014397037448361516f, 0.0011320788180455565f, 0.0015351223992183805f, 0.0012811586493626237f, 0.0012149327667430043f, 0.0013296097749844193f, 0.001242709462530911f, 0.0010661795968189836f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.406072109006345e-05f, 6.75839401083067e-05f, 8.893445192370564e-05f, 9.214141027769074e-05f, 8.132814400596544e-05f, 5.962511204415932e-05f, 7.903320511104539e-05f, 7.058486517053097e-05f, 7.375024142675102e-05f, 8.3371160144452e-05f, 6.825826858403161e-05f, 8.22528381831944e-05f, 9.107462392421439e-05f, 6.072663381928578e-05f, 6.814474909333512e-05f, 8.627605711808428e-05f, 6.271931488299742e-05f, 6.185085658216849e-05f, 7.203815039247274e-05f, 6.663873500656337e-05f, 6.972126720938832e-05f, 7.511728472309187e-05f, 6.630489224335179e-05f, 7.214264769572765e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0033045103773474693f, 0.0030155230779200792f, 0.003968160133808851f, 0.004111251328140497f, 0.003628774778917432f, 0.0026604088488966227f, 0.003526377258822322f, 0.0031494214199483395f, 0.003290656954050064f, 0.003719931934028864f, 0.003045611083507538f, 0.0036700337659567595f, 0.004063652362674475f, 0.0027095575351268053f, 0.003040545852854848f, 0.003849545493721962f, 0.002798468805849552f, 0.002759719267487526f, 0.003214265452697873f, 0.002973349066451192f, 0.0031108884140849113f, 0.0033516529947519302f, 0.002958453493192792f, 0.003218927886337042f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011067783634644002f, 0.0001704410824459046f, 0.00013039758778177202f, 0.00019452646665740758f, 9.064436017069966e-05f, 0.00012330670142546296f, 0.0001222905411850661f, 6.578526517841965e-05f, 0.00010266111348755658f, 0.0001349541562376544f, 0.00023375041200779378f, 0.00011637275019893423f, 0.00020471069728955626f, 0.00013037538155913353f, 0.00013521796790882945f, 0.00010566583659965545f, 0.0002456543152220547f, 0.00011405629629734904f, 0.0002054934302577749f, 7.98216278781183e-05f, 0.00012705838889814913f, 8.837636414682493e-05f, 8.436611096840352e-05f, 8.911257464205846e-05f, 0.00020830509311053902f, 0.0001606675941729918f, 9.283039253205061e-05f, 0.00011213331890758127f, 0.00026415844331495464f, 0.0001195574295707047f, 0.00011267374793533236f, 8.987238834379241e-05f, 0.0002219561574747786f, 0.00014126274618320167f, 0.00011783406807808205f, 6.190401472849771e-05f, 0.00012173951108707115f, 0.0001838052412495017f, 9.89030086202547e-05f, 0.00017995918460655957f, 6.5127074776683e-05f, 0.0001168119051726535f, 0.0001223048457177356f, 0.00010957066842820495f, 7.518411439377815e-05f, 0.0001665742602199316f, 9.907941421261057e-05f, 0.00015123623597901314f, 0.00016007288650143892f, 0.00038822207716293633f, 6.113203562563285e-05f, 8.110769704217091e-05f, 0.00014724688662681729f, 0.00018865471065510064f, 0.0001277128903893754f, 0.00010919582564383745f, 8.957549289334565e-05f, 0.00010430969268782064f, 9.41184043767862e-05f, 4.9985366786131635e-05f, 0.00015668684500269592f, 0.00015116659051273018f, 8.916966180549935e-05f, 0.0001484214299125597f, 7.989281584741548e-05f, 0.00023331990814767778f, 0.0001078145724022761f, 7.817403820808977e-05f, 8.249076927313581e-05f, 8.580414578318596e-05f, 0.00018702333909459412f, 0.000183374373591505f, 0.0001895132299978286f, 8.757048635743558e-05f, 7.476542668882757e-05f, 0.0001287814084207639f, 0.00014555445523001254f, 0.0001773676194716245f, 0.00021442431898321956f, 0.00015970508684404194f, 7.547263521701097e-05f, 0.00015110911044757813f, 0.0001287276390939951f, 0.00011243756307521835f, 8.424850238952786e-05f, 0.00012118538870709017f, 6.239070353331044e-05f, 0.00012205916573293507f, 0.00018938198627438396f, 0.0001441532076569274f, 7.974138134159148e-05f, 0.0001432874851161614f, 0.00011119992268504575f, 8.300202898681164e-05f, 0.00014511022891383618f, 0.00017315245349891484f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006904404144734144f, 0.010632609017193317f, 0.008134579285979271f, 0.012135124765336514f, 0.005654658190906048f, 0.007692229468375444f, 0.007628838066011667f, 0.00410387571901083f, 0.0064042978920042515f, 0.00841883197426796f, 0.014582028612494469f, 0.007259669713675976f, 0.012770446948707104f, 0.008133194409310818f, 0.008435288444161415f, 0.00659174146130681f, 0.015324628911912441f, 0.007115162443369627f, 0.012819276191294193f, 0.0049795047380030155f, 0.007926270365715027f, 0.005513173993676901f, 0.005263002589344978f, 0.005559100769460201f, 0.012994675897061825f, 0.010022910311818123f, 0.0057910289615392685f, 0.006995201576501131f, 0.016478968784213066f, 0.007458338979631662f, 0.007028914988040924f, 0.005606499966233969f, 0.013846268877387047f, 0.008812380023300648f, 0.00735083082690835f, 0.0038617521058768034f, 0.0075944638811051846f, 0.01146630384027958f, 0.006169856525957584f, 0.011226375587284565f, 0.004062815569341183f, 0.007287065498530865f, 0.0076297312043607235f, 0.006835335865616798f, 0.004690202884376049f, 0.010391385294497013f, 0.006180861033499241f, 0.009434554725885391f, 0.009985811077058315f, 0.024218419566750526f, 0.0038135936483740807f, 0.005059733521193266f, 0.009185687638819218f, 0.011768828146159649f, 0.007967100478708744f, 0.006811952218413353f, 0.005587978754192591f, 0.006507141049951315f, 0.005871378816664219f, 0.003118232125416398f, 0.009774579666554928f, 0.00943021010607481f, 0.005562662146985531f, 0.00925895944237709f, 0.004983945284038782f, 0.014555172063410282f, 0.006725785788148642f, 0.004876723047345877f, 0.00514601357281208f, 0.00535271130502224f, 0.011667057871818542f, 0.011439424939453602f, 0.011822384782135487f, 0.00546290073543787f, 0.004664083942770958f, 0.008033758029341698f, 0.009080109186470509f, 0.01106470637023449f, 0.01337641105055809f, 0.009962866082787514f, 0.004708201624453068f, 0.00942662451416254f, 0.008030403405427933f, 0.00701418099924922f, 0.005255665630102158f, 0.007559895981103182f, 0.0038921129889786243f, 0.0076144044287502766f, 0.011814197525382042f, 0.0089926952496171f, 0.00497449841350317f, 0.008938688784837723f, 0.006936973426491022f, 0.005177907180041075f, 0.00905239675194025f, 0.010801752097904682f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.166702223708853e-05f, 0.00010764812031993642f, 9.007233165903017e-05f, 7.488580013159662e-05f, 0.00013632391346618533f, 6.0418205976020545e-05f, 0.00012766124564222991f, 0.00010637791274348274f, 0.00011439781519584358f, 8.02729555289261e-05f, 0.00013836387370247394f, 7.869313412811607e-05f, 8.839801739668474e-05f, 9.205962851410732e-05f, 0.00011493185593280941f, 7.56894369260408e-05f, 9.422964649274945e-05f, 7.534803444286808e-05f, 8.184655598597601e-05f, 0.00011394463217584416f, 0.00015741222887299955f, 0.00011357312178006396f, 0.0001113588223233819f, 0.00011244563211221248f, 0.00010515163012314588f, 8.929821342462674e-05f, 0.00010043193469755352f, 0.0001201286431751214f, 7.744184404145926e-05f, 7.155365165090188e-05f, 0.000159984701895155f, 0.00010515051690163091f, 9.096790745388716e-05f, 6.660375947831199e-05f, 9.502182365395129e-05f, 0.00010713033407228068f, 0.00012205007078591734f, 0.00012010951468255371f, 0.0001467597030568868f, 5.7223805924877524e-05f, 0.00012925974442623556f, 7.582303805975243e-05f, 0.00010775646660476923f, 9.453962411498651e-05f, 0.00011594066018005833f, 0.00010184724669670686f, 8.82544118212536e-05f, 0.0001763060863595456f, 0.0001181833358714357f, 7.598723459523171e-05f, 0.00012567137309815735f, 0.00010293816740158945f, 9.15671480470337e-05f, 0.00010076397302327678f, 0.00013875959848519415f, 8.804224489722401e-05f, 0.00019768673519138247f, 9.923402103595436e-05f, 9.08054644241929e-05f, 0.0001237489632330835f, 0.00012105422501917928f, 6.773977656848729e-05f, 0.00012335584324318916f, 8.369798888452351e-05f, 0.00011891560279764235f, 9.671723091742024e-05f, 0.00017741258488968015f, 8.79633444128558e-05f, 0.0001061400180333294f, 0.00011493596684886143f, 0.00010865584044950083f, 0.00011002444080077112f, 0.00010149244917556643f, 0.00010237366950605065f, 0.00010958898201351985f, 0.0001019521223497577f, 0.00010227599705103785f, 0.00011128075129818171f, 8.15479361335747e-05f, 0.00011164976604050025f, 0.00012661250366363674f, 0.00014329059922602028f, 0.00012469898501876742f, 0.00013021718768868595f, 9.651282016420737e-05f, 8.440138481091708e-05f, 0.00013898609904572368f, 0.00010489367559785023f, 9.119699825532734e-05f, 0.00012698349019046873f, 0.0001461247738916427f, 0.00011865777923958376f, 5.49573014723137e-05f, 8.997091936180368e-05f, 0.00014816490875091404f, 0.000101540754258167f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010503575904294848f, 0.0018335412023589015f, 0.001534177572466433f, 0.0012755094794556499f, 0.002321968087926507f, 0.0010290868813171983f, 0.0021744193509221077f, 0.0018119061132892966f, 0.0019485069205984473f, 0.0013672674540430307f, 0.0023567143362015486f, 0.0013403587508946657f, 0.0015056594274938107f, 0.0015680266078561544f, 0.001957603031769395f, 0.0012891975929960608f, 0.001604988006874919f, 0.0012833825312554836f, 0.0013940701028332114f, 0.0019407880026847124f, 0.00268115964718163f, 0.0019344601314514875f, 0.0018967445939779282f, 0.001915255910716951f, 0.0017910191090777516f, 0.0015209922567009926f, 0.0017106299055740237f, 0.00204611849039793f, 0.0013190458994358778f, 0.0012187538668513298f, 0.002724976046010852f, 0.0017910001333802938f, 0.00154943170491606f, 0.001134443678893149f, 0.0016184808919206262f, 0.0018247218104079366f, 0.0020788456313312054f, 0.0020457927603274584f, 0.0024997182190418243f, 0.0009746775031089783f, 0.002201646100729704f, 0.001291473163291812f, 0.001835386618040502f, 0.001610267674550414f, 0.001974785700440407f, 0.0017347364919260144f, 0.001503213425166905f, 0.0030029737390577793f, 0.0020129845943301916f, 0.0012942699249833822f, 0.0021405264269560575f, 0.0017533177742734551f, 0.0015596383018419147f, 0.0017162853619083762f, 0.0023634545505046844f, 0.0014995996607467532f, 0.0033671443816274405f, 0.0016902261413633823f, 0.0015466647455468774f, 0.0021077825222164392f, 0.0020618836861103773f, 0.0011537931859493256f, 0.0021010865457355976f, 0.0014256051508709788f, 0.0020254570990800858f, 0.0016473582945764065f, 0.0030218204483389854f, 0.001498255762271583f, 0.0018078540451824665f, 0.0019576731137931347f, 0.001850705360993743f, 0.0018740163650363684f, 0.0017286932561546564f, 0.0017437029164284468f, 0.0018665993120521307f, 0.001736522768624127f, 0.001742039225064218f, 0.001895414781756699f, 0.0013889838010072708f, 0.0019017001613974571f, 0.002156556351110339f, 0.0024406297598034143f, 0.0021239640191197395f, 0.0022179540246725082f, 0.0016438766615465283f, 0.0014375858008861542f, 0.002367312554270029f, 0.0017866254784166813f, 0.0015533337136730552f, 0.002162875374779105f, 0.0024889034684747458f, 0.00202106568031013f, 0.0009360727854073048f, 0.001532450201921165f, 0.002523652510717511f, 0.0017295160796493292f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001262262521777302f, 0.00011290283873677254f, 6.47702909191139e-05f, 0.00011860570521093905f, 0.0001239574485225603f, 9.795377991395071e-05f, 0.00016141610103659332f, 0.0001490657450631261f, 9.653774759499356e-05f, 0.00012109920498915017f, 0.00017952825874090195f, 0.00014894769992679358f, 8.656260615680367e-05f, 0.00011668349179672077f, 0.00013440646580420434f, 0.00013093007146380842f, 0.00012865215830970556f, 0.0001274308015126735f, 0.00012100677122361958f, 8.882484689820558e-05f, 0.0001284293830394745f, 0.00016432102711405605f, 0.0001361223985441029f, 0.00012135025463066995f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003382957074791193f, 0.0030258798506110907f, 0.001735891797579825f, 0.0031787208281457424f, 0.0033221514895558357f, 0.0026252339594066143f, 0.004326071124523878f, 0.003995072562247515f, 0.0025872832629829645f, 0.003245548577979207f, 0.004811490420252085f, 0.003991908859461546f, 0.002319941995665431f, 0.0031272042542696f, 0.003602192969992757f, 0.003509022993966937f, 0.003447973169386387f, 0.0034152399748563766f, 0.00324307125993073f, 0.0023805717937648296f, 0.0034420029260218143f, 0.004403925500810146f, 0.003648181213065982f, 0.0032522769179195166f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010375299461884424f, 0.0001171657131635584f, 0.00033068720949813724f, 0.0002973037480842322f, 0.000244181661400944f, 0.0001965426781680435f, 0.00028975788154639304f, 0.00031615086481906474f, 0.00029809048282913864f, 0.0003282400139141828f, 0.0001624675642233342f, 0.00031805422622710466f, 0.00020199343271087855f, 0.00022564090613741428f, 0.00012618924665730447f, 0.0002881769905798137f, 0.0001870955020422116f, 0.00021645525703206658f, 0.00015896045078989118f, 0.00036943730083294213f, 0.00026669545331969857f, 0.0004045021196361631f, 0.00030647916719317436f, 0.00033956667175516486f, 0.00019621146202553064f, 0.00014055789506528527f, 0.00013586571731138974f, 0.0001426311064278707f, 0.00033633591374382377f, 0.00025828578509390354f, 0.00023446680279448628f, 0.0001702991285128519f, 0.0002093418297590688f, 0.0002207405341323465f, 0.00016012327978387475f, 0.00013886360102333128f, 0.00017496131476946175f, 0.0002792942977976054f, 0.00028882251353934407f, 0.0002794671745505184f, 0.00012762284313794225f, 0.00013555109035223722f, 0.000223218317842111f, 0.00014766653475817293f, 0.0002596927515696734f, 0.0005434488411992788f, 0.00021625249064527452f, 0.00016282628348562866f, 0.00028105443925596774f, 0.0004398384189698845f, 0.00013033757568337023f, 0.00029361044289544225f, 0.0002416901261312887f, 0.0001801483886083588f, 0.0002181493182433769f, 0.00030420892289839685f, 0.00041040973155759275f, 0.00025328737683594227f, 0.00036068912595510483f, 0.00016763206804171205f, 0.00017155747627839446f, 0.00023763738863635808f, 0.00017029259470291436f, 0.00015031822840683162f, 0.0004589053278323263f, 0.00013354627299122512f, 0.0005341748474165797f, 0.00021244175150059164f, 0.0003969616664107889f, 0.00017298503371421248f, 0.00024149171076714993f, 0.0003669840516522527f, 0.0001821316545829177f, 0.00030305961263366044f, 0.00021819282846990973f, 0.00017180066788569093f, 0.00022241288388613611f, 0.00017619202844798565f, 0.00019727299513760954f, 0.0002552909718360752f, 0.00022823020117357373f, 0.0002181032468797639f, 0.0002843475085683167f, 0.0003677364729810506f, 0.00023665626940783113f, 0.00018312530301045626f, 0.0002486581797711551f, 0.00024191428383346647f, 0.00015291334420908242f, 0.00027502470766194165f, 0.00013715472596231848f, 0.00020723609486594796f, 0.0001535827905172482f, 0.00017736696463543922f, 0.0002269172400701791f, 0.00033142027677968144f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0037352226208895445f, 0.004218095447868109f, 0.011905105784535408f, 0.010703264735639095f, 0.008790810592472553f, 0.00707575399428606f, 0.010431604459881783f, 0.011381781660020351f, 0.010731588117778301f, 0.011817003600299358f, 0.005849012173712254f, 0.01145030464977026f, 0.00727198738604784f, 0.008123322390019894f, 0.004542952869087458f, 0.010374690406024456f, 0.006735645234584808f, 0.007792628835886717f, 0.005722752306610346f, 0.013300151564180851f, 0.009601331315934658f, 0.014562523923814297f, 0.011033589951694012f, 0.012224776670336723f, 0.007063829805701971f, 0.005060240160673857f, 0.004891316406428814f, 0.005134877748787403f, 0.012108465656638145f, 0.009298574179410934f, 0.00844106450676918f, 0.006130957510322332f, 0.007536537945270538f, 0.007946903817355633f, 0.005764615256339312f, 0.004999243654310703f, 0.0062988013960421085f, 0.010054904036223888f, 0.01039793062955141f, 0.010061128064990044f, 0.004594563972204924f, 0.004879989195615053f, 0.008036106824874878f, 0.005316158756613731f, 0.009349226951599121f, 0.019564760848879814f, 0.007785329129546881f, 0.005861926358193159f, 0.010118271224200726f, 0.015834670513868332f, 0.004692296963185072f, 0.010570300742983818f, 0.008701112121343613f, 0.0064855413511395454f, 0.007853616960346699f, 0.010951858013868332f, 0.014775204472243786f, 0.009118625894188881f, 0.012985208071768284f, 0.006034940015524626f, 0.006176259368658066f, 0.008555209264159203f, 0.006130721885710955f, 0.005411622580140829f, 0.01652109995484352f, 0.004807813558727503f, 0.019230885431170464f, 0.007648138329386711f, 0.014291059225797653f, 0.006227653007954359f, 0.008693968877196312f, 0.013211832381784916f, 0.006556941196322441f, 0.01091048214584589f, 0.007855183444917202f, 0.006185014266520739f, 0.008007110096514225f, 0.006343108136206865f, 0.00710204616189003f, 0.009190757758915424f, 0.008216540329158306f, 0.007851958274841309f, 0.010236824862658978f, 0.013238920830190182f, 0.008519887924194336f, 0.006592713762074709f, 0.008951970376074314f, 0.008709182031452656f, 0.005505049601197243f, 0.009901193901896477f, 0.004937721882015467f, 0.007460729219019413f, 0.005529150366783142f, 0.006385407410562038f, 0.008169271983206272f, 0.011931497603654861f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016518685151822865f, 0.00016270139894913882f, 9.577465243637562e-05f, 0.00017644371837377548f, 0.00011303244536975399f, 0.00011752888531191275f, 0.00015450998034793884f, 7.381160685326904e-05f, 6.454951653722674e-05f, 6.280878005782142e-05f, 0.00014914065832272172f, 7.413203275064006e-05f, 0.00012158140452811494f, 0.00014224433107301593f, 0.00012792284542229027f, 0.00012581574264913797f, 0.0001297378184972331f, 0.00012178505130577832f, 0.00014670124801341444f, 0.0001413811114616692f, 7.539567013736814e-05f, 0.00013740442227572203f, 0.00014955569349694997f, 0.00011447479482740164f, 9.83176360023208e-05f, 0.00015449961938429624f, 0.00011580977297853678f, 0.00012832271750085056f, 7.019983604550362e-05f, 9.715835039969534e-05f, 0.00011846654524561018f, 0.000191768747754395f, 0.00013238417159300297f, 0.00011931820336030796f, 0.00016713929653633386f, 0.00014508100866805762f, 0.0001155014761025086f, 8.7953798356466e-05f, 0.00014447762805502862f, 7.767818169668317e-05f, 0.00012702360982075334f, 0.00013672180648427457f, 8.451372559648007e-05f, 0.00012130173854529858f, 0.00011839606304420158f, 5.359315036912449e-05f, 4.980953599442728e-05f, 0.0001498965866630897f, 7.533389725722373e-05f, 5.5366504966514185e-05f, 0.0001108302385546267f, 8.864899427862838e-05f, 7.623913552379236e-05f, 0.00015026795153971761f, 0.0002070904738502577f, 0.00015820431872271f, 7.652927160961553e-05f, 0.00010573987674433738f, 9.599944314686581e-05f, 0.00017049653979483992f, 0.00011947572056669742f, 0.00011699923197738826f, 9.708094876259565e-05f, 0.00012375708320178092f, 9.104781929636374e-05f, 0.00016637510270811617f, 8.611058729002252e-05f, 6.935589772183448e-05f, 0.00014602635928895324f, 0.00012025185424135998f, 0.00013054898590780795f, 7.218252721941099e-05f, 0.0001043690208462067f, 7.321577140828595e-05f, 5.887060979148373e-05f, 0.00016380548186134547f, 0.0001513984170742333f, 0.00010110015864484012f, 0.00012765750580001622f, 9.831857460085303e-05f, 9.511450480204076e-05f, 9.755529754329473e-05f, 9.14677802938968e-05f, 6.498638686025515e-05f, 0.00011948902101721615f, 0.00015696608170401305f, 5.943550422671251e-05f, 0.0001797505101421848f, 0.00010417230805614963f, 6.859331188024953e-05f, 0.0001665068994043395f, 9.437037078896537e-05f, 0.00021760999516118318f, 0.00012145529763074592f, 0.00012540722673293203f, 9.438419510843232e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0031550696585327387f, 0.0031075975857675076f, 0.001829296350479126f, 0.0033700759522616863f, 0.002158920280635357f, 0.0022448021918535233f, 0.002951141446828842f, 0.001409802003763616f, 0.0012328961165621877f, 0.001199648017063737f, 0.002848587231710553f, 0.0014159221900627017f, 0.0023222053423523903f, 0.0027168672531843185f, 0.0024433268699795008f, 0.002403081161901355f, 0.0024779927916824818f, 0.002326095011085272f, 0.0028019945602864027f, 0.002700379816815257f, 0.0014400576474145055f, 0.0026244251057505608f, 0.0028565144166350365f, 0.0021864690352231264f, 0.0018778672674670815f, 0.0029509435407817364f, 0.0022119672503322363f, 0.0024509644135832787f, 0.0013408171944320202f, 0.0018557249568402767f, 0.002262711524963379f, 0.0036627838853746653f, 0.002528538228943944f, 0.0022789782378822565f, 0.003192361444234848f, 0.0027710478752851486f, 0.0022060787305235863f, 0.0016799179138615727f, 0.002759523456916213f, 0.001483653555624187f, 0.002426151419058442f, 0.0026113870553672314f, 0.0016142125241458416f, 0.002316863741725683f, 0.0022613652981817722f, 0.0010236294474452734f, 0.000951362366322428f, 0.002863025525584817f, 0.0014388777781277895f, 0.00105750048533082f, 0.0021168580278754234f, 0.001693196129053831f, 0.0014561678981408477f, 0.0028701184783130884f, 0.003955428954213858f, 0.0030217033345252275f, 0.0014617093838751316f, 0.0020196321420371532f, 0.0018335897475481033f, 0.0032564846333116293f, 0.002281986875459552f, 0.0022346859332174063f, 0.0018542465986683965f, 0.0023637607228010893f, 0.0017390137072652578f, 0.003177765291184187f, 0.0016447126399725676f, 0.0013246979797258973f, 0.00278910412453115f, 0.00229681096971035f, 0.002493486274033785f, 0.0013786866329610348f, 0.00199344870634377f, 0.0013984215911477804f, 0.001124428934417665f, 0.003128685522824526f, 0.0028917104937136173f, 0.0019310134230181575f, 0.0024382590781897306f, 0.001877885195426643f, 0.0018166875233873725f, 0.0018633066210895777f, 0.0017470349557697773f, 0.001241240301169455f, 0.002282240893691778f, 0.0029980528634041548f, 0.0011352184228599072f, 0.0034332354553043842f, 0.0019896915182471275f, 0.0013101325603201985f, 0.0031802826561033726f, 0.0018024744931608438f, 0.004156352020800114f, 0.002319796709343791f, 0.0023952785413712263f, 0.0018027385231107473f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024364017008338124f, 0.00011570552305784076f, 0.0002941754646599293f, 0.00019125794642604887f, 0.00012567439989652485f, 0.00020636660337913781f, 0.00024009606568142772f, 0.00016229506582021713f, 0.00016855676949489862f, 9.847075125435367e-05f, 0.00011291367991361767f, 0.00016448872338514775f, 0.0001310619554715231f, 0.00016581732779741287f, 0.00011479622480692342f, 0.0001391760160913691f, 0.00016084300295915455f, 0.00019518318003974855f, 0.0001408244133926928f, 0.00014518505486194044f, 0.00012816721573472023f, 0.00017167582700494677f, 0.00014507226296700537f, 0.00013093494635540992f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0034530595876276493f, 0.0016398694133386016f, 0.004169285297393799f, 0.00271065765991807f, 0.00178115617018193f, 0.0029247894417494535f, 0.0034028298687189817f, 0.002300173044204712f, 0.002388918772339821f, 0.001395604689605534f, 0.0016003012424334884f, 0.0023312631528824568f, 0.001857512746937573f, 0.0023500933311879635f, 0.001626982120797038f, 0.0019725116435438395f, 0.0022795931436121464f, 0.002766289049759507f, 0.0019958741031587124f, 0.002057676436379552f, 0.0018164863577112556f, 0.002433124464005232f, 0.0020560778211802244f, 0.0018557128496468067f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00025317876134067774f, 0.00015059305587783456f, 0.00016371195670217276f, 0.00028689863393083215f, 0.0003333838249091059f, 0.00022198368969839066f, 0.00019694567890837789f, 0.0003535394207574427f, 0.00022512303257826716f, 0.0003442365559749305f, 0.00019054602307733148f, 0.00037628173595294356f, 0.00023919905652292073f, 0.00022905200603418052f, 0.0003014530520886183f, 0.00014567187463399023f, 0.00015369300672318786f, 0.00015140936011448503f, 0.00047998115769587457f, 0.00025977991754189134f, 0.00017731628031469882f, 0.0002962893631774932f, 0.00046640640357509255f, 0.0002585536858532578f, 0.0003715844650287181f, 0.00012815905211027712f, 0.00033636268926784396f, 0.00023968347522895783f, 0.00018081437156070024f, 0.00019533837621565908f, 0.00030834233621135354f, 0.00015961912868078798f, 0.0003912471001967788f, 0.00015276367776095867f, 0.0002518068940844387f, 0.0003865320759359747f, 0.00026578540564514697f, 0.0002582457091193646f, 0.0001299694849876687f, 0.0004847948148380965f, 0.00014078913955017924f, 0.0004134398477617651f, 0.00026318078744225204f, 0.00023901762324385345f, 0.0002372897433815524f, 0.00025416238349862397f, 0.00017115524678956717f, 0.00023436509945895523f, 0.00016019587928894907f, 0.00019942161452490836f, 0.0002525534655433148f, 0.0003006357583217323f, 0.0008743404760025442f, 0.00014973986253608018f, 0.0002853023470379412f, 0.00018562482728157192f, 0.0002193448890466243f, 0.0002974884118884802f, 0.00021740204829256982f, 0.00016377873544115573f, 0.0005054247449152172f, 0.0002901506086345762f, 0.0003664252581074834f, 0.0005110124475322664f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008710173889994621f, 0.005180891137570143f, 0.005632224027067423f, 0.009870246984064579f, 0.011469488963484764f, 0.007636961527168751f, 0.006775572430342436f, 0.012162907049059868f, 0.007744965143501759f, 0.011842858046293259f, 0.006555403582751751f, 0.012945316731929779f, 0.008229225873947144f, 0.007880134508013725f, 0.010370966047048569f, 0.005011586472392082f, 0.005287539679557085f, 0.005208974704146385f, 0.01651291362941265f, 0.008937275037169456f, 0.006100257392972708f, 0.010193318128585815f, 0.01604589819908142f, 0.008895087987184525f, 0.012783714570105076f, 0.0044090887531638145f, 0.011571971699595451f, 0.008245891891419888f, 0.00622060289606452f, 0.006720276083797216f, 0.010607980191707611f, 0.005491417367011309f, 0.013460174202919006f, 0.005255567841231823f, 0.008662976324558258f, 0.01329796202480793f, 0.009143883362412453f, 0.008884493261575699f, 0.004471373278647661f, 0.016678519546985626f, 0.004843604750931263f, 0.014223676174879074f, 0.00905427522957325f, 0.00822298415005207f, 0.008163539692759514f, 0.008744013495743275f, 0.005888297688215971f, 0.008062922395765781f, 0.005511259660124779f, 0.006860752590000629f, 0.008688661269843578f, 0.010342848487198353f, 0.0300801582634449f, 0.005151538643985987f, 0.009815329685807228f, 0.006386098451912403f, 0.007546178065240383f, 0.010234570130705833f, 0.007479337975382805f, 0.005634521599858999f, 0.017388256266713142f, 0.009982125833630562f, 0.012606221251189709f, 0.017580492421984673f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00025385545450262725f, 0.0002539404376875609f, 0.0002471943444106728f, 0.00024839508114382625f, 0.00015757531218696386f, 0.0002982746809720993f, 0.00019216819782741368f, 0.00012578711903188378f, 0.00015077531861606985f, 0.00021521230519283563f, 0.0001665223971940577f, 0.00017551492783240974f, 0.00019844534108415246f, 0.0002130406501237303f, 0.00021640208433382213f, 0.0002518602414056659f, 0.0002194140834035352f, 0.00027321820380166173f, 0.0002147401391994208f, 0.00022198948136065155f, 0.00023621319269295782f, 0.0001644294534344226f, 0.0001729272335069254f, 0.000215065578231588f, 0.00030190119286999106f, 0.00027075098478235304f, 0.000257866078754887f, 0.00021599532919935882f, 0.0002709808759391308f, 0.0002741997304838151f, 0.00016732992662582546f, 0.00019446165242698044f, 9.284365660278127e-05f, 0.0002198423899244517f, 0.0001724373723845929f, 9.986444638343528e-05f, 0.00024047338229138404f, 9.72915004240349e-05f, 0.0002479535760357976f, 0.00022159723448567092f, 0.00031259897514246404f, 0.0001151686446974054f, 0.0003132070414721966f, 0.00024266279069706798f, 0.00014067089068703353f, 0.00012770088505931199f, 0.00017799435590859503f, 0.00026992461062036455f, 0.00020913624030072242f, 0.0002030590403592214f, 0.0001931842853082344f, 0.0002842796384356916f, 0.00022600131342187524f, 0.00020653288811445236f, 0.0002730630221776664f, 0.00029271855601109564f, 0.0002489356556907296f, 0.0001967384450836107f, 0.00028173389728181064f, 0.00034685953869484365f, 0.00022588917636312544f, 0.00022509193513542414f, 0.00028794584795832634f, 0.0001377789885737002f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0027477950789034367f, 0.002748714992776513f, 0.002675693714991212f, 0.002688690787181258f, 0.0017056347569450736f, 0.003228600136935711f, 0.002080076839774847f, 0.0013615513453260064f, 0.001632029889151454f, 0.002329512033611536f, 0.0018024803139269352f, 0.0018998176092281938f, 0.0021480221766978502f, 0.0023060054518282413f, 0.0023423905950039625f, 0.0027261984068900347f, 0.002374993171542883f, 0.002957382472231984f, 0.00232440116815269f, 0.0024028699845075607f, 0.0025568308774381876f, 0.0017798257758840919f, 0.0018718078499659896f, 0.002327923895791173f, 0.0032678544521331787f, 0.0029306765645742416f, 0.0027912072837352753f, 0.002337987767532468f, 0.002933165058493614f, 0.002968006767332554f, 0.001811221125535667f, 0.00210490170866251f, 0.0010049630654975772f, 0.0023796292953193188f, 0.0018665054813027382f, 0.001080957823432982f, 0.0026029443833976984f, 0.0010531076695770025f, 0.0026839119382202625f, 0.0023986240848898888f, 0.003383649978786707f, 0.0012466143816709518f, 0.0033902316354215145f, 0.0026266430504620075f, 0.0015226569958031178f, 0.0013822665205225348f, 0.0019266556482762098f, 0.002921731909736991f, 0.002263743197545409f, 0.0021979620214551687f, 0.0020910752937197685f, 0.0030771142337471247f, 0.0024462949950248003f, 0.002235563937574625f, 0.002955702831968665f, 0.0031684592831879854f, 0.0026945420540869236f, 0.0021295463666319847f, 0.0030495584942400455f, 0.00375449494458735f, 0.0024450812488794327f, 0.0024364516139030457f, 0.003116798121482134f, 0.001491354312747717f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023395326570607722f, 0.0001517404307378456f, 0.00018676207400858402f, 0.0003954862477257848f, 0.0002296252641826868f, 0.00022325378085952252f, 0.00022756998077966273f, 0.0002672223490662873f, 0.00027552395476959646f, 0.00021490268409252167f, 0.00022328221530187875f, 0.00023734508431516588f, 0.00017924507847055793f, 0.00020930988830514252f, 0.0002066612069029361f, 0.00030189697281457484f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00446037482470274f, 0.0028929675463587046f, 0.0035606634337455034f, 0.0075400397181510925f, 0.004377860575914383f, 0.004256386775523424f, 0.004338676109910011f, 0.005094658117741346f, 0.005252929870039225f, 0.004097171127796173f, 0.00425692880526185f, 0.004525040742009878f, 0.0034173501189798117f, 0.003990543074905872f, 0.003940045367926359f, 0.005755737889558077f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006702154641970992f, 0.00039540615398436785f, 0.00034024124033749104f, 0.0005752321449108422f, 0.0006746365688741207f, 0.0002517929533496499f, 0.0007300549768842757f, 0.0005816377815790474f, 0.00027251357096247375f, 0.0004667683970183134f, 0.00039622376789338887f, 0.0004233699291944504f, 0.00032316191936843097f, 0.0002139518765034154f, 0.00017694290727376938f, 0.00048309884732589126f, 0.0006226159166544676f, 0.0003109572862740606f, 0.000853578676469624f, 0.0003740970860235393f, 0.0005859325756318867f, 0.00059381069149822f, 0.0004945790278725326f, 0.00027733869501389563f, 0.0003684108960442245f, 0.00025971134891733527f, 0.0005089844344183803f, 0.00046346455928869545f, 0.0008341001230292022f, 0.0007419057074002922f, 0.0002673294802661985f, 0.0005448278388939798f, 0.00025515264132991433f, 0.000550258147995919f, 0.0003567581588868052f, 0.0003593380097299814f, 0.0003786224697250873f, 0.00020849844440817833f, 0.00033346808049827814f, 0.0005556892137974501f, 0.00032210914650931954f, 0.0009579594479873776f, 0.0005726739182136953f, 0.0002012062759604305f, 0.0009680257644504309f, 0.00022596685448661447f, 0.00023579438857268542f, 0.0006516296998597682f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019175730645656586f, 0.011313080787658691f, 0.009734741412103176f, 0.016458135098218918f, 0.01930222287774086f, 0.007204121444374323f, 0.020887816324830055f, 0.01664140820503235f, 0.007796965539455414f, 0.013354846276342869f, 0.011336473748087883f, 0.012113160453736782f, 0.009246080182492733f, 0.006121439393609762f, 0.005062565207481384f, 0.013822081498801708f, 0.017813844606280327f, 0.008896889165043831f, 0.024421988055109978f, 0.01070340070873499f, 0.016764286905527115f, 0.016989691182971f, 0.014150544069707394f, 0.00793501827865839f, 0.01054071169346571f, 0.007430677302181721f, 0.014562701806426048f, 0.013260319828987122f, 0.023864680901169777f, 0.021226881071925163f, 0.007648641709238291f, 0.015588228590786457f, 0.007300246972590685f, 0.015743596479296684f, 0.010207311250269413f, 0.010281124152243137f, 0.010832877829670906f, 0.005965409800410271f, 0.009540952742099762f, 0.015898985788226128f, 0.009215958416461945f, 0.027408456429839134f, 0.016384940594434738f, 0.005756771191954613f, 0.02769646793603897f, 0.00646520359441638f, 0.006746381986886263f, 0.018643967807292938f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001604813151061535f, 0.0003758794628083706f, 7.930985884740949e-05f, 0.00017460848903283477f, 0.00021541572641581297f, 0.00023849149874877185f, 0.00014336808817461133f, 6.358970131259412e-05f, 0.00024406361626461148f, 0.00031139369821175933f, 0.0002095602685585618f, 0.00029331937548704445f, 0.00024240717175416648f, 0.00022427608200814575f, 0.0002122456644428894f, 0.0001341174793196842f, 0.0001333511754637584f, 0.00013637891970574856f, 5.143694579601288e-05f, 0.00029747450025752187f, 0.00018242331861983985f, 0.00011606699990807101f, 9.395372035214677e-05f, 0.00014450728485826403f, 0.0003371024795342237f, 0.00014539502444677055f, 0.00012634570884983987f, 0.0001476809848099947f, 0.00012452231021597981f, 0.00017281768668908626f, 0.00023063340631779283f, 0.0003128194948658347f, 0.00023159717966336757f, 0.00014416709018405527f, 0.00017624929023440927f, 0.00021938009012956172f, 0.0001908755803015083f, 0.00023497967049479485f, 0.000151526925037615f, 0.0002198975853389129f, 0.0002139381249435246f, 7.336198177654296e-05f, 0.00026805815286934376f, 0.000304334593238309f, 0.0002023787674261257f, 0.00028943197685293853f, 0.00039792602183297276f, 0.00015182116476353258f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0031513639260083437f, 0.007381127215921879f, 0.0015574039425700903f, 0.003428778611123562f, 0.004230108577758074f, 0.004683246370404959f, 0.0028153122402727604f, 0.0012487079948186874f, 0.004792665597051382f, 0.006114823278039694f, 0.00411512516438961f, 0.0057598985731601715f, 0.004760138224810362f, 0.004404098726809025f, 0.004167858045548201f, 0.0026336584705859423f, 0.0026186108589172363f, 0.0026780664920806885f, 0.0010100648505613208f, 0.005841492675244808f, 0.0035822379868477583f, 0.0022792022209614515f, 0.001844964805059135f, 0.002837682841345668f, 0.006619665306061506f, 0.0028551153372973204f, 0.0024810447357594967f, 0.002900004619732499f, 0.0024452386423945427f, 0.003393612802028656f, 0.004528937395662069f, 0.006142821628600359f, 0.0045478628017008305f, 0.0028310022316873074f, 0.0034609991125762463f, 0.00430795643478632f, 0.003748214803636074f, 0.004614284727722406f, 0.002975527197122574f, 0.0043181185610592365f, 0.004201092757284641f, 0.0014406057307496667f, 0.005263845436275005f, 0.005976204294711351f, 0.003974102437496185f, 0.005683561787009239f, 0.007814054377377033f, 0.0029813051223754883f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001950351579580456f, 0.00026477116625756025f, 0.0003137874882668257f, 0.00024999346351251006f, 0.0002235285210190341f, 0.0002321519423276186f, 0.00034087372478097677f, 0.00025496259331703186f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011441685492172837f, 0.0015532729448750615f, 0.001840825891122222f, 0.001466579968109727f, 0.0013113240711390972f, 0.0013619131641462445f, 0.0019997265189886093f, 0.001495731296017766f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006503949989564717f, 0.000982570694759488f, 0.0005717737367376685f, 0.0008492604247294366f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006407109554857016f, 0.009679406881332397f, 0.005632603075355291f, 0.008366153575479984f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0020581362769007683f, 0.003328811377286911f, 0.0021380363032221794f, 0.0002632546238601208f, 0.0007270218920893967f, 0.0007967125275172293f, 0.0004713647940661758f, 0.0003616551111917943f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017277194187045097f, 0.02794397994875908f, 0.01794792152941227f, 0.002209912519901991f, 0.006103044841438532f, 0.006688068620860577f, 0.003956910222768784f, 0.003035943489521742f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00041972793405875564f, 0.00018631614511832595f, 0.0003340404946357012f, 0.0006556377629749477f, 0.0006505523924715817f, 0.0004435127484612167f, 0.0007673500222153962f, 0.001351530896499753f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004451849032193422f, 0.0019761642906814814f, 0.003543004160746932f, 0.006954029202461243f, 0.0069000911898911f, 0.004704122897237539f, 0.008138906210660934f, 0.01433502696454525f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024271536676678807f, 0.0003450765507295728f, 8.320798951899633e-05f, 0.0003661469672806561f, 0.0002895419020205736f, 0.0003590295382309705f, 8.960301784100011e-05f, 0.00031518199830316007f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06189241632819176f, 0.0879945158958435f, 0.021218035370111465f, 0.09336747229099274f, 0.07383318245410919f, 0.09155252575874329f, 0.022848768159747124f, 0.08037140220403671f),
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
    AI_PACK_INTQ_SCALE(0.09428171068429947f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11912445724010468f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10151145607233047f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17046016454696655f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0509243980050087f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.034951236099004745f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0524514801800251f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09238514304161072f),
    AI_PACK_INTQ_ZP(-32)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09238514304161072f),
    AI_PACK_INTQ_ZP(-32)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.029067017138004303f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07055776566267014f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05235600844025612f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027776923030614853f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.037312399595975876f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03971036151051521f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.058710500597953796f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01603003405034542f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02241201139986515f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.029409145936369896f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07411297410726547f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01708373613655567f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020101720467209816f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03792129084467888f),
    AI_PACK_INTQ_ZP(16)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07878148555755615f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11261384189128876f),
    AI_PACK_INTQ_ZP(-33)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01670079678297043f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01901976764202118f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019142823293805122f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015607061795890331f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1143835186958313f),
    AI_PACK_INTQ_ZP(43)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1424, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1424, 1424),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2816, 2816),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &conv2d_36_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_35_scratch0_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1632, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1632, 1632),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 496, 1, 1), AI_STRIDE_INIT(4, 1, 1, 496, 496),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 736, 1, 1), AI_STRIDE_INIT(4, 1, 1, 736, 736),
  1, &conv2d_14_scratch0_array, NULL)

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
  conv2d_38_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 40, 1, 1), AI_STRIDE_INIT(4, 4, 4, 160, 160),
  1, &conv2d_38_bias_array, &conv2d_38_bias_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 40), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_38_weights_array, &conv2d_38_weights_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_37_bias_array, &conv2d_37_bias_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 256), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_37_weights_array, &conv2d_37_weights_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_36_bias_array, &conv2d_36_bias_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_36_weights_array, &conv2d_36_weights_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_35_bias_array, &conv2d_35_bias_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_35_weights_array, &conv2d_35_weights_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 88, 1, 1, 128), AI_STRIDE_INIT(4, 1, 88, 88, 88),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_26_bias_array, &conv2d_26_bias_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_26_weights_array, &conv2d_26_weights_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_24_bias_array, &conv2d_24_bias_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_24_weights_array, &conv2d_24_weights_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_20_bias_array, &conv2d_20_bias_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_20_weights_array, &conv2d_20_weights_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 24), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_14_bias_array, &conv2d_14_bias_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 64), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_14_weights_array, &conv2d_14_weights_intq)

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
  concat_13_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 20, 20), AI_STRIDE_INIT(4, 1, 1, 24, 480),
  1, &concat_13_output_array, &concat_13_output_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_14_output_array, &conv2d_14_output_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_20_output_array, &conv2d_20_output_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_21_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_21_output_array, &eltwise_21_output_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_24_output_array, &conv2d_24_output_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_25_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_25_output_array, &eltwise_25_output_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_26_output_array, &conv2d_26_output_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_29_output_array, &eltwise_29_output_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  concat_32_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 88, 10, 10), AI_STRIDE_INIT(4, 1, 1, 88, 880),
  1, &concat_32_output_array, &concat_32_output_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_35_output_array, &conv2d_35_output_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 5, 5), AI_STRIDE_INIT(4, 1, 1, 64, 320),
  1, &conv2d_36_output_array, &conv2d_36_output_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 5, 5), AI_STRIDE_INIT(4, 1, 1, 256, 1280),
  1, &conv2d_37_output_array, &conv2d_37_output_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 40, 5, 5), AI_STRIDE_INIT(4, 1, 1, 40, 200),
  1, &conv2d_38_output_array, &conv2d_38_output_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conversion_39_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 40, 5, 5), AI_STRIDE_INIT(4, 4, 4, 160, 800),
  1, &conversion_39_output_array, NULL)



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
  &AI_NET_OBJ_INSTANCE, &concat_13_layer, AI_STATIC,
  .tensors = &conv2d_11_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_output, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_13_layer, 13,
  CONCAT_TYPE,
  concat, forward_concat,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC,
  .tensors = &concat_13_chain, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 14,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC,
  .tensors = &conv2d_14_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC,
  .tensors = &conv2d_16_chain, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
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
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
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
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
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
  &AI_NET_OBJ_INSTANCE, &eltwise_21_layer, AI_STATIC,
  .tensors = &conv2d_20_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_output, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_21_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_21_layer, 21,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC,
  .tensors = &eltwise_21_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC,
  .tensors = &conv2d_22_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
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
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
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
  &AI_NET_OBJ_INSTANCE, &eltwise_25_layer, AI_STATIC,
  .tensors = &conv2d_24_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_21_output, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_25_layer, 25,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &conv2d_26_layer, AI_STATIC,
  .tensors = &eltwise_25_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 26,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC,
  .tensors = &conv2d_26_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
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
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
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
  &AI_NET_OBJ_INSTANCE, &eltwise_29_layer, AI_STATIC,
  .tensors = &conv2d_28_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_25_output, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_29_layer, 29,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &concat_32_layer, AI_STATIC,
  .tensors = &eltwise_29_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_29_output, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_32_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_32_layer, 32,
  CONCAT_TYPE,
  concat, forward_concat,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC,
  .tensors = &concat_32_chain, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_35_layer, AI_STATIC,
  .tensors = &conv2d_33_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_35_weights, &conv2d_35_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_35_layer, 35,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC,
  .tensors = &conv2d_35_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
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
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
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
  &AI_NET_OBJ_INSTANCE, &conversion_39_layer, AI_STATIC,
  .tensors = &conv2d_38_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_39_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_39_layer, 39,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &conversion_39_layer, AI_STATIC,
  .tensors = &conversion_39_chain, 
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
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PERSON_YOLO_OUT_NUM, &conversion_39_output),
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
    conv2d_38_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_38_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data = AI_PTR(activations + 2752);
    conv2d_37_scratch0_array.data_start = AI_PTR(activations + 2752);
    conv2d_36_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_36_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_35_scratch0_array.data = AI_PTR(activations + 14432);
    conv2d_35_scratch0_array.data_start = AI_PTR(activations + 14432);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 23172);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 23172);
    conv2d_26_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_26_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_24_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_24_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 8772);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 8772);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_20_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_20_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 20772);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 20772);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_14_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_14_scratch0_array.data_start = AI_PTR(activations + 0);
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
    concat_13_output_array.data = AI_PTR(activations + 10432);
    concat_13_output_array.data_start = AI_PTR(activations + 10432);
    conv2d_14_output_array.data = AI_PTR(activations + 20032);
    conv2d_14_output_array.data_start = AI_PTR(activations + 20032);
    conv2d_16_output_array.data = AI_PTR(activations + 2372);
    conv2d_16_output_array.data_start = AI_PTR(activations + 2372);
    conv2d_17_output_array.data = AI_PTR(activations + 8772);
    conv2d_17_output_array.data_start = AI_PTR(activations + 8772);
    conv2d_18_output_array.data = AI_PTR(activations + 11172);
    conv2d_18_output_array.data_start = AI_PTR(activations + 11172);
    conv2d_19_output_array.data = AI_PTR(activations + 24328);
    conv2d_19_output_array.data_start = AI_PTR(activations + 24328);
    conv2d_20_output_array.data = AI_PTR(activations + 11172);
    conv2d_20_output_array.data_start = AI_PTR(activations + 11172);
    eltwise_21_output_array.data = AI_PTR(activations + 13572);
    eltwise_21_output_array.data_start = AI_PTR(activations + 13572);
    conv2d_22_output_array.data = AI_PTR(activations + 15972);
    conv2d_22_output_array.data_start = AI_PTR(activations + 15972);
    conv2d_23_output_array.data = AI_PTR(activations + 25572);
    conv2d_23_output_array.data_start = AI_PTR(activations + 25572);
    conv2d_24_output_array.data = AI_PTR(activations + 8772);
    conv2d_24_output_array.data_start = AI_PTR(activations + 8772);
    eltwise_25_output_array.data = AI_PTR(activations + 11172);
    eltwise_25_output_array.data_start = AI_PTR(activations + 11172);
    conv2d_26_output_array.data = AI_PTR(activations + 13572);
    conv2d_26_output_array.data_start = AI_PTR(activations + 13572);
    conv2d_27_output_array.data = AI_PTR(activations + 26728);
    conv2d_27_output_array.data_start = AI_PTR(activations + 26728);
    conv2d_28_output_array.data = AI_PTR(activations + 8772);
    conv2d_28_output_array.data_start = AI_PTR(activations + 8772);
    eltwise_29_output_array.data = AI_PTR(activations + 13572);
    eltwise_29_output_array.data_start = AI_PTR(activations + 13572);
    concat_32_output_array.data = AI_PTR(activations + 15972);
    concat_32_output_array.data_start = AI_PTR(activations + 15972);
    conv2d_33_output_array.data = AI_PTR(activations + 1632);
    conv2d_33_output_array.data_start = AI_PTR(activations + 1632);
    conv2d_35_output_array.data = AI_PTR(activations + 19172);
    conv2d_35_output_array.data_start = AI_PTR(activations + 19172);
    conv2d_36_output_array.data = AI_PTR(activations + 1152);
    conv2d_36_output_array.data_start = AI_PTR(activations + 1152);
    conv2d_37_output_array.data = AI_PTR(activations + 5568);
    conv2d_37_output_array.data_start = AI_PTR(activations + 5568);
    conv2d_38_output_array.data = AI_PTR(activations + 1424);
    conv2d_38_output_array.data_start = AI_PTR(activations + 1424);
    conversion_39_output_array.data = AI_PTR(NULL);
    conversion_39_output_array.data_start = AI_PTR(NULL);
    
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
    
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(weights + 75504);
    conv2d_38_bias_array.data_start = AI_PTR(weights + 75504);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(weights + 65264);
    conv2d_38_weights_array.data_start = AI_PTR(weights + 65264);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(weights + 64240);
    conv2d_37_bias_array.data_start = AI_PTR(weights + 64240);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(weights + 47856);
    conv2d_37_weights_array.data_start = AI_PTR(weights + 47856);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(weights + 47600);
    conv2d_36_bias_array.data_start = AI_PTR(weights + 47600);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(weights + 39408);
    conv2d_36_weights_array.data_start = AI_PTR(weights + 39408);
    conv2d_35_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_bias_array.data = AI_PTR(weights + 38896);
    conv2d_35_bias_array.data_start = AI_PTR(weights + 38896);
    conv2d_35_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_weights_array.data = AI_PTR(weights + 37744);
    conv2d_35_weights_array.data_start = AI_PTR(weights + 37744);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 37232);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 37232);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 25968);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 25968);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 25872);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 25872);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 23568);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 23568);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 23184);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 23184);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 22320);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 22320);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(weights + 21936);
    conv2d_26_bias_array.data_start = AI_PTR(weights + 21936);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(weights + 19632);
    conv2d_26_weights_array.data_start = AI_PTR(weights + 19632);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 19536);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 19536);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 17232);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 17232);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 16848);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 16848);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 15984);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 15984);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 15600);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 15600);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 13296);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 13296);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 13200);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 13200);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 10896);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 10896);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 10512);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 10512);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 9648);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 9648);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 9264);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 9264);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 6960);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 6960);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 6864);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 6864);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 5328);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 5328);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 5072);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 5072);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 4496);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 4496);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 4240);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 4240);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 2704);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 2704);
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

