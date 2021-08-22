/**
  ******************************************************************************
  * @file    person_yolo.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Aug 20 22:39:46 2021
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
#define AI_PERSON_YOLO_MODEL_SIGNATURE     "8e40a6a29ce9f4e7f93d2a720dbe6983"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Fri Aug 20 22:39:46 2021"

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
  NULL, NULL, 1324, AI_STATIC)

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
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 30, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7680, AI_STATIC)

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
  NULL, NULL, 750, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conversion_39_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 750, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 30,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.3819062334951013e-05f, 3.996301529696211e-05f, 1.0931038559647277e-05f, 1.7895519704325125e-05f, 0.00010930087591987103f, 5.727004099753685e-05f, 2.6492798497201875e-05f, 3.7074205465614796e-05f, 1.2684427019848954e-05f, 2.3320360924117267e-05f, 0.00010145287524210289f, 5.454349593492225e-05f, 2.9858023481210694e-05f, 3.437928171479143e-05f, 1.4410469702852424e-05f, 2.1420100893010385e-05f, 9.648274863138795e-05f, 5.701877671526745e-05f, 2.7700678401743062e-05f, 3.513822230161168e-05f, 1.4236494280339684e-05f, 2.1006469978601672e-05f, 9.632886212784797e-05f, 5.724660150008276e-05f, 2.7544572731130756e-05f, 3.610324711189605e-05f, 1.5122875993256457e-05f, 1.9866154616465792e-05f, 9.066112397704273e-05f, 5.764226443716325e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 30,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000894292548764497f, 0.001500421203672886f, 0.000410408538300544f, 0.0006718916702084243f, 0.004103728104382753f, 0.0021502177696675062f, 0.0009946785867214203f, 0.0013919600751250982f, 0.00047623991849832237f, 0.0008755686576478183f, 0.003809073008596897f, 0.0020478488877415657f, 0.0011210268130525947f, 0.0012907785130664706f, 0.000541044631972909f, 0.0008042229455895722f, 0.003622468328103423f, 0.0021407839376479387f, 0.0010400287574157119f, 0.001319273142144084f, 0.0005345126846805215f, 0.0007886930834501982f, 0.003616690868511796f, 0.0021493376698344946f, 0.001034167711623013f, 0.0013555053155869246f, 0.0005677920999005437f, 0.0007458796608261764f, 0.0034038941375911236f, 0.0021641929633915424f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.1532200915098656e-05f, 3.1609295547241345e-05f, 2.397670687059872e-05f, 1.9976325347670354e-05f, 2.015919380937703e-05f, 1.6337606211891398e-05f, 2.086121094180271e-05f, 1.413552035955945e-05f, 3.1058374588610604e-05f, 2.3805268938303925e-05f, 2.3821947252145037e-05f, 1.4614469364460092e-05f, 1.5601541235810146e-05f, 1.5012686162663158e-05f, 1.980781598831527e-05f, 1.539243385195732e-05f, 2.096780008287169e-05f, 4.128881118958816e-05f, 2.0340943592600524e-05f, 1.618816895643249e-05f, 1.362274542771047e-05f, 2.9905675546615385e-05f, 2.2111864382168278e-05f, 1.7306592781096697e-05f, 2.1944975742371753e-05f, 4.114045441383496e-05f, 1.664767478359863e-05f, 1.2291846360312775e-05f, 2.526879688957706e-05f, 1.3385520105657633e-05f, 2.6714435080066323e-05f, 2.0554762159008533e-05f, 1.8154754798160866e-05f, 1.4936573279555887e-05f, 1.5985153368092142e-05f, 2.3010743461782113e-05f, 2.7582411348703317e-05f, 2.574747304606717e-05f, 2.7254865926806815e-05f, 1.4553778783010785e-05f, 2.254799983347766e-05f, 1.5052563867357094e-05f, 1.5257936865964439e-05f, 1.94057502085343e-05f, 1.7295717043452896e-05f, 1.4163173545966856e-05f, 1.8838652977137826e-05f, 1.4789249689783901e-05f, 1.6002064512576908e-05f, 2.0793584553757682e-05f, 1.757100471877493e-05f, 2.5876888685161248e-05f, 2.045710789388977e-05f, 3.073706102441065e-05f, 3.819333505816758e-05f, 1.756066376401577e-05f, 1.5845447705942206e-05f, 2.1328212824300863e-05f, 2.2801099476055242e-05f, 2.2760184947401285e-05f, 1.5332712791860104e-05f, 2.1985930288792588e-05f, 2.5893394195009023e-05f, 1.6368234355468303e-05f, 1.609801984159276e-05f, 1.805527790565975e-05f, 1.6853586203069426e-05f, 1.3742638657276984e-05f, 1.4954048310755752e-05f, 1.2919959772261791e-05f, 1.9246197553002276e-05f, 2.5153305614367127e-05f, 1.2987737136427313e-05f, 4.5927732571726665e-05f, 1.733554745442234e-05f, 1.6079848137451336e-05f, 1.7356695025227964e-05f, 1.6042025890783407e-05f, 1.6065929230535403e-05f, 1.5041207916510757e-05f, 1.5321700630011037e-05f, 1.5523326510447077e-05f, 1.337138564849738e-05f, 1.8624121366883628e-05f, 1.990370401472319e-05f, 1.548941872897558e-05f, 1.3127221791364718e-05f, 2.7276786568108946e-05f, 3.712472243933007e-05f, 1.887316830107011e-05f, 1.63919849001104e-05f, 3.0517985578626394e-05f, 2.006350041483529e-05f, 2.1774125343654305e-05f, 1.4978380932006985e-05f, 1.6357807908207178e-05f, 1.793461706256494e-05f, 2.0027808204758912e-05f, 2.5877328880596906e-05f, 2.0997038518544286e-05f, 1.7168547856272198e-05f, 1.755194170982577e-05f, 2.7011938072973862e-05f, 2.8655909773078747e-05f, 1.4793818991165608e-05f, 1.680708555795718e-05f, 1.6104768292279914e-05f, 1.7198966816067696e-05f, 2.4607805244158953e-05f, 1.9420240278122947e-05f, 1.7437630958738737e-05f, 1.416218583472073e-05f, 2.07461416721344e-05f, 3.125200601061806e-05f, 1.4956092854845338e-05f, 3.0525763577315956e-05f, 1.5387562598334625e-05f, 2.184283766837325e-05f, 1.2107239854231011e-05f, 2.0960580513929017e-05f, 1.6707479517208412e-05f, 2.0172252334305085e-05f, 2.3779204639140517e-05f, 2.679931276361458e-05f, 2.5723158614709973e-05f, 4.2605053749866784e-05f, 2.686924926820211e-05f, 1.941436312336009e-05f, 3.25934961438179e-05f, 3.8189507904462516e-05f, 3.7753507058368996e-05f, 1.575467649672646e-05f, 2.350844988541212e-05f, 1.3295085409481544e-05f, 1.4642214409832377e-05f, 1.925712604133878e-05f, 2.0635545297409408e-05f, 3.113181082881056e-05f, 1.803520899557043e-05f, 2.0295374270062894e-05f, 2.2951408027438447e-05f, 1.9356499251443893e-05f, 2.300859341630712e-05f, 2.0849840439041145e-05f, 1.3227511772129219e-05f, 2.0164112356724218e-05f, 2.2428157535614446e-05f, 1.431921191397123e-05f, 2.083459730783943e-05f, 3.152812860207632e-05f, 2.984480670420453e-05f, 1.7618074707570486e-05f, 1.5568608432658948e-05f, 2.759868402790744e-05f, 1.7771664715837687e-05f, 3.616614776547067e-05f, 2.5320478016510606e-05f, 1.5553036064375192e-05f, 2.253285128972493e-05f, 2.0585677702911198e-05f, 2.1516239939955994e-05f, 3.2869542337721214e-05f, 1.8338236259296536e-05f, 1.9322549633216113e-05f, 1.689586315478664e-05f, 1.6181049431907013e-05f, 1.55919769895263e-05f, 1.654549123486504e-05f, 2.590026633697562e-05f, 1.3239653526397888e-05f, 1.7387597836204804e-05f, 1.4097518942435272e-05f, 1.1663182704069186e-05f, 1.4736924640601501e-05f, 1.3730217688134871e-05f, 4.1369123209733516e-05f, 2.0466599380597472e-05f, 1.6732392396079376e-05f, 2.2057358364691027e-05f, 2.520980706322007e-05f, 2.101274731103331e-05f, 1.634959517105017e-05f, 2.8092277716496028e-05f, 1.997184517676942e-05f, 2.1984975319355726e-05f, 1.859395888459403e-05f, 2.462633710820228e-05f, 1.5135349713091273e-05f, 1.5312962204916403e-05f, 2.0632876839954406e-05f, 1.3077387848170474e-05f, 2.04775406018598e-05f, 1.90205973922275e-05f, 2.2172293029143475e-05f, 1.3736805158259813e-05f, 1.823545062507037e-05f, 1.5952735338942148e-05f, 3.079434827668592e-05f, 2.0227465938660316e-05f, 1.850007538450882e-05f, 1.574046655150596e-05f, 2.7593312552198768e-05f, 1.9645094653242268e-05f, 3.0408811653614976e-05f, 3.090932659688406e-05f, 2.4800507162581198e-05f, 1.5945099221426062e-05f, 2.476258305250667e-05f, 1.6210911780945025e-05f, 1.3507968105841428e-05f, 1.3385219972406048e-05f, 1.4166492292133626e-05f, 1.8678623746382073e-05f, 2.01712337002391e-05f, 1.3601649698102847e-05f, 1.3977019989397377e-05f, 2.017603583226446e-05f, 3.126620140392333e-05f, 2.0615891116904095e-05f, 2.2824815459898673e-05f, 1.3254681107355282e-05f, 1.2481205885706004e-05f, 1.71925566974096e-05f, 1.1783657100750133e-05f, 1.7848253264673986e-05f, 2.3922113541630097e-05f, 1.5968547813827172e-05f, 2.873790253943298e-05f, 1.2688242350122891e-05f, 1.7869779185275547e-05f, 2.5885106879286468e-05f, 2.3897513528936543e-05f, 1.7895197743200697e-05f, 1.5161615010583773e-05f, 1.4736553566763178e-05f, 1.1433869076427072e-05f, 1.792108560039196e-05f, 1.811349648050964e-05f, 1.9699275071616285e-05f, 1.6826017599669285e-05f, 1.9207871446269564e-05f, 3.41794548148755e-05f, 2.1120960809639655e-05f, 2.946114182122983e-05f, 2.0903182303300127e-05f, 2.116463474521879e-05f, 2.0696314095403068e-05f, 1.8055357941193506e-05f, 2.0702205802081153e-05f, 1.9028899259865284e-05f, 1.3998192116559949e-05f, 1.8736855054157786e-05f, 1.9163035176461563e-05f, 3.1711795600131154e-05f, 1.3668609426531475e-05f, 2.204666452598758e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003189875860698521f, 0.0008743320358917117f, 0.0006632100557908416f, 0.0005525571177713573f, 0.0005576153635047376f, 0.0004519079811871052f, 0.0005770335556007922f, 0.00039099695277400315f, 0.000859093212056905f, 0.0006584679940715432f, 0.0006589292897842824f, 0.0004042449581902474f, 0.00043154796003364027f, 0.0004152598849032074f, 0.0005478960229083896f, 0.0004257639229763299f, 0.0005799818900413811f, 0.0011420731898397207f, 0.000562642642762512f, 0.0004477744223549962f, 0.00037681328831240535f, 0.0008272088598459959f, 0.0006116274162195623f, 0.0004787106881849468f, 0.0006070111412554979f, 0.0011379695497453213f, 0.00046048464719206095f, 0.00033999982406385243f, 0.0006989500252529979f, 0.00037025148048996925f, 0.0007389372331090271f, 0.0005685570067726076f, 0.0005021714023314416f, 0.00041315454291179776f, 0.00044215889647603035f, 0.0006364909349940717f, 0.0007629459723830223f, 0.0007121905218809843f, 0.0007538858917541802f, 0.00040256622014567256f, 0.0006236911867745221f, 0.00041636292007751763f, 0.000422043667640537f, 0.0005367746343836188f, 0.000478409870993346f, 0.000391761859646067f, 0.0005210884264670312f, 0.0004090794827789068f, 0.00044262668234296143f, 0.000575162994209677f, 0.0004860245098825544f, 0.0007157702348195016f, 0.0005658558220602572f, 0.0008502055425196886f, 0.001056450535543263f, 0.00048573847743682563f, 0.00043829454807564616f, 0.0005899511161260307f, 0.0006306920549832284f, 0.0006295603234320879f, 0.0004241120186634362f, 0.0006081439787521958f, 0.000716226757504046f, 0.0004527551354840398f, 0.0004452808352652937f, 0.0004994198097847402f, 0.00046618026681244373f, 0.00038012961158528924f, 0.00041363792843185365f, 0.0003573738213162869f, 0.0005323613295331597f, 0.000695755472406745f, 0.0003592485736589879f, 0.0012703886022791266f, 0.0004795116255991161f, 0.0004447782121133059f, 0.000480096583487466f, 0.0004437320458237082f, 0.00044439322664402425f, 0.0004160488024353981f, 0.000423807417973876f, 0.0004293844976928085f, 0.00036986052873544395f, 0.000515154330059886f, 0.0005505483713932335f, 0.0004284465976525098f, 0.00036310681025497615f, 0.0007544922409579158f, 0.0010268919868394732f, 0.0005220431485213339f, 0.00045341209624893963f, 0.0008441457757726312f, 0.0005549684283323586f, 0.0006022853194735944f, 0.0004143109836149961f, 0.000452466745628044f, 0.0004960822407156229f, 0.0005539811681956053f, 0.0007157824002206326f, 0.0005807906272821128f, 0.00047489229473285377f, 0.0004854972066823393f, 0.0007471663411706686f, 0.0007926396210677922f, 0.0004092058807145804f, 0.00046489405212923884f, 0.00044546753633767366f, 0.00047573368647135794f, 0.0006806665915064514f, 0.000537175452336669f, 0.00048233530833385885f, 0.00039173453114926815f, 0.0005738507024943829f, 0.0008644491899758577f, 0.0004136944771744311f, 0.0008443609112873673f, 0.0004256292013451457f, 0.0006041859742254019f, 0.0003348934988025576f, 0.000579782179556787f, 0.00046213887981139123f, 0.0005579765420407057f, 0.000657747033983469f, 0.0007412850391119719f, 0.0007115179323591292f, 0.0011784812668338418f, 0.00074321951251477f, 0.0005370128783397377f, 0.0009015556424856186f, 0.0010563445976004004f, 0.0010442845523357391f, 0.00043578376062214375f, 0.0006502578034996986f, 0.000367750006262213f, 0.00040501239709556103f, 0.0005326636019162834f, 0.0005707915406674147f, 0.0008611244847998023f, 0.0004988646833226085f, 0.0005613822140730917f, 0.0006348496535792947f, 0.0005354123422876f, 0.0006364314467646182f, 0.0005767190596088767f, 0.00036588090006262064f, 0.0005577513948082924f, 0.0006203762604855001f, 0.00039607795770280063f, 0.0005762974033132195f, 0.0008720868499949574f, 0.0008255252032540739f, 0.00048732649884186685f, 0.00043063703924417496f, 0.0007633960922248662f, 0.0004915748722851276f, 0.0010003772331401706f, 0.0007003795471973717f, 0.00043020627344958484f, 0.000623272149823606f, 0.0005694121355190873f, 0.0005951520870439708f, 0.0009091912070289254f, 0.0005072465864941478f, 0.0005344732780940831f, 0.00046734968782402575f, 0.00044757750583812594f, 0.00043128340621478856f, 0.00045765817048959434f, 0.0007164168637245893f, 0.0003662167291622609f, 0.00048095136298798025f, 0.0003899458097293973f, 0.00032261060550808907f, 0.00040763214929029346f, 0.0003797860408667475f, 0.0011442947434261441f, 0.0005661183968186378f, 0.0004628280003089458f, 0.0006101197213865817f, 0.0006973183481022716f, 0.0005812251474708319f, 0.00045223956112749875f, 0.0007770492229610682f, 0.0005524331936612725f, 0.0006081175524741411f, 0.0005143200396560133f, 0.0006811792263761163f, 0.0004186528385616839f, 0.0004235657106619328f, 0.0005707177333533764f, 0.0003617283655330539f, 0.000566421018447727f, 0.0005261211190372705f, 0.0006132989074103534f, 0.0003799682599492371f, 0.0005044034915044904f, 0.0004412622074596584f, 0.0008517901296727359f, 0.0005595037946477532f, 0.0005117231630720198f, 0.000435390742495656f, 0.000763247546274215f, 0.0005433950573205948f, 0.0008411259041167796f, 0.000854970421642065f, 0.0006859968416392803f, 0.0004410509718582034f, 0.0006849478813819587f, 0.0004484035016503185f, 0.0003736384678632021f, 0.0003702431858982891f, 0.00039185365312732756f, 0.0005166619084775448f, 0.0005579483695328236f, 0.00037622975651174784f, 0.0003866127226501703f, 0.0005580811994150281f, 0.00086484185885638f, 0.0005702478811144829f, 0.0006313480553217232f, 0.0003666324191726744f, 0.00034523761132732034f, 0.0004755563859362155f, 0.0003259429940953851f, 0.0004936933401040733f, 0.0006616999744437635f, 0.00044169960892759264f, 0.0007949075661599636f, 0.00035096437204629183f, 0.0004942888044752181f, 0.0007159975357353687f, 0.0006610195268876851f, 0.0004949918948113918f, 0.0004193793283775449f, 0.00040762187563814223f, 0.0003162676584906876f, 0.0004957079654559493f, 0.0005010301247239113f, 0.0005448937299661338f, 0.00046541771735064685f, 0.0005313011934049428f, 0.0009454241953790188f, 0.000584218418225646f, 0.0008149127825163305f, 0.0005781945073977113f, 0.0005854264600202441f, 0.0005724724032916129f, 0.0004994220216758549f, 0.0005726353847421706f, 0.0005263507482595742f, 0.0003871983790304512f, 0.0005182726308703423f, 0.0005300610209815204f, 0.0008771672728471458f, 0.00037808192428201437f, 0.0006098239100538194f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.1324258341337554e-05f, 8.422740938840434e-05f, 6.20625214651227e-05f, 6.961224426049739e-05f, 5.784929817309603e-05f, 5.5485426855739206e-05f, 4.7944660764187574e-05f, 3.4837383282138035e-05f, 4.1901170334313065e-05f, 3.48891771864146e-05f, 3.82231519324705e-05f, 2.9270200684550218e-05f, 4.843578062718734e-05f, 7.997938519110903e-05f, 4.005544542451389e-05f, 4.991875903215259e-05f, 4.2270847188774496e-05f, 4.451891436474398e-05f, 3.562587880878709e-05f, 5.2205577958375216e-05f, 3.8560112443519756e-05f, 3.4229084121761844e-05f, 2.819284054567106e-05f, 3.447416384005919e-05f, 5.2056009735679254e-05f, 0.00010177984222536907f, 3.681756425066851e-05f, 2.8745400413754396e-05f, 3.3431631891289726e-05f, 5.276185038383119e-05f, 3.107462907792069e-05f, 3.930473030777648e-05f, 4.632096170098521e-05f, 4.1641334973974153e-05f, 3.874122921843082e-05f, 3.756424121093005e-05f, 5.0643015129026026e-05f, 3.0105797122814693e-05f, 5.127275289851241e-05f, 3.2824184017954394e-05f, 5.9271653299219906e-05f, 3.6783021641895175e-05f, 7.738172280369326e-05f, 5.7736662711249664e-05f, 8.77296770340763e-05f, 3.8266312913037837e-05f, 3.762197229661979e-05f, 3.375171581865288e-05f, 3.445721449679695e-05f, 2.5084344088099897e-05f, 4.588376759784296e-05f, 6.108223897172138e-05f, 5.770602365373634e-05f, 4.240210910211317e-05f, 4.266039468348026e-05f, 3.449734504101798e-05f, 4.015347076347098e-05f, 6.004300666972995e-05f, 3.203776213922538e-05f, 4.930506111122668e-05f, 3.92335387005005e-05f, 3.766885129152797e-05f, 7.046539394650608e-05f, 4.874400474363938e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008901900728233159f, 0.003516108263283968f, 0.002590826014056802f, 0.002905992092564702f, 0.0024149431847035885f, 0.0023162623401731253f, 0.0020014699548482895f, 0.001454301062040031f, 0.0017491818871349096f, 0.0014564632438123226f, 0.0015956414863467216f, 0.0012218967312946916f, 0.002021971857175231f, 0.003338772803544998f, 0.0016721312422305346f, 0.002083879429847002f, 0.0017646141350269318f, 0.0018584607169032097f, 0.0014872172614559531f, 0.002179343719035387f, 0.0016097079496830702f, 0.0014289073878899217f, 0.00117692188359797f, 0.0014391383156180382f, 0.0021730998996645212f, 0.004248842131346464f, 0.0015369645552709699f, 0.0011999887647107244f, 0.001395617495290935f, 0.002202565548941493f, 0.0012972233816981316f, 0.0016407923540100455f, 0.0019336879486218095f, 0.001738334889523685f, 0.0016172687755897641f, 0.0015681349905207753f, 0.002114113885909319f, 0.0012567790690809488f, 0.0021404025610536337f, 0.001370259327813983f, 0.002474319888278842f, 0.0015355226350948215f, 0.0032303323969244957f, 0.0024102411698549986f, 0.0036623121704906225f, 0.0015974432462826371f, 0.0015705450205132365f, 0.001408979413099587f, 0.001438430743291974f, 0.0010471564019098878f, 0.0019154370529577136f, 0.002549903467297554f, 0.0024089619982987642f, 0.0017700936878100038f, 0.0017808760749176145f, 0.0014401060761883855f, 0.0016762233572080731f, 0.002506520366296172f, 0.0013374297413975f, 0.002058260375633836f, 0.0016378205036744475f, 0.0015725019620731473f, 0.00294160726480186f, 0.0020348387770354748f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.65601614350453e-05f, 0.00010271931387251243f, 4.373842602944933e-05f, 5.6175249483203515e-05f, 0.0001097403364838101f, 6.064493572921492e-05f, 0.00011247475049458444f, 6.426186882890761e-05f, 0.00018053714302368462f, 0.00014382759400177747f, 0.00013993715401738882f, 8.319262269651517e-05f, 0.0001538605138193816f, 8.899514068616554e-05f, 7.80261616455391e-05f, 0.00013781119196210057f, 8.42185690999031e-05f, 0.00018481512961443514f, 4.2027844756376e-05f, 9.413914813194424e-05f, 6.465557089541107e-05f, 0.00010013060091296211f, 5.5538141168653965e-05f, 8.207593054976314e-05f, 7.986090349731967e-05f, 8.152634836733341e-05f, 0.00014939204265829176f, 5.892041735933162e-05f, 7.596714567625895e-05f, 0.00012573810818139464f, 9.212247096002102e-05f, 0.0001650985359447077f, 9.01684834389016e-05f, 9.921277523972094e-05f, 0.00016980829241219908f, 8.225143392337486e-05f, 3.735496284207329e-05f, 3.850192661047913e-05f, 0.00023177395632956177f, 9.387778118252754e-05f, 8.644358604215086e-05f, 0.0001274778915103525f, 0.0001288422499783337f, 5.2531326218741015e-05f, 0.00016722609871067107f, 5.387976852944121e-05f, 0.00010378822480561212f, 0.00010399754683021456f, 0.0001013774672173895f, 9.809103357838467e-05f, 7.7869750384707e-05f, 6.007633055560291e-05f, 8.250358223449439e-05f, 0.0001423911307938397f, 0.0001208333414979279f, 6.479411968030035e-05f, 5.8464462199481204e-05f, 0.00026360322954133153f, 6.335903162835166e-05f, 0.00011641270975815132f, 5.160607543075457e-05f, 0.00017985534213948995f, 8.626938506495208e-05f, 6.528731319122016e-05f, 9.701755334390327e-05f, 0.00015249040734488517f, 0.0001342157192993909f, 8.246360084740445e-05f, 4.1753777622943744e-05f, 8.461157267447561e-05f, 0.0001608250313438475f, 0.0001858804898802191f, 0.00013626492000184953f, 3.472947719274089e-05f, 9.020229481393471e-05f, 7.746821211185306e-05f, 5.6767014029901475e-05f, 0.00010612406185828149f, 4.0909555536927655e-05f, 4.6514942368958145e-05f, 9.56034564296715e-05f, 5.204834451433271e-05f, 7.53416825318709e-05f, 0.00010555682820267975f, 7.664205622859299e-05f, 0.0001277787669096142f, 8.927117596613243e-05f, 0.0001082526141544804f, 0.00015225110109895468f, 0.0001041465366142802f, 0.00010345344344386831f, 0.00010212465713266283f, 6.662542000412941e-05f, 7.279963756445795e-05f, 7.275454845512286e-05f, 5.471284021041356e-05f, 0.00011380267096683383f, 2.6467463612789288e-05f, 5.3996569477021694e-05f, 9.118831076193601e-05f, 0.00010005095828091726f, 7.59927206672728e-05f, 4.4300973968347535e-05f, 8.537601388525218e-05f, 0.00011862135579576716f, 0.00012805243022739887f, 9.655994654167444e-05f, 7.747524068690836e-05f, 0.00010969757568091154f, 9.617891919333488e-05f, 0.0006400893907994032f, 0.0001335253327852115f, 7.877720054239035e-05f, 8.830497972667217e-05f, 0.00014666991773992777f, 6.667098205070943e-05f, 9.538794256513938e-05f, 0.00023025016707833856f, 7.947700214572251e-05f, 3.7620073271682486e-05f, 0.00012278754729777575f, 3.983661372330971e-05f, 0.00011166689364472404f, 6.581169145647436e-05f, 2.3785058147041127e-05f, 8.347920083906502e-05f, 5.9552508901106194e-05f, 0.00010067714902106673f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004856553394347429f, 0.0057631805539131165f, 0.0024539928417652845f, 0.0031517744064331055f, 0.0061571029946208f, 0.003402551170438528f, 0.006310520227998495f, 0.0036054833326488733f, 0.010129235684871674f, 0.008069606497883797f, 0.007851328700780869f, 0.004667614120990038f, 0.008632514625787735f, 0.004993170965462923f, 0.004377744160592556f, 0.007732049096375704f, 0.0047251759096980095f, 0.01036925707012415f, 0.0023580186534672976f, 0.00528178084641695f, 0.0036275722086429596f, 0.005617938004434109f, 0.0031160288490355015f, 0.0046049607917666435f, 0.0044806841760873795f, 0.004574126098304987f, 0.008381805382668972f, 0.0033057951368391514f, 0.0042622205801308155f, 0.0070546758361160755f, 0.005168633069843054f, 0.009263035841286182f, 0.005059002432972193f, 0.005566442385315895f, 0.009527281858026981f, 0.004614807665348053f, 0.002095841569826007f, 0.0021601931657642126f, 0.013003934174776077f, 0.005267116706818342f, 0.004850013181567192f, 0.007152288220822811f, 0.0072288368828594685f, 0.002947328146547079f, 0.009382405318319798f, 0.003022983903065324f, 0.00582315307110548f, 0.005834897514432669f, 0.005687894765287638f, 0.005503505934029818f, 0.004368968307971954f, 0.0033706489484757185f, 0.004628954920917749f, 0.007989011704921722f, 0.006779488176107407f, 0.0036353457253426313f, 0.0032802133355289698f, 0.014789750799536705f, 0.003554828464984894f, 0.00653146393597126f, 0.0028954159934073687f, 0.010090982541441917f, 0.00484023941680789f, 0.003663016948848963f, 0.005443277303129435f, 0.008555643260478973f, 0.00753032136708498f, 0.004626711364835501f, 0.002342641819268465f, 0.0047472259029746056f, 0.009023265913128853f, 0.010429030284285545f, 0.0076452940702438354f, 0.0019485356751829386f, 0.0050608995370566845f, 0.004346439614892006f, 0.0031849760562181473f, 0.005954207852482796f, 0.00229527591727674f, 0.0026097723748534918f, 0.005363937467336655f, 0.00292022991925478f, 0.004227128345519304f, 0.005922382697463036f, 0.004300087224692106f, 0.007169168908149004f, 0.005008657928556204f, 0.0060736327432096004f, 0.008542216382920742f, 0.00584325660020113f, 0.005804369691759348f, 0.0057298168540000916f, 0.0037380929570645094f, 0.004084504209458828f, 0.004081974271684885f, 0.0030697244219481945f, 0.0063850246369838715f, 0.0014849862782284617f, 0.0030295371543616056f, 0.0051162210293114185f, 0.005613469518721104f, 0.004263655748218298f, 0.0024855551309883595f, 0.004790115635842085f, 0.0066553824581205845f, 0.007184523157775402f, 0.005417602602392435f, 0.004346834030002356f, 0.0061547039076685905f, 0.005396224558353424f, 0.03591292351484299f, 0.00749158626422286f, 0.004419881850481033f, 0.004954448435455561f, 0.00822907779365778f, 0.0037406492047011852f, 0.005351846106350422f, 0.012918440625071526f, 0.00445914501324296f, 0.0021107157226651907f, 0.006889130920171738f, 0.0022350773215293884f, 0.006265194620937109f, 0.003692437894642353f, 0.0013344869948923588f, 0.004683692939579487f, 0.0033412594348192215f, 0.005648602731525898f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.870801346143708e-05f, 7.126497803255916e-05f, 8.145403990056366e-05f, 0.00011754592560464516f, 0.00012235456961207092f, 8.878539665602148e-05f, 5.1236456783954054e-05f, 0.00014891019964125007f, 4.4010939745930955e-05f, 0.00012422683357726783f, 0.00014333798026200384f, 0.00011129589984193444f, 7.342130993492901e-05f, 0.00014795263996347785f, 0.00010849517275346443f, 0.00011724236537702382f, 0.00012622182839550078f, 8.545405580662191e-05f, 0.00011080878175562248f, 6.849046621937305e-05f, 6.523497722810134e-05f, 0.00010720355930970982f, 9.991259139496833e-05f, 7.636673399247229e-05f, 0.00014143894077278674f, 0.00011768651165766641f, 0.00010267180186929181f, 0.00010772897076094523f, 9.679296636022627e-05f, 0.00011853074101964012f, 8.847937715472654e-05f, 0.00010332398960599676f, 0.00012304367555771023f, 0.00010759970609797165f, 6.016350380377844e-05f, 8.250991959357634e-05f, 0.00011365785030648112f, 0.00011375686881365255f, 0.00011339517368469387f, 9.092828258872032e-05f, 9.656888869358227e-05f, 8.462797268293798e-05f, 0.0001043266529450193f, 8.040247485041618e-05f, 7.290882058441639e-05f, 6.353326898533851e-05f, 5.528232213691808e-05f, 0.00012102122127544135f, 0.00010821015894180164f, 0.00014051089237909764f, 9.149580000666901e-05f, 9.144415525952354e-05f, 7.176025246735662e-05f, 0.00010695508535718545f, 7.964639371493831e-05f, 0.00010534279863350093f, 9.076517744688317e-05f, 7.691710925428197e-05f, 9.688865975476801e-05f, 0.00010343502799514681f, 7.948347047204152e-05f, 0.00014295017172116786f, 9.111646068049595e-05f, 0.00011656997230602428f, 9.134541323874146e-05f, 0.00010757017298601568f, 4.5838569349143654e-05f, 0.0001214002986671403f, 6.849657802376896e-05f, 9.83347708825022e-05f, 9.470262739341706e-05f, 6.339037645375356e-05f, 0.00010630164615577087f, 0.00011947122402489185f, 7.63193384045735e-05f, 9.760980901774019e-05f, 0.00013846364163327962f, 9.64856953942217e-05f, 8.67836206452921e-05f, 0.00011379327770555392f, 9.074174158740789e-05f, 0.00012159523612353951f, 9.340000542579219e-05f, 7.598670345032588e-05f, 6.342324195429683e-05f, 9.168469114229083e-05f, 7.475372694898397e-05f, 8.908442396204919e-05f, 0.00011637392890406772f, 4.910847928840667e-05f, 5.808322021039203e-05f, 8.722233906155452e-05f, 0.00013892364222556353f, 8.273627463495359e-05f, 0.00011331774294376373f, 8.312785939779133e-05f, 0.00010041335190180689f, 0.00014595196989830583f, 9.26485809031874e-05f, 0.00010239033144898713f, 8.462515688734129e-05f, 0.00013928602857049555f, 0.00011863234249176458f, 0.00011156780237797648f, 0.00012223946396261454f, 0.00012004715244984254f, 0.00011524719593580812f, 0.0001051432263921015f, 9.076190326595679e-05f, 5.8088877267437056e-05f, 7.111650484148413e-05f, 9.756060899235308e-05f, 0.00010805157944560051f, 9.364031575387344e-05f, 9.85182196018286e-05f, 0.00015471901861019433f, 8.918422099668533e-05f, 7.044879748718813e-05f, 0.00010976979683618993f, 6.949300586711615e-05f, 0.00017093910719268024f, 0.00010566171840764582f, 7.419291796395555e-05f, 8.394025644520298e-05f, 0.00010902911162702367f, 9.16432763915509e-05f, 6.0253172705415636e-05f, 8.143779268721119e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008934380603022873f, 0.0008089499897323549f, 0.000924609019421041f, 0.0013342987513169646f, 0.0013888831017538905f, 0.0010078294435516f, 0.0005816002376377583f, 0.001690323930233717f, 0.0004995812778361142f, 0.001410135650075972f, 0.0016270719934254885f, 0.0012633528094738722f, 0.0008334271260537207f, 0.0016794544644653797f, 0.0012315609492361546f, 0.0013308529742062092f, 0.0014327814569696784f, 0.0009700144291855395f, 0.0012578234309330583f, 0.000777455628849566f, 0.0007405016222037375f, 0.0012168994871899486f, 0.001134137506596744f, 0.0008668614900670946f, 0.0016055154846981168f, 0.0013358945725485682f, 0.0011654581176117063f, 0.0012228635605424643f, 0.001098725711926818f, 0.0013454776490107179f, 0.001004355726763606f, 0.0011728613171726465f, 0.0013967053964734077f, 0.0012213962618261576f, 0.0006829338381066918f, 0.000936594617087394f, 0.001290164072997868f, 0.0012912880629301071f, 0.0012871823273599148f, 0.0010321539593860507f, 0.0010961821535602212f, 0.0009606372914277017f, 0.0011842428939417005f, 0.0009126723743975163f, 0.000827609736006707f, 0.0007211850606836379f, 0.000627526082098484f, 0.001373747829347849f, 0.0012283256510272622f, 0.0015949809458106756f, 0.0010385960340499878f, 0.0010380097664892673f, 0.0008145719766616821f, 0.0012140789767727256f, 0.0009040898876264691f, 0.001195777440443635f, 0.0010303024901077151f, 0.0008731089765205979f, 0.001099811983294785f, 0.0011741217458620667f, 0.0009022405138239264f, 0.0016226698644459248f, 0.0010342900641262531f, 0.0013232204364612699f, 0.0010368889197707176f, 0.001221060985699296f, 0.0005203272448852658f, 0.0013780508888885379f, 0.0007775250123813748f, 0.0011162272421643138f, 0.0010749977082014084f, 0.0007195629877969623f, 0.0012066615745425224f, 0.001356153399683535f, 0.0008663234766572714f, 0.0011079979594796896f, 0.001571742002852261f, 0.001095237792469561f, 0.000985106686130166f, 0.0012917013373225927f, 0.0010300364810973406f, 0.0013802637113258243f, 0.0010602112160995603f, 0.0008625476621091366f, 0.0007199360406957567f, 0.0010407401714473963f, 0.0008485517464578152f, 0.001011223765090108f, 0.0013209950411692262f, 0.000557444931473583f, 0.0006593199213966727f, 0.0009900867007672787f, 0.0015769635792821646f, 0.0009391640196554363f, 0.0012863033916801214f, 0.0009436090476810932f, 0.0011398218339309096f, 0.001656744279898703f, 0.0010516815818846226f, 0.001162263099104166f, 0.0009606053354218602f, 0.0015810771146789193f, 0.0013466309756040573f, 0.0012664393289014697f, 0.0013875765725970268f, 0.0013626909349113703f, 0.0013082051882520318f, 0.0011935119982808828f, 0.0010302653536200523f, 0.0006593841244466603f, 0.0008072645869106054f, 0.0011074395151808858f, 0.0012265256373211741f, 0.001062939059920609f, 0.0011183095630258322f, 0.0017562615685164928f, 0.0010123566025868058f, 0.000799685250967741f, 0.0012460296275094151f, 0.000788835808634758f, 0.0019403805490583181f, 0.0011993976077064872f, 0.0008421858656220138f, 0.000952830770984292f, 0.0012376218801364303f, 0.0010402700863778591f, 0.0006839516572654247f, 0.0009244246175512671f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.228028648067266e-05f, 0.00012756288924720138f, 0.00012385312584228814f, 0.00011539564002305269f, 0.0001015536836348474f, 0.00011180581350345165f, 0.00012447549670469016f, 5.548876288230531e-05f, 7.880258635850623e-05f, 0.00010383882909081876f, 0.00011564293527044356f, 0.00013035268057137728f, 0.00012449956557247788f, 0.00011548402108019218f, 7.837548037059605e-05f, 0.0001289296633331105f, 0.0001355924759991467f, 4.608352173818275e-05f, 0.00011989171616733074f, 0.00011789612472057343f, 7.103816460585222e-05f, 8.91720992513001e-05f, 8.036274084588513e-05f, 8.787739352555946e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003279930679127574f, 0.004533985164016485f, 0.004402128513902426f, 0.004101522732526064f, 0.0036095362156629562f, 0.003973929211497307f, 0.004424249287694693f, 0.0019722445867955685f, 0.0028008909430354834f, 0.003690757555887103f, 0.004110312554985285f, 0.004633143078535795f, 0.004425104707479477f, 0.004104664083570242f, 0.002785710385069251f, 0.0045825643464922905f, 0.004819381516426802f, 0.0016379528678953648f, 0.004261327441781759f, 0.004190397914499044f, 0.0025249191094189882f, 0.0031694560311734676f, 0.002856343751773238f, 0.003123437985777855f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.348200597334653e-05f, 0.00017249763186555356f, 0.00016221807163674384f, 7.927925616968423e-05f, 0.00013267216854728758f, 0.00013178570952732116f, 0.00011860844097100198f, 0.0002284920192323625f, 7.880471821408719e-05f, 5.8468900533625856e-05f, 0.0001334121188847348f, 0.0002355180768063292f, 0.00011839390208479017f, 9.10123999346979e-05f, 0.0001597717491677031f, 0.00012193137808935717f, 0.00014839513460174203f, 9.999650501413271e-05f, 0.00010236409434583038f, 0.00010988291614921764f, 8.069249452091753e-05f, 7.747257041046396e-05f, 9.065578342415392e-05f, 0.00019746260659303516f, 0.00011586427717702463f, 0.00013065265375189483f, 0.00013590518210548908f, 0.00010888437100220472f, 0.00011676605936372653f, 8.547437755623832e-05f, 0.00012213234731461853f, 9.05077249626629e-05f, 0.00010399013262940571f, 0.00022471310512628406f, 0.00012940332817379385f, 9.790378680918366e-05f, 6.607639807043597e-05f, 0.00010338668653275818f, 0.00016058085020631552f, 6.196436152094975e-05f, 9.529267117613927e-05f, 8.577538392273709e-05f, 0.00013063974620308727f, 0.00013176581705920398f, 0.00020286192011553794f, 0.00012609377154149115f, 0.00013202345871832222f, 7.687250763410702e-05f, 0.00012506914208643138f, 0.0001658550463616848f, 7.896033639553934e-05f, 0.00011734879808500409f, 9.084479825105518e-05f, 0.0001739870640449226f, 7.116398046491668e-05f, 0.00014005103730596602f, 8.323275687871501e-05f, 0.00010115735494764522f, 0.00010830628889380023f, 0.00013932425645180047f, 0.0001437582541257143f, 9.000589489005506e-05f, 9.818152466323227e-05f, 0.00014413851022254676f, 0.00015294076001737267f, 0.00019848892407026142f, 0.00013272833894006908f, 0.00023567650350742042f, 9.016973490361124e-05f, 9.571781265549362e-05f, 0.00011773544974857941f, 0.00014170528447721153f, 0.00012062540918122977f, 8.427789725828916e-05f, 0.00014289531100075692f, 7.279388955794275e-05f, 0.00017417551134712994f, 0.00027359899831935763f, 9.715936903376132e-05f, 0.00013779434084426612f, 0.000222949922317639f, 0.00010227398888673633f, 0.00014979402476456016f, 0.00014929160533938557f, 0.00019018742023035884f, 8.837990753818303e-05f, 0.00017012818716466427f, 8.745207014726475e-05f, 0.00025590992299839854f, 0.00012740572856273502f, 0.0001480792270740494f, 0.0001064445823431015f, 0.00016576479538343847f, 8.059207902988419e-05f, 0.00017226366617251188f, 8.630837692180648e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0040420773439109325f, 0.00948870088905096f, 0.008923245593905449f, 0.004360971041023731f, 0.007297993171960115f, 0.007249230984598398f, 0.00652437936514616f, 0.012568823993206024f, 0.004334867466241121f, 0.0032162407878786325f, 0.00733869569376111f, 0.012955311685800552f, 0.00651257811114192f, 0.00500638410449028f, 0.008788678795099258f, 0.006707166787236929f, 0.008162877522408962f, 0.0055005792528390884f, 0.00563081493601203f, 0.006044408306479454f, 0.004438709933310747f, 0.004261589143425226f, 0.004986767657101154f, 0.010861966758966446f, 0.0063734292052686214f, 0.0071869040839374065f, 0.007475833874195814f, 0.005989480763673782f, 0.006423034239560366f, 0.004701750352978706f, 0.006718221586197615f, 0.004978623241186142f, 0.0057202596217393875f, 0.012360954657196999f, 0.007118181325495243f, 0.0053854635916650295f, 0.003634711727499962f, 0.005687065422534943f, 0.008833185769617558f, 0.0034085179213434458f, 0.005241832230240107f, 0.004718307871371508f, 0.0071861944161355495f, 0.007248136680573225f, 0.01115897111594677f, 0.006936130113899708f, 0.007262309081852436f, 0.004228581208735704f, 0.006879767868667841f, 0.009123307652771473f, 0.0043434277176856995f, 0.006455089431256056f, 0.0049971649423241615f, 0.009570631198585033f, 0.003914568107575178f, 0.007703887764364481f, 0.004578443709760904f, 0.005564434919506311f, 0.0059576816856861115f, 0.007663908880203962f, 0.007907813414931297f, 0.004951018840074539f, 0.005400741472840309f, 0.007928729988634586f, 0.00841292180120945f, 0.010918422602117062f, 0.007301082834601402f, 0.01296402607113123f, 0.004960031248629093f, 0.0052652182057499886f, 0.0064763580448925495f, 0.007794884033501148f, 0.006635328289121389f, 0.004635934717953205f, 0.007860344834625721f, 0.004004225600510836f, 0.009580996818840504f, 0.015050056390464306f, 0.005344515200704336f, 0.007579752244055271f, 0.012263965792953968f, 0.005625858437269926f, 0.008239827118813992f, 0.008212190121412277f, 0.010461775586009026f, 0.004861576948314905f, 0.009358363226056099f, 0.004810538608580828f, 0.014077020809054375f, 0.007008297834545374f, 0.008145499974489212f, 0.005855273455381393f, 0.009118342772126198f, 0.004433186259120703f, 0.00947583094239235f, 0.0047476268373429775f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011146057659061626f, 6.188859697431326e-05f, 9.900757868308574e-05f, 0.00010153445327887312f, 9.923231846187264e-05f, 0.00010636002843966708f, 6.491319072665647e-05f, 7.752797682769597e-05f, 0.00011372620065230876f, 0.00011268872913205996f, 6.546040094690397e-05f, 8.792839798843488e-05f, 8.163269376382232e-05f, 8.293427526950836e-05f, 7.029270636849105e-05f, 9.924791083903983e-05f, 7.381093746516854e-05f, 9.401135321240872e-05f, 7.456136518158019e-05f, 6.214874156285077e-05f, 9.847011097008362e-05f, 0.00011854767217300832f, 8.417973731411621e-05f, 9.721027163323015e-05f, 8.680884639034048e-05f, 0.00010845994256669655f, 0.00014875558554194868f, 0.00012166378292022273f, 8.74322940944694e-05f, 7.388316589640453e-05f, 9.37715740292333e-05f, 9.869204222923145e-05f, 0.00010274401574861258f, 8.675039134686813e-05f, 0.00010426691733300686f, 9.197439067065716e-05f, 7.323321915464476e-05f, 7.217952224891633e-05f, 8.237722067860886e-05f, 7.07658618921414e-05f, 9.41209655138664e-05f, 9.429401688976213e-05f, 7.45907673262991e-05f, 6.503193435491994e-05f, 6.346125155687332e-05f, 9.816617966862395e-05f, 8.97025311132893e-05f, 9.336637594969943e-05f, 9.557281737215817e-05f, 0.0001407103700330481f, 0.00010536270565353334f, 9.617935575079173e-05f, 0.00013667433813679963f, 5.776407851953991e-05f, 6.446838960982859e-05f, 6.562692578881979e-05f, 0.00014993236982263625f, 9.325500286649913e-05f, 0.00013417680747807026f, 8.459087257506326e-05f, 6.40401485725306e-05f, 0.0001118212312576361f, 0.0001255869574379176f, 0.00010200149699812755f, 7.266861211974174e-05f, 7.651297346455976e-05f, 6.640928040724248e-05f, 8.254223939729854e-05f, 0.00010645992733770981f, 0.00010732279042713344f, 6.221429794095457e-05f, 8.533383515896276e-05f, 9.484560723649338e-05f, 0.0001205321605084464f, 5.903384953853674e-05f, 0.00011436159547884017f, 7.939279021229595e-05f, 0.00012892510858364403f, 0.00011740382615244016f, 7.927111437311396e-05f, 3.966565782320686e-05f, 7.828672823961824e-05f, 9.227071859641e-05f, 7.53193671698682e-05f, 8.819377399049699e-05f, 5.205974230193533e-05f, 8.45381073304452e-05f, 0.00010192899935645983f, 5.730517295887694e-05f, 9.706104901852086e-05f, 0.00010065628157462925f, 0.00010157385986531153f, 8.590298239141703e-05f, 9.163648792309687e-05f, 6.203086377354339e-05f, 8.501022239215672e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002427425468340516f, 0.0013478304026648402f, 0.0021562199108302593f, 0.002211251063272357f, 0.002161114476621151f, 0.0023163440637290478f, 0.0014137011021375656f, 0.0016884299693629146f, 0.002476766938343644f, 0.0024541725870221853f, 0.001425618422217667f, 0.0019149339059367776f, 0.0017778240144252777f, 0.0018061702139675617f, 0.001530857989564538f, 0.0021614539436995983f, 0.0016074791783466935f, 0.0020474104676395655f, 0.0016238222597166896f, 0.0013534959871321917f, 0.0021445148158818483f, 0.002581770531833172f, 0.0018332942854613066f, 0.002117077587172389f, 0.0018905518809333444f, 0.002362076658755541f, 0.003239648649469018f, 0.002649634378030896f, 0.0019041295163333416f, 0.0016090520657598972f, 0.0020421885419636965f, 0.002149348147213459f, 0.002237593289464712f, 0.0018892788793891668f, 0.0022707595489919186f, 0.0020030487794429064f, 0.0015948973596096039f, 0.0015719495713710785f, 0.001794038456864655f, 0.0015411624917760491f, 0.0020497976802289486f, 0.0020535665098577738f, 0.0016244625439867377f, 0.0014162871520966291f, 0.0013820802560076118f, 0.0021378956735134125f, 0.001953571569174528f, 0.002033364027738571f, 0.0020814165472984314f, 0.0030644373036921024f, 0.0022946239914745092f, 0.00209462596103549f, 0.0029765390790998936f, 0.001258005271665752f, 0.0014040139503777027f, 0.0014292449923232198f, 0.0032652770169079304f, 0.002030938398092985f, 0.0029221470467746258f, 0.0018422481371089816f, 0.0013946875697001815f, 0.0024352800101041794f, 0.0027350743766874075f, 0.00222142250277102f, 0.0015826012240722775f, 0.0016663249116390944f, 0.0014462833059951663f, 0.0017976323142647743f, 0.0023185196332633495f, 0.0023373113945126534f, 0.0013549237046390772f, 0.0018584285862743855f, 0.0020655791740864515f, 0.0026249894872307777f, 0.0012856588000431657f, 0.0024906047619879246f, 0.0017290425021201372f, 0.002807773882523179f, 0.002556859515607357f, 0.0017263926565647125f, 0.0008638518629595637f, 0.001704954425804317f, 0.0020095023792237043f, 0.0016403301851823926f, 0.0019207133445888758f, 0.0011337744072079659f, 0.001841099001467228f, 0.002219843678176403f, 0.0012480111327022314f, 0.0021138277370482683f, 0.002192125888541341f, 0.002212109277024865f, 0.0018708236748352647f, 0.001995689934119582f, 0.001350928796455264f, 0.0018513809191063046f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.088111720397137e-05f, 6.800077972002327e-05f, 8.380594226764515e-05f, 5.8020017604576424e-05f, 4.4810840336140245e-05f, 4.911336145596579e-05f, 7.739098509773612e-05f, 4.5604985643876716e-05f, 5.586295446846634e-05f, 6.134660361567512e-05f, 5.273561328067444e-05f, 6.0265560023253784e-05f, 4.510910002863966e-05f, 5.0550876039778814e-05f, 5.8891968365060166e-05f, 7.02928809914738e-05f, 5.3761385061079636e-05f, 3.8339931052178144e-05f, 6.76466734148562e-05f, 5.433876140159555e-05f, 7.061408541630954e-05f, 4.6935583668528125e-05f, 6.326249422272667e-05f, 5.0659815315157175e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002135766437277198f, 0.002854374935850501f, 0.0035178065299987793f, 0.002435426227748394f, 0.0018809628672897816f, 0.002061563776805997f, 0.003248534630984068f, 0.0019142975797876716f, 0.0023448821157217026f, 0.0025750617496669292f, 0.002213610103353858f, 0.0025296842213720083f, 0.0018934825202450156f, 0.0021219043992459774f, 0.0024720269721001387f, 0.002950587309896946f, 0.002256667474284768f, 0.0016093424055725336f, 0.002839511027559638f, 0.0022809032816439867f, 0.0029640700668096542f, 0.001970150275155902f, 0.0026554823853075504f, 0.0021264771930873394f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001657941611483693f, 0.00012553755368571728f, 0.0001456190802855417f, 0.00021193570864852518f, 0.0001010928608593531f, 0.00013545024557970464f, 0.00011967970203841105f, 0.0001799572928575799f, 0.00016630455502308905f, 9.709640289656818e-05f, 0.0002116436226060614f, 0.00016002981283236295f, 0.00018957542488351464f, 0.00011441218521213159f, 0.00012189659901196137f, 0.00011286002700217068f, 0.0002644840569701046f, 0.00021586264483630657f, 0.0001427968527423218f, 0.00013213361671660095f, 9.369798499392346e-05f, 0.00012196794705232605f, 7.781519525451586e-05f, 0.00010151736933039501f, 0.00014223743346519768f, 0.0001884572848211974f, 0.00012044124014209956f, 0.00015267552225850523f, 0.0001472228323109448f, 0.00012265700206626207f, 0.0001337770081590861f, 0.0001399751054123044f, 0.00024538638535887003f, 0.0001418151514371857f, 0.00010379233572166413f, 0.00016761469305492938f, 0.0002177225105697289f, 0.00016415768186561763f, 0.00011620245641097426f, 0.0003968040691688657f, 0.00012125197099521756f, 0.0001726230257190764f, 0.00018001698481384665f, 0.00015039548452477902f, 9.632588626118377e-05f, 0.00015069416258484125f, 8.969700138550252e-05f, 0.0001246537285624072f, 0.00014481958351098f, 0.0003104337665718049f, 9.474499529460445e-05f, 0.00011293389979982749f, 0.0002038599195657298f, 0.00017216004198417068f, 0.00014960116823203862f, 0.00012848379265051335f, 0.00012499521835707128f, 8.450477616861463e-05f, 0.00012017355038551614f, 5.2248295105528086e-05f, 0.0001828201930038631f, 0.00014172233932185918f, 8.739857730688527e-05f, 0.0001381931360810995f, 8.444667764706537e-05f, 0.00013389230298344046f, 0.00012676151527557522f, 8.869991870597005e-05f, 0.00016620074165984988f, 0.00010001112968893722f, 0.0002436630893498659f, 0.00015633665316272527f, 0.00020096743537578732f, 0.00012566972873173654f, 9.318534284830093e-05f, 0.00021895422833040357f, 0.00012769189197570086f, 0.00014205029583536088f, 0.0001809353707358241f, 0.00020797475008293986f, 0.00010020337504101917f, 0.0001565934653626755f, 0.00020021597447339445f, 0.0001332990505034104f, 9.183544898405671e-05f, 0.0002178755821660161f, 0.00012239183706697077f, 0.00011254866694798693f, 0.000143991710501723f, 0.00014874120824970305f, 9.980519098462537e-05f, 0.000140665695653297f, 0.00013098055205773562f, 0.00012455966498237103f, 0.00017390870198141783f, 0.00015735242050141096f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008528761565685272f, 0.006457886658608913f, 0.007490918040275574f, 0.010902369394898415f, 0.005200405605137348f, 0.006967814173549414f, 0.006156547460705042f, 0.009257339872419834f, 0.008555017411708832f, 0.004994820337742567f, 0.010887343436479568f, 0.008232233114540577f, 0.009752114303410053f, 0.005885576829314232f, 0.006270588841289282f, 0.0058057308197021484f, 0.013605553656816483f, 0.011104377917945385f, 0.007345737423747778f, 0.006797200534492731f, 0.004819999448955059f, 0.0062742591835558414f, 0.004002959001809359f, 0.005222243256866932f, 0.00731695955619216f, 0.009694594889879227f, 0.006195722613483667f, 0.007853914052248001f, 0.007573417387902737f, 0.0063097053207457066f, 0.006881739478558302f, 0.007200581021606922f, 0.0126231350004673f, 0.007295236457139254f, 0.005339271854609251f, 0.008622413501143456f, 0.011200052686035633f, 0.008444578386843204f, 0.005977671593427658f, 0.020412342622876167f, 0.006237428169697523f, 0.008880050852894783f, 0.009260410442948341f, 0.007736625149846077f, 0.00495518371462822f, 0.0077519891783595085f, 0.004614181350916624f, 0.006412420887500048f, 0.007449790369719267f, 0.015969293192029f, 0.004873859696090221f, 0.005809531081467867f, 0.010486935265362263f, 0.008856234140694141f, 0.00769576383754611f, 0.006609446369111538f, 0.006429987493902445f, 0.0043470836244523525f, 0.006181952077895403f, 0.002687749918550253f, 0.009404612705111504f, 0.007290462031960487f, 0.004495946224778891f, 0.007108913268893957f, 0.0043440950103104115f, 0.006887670606374741f, 0.00652084918692708f, 0.004562889691442251f, 0.008549677208065987f, 0.005144759546965361f, 0.012534485198557377f, 0.008042249828577042f, 0.010338140651583672f, 0.006464685779064894f, 0.004793628118932247f, 0.011263415217399597f, 0.00656870985403657f, 0.0073073324747383595f, 0.00930765364319086f, 0.010698609985411167f, 0.005154648795723915f, 0.008055460639297962f, 0.010299484245479107f, 0.006857152562588453f, 0.004724187310785055f, 0.011207927018404007f, 0.006296065170317888f, 0.0057897139340639114f, 0.00740720285102725f, 0.007651525549590588f, 0.00513416575267911f, 0.00723610632121563f, 0.006737884599715471f, 0.006407582201063633f, 0.008946188725531101f, 0.008094502612948418f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.32492233812809e-05f, 0.00014325404481496662f, 0.00010567255958449095f, 7.66615048632957e-05f, 8.976873505162075e-05f, 5.812325980514288e-05f, 8.695464202901348e-05f, 0.00010409613605588675f, 0.00012168147077318281f, 8.705403161002323e-05f, 0.00010369517258368433f, 9.979419701267034e-05f, 6.926024070708081e-05f, 8.544898446416482e-05f, 8.290460391435772e-05f, 7.266429020091891e-05f, 6.206089165061712e-05f, 6.140139157650992e-05f, 0.0001077330598491244f, 0.0001542286918265745f, 0.0001759152510203421f, 9.576640150044113e-05f, 0.00014247848594095558f, 8.9934968855232e-05f, 0.00011089799227192998f, 9.245164255844429e-05f, 8.729251567274332e-05f, 9.982930350815877e-05f, 8.876479842001572e-05f, 8.722516213310882e-05f, 0.00012387320748530328f, 0.00010851148545043543f, 7.456792081939057e-05f, 8.863231778377667e-05f, 9.440100257052109e-05f, 9.558565216138959e-05f, 8.35078171803616e-05f, 7.296986586879939e-05f, 8.761740900808945e-05f, 4.380744940135628e-05f, 0.00018173280113842338f, 6.334559293463826e-05f, 8.840435475576669e-05f, 9.319453965872526e-05f, 8.069764589890838e-05f, 9.272259194403887e-05f, 0.00010146768181584775f, 0.00010718037083279341f, 0.00011881252430612221f, 8.484134013997391e-05f, 0.00010253446089336649f, 0.00011187439667992294f, 6.574114377144724e-05f, 0.0001264843303943053f, 0.00011907191219506785f, 8.269526006188244e-05f, 0.00015328681911341846f, 0.00010496123286429793f, 9.189463162329048e-05f, 0.00010751792433438823f, 0.00011216201528441161f, 0.00011965232260990888f, 0.0001340350863756612f, 9.205356036545709e-05f, 0.0001027936305035837f, 9.53121343627572e-05f, 0.00010937028855551034f, 8.707211964065209e-05f, 7.308189378818497e-05f, 0.00011362913210177794f, 0.0001431775453966111f, 0.00011771904974011704f, 9.13631811272353e-05f, 9.99312978819944e-05f, 0.00010644156282069162f, 8.183989848475903e-05f, 9.568503446644172e-05f, 9.391512139700353e-05f, 6.284294795477763e-05f, 7.672692299820483e-05f, 0.00012784943100996315f, 7.713495870120823e-05f, 7.120914960978553e-05f, 9.402968134963885e-05f, 0.00011560379061847925f, 0.00012688145216088742f, 0.00012286439596209675f, 6.869172648293898e-05f, 0.00012037126725772396f, 0.0001012464490486309f, 0.00010351497621741146f, 8.383636304643005e-05f, 5.250826870906167e-05f, 0.00010381765605416149f, 7.895416638348252e-05f, 0.00010353147081332281f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013137280475348234f, 0.0043514505960047245f, 0.0032098842784762383f, 0.0023286514915525913f, 0.002726793522015214f, 0.001765538239851594f, 0.002641313476487994f, 0.003161999396979809f, 0.003696167143061757f, 0.0026443323586136103f, 0.0031498197931796312f, 0.0030313245952129364f, 0.0021038325503468513f, 0.0025955778546631336f, 0.0025182904209941626f, 0.002207233104854822f, 0.0018851468339562416f, 0.0018651139689609408f, 0.003272473579272628f, 0.004684813786298037f, 0.005343559663742781f, 0.0029089772142469883f, 0.004327892325818539f, 0.002731843153014779f, 0.0033686107490211725f, 0.0028082889039069414f, 0.0026515766512602568f, 0.003032390959560871f, 0.0026962982956320047f, 0.0026495305355638266f, 0.0037627429701387882f, 0.00329611892811954f, 0.0022650572936981916f, 0.0026922740507870913f, 0.00286750216037035f, 0.0029034868348389864f, 0.002536613494157791f, 0.0022165151312947273f, 0.0026614454109221697f, 0.0013306846376508474f, 0.005520272068679333f, 0.0019241705304011703f, 0.0026853494346141815f, 0.002830855082720518f, 0.0024512524250894785f, 0.002816519234329462f, 0.0030821580439805984f, 0.0032556853257119656f, 0.0036090207286179066f, 0.002577120205387473f, 0.0031145622488111258f, 0.0033982698805630207f, 0.001996937207877636f, 0.003842057893052697f, 0.003616899950429797f, 0.002511931350454688f, 0.004656203556805849f, 0.0031882773619145155f, 0.0027913693338632584f, 0.0032659387215971947f, 0.0034070066176354885f, 0.0036345303524285555f, 0.004071417730301619f, 0.0027961968444287777f, 0.0031224347185343504f, 0.0028951785061508417f, 0.003322205739095807f, 0.0026448818389326334f, 0.0022199181839823723f, 0.0034515713341534138f, 0.004349126946181059f, 0.003575805574655533f, 0.0027752260211855173f, 0.003035489236935973f, 0.0032332434784621f, 0.002485949080437422f, 0.0029065057169646025f, 0.0028527432586997747f, 0.0019089023116976023f, 0.002330638701096177f, 0.003883523866534233f, 0.0023430329747498035f, 0.0021630320698022842f, 0.0028562231454998255f, 0.0035115531645715237f, 0.0038541206158697605f, 0.003732099663466215f, 0.002086563501507044f, 0.00365636870265007f, 0.003075437853112817f, 0.0031443461775779724f, 0.002546593314036727f, 0.001594978617504239f, 0.0031535401940345764f, 0.0023982927668839693f, 0.0031448472291231155f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.399935667403042e-05f, 3.264780389145017e-05f, 2.3494918423239142e-05f, 3.910352825187147e-05f, 3.3482483559055254e-05f, 3.7037767469882965e-05f, 3.2548497983952984e-05f, 3.993128484580666e-05f, 3.6772264138562605e-05f, 4.808675657841377e-05f, 3.725807255250402e-05f, 4.2412713810335845e-05f, 4.6643559471704066e-05f, 4.7185589210130274e-05f, 4.498599810176529e-05f, 4.8223046178463846e-05f, 3.7318106478778645e-05f, 3.405914321774617e-05f, 3.7238773074932396e-05f, 3.0387531296582893e-05f, 4.9498339649289846e-05f, 4.2282157664885744e-05f, 3.987999662058428e-05f, 6.34225070825778e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001505567692220211f, 0.0014457179931923747f, 0.0010404076892882586f, 0.001731591997668147f, 0.0014826793922111392f, 0.001640115398913622f, 0.001441320520825684f, 0.0017682468751445413f, 0.0016283582663163543f, 0.002129389438778162f, 0.001649871002882719f, 0.0018781301332637668f, 0.002065481385216117f, 0.0020894836634397507f, 0.0019920808263123035f, 0.002135424641892314f, 0.001652529463171959f, 0.0015082152094691992f, 0.0016490163980051875f, 0.0013456280576065183f, 0.0021918974816799164f, 0.0018723488319665194f, 0.0017659757286310196f, 0.0028084907680749893f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.190242882235907e-05f, 9.617094474378973e-05f, 0.0001931570004671812f, 0.00012991570110898465f, 9.0916219050996e-05f, 0.00011899499804712832f, 0.0001503548992332071f, 0.00022225306020118296f, 0.00014718924649059772f, 0.0001594269269844517f, 7.346245547523722e-05f, 0.00017094507347792387f, 0.00010056428436655551f, 0.00018054081010632217f, 9.570836846251041e-05f, 0.00018081649614032358f, 0.00011604258179431781f, 0.00010656363156158477f, 0.00011402556992834434f, 0.00017930266039911658f, 0.00018732165335677564f, 0.00020074094936717302f, 0.00016207213047891855f, 0.00014838951756246388f, 0.00012281164526939392f, 7.800624007359147e-05f, 6.798685353714973e-05f, 0.00014528456085827202f, 0.00017232709797099233f, 0.00010395259596407413f, 0.0001547886204207316f, 0.00015460718714166433f, 0.00013490802666638047f, 0.00010842982010217384f, 8.61358639667742e-05f, 0.00010516183101572096f, 0.0001441052882000804f, 0.00021858896070625633f, 0.00020079902606084943f, 0.00014526299491990358f, 9.796473023016006e-05f, 7.752124656690285e-05f, 0.0001325455668848008f, 8.193497342290357e-05f, 0.00026188601623289287f, 0.0001948905410245061f, 0.00020574434893205762f, 9.266731649404392e-05f, 0.00014589600323233753f, 0.00019156849884893745f, 5.952361971139908e-05f, 0.00021178527094889432f, 0.00013473838043864816f, 0.00014635099796578288f, 0.00011977935355389491f, 0.00020524102728813887f, 0.0001736636768328026f, 0.00016373328980989754f, 0.00015925479237921536f, 7.397964509436861e-05f, 0.00010748802014859393f, 0.00023385586973745376f, 0.0001375990395899862f, 0.00010688894690247253f, 0.00022977375192567706f, 0.00010774222755571827f, 0.0003099048335570842f, 0.00018209392146673054f, 0.0001485075626987964f, 0.00014525720325764269f, 0.00012040139699820429f, 0.0002616058918647468f, 0.00010014956933446229f, 0.0001628613390494138f, 0.00014953261415939778f, 0.0001350740931229666f, 0.00013243072316981852f, 0.00018155678117182106f, 0.00019333719683345407f, 0.00010637422383297235f, 0.00012789672473445535f, 0.0001152490294771269f, 0.00014842671225778759f, 0.00017678244330454618f, 0.00010228789324173704f, 0.00013253904762677848f, 0.00011217784776818007f, 0.00017540545377414674f, 0.00012341797992121428f, 0.00011756307503674179f, 9.698958456283435e-05f, 0.00017274156562052667f, 0.00018178275786340237f, 6.555677100550383e-05f, 0.00013509526615962386f, 0.0001563693949719891f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003016709815710783f, 0.005589715670794249f, 0.011226807720959187f, 0.0075510526075959206f, 0.005284296814352274f, 0.00691631156951189f, 0.008739033713936806f, 0.012917949818074703f, 0.008555037900805473f, 0.00926632434129715f, 0.004269836936146021f, 0.009935790672898293f, 0.005845068488270044f, 0.010493520647287369f, 0.005562829785048962f, 0.010509544052183628f, 0.0067447093315422535f, 0.006193766836076975f, 0.006627474911510944f, 0.010421556420624256f, 0.010887641459703445f, 0.011667607352137566f, 0.009420070797204971f, 0.008624800480902195f, 0.0071381451562047005f, 0.004533933941274881f, 0.003951580263674259f, 0.008444332517683506f, 0.010016117244958878f, 0.006042006425559521f, 0.008996733464300632f, 0.008986188098788261f, 0.007841220125555992f, 0.0063022347167134285f, 0.0050064497627317905f, 0.006112290546298027f, 0.00837578997015953f, 0.012704982422292233f, 0.011670983396470547f, 0.008443078957498074f, 0.005693975370377302f, 0.00450574466958642f, 0.007703907322138548f, 0.004762282595038414f, 0.015221524983644485f, 0.011327565647661686f, 0.011958418413996696f, 0.005386075470596552f, 0.008479870855808258f, 0.011134480126202106f, 0.003459674073383212f, 0.012309533543884754f, 0.007831359282135963f, 0.00850631669163704f, 0.006961900275200605f, 0.01192916464060545f, 0.010093803517520428f, 0.009516621939837933f, 0.00925632007420063f, 0.004299897234886885f, 0.006247494835406542f, 0.01359233632683754f, 0.00799762923270464f, 0.006212675012648106f, 0.0133550725877285f, 0.006262270268052816f, 0.018012508749961853f, 0.010583791881799698f, 0.008631661534309387f, 0.008442741818726063f, 0.006998055148869753f, 0.015205242671072483f, 0.0058209639973938465f, 0.009465942159295082f, 0.008691240102052689f, 0.007850872352719307f, 0.007697232533246279f, 0.010552572086453438f, 0.011237281374633312f, 0.006182758137583733f, 0.007433704100549221f, 0.006698585581034422f, 0.008626962080597878f, 0.010275074280798435f, 0.005945249460637569f, 0.007703528273850679f, 0.006520080380141735f, 0.01019504014402628f, 0.007173387333750725f, 0.0068330843932926655f, 0.005637297406792641f, 0.010040207765996456f, 0.01056570652872324f, 0.003810337046161294f, 0.007852102629840374f, 0.009088613092899323f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011475258361315355f, 0.00015149044338613749f, 0.00010076830221805722f, 0.00011854487820528448f, 0.0001394713472109288f, 8.171726949512959e-05f, 9.799278632272035e-05f, 6.558198219863698e-05f, 4.5164320908952504e-05f, 5.444603448268026e-05f, 9.351079643238336e-05f, 9.546778164803982e-05f, 9.091423271456733e-05f, 0.00010523928358452395f, 0.00012097661237930879f, 8.682865154696628e-05f, 0.00015776285727042705f, 9.272310853702947e-05f, 0.00014032972103450447f, 0.00016138542559929192f, 0.00010853751882677898f, 0.00010822443437064067f, 0.00010876024316530675f, 0.00015084004553500563f, 7.153565820772201e-05f, 0.0002127401967300102f, 0.00013618117372971028f, 0.00013676684466190636f, 0.00010120528168044984f, 0.00012334453640505672f, 0.00012749421875923872f, 0.00015968765364959836f, 0.00012898774002678692f, 0.0001623905700398609f, 0.00013280927669256926f, 9.24257401493378e-05f, 0.00011310662375763059f, 0.00011561300198081881f, 9.515290730632842e-05f, 6.632880831602961e-05f, 0.00011816029291367158f, 9.94535002973862e-05f, 7.456713501596823e-05f, 0.00016489152039866894f, 0.00011360662756487727f, 5.5737822549417615e-05f, 2.573241181380581e-05f, 0.00013601577666122466f, 5.434744161902927e-05f, 0.00012700803927145898f, 0.0001290153741138056f, 5.6641372793819755e-05f, 8.986503962660208e-05f, 9.57380689214915e-05f, 0.0001315946865361184f, 0.00014516916417051107f, 9.449800563743338e-05f, 9.338146628579125e-05f, 7.24509809515439e-05f, 9.124187636189163e-05f, 8.56920814840123e-05f, 0.00013247581955511123f, 8.101358253043145e-05f, 5.831267480971292e-05f, 5.7327866670675576e-05f, 0.0001572922192281112f, 4.5272034185472876e-05f, 7.008566171862185e-05f, 0.0001186660592793487f, 6.72670139465481e-05f, 0.0001528070861240849f, 8.526723104296252e-05f, 9.115853026742116e-05f, 8.970968337962404e-05f, 0.00010264215234201401f, 0.00012455717660486698f, 0.00018554039706941694f, 5.06585456605535e-05f, 0.00011327421816531569f, 0.00013358712021727115f, 9.748836600920185e-05f, 0.00010097314225276932f, 7.094338798196986e-05f, 7.545592961832881e-05f, 9.193411824526265e-05f, 0.00017971664783544838f, 0.00014745030784979463f, 0.0001180011240649037f, 0.0001032722502714023f, 7.816652941983193e-05f, 0.00010222401760984212f, 7.11718894308433e-05f, 0.000183838841621764f, 0.0001123226757044904f, 0.0001169342576758936f, 9.648685954743996e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004181019961833954f, 0.005519567057490349f, 0.0036715015303343534f, 0.004319192375987768f, 0.005081649869680405f, 0.0029773754067718983f, 0.0035703752655535936f, 0.002389485016465187f, 0.0016455657314509153f, 0.0019837457221001387f, 0.003407073672860861f, 0.003478376427665353f, 0.003312467597424984f, 0.0038344019558280706f, 0.004407792817801237f, 0.0031636091880500317f, 0.005748102907091379f, 0.003378374269232154f, 0.005112925078719854f, 0.005880091339349747f, 0.003954573534429073f, 0.003943166229873896f, 0.003962688613682985f, 0.005495869554579258f, 0.0026064077392220497f, 0.0077512068673968315f, 0.004961772356182337f, 0.004983111284673214f, 0.0036874229554086924f, 0.0044940682128071785f, 0.0046452623791992664f, 0.005818232893943787f, 0.0046996790915727615f, 0.005916713736951351f, 0.004838916938751936f, 0.003367539495229721f, 0.004121049307286739f, 0.0042123692110180855f, 0.0034669041633605957f, 0.002416695700958371f, 0.004305180162191391f, 0.0036235966254025698f, 0.0027168598026037216f, 0.006007836200296879f, 0.004139266908168793f, 0.0020308122038841248f, 0.000937562552280724f, 0.004955746233463287f, 0.0019801536109298468f, 0.00462754862383008f, 0.004700685851275921f, 0.00206373305991292f, 0.0032742400653660297f, 0.0034882244653999805f, 0.004794663283973932f, 0.005289250519126654f, 0.0034430427476763725f, 0.00340236141346395f, 0.0026397574692964554f, 0.003324405290186405f, 0.003122198162600398f, 0.00482676737010479f, 0.0029517365619540215f, 0.0021246271207928658f, 0.002088745590299368f, 0.005730954930186272f, 0.001649490324780345f, 0.002553576836362481f, 0.00432360777631402f, 0.0024508791975677013f, 0.005567539017647505f, 0.003106718650087714f, 0.0033213687129318714f, 0.0032685797195881605f, 0.0037397753912955523f, 0.004538251087069511f, 0.0067601799964904785f, 0.0018457482801750302f, 0.004127155523747206f, 0.00486725801602006f, 0.0035519967786967754f, 0.0036789649166166782f, 0.002584828296676278f, 0.00274924305267632f, 0.003349627135321498f, 0.006547990720719099f, 0.0053723640739917755f, 0.00429938081651926f, 0.003762732958421111f, 0.0028480039909482002f, 0.0037245405837893486f, 0.0025931536220014095f, 0.006698183249682188f, 0.00409248610958457f, 0.0042605092748999596f, 0.00351550686173141f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.0526770539581776e-05f, 6.758383824490011e-05f, 7.129705772968009e-05f, 5.697897358913906e-05f, 5.381985829444602e-05f, 9.506653441349044e-05f, 7.714121602475643e-05f, 6.394612864824012e-05f, 4.022749999421649e-05f, 3.617243419284932e-05f, 5.958583642495796e-05f, 5.408290235209279e-05f, 6.225549441296607e-05f, 5.120842979522422e-05f, 5.025253994972445e-05f, 4.9133905122289434e-05f, 5.474775389302522e-05f, 7.025741797406226e-05f, 6.0254889831412584e-05f, 7.192353950813413e-05f, 5.378449714044109e-05f, 8.095011435216293e-05f, 4.057357364217751e-05f, 7.129048026399687e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001611651387065649f, 0.0017995605012401938f, 0.0018984327325597405f, 0.0015171838458627462f, 0.0014330658596009016f, 0.002531344536691904f, 0.0020540456753224134f, 0.0017026988789439201f, 0.0010711409850046039f, 0.0009631664142943919f, 0.0015865970635786653f, 0.0014400699874386191f, 0.0016576822381466627f, 0.0013635311042889953f, 0.0013380785239860415f, 0.0013082926161587238f, 0.0014577730325981975f, 0.00187075010035187f, 0.0016044119838625193f, 0.0019151141168549657f, 0.0014321242924779654f, 0.002155465539544821f, 0.0010803559562191367f, 0.0018982576439157128f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002129070198861882f, 0.00012691711890511215f, 9.497397695668042e-05f, 0.00022216855722945184f, 0.00042278875480405986f, 0.00014481328253168613f, 0.0001281990116694942f, 0.00018373175407759845f, 0.00019786786288022995f, 0.0003072955005336553f, 0.00019616121426224709f, 0.0003716780920512974f, 0.00012216070899739861f, 0.0001695185201242566f, 0.00024353338812943548f, 0.0001733386015985161f, 0.00014703419583383948f, 0.00010809885134221986f, 0.00021228026889730245f, 0.00022506897221319377f, 7.745195034658536e-05f, 0.00022681173868477345f, 0.00016153328760992736f, 0.00013567946734838188f, 0.00021943186584394425f, 0.00015200355846900493f, 0.0002059496328001842f, 0.00017110875342041254f, 0.00019161988166160882f, 0.00020479403610806912f, 0.00012502860045060515f, 7.676237146370113e-05f, 0.0001900126808322966f, 0.00011584754975046962f, 0.000151480344356969f, 0.00021698532509617507f, 0.00019066795357502997f, 0.00018190412083640695f, 0.00012423860607668757f, 9.630707063479349e-05f, 0.00010501471842871979f, 0.0003350660263095051f, 0.00013631873298436403f, 0.0001542354584671557f, 0.0001224844454554841f, 0.00025299363187514246f, 0.00012438517296686769f, 0.00010975702753057703f, 0.00010727402695920318f, 0.00010556430061114952f, 0.00013608475273940712f, 0.0001786610810086131f, 0.00026565510779619217f, 0.0001002917779260315f, 0.0001828262029448524f, 0.00013272705837152898f, 0.00012635462917387486f, 0.00016372631944250315f, 8.871660247677937e-05f, 0.00023660216538701206f, 0.000350775575498119f, 0.0002465810684952885f, 0.0003374470106791705f, 0.00023952077026478946f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010109501890838146f, 0.006026428192853928f, 0.0045096660032868385f, 0.010549268685281277f, 0.020075352862477303f, 0.006876194383949041f, 0.0060872966423630714f, 0.008724167011678219f, 0.00939539447426796f, 0.014591366983950138f, 0.009314357303082943f, 0.01764845661818981f, 0.005800578743219376f, 0.00804927758872509f, 0.01156373880803585f, 0.008230667561292648f, 0.006981650833040476f, 0.005132876802235842f, 0.010079741477966309f, 0.01068698987364769f, 0.0036776645574718714f, 0.010769741609692574f, 0.007670113816857338f, 0.0064424918964505196f, 0.010419322177767754f, 0.007217612117528915f, 0.009779143147170544f, 0.008124787360429764f, 0.009098720736801624f, 0.009724271483719349f, 0.005936755333095789f, 0.003644921351224184f, 0.009022405371069908f, 0.005500809755176306f, 0.007192767690867186f, 0.010303152725100517f, 0.009053519926965237f, 0.008637385442852974f, 0.005899243522435427f, 0.004572965670377016f, 0.004986432380974293f, 0.01590999960899353f, 0.006472846493124962f, 0.007323589641600847f, 0.005815950687974691f, 0.012012941762804985f, 0.005906202830374241f, 0.005211612209677696f, 0.00509371142834425f, 0.005012528505176306f, 0.0064617362804710865f, 0.008483395911753178f, 0.012614148668944836f, 0.004762172233313322f, 0.008681168779730797f, 0.006302302237600088f, 0.005999719258397818f, 0.007774245925247669f, 0.004212546162307262f, 0.011234622448682785f, 0.0166559386998415f, 0.011708452366292477f, 0.0160230565816164f, 0.011373206973075867f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021837031817995012f, 0.0001291588559979573f, 0.00025557581102475524f, 0.00017564548761583865f, 0.00013543076056521386f, 0.0002989139757119119f, 0.0001565861311974004f, 0.00013757716806139797f, 9.95298323687166e-05f, 0.0002523795119486749f, 0.0001341476890956983f, 0.0001333256223006174f, 0.0001585798163432628f, 0.0001079566209227778f, 0.00020338044851087034f, 0.00021280953660607338f, 0.00015011659706942737f, 0.00017437523638363928f, 0.0001505795371485874f, 0.00015697884373366833f, 0.00017503020353615284f, 0.00015089272346813232f, 0.00014445025590248406f, 0.00021746326819993556f, 0.00018562222248874605f, 0.0001952896564034745f, 0.0001873648725450039f, 0.00014253903646022081f, 0.00015872456424403936f, 0.00020072895858902484f, 0.00020000846416223794f, 0.0002178946160711348f, 0.00010922685032710433f, 0.00011695732973748818f, 0.00017034565098583698f, 0.00011825603723991662f, 0.00012180917838122696f, 0.00014023589028511196f, 0.00018061732407659292f, 0.00022641438408754766f, 0.0001916294713737443f, 6.251907325349748e-05f, 0.0002155298861907795f, 0.00025439911405555904f, 0.0001306798221776262f, 0.00011624314356595278f, 0.00019490734848659486f, 0.00018891155195888132f, 0.0002268987154820934f, 0.0001416217564838007f, 0.00012688081187661737f, 0.00020019961812067777f, 0.00018587568774819374f, 0.00012324607814662158f, 0.0002514771476853639f, 0.000321923173032701f, 0.00013548506831284612f, 0.0001668839977355674f, 0.00020314898574724793f, 0.00026559748221188784f, 0.00016825919738039374f, 0.00021286199626047164f, 0.00019920938939321786f, 0.00010185618157265708f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036612306721508503f, 0.002165497513487935f, 0.0042850240133702755f, 0.0029448994901031256f, 0.0022706531453877687f, 0.005011638160794973f, 0.0026253473479300737f, 0.002306640148162842f, 0.001668732613325119f, 0.004231434315443039f, 0.002249140990898013f, 0.002235358115285635f, 0.002658773912116885f, 0.0018100175075232983f, 0.003409908153116703f, 0.003567997831851244f, 0.002516878303140402f, 0.0029236022382974625f, 0.0025246399454772472f, 0.002631931798532605f, 0.0029345836956053972f, 0.002529890974983573f, 0.002421875484287739f, 0.0036460228729993105f, 0.0031121710781008005f, 0.003274256829172373f, 0.0031413885299116373f, 0.0023898317012935877f, 0.0026612007059156895f, 0.003365452867001295f, 0.0033533729147166014f, 0.003653255058452487f, 0.0018313144100829959f, 0.0019609248265624046f, 0.002856041770428419f, 0.0019826991483569145f, 0.002042271662503481f, 0.0023512167390435934f, 0.003028258215636015f, 0.003796098753809929f, 0.0032128894235938787f, 0.0010482044890522957f, 0.0036136077251285315f, 0.0042652953416109085f, 0.002190998289734125f, 0.0019489505793899298f, 0.003267847001552582f, 0.0031673205085098743f, 0.003804219188168645f, 0.002374452305957675f, 0.002127303509041667f, 0.0033565780613571405f, 0.003116420703008771f, 0.0020663628820329905f, 0.0042163049802184105f, 0.005397413857281208f, 0.002271563746035099f, 0.0027980031445622444f, 0.003406027564778924f, 0.004453048575669527f, 0.002821059897542f, 0.0035688774660229683f, 0.003339975606650114f, 0.001707736635580659f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018717623606789857f, 0.00011679498857120052f, 9.366052836412564e-05f, 0.0001340439193882048f, 0.00010727083281381056f, 0.00012704162509180605f, 0.00014951075718272477f, 0.00014657850260846317f, 0.00013755612599197775f, 0.00014071425539441407f, 0.00017073139315471053f, 0.00011962541611865163f, 0.00011718178575392812f, 0.0001163299530162476f, 0.00012141644401708618f, 0.00019161918316967785f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005369572434574366f, 0.003350527724251151f, 0.0026868635322898626f, 0.003845351980999112f, 0.003077305853366852f, 0.003644475480541587f, 0.004289053380489349f, 0.004204934928566217f, 0.003946107812225819f, 0.004036705940961838f, 0.004897815175354481f, 0.003431724850088358f, 0.0033616237342357635f, 0.0033371869940310717f, 0.003483104519546032f, 0.005497028585523367f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010021107736974955f, 0.0003056467685382813f, 0.0002929281035903841f, 0.0004443132784217596f, 0.0006077890284359455f, 0.00018068247300107032f, 0.00027977832360193133f, 0.0005917426897212863f, 0.00034492986742407084f, 0.000683021207805723f, 0.0005033424822613597f, 0.00048090677591972053f, 0.00039526124601252377f, 0.0002677999436855316f, 0.00020209192007314414f, 0.0002950143825728446f, 0.0003299569070804864f, 0.0003799673868343234f, 0.0007170988246798515f, 0.0001711398217594251f, 0.0004572549369186163f, 0.0004601439577527344f, 0.00030211987905204296f, 0.000326283072354272f, 0.0004494219901971519f, 0.00027498597046360373f, 0.0006407236214727163f, 0.0005667695077136159f, 0.0007284501916728914f, 0.0008279589819721878f, 0.0002574327227193862f, 0.0003510416718199849f, 0.00032597596873529255f, 0.0004343142791185528f, 0.0005208507063798606f, 0.00020387519907671958f, 0.00042612140532583f, 0.00016999791841953993f, 0.0003313551424071193f, 0.0004898710758425295f, 0.0002539422130212188f, 0.0006578329484909773f, 0.00036096345866099f, 0.0001394042046740651f, 0.00036422841367311776f, 0.00016720136045478284f, 0.00017501006368547678f, 0.0006666388362646103f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.030887320637702942f, 0.009420724585652351f, 0.009028706699609756f, 0.013694739900529385f, 0.01873343251645565f, 0.0055690426379442215f, 0.008623400703072548f, 0.018238848075270653f, 0.010631518438458443f, 0.02105225808918476f, 0.015514153055846691f, 0.014822634868323803f, 0.01218284573405981f, 0.008254200220108032f, 0.006228930316865444f, 0.009093010798096657f, 0.010170018300414085f, 0.011711454018950462f, 0.022102607414126396f, 0.005274916533380747f, 0.014093631878495216f, 0.014182677492499352f, 0.009312017820775509f, 0.010056782513856888f, 0.013852202333509922f, 0.008475689217448235f, 0.01974855177104473f, 0.017469117417931557f, 0.02245248295366764f, 0.025519568473100662f, 0.007934658788144588f, 0.01081989798694849f, 0.010047316551208496f, 0.01338654849678278f, 0.01605379767715931f, 0.006283894646912813f, 0.01313402596861124f, 0.005239720456302166f, 0.010213115252554417f, 0.01509893499314785f, 0.007827073335647583f, 0.0202759001404047f, 0.011125709861516953f, 0.004296753089874983f, 0.011226343922317028f, 0.005153524223715067f, 0.005394205916672945f, 0.02054731734097004f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.732419857755303e-05f, 0.0003533619164954871f, 0.00013670348562300205f, 9.198868065141141e-05f, 0.00011280625767540187f, 0.00024604209465906024f, 0.00017740462499205023f, 6.795045192120597e-05f, 0.00019359913130756468f, 0.0002076150121865794f, 0.00013965001562610269f, 0.00026366490055806935f, 0.00010980709339492023f, 0.00021804891002830118f, 0.00025832036044448614f, 0.00013097711780574173f, 0.0001379330933559686f, 0.00012174784205853939f, 7.018323958618566e-05f, 0.0003337428206577897f, 0.0001866468955995515f, 7.36569709260948e-05f, 9.601331112207845e-05f, 0.00018336763605475426f, 0.00024073403619695455f, 0.00013202123227529228f, 0.00010646781447576359f, 0.00010603712144074962f, 0.00012282167153898627f, 0.0001429112016921863f, 0.00011582647130126134f, 0.0003365199954714626f, 0.00014704567729495466f, 0.00019544998940546066f, 0.00015731480380054563f, 0.00014684155758004636f, 0.00017075485084205866f, 0.0003128673997707665f, 0.00016491414862684906f, 0.00017681576719041914f, 0.0002181828167522326f, 0.00011367386468918994f, 0.0002936755190603435f, 0.0002866486902348697f, 0.0001440380437998101f, 0.0002848127915058285f, 0.0004945347318425775f, 0.00011695441207848489f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0025307429023087025f, 0.009188548661768436f, 0.0035547311417758465f, 0.002392002148553729f, 0.0029333261772990227f, 0.006397887133061886f, 0.004613092169165611f, 0.001766930683515966f, 0.005034201312810183f, 0.005398659501224756f, 0.003631350351497531f, 0.006856136955320835f, 0.0028553383890539408f, 0.005669974256306887f, 0.006717161741107702f, 0.003405827097594738f, 0.0035867048427462578f, 0.003165836213156581f, 0.0018249904969707131f, 0.00867838878184557f, 0.00485342089086771f, 0.0019153186585754156f, 0.0024966555647552013f, 0.004768149461597204f, 0.006259860936552286f, 0.0034329777117818594f, 0.002768506295979023f, 0.002757306909188628f, 0.003193759359419346f, 0.0037161519285291433f, 0.0030118615832179785f, 0.008750604465603828f, 0.0038236614782363176f, 0.005082329735159874f, 0.004090691916644573f, 0.0038183536380529404f, 0.004440176300704479f, 0.008135560899972916f, 0.004288299474865198f, 0.004597779829055071f, 0.005673456471413374f, 0.0029558867681771517f, 0.007636509835720062f, 0.007453789934515953f, 0.003745453432202339f, 0.007406050339341164f, 0.012859496288001537f, 0.0030411917250603437f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012136252189520746f, 0.00020435104670468718f, 0.0001757440040819347f, 0.00016745197353884578f, 0.0001489110291004181f, 0.00017507636221125722f, 0.00013826912618242204f, 0.00018755343626253307f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010785390622913837f, 0.0018160514300689101f, 0.001561822951771319f, 0.0014881324023008347f, 0.0013233604840934277f, 0.0015558897284790874f, 0.0012287867721170187f, 0.001666772412136197f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005063037970103323f, 0.0008082595304585993f, 0.0004550998564809561f, 0.0005617729038931429f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006998982280492783f, 0.011173121631145477f, 0.0062911552377045155f, 0.0077657694928348064f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0015107829822227359f, 0.0020267751533538103f, 0.0030035492964088917f, 0.00021510284568648785f, 0.002173961140215397f, 0.0007622673292644322f, 0.0003949206438846886f, 0.0002490973856765777f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012215379625558853f, 0.016387414187192917f, 0.02428508549928665f, 0.001739206025376916f, 0.017577482387423515f, 0.006163284182548523f, 0.003193116281181574f, 0.0020140677224844694f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002102281287079677f, 0.0001313693355768919f, 0.00019171793246641755f, 0.0006741384277120233f, 0.0004388588131405413f, 0.00039749257848598063f, 0.0005300707998685539f, 0.0011688405647873878f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028195835184305906f, 0.001761927967891097f, 0.0025713243521749973f, 0.0090415570884943f, 0.005885982420295477f, 0.005331177730113268f, 0.0071093193255364895f, 0.015676511451601982f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000360029109288007f, 0.0003005935868714005f, 6.38729179627262e-05f, 0.0005321004427969456f, 0.00017645563639234751f, 0.00047531057498417795f, 9.744644194142893e-05f, 0.0003953137493226677f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09180741757154465f, 0.07665135711431503f, 0.01628759317100048f, 0.13568560779094696f, 0.04499618336558342f, 0.1212041899561882f, 0.02484884113073349f, 0.10080499947071075f),
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
    AI_PACK_INTQ_SCALE(0.07455999404191971f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12367875874042511f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07233963161706924f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11252491921186447f),
    AI_PACK_INTQ_ZP(20)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03845677152276039f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03244408220052719f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03485868498682976f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04404342547059059f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05964396521449089f),
    AI_PACK_INTQ_ZP(-37)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021060090512037277f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0375557467341423f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027446074411273003f),
    AI_PACK_INTQ_ZP(13)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017204979434609413f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022582415491342545f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022031402215361595f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03292098641395569f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019439417868852615f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02382335253059864f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.035510167479515076f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.045917198061943054f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018179267644882202f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.028134828433394432f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.050382740795612335f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08809565752744675f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08809565752744675f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017823372036218643f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0239547248929739f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03615250810980797f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02663453109562397f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14928840100765228f),
    AI_PACK_INTQ_ZP(30)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1324, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1324, 1324),
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
  conv2d_38_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 30, 1, 1), AI_STRIDE_INIT(4, 4, 4, 120, 120),
  1, &conv2d_38_bias_array, &conv2d_38_bias_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 30), AI_STRIDE_INIT(4, 1, 256, 256, 256),
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
  AI_SHAPE_INIT(4, 1, 30, 5, 5), AI_STRIDE_INIT(4, 1, 1, 30, 150),
  1, &conv2d_38_output_array, &conv2d_38_output_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conversion_39_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 30, 5, 5), AI_STRIDE_INIT(4, 4, 4, 120, 600),
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
  &AI_NET_OBJ_INSTANCE, &concat_32_layer, AI_STATIC,
  .tensors = &eltwise_30_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_30_output, &conv2d_17_output),
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
                     1, 1, 73064, 1,
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
    conv2d_38_output_array.data = AI_PTR(activations + 1324);
    conv2d_38_output_array.data_start = AI_PTR(activations + 1324);
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
    conv2d_38_bias_array.data = AI_PTR(weights + 72944);
    conv2d_38_bias_array.data_start = AI_PTR(weights + 72944);
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
      
      .n_macc            = 6275854,
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

