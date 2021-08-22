/**
  ******************************************************************************
  * @file    person_yolo.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Aug 22 17:27:03 2021
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
#define AI_PERSON_YOLO_MODEL_SIGNATURE     "a0617a0de82d0464f1834f6789c33615"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Aug 22 17:27:03 2021"

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
  NULL, NULL, 1374, AI_STATIC)

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
  NULL, NULL, 35, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8960, AI_STATIC)

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
  NULL, NULL, 875, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conversion_40_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 875, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 35,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.8336242141667753e-05f, 6.894370744703338e-05f, 2.46593845076859e-05f, 4.078608617419377e-05f, 0.00015760517271701247f, 0.00011143794108647853f, 0.00012115493882447481f, 3.674505205708556e-05f, 7.065318641252816e-05f, 2.7991376555291936e-05f, 5.4663072660332546e-05f, 0.0001385083160130307f, 0.00012588473327923566f, 0.00012312308535911143f, 4.1110713937086985e-05f, 6.944408232811838e-05f, 3.8147991290315986e-05f, 5.059433533460833e-05f, 0.00014150913921184838f, 0.00012500793673098087f, 0.00012381050328258425f, 4.0490893297828734e-05f, 7.410238322336227e-05f, 4.666732274927199e-05f, 4.153289773967117e-05f, 0.00013851511175744236f, 0.00012533654808066785f, 0.0001242737052962184f, 6.640981155214831e-05f, 6.231418228708208e-05f, 2.0769090042449534e-05f, 4.002457717433572e-05f, 0.0001301574957324192f, 0.00012469346984289587f, 0.00012250685540493578f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 35,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013113064924255013f, 0.002358247060328722f, 0.0008434840710833669f, 0.001395104336552322f, 0.005390947684645653f, 0.003811779199168086f, 0.004144153092056513f, 0.00125687918625772f, 0.0024167203810065985f, 0.0009574561845511198f, 0.0018697722116485238f, 0.004737732000648975f, 0.004305937793105841f, 0.00421147421002388f, 0.0014062083791941404f, 0.002375362440943718f, 0.00130486732814461f, 0.0017305994406342506f, 0.004840376786887646f, 0.004275946412235498f, 0.004234987776726484f, 0.0013850071700289845f, 0.0025347014889121056f, 0.0015962744364514947f, 0.0014206493506208062f, 0.004737964831292629f, 0.004287186544388533f, 0.00425083190202713f, 0.0022715742234140635f, 0.002131481422111392f, 0.0007104150136001408f, 0.001369056641124189f, 0.004452089313417673f, 0.004265190102159977f, 0.004190396051853895f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.5936837371555157e-05f, 3.76180287275929e-05f, 2.1724970793002285e-05f, 2.5912571800290607e-05f, 2.2830558009445667e-05f, 3.087958612013608e-05f, 1.959117980732117e-05f, 1.48471144711948e-05f, 2.4038577976170927e-05f, 2.2586045815842226e-05f, 1.6669515389367007e-05f, 1.0180103345192038e-05f, 2.2996839106781408e-05f, 1.9233066268498078e-05f, 2.8510552510851994e-05f, 2.184420191042591e-05f, 1.646971213631332e-05f, 3.688889046316035e-05f, 2.3201597286970355e-05f, 2.5192834073095582e-05f, 1.4593299965781625e-05f, 1.6629526726319455e-05f, 2.2754669771529734e-05f, 1.386151143378811e-05f, 2.0943762137903832e-05f, 3.5372155252844095e-05f, 1.8673299564397894e-05f, 1.2763674021698534e-05f, 2.929385118477512e-05f, 1.5568914022878744e-05f, 2.6499154046177864e-05f, 1.218318266182905e-05f, 1.4362235560838599e-05f, 1.3392103937803768e-05f, 2.7558320653042756e-05f, 1.7751255654729903e-05f, 2.533984479669016e-05f, 2.323049193364568e-05f, 4.047507172799669e-05f, 1.233143666468095e-05f, 2.5608705982449464e-05f, 1.3768139979219995e-05f, 1.3802129615214653e-05f, 1.668216282268986e-05f, 1.4521334378514439e-05f, 1.3200310604588594e-05f, 1.7474698324804194e-05f, 1.4709859897266142e-05f, 1.5449973943759687e-05f, 3.9269936678465456e-05f, 1.2183670150989201e-05f, 1.6528303603990935e-05f, 2.1986441424814984e-05f, 2.9035474653937854e-05f, 3.8500369555549696e-05f, 2.2630425519309938e-05f, 1.3966066944703925e-05f, 1.7827096598921344e-05f, 1.670681740506552e-05f, 2.7086296540801413e-05f, 1.5580031686113216e-05f, 1.8554763300926425e-05f, 3.24883840221446e-05f, 1.4939966604288202e-05f, 1.5612322386004962e-05f, 1.794376839825418e-05f, 1.74028828041628e-05f, 1.0889462828345131e-05f, 1.922987576108426e-05f, 2.3222635718411766e-05f, 2.8057460440322757e-05f, 2.5072082280530594e-05f, 1.706402690615505e-05f, 3.154668229399249e-05f, 2.0746207155752927e-05f, 2.2187015929375775e-05f, 2.6917507057078183e-05f, 1.677333057159558e-05f, 1.8163022104999982e-05f, 2.779386704787612e-05f, 1.622179479454644e-05f, 1.2163438441348262e-05f, 1.1987473953922745e-05f, 2.1443836885737255e-05f, 3.1556206522509456e-05f, 1.2432019502739422e-05f, 3.155030572088435e-05f, 2.3682961909798905e-05f, 2.1146262952242978e-05f, 1.4293668755271938e-05f, 1.647585304453969e-05f, 2.0288283849367872e-05f, 1.913421874633059e-05f, 1.6709973351680674e-05f, 2.9330914912861772e-05f, 3.498177829897031e-05f, 2.1188490791246295e-05f, 1.891170541057363e-05f, 1.9783268726314418e-05f, 1.5516070561716333e-05f, 3.5322169424034655e-05f, 3.170552372466773e-05f, 2.2875181457493454e-05f, 2.7550055165193044e-05f, 1.2176991731394082e-05f, 2.726740058278665e-05f, 1.5435249224537984e-05f, 1.8960870875162072e-05f, 2.307785689481534e-05f, 1.7249598386115395e-05f, 1.4181952792569064e-05f, 1.4292034393292852e-05f, 2.823417707986664e-05f, 2.771446634142194e-05f, 1.52633037941996e-05f, 3.078522058785893e-05f, 2.024116474785842e-05f, 3.599726551328786e-05f, 1.4268905943026766e-05f, 3.411100260564126e-05f, 1.9511515347403474e-05f, 1.966356285265647e-05f, 1.924780553963501e-05f, 3.264088081778027e-05f, 2.3916105419630185e-05f, 5.907898594159633e-05f, 1.1183774404344149e-05f, 1.5121067917789333e-05f, 1.758777398208622e-05f, 4.2842686525546014e-05f, 3.414027742110193e-05f, 1.8733411707216874e-05f, 1.7418686184100807e-05f, 1.4457024917646777e-05f, 1.6309057173202746e-05f, 1.6727042748243548e-05f, 4.380676182336174e-05f, 1.8780807295115665e-05f, 2.07641987799434e-05f, 2.425461025268305e-05f, 2.230129211966414e-05f, 2.0786892491742037e-05f, 1.983554830076173e-05f, 2.1410605768323876e-05f, 1.7687343643046916e-05f, 4.402341801323928e-05f, 2.0252940885256976e-05f, 3.544559149304405e-05f, 1.5312552932300605e-05f, 4.055125828017481e-05f, 2.60522047028644e-05f, 1.4594922504329588e-05f, 1.6056410458986647e-05f, 3.0763912945985794e-05f, 1.2569049431476742e-05f, 2.127451080013998e-05f, 2.0769122784258798e-05f, 1.1428242942201905e-05f, 2.0722111003124155e-05f, 2.155893889721483e-05f, 2.4109544028760865e-05f, 2.8892474801978096e-05f, 2.8150469006504864e-05f, 2.333076554350555e-05f, 1.7852802557172254e-05f, 2.1362333427532576e-05f, 2.641051833052188e-05f, 1.427473580406513e-05f, 2.7076464903075248e-05f, 1.455612618883606e-05f, 1.833816168073099e-05f, 1.6298828995786607e-05f, 1.476965826441301e-05f, 2.3484792109229602e-05f, 1.1290804650343489e-05f, 2.172584026993718e-05f, 2.1817233573528938e-05f, 1.6812291505630128e-05f, 1.674305894994177e-05f, 3.747778828255832e-05f, 2.660381142050028e-05f, 1.549794433231e-05f, 2.7920466891373508e-05f, 1.4435451703320723e-05f, 1.6573247194173746e-05f, 2.388731991231907e-05f, 2.1015606762375683e-05f, 1.6659767425153404e-05f, 2.181164381909184e-05f, 1.7845381080405787e-05f, 1.2679553947236855e-05f, 1.4783454389544204e-05f, 1.6909918485907838e-05f, 1.2879011592303868e-05f, 1.5172494386206381e-05f, 1.6890639017219655e-05f, 1.6040845366660506e-05f, 2.6645773687050678e-05f, 1.7140497220680118e-05f, 1.3180662790546194e-05f, 3.1863266485743225e-05f, 2.7038004191126674e-05f, 2.541367575759068e-05f, 1.3128753380442504e-05f, 3.147802271996625e-05f, 2.5723327780724503e-05f, 2.4224478693213314e-05f, 2.1031408323324285e-05f, 2.0384115487104282e-05f, 1.4367880794452503e-05f, 1.600860196049325e-05f, 1.7185173419420607e-05f, 2.606735870358534e-05f, 1.9410037566558458e-05f, 1.5869332855800167e-05f, 1.1211921446374618e-05f, 2.369527646806091e-05f, 2.7851125196320936e-05f, 2.6817060643224977e-05f, 1.5928893844829872e-05f, 1.4488407032331452e-05f, 1.1145181815663818e-05f, 1.763840191415511e-05f, 2.073050563922152e-05f, 1.298425740969833e-05f, 3.149729673168622e-05f, 3.809210465988144e-05f, 3.265877967351116e-05f, 1.330340910499217e-05f, 3.582606223062612e-05f, 2.2602122044190764e-05f, 2.3669768779654987e-05f, 1.7118452888098545e-05f, 1.114941005653236e-05f, 1.9309632989461534e-05f, 1.9974140741396695e-05f, 1.4014318367117085e-05f, 1.8917933630291373e-05f, 2.2101665308582596e-05f, 2.1295782062225044e-05f, 2.5014323909999803e-05f, 3.1843788747210056e-05f, 1.5848556358832866e-05f, 1.6246134691755287e-05f, 2.4787121219560504e-05f, 2.13388502743328e-05f, 2.611356831039302e-05f, 2.2178688595886342e-05f, 1.6792459064163268e-05f, 2.2430813260143623e-05f, 2.051030060101766e-05f, 1.811684705899097e-05f, 2.34222061408218e-05f, 2.1031317373854108e-05f, 1.5754269043100066e-05f, 1.77478177647572e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00035419862251728773f, 0.0008360663778148592f, 0.0004828407254535705f, 0.0005759107880294323f, 0.000507412594743073f, 0.0006863034213893116f, 0.0004354169068392366f, 0.00032997934613376856f, 0.0005342609947547317f, 0.0005019782693125308f, 0.0003704825066961348f, 0.00022625432757195085f, 0.000511108199134469f, 0.0004274577950127423f, 0.0006336513324640691f, 0.00048549065832048655f, 0.0003660418151412159f, 0.0008198611321859062f, 0.0005156589904800057f, 0.0005599145079031587f, 0.00032433829619549215f, 0.00036959373392164707f, 0.0005057259695604444f, 0.0003080741735175252f, 0.00046547825331799686f, 0.0007861515041440725f, 0.00041501689702272415f, 0.0002836745698004961f, 0.0006510602543130517f, 0.00034602146479301155f, 0.0005889476742595434f, 0.0002707730745896697f, 0.0003192028379999101f, 0.00029764152714051306f, 0.0006124878418631852f, 0.0003945243079215288f, 0.0005631818785332143f, 0.000516301195602864f, 0.0008995645330287516f, 0.00027406803565099835f, 0.0005691573605872691f, 0.0003059989830944687f, 0.0003067544021178037f, 0.0003707635623868555f, 0.00032273883698508143f, 0.0002933788928203285f, 0.0003883778117597103f, 0.00032692885724827647f, 0.0003433779929764569f, 0.0008727802778594196f, 0.0002707839012145996f, 0.000367344036931172f, 0.0004886519745923579f, 0.0006453177775256336f, 0.0008556765387766063f, 0.0005029645981267095f, 0.00031039793975651264f, 0.000396209885366261f, 0.00037131152930669487f, 0.00060199701692909f, 0.0003462685563135892f, 0.00041238238918595016f, 0.0007220592233352363f, 0.0003320430114399642f, 0.0003469862276688218f, 0.0003988029493484646f, 0.00038678167038597167f, 0.00024201994528993964f, 0.0004273868689779192f, 0.0005161265726201236f, 0.0006235812907107174f, 0.0005572307854890823f, 0.00037925055949017406f, 0.0007011297275312245f, 0.0004610875912476331f, 0.0004931097500957549f, 0.0005982456495985389f, 0.00037278980016708374f, 0.0004036758909933269f, 0.0006177228642627597f, 0.0003605318197514862f, 0.0002703342470340431f, 0.0002664234198164195f, 0.0004765925114043057f, 0.0007013414287939668f, 0.00027630350086838007f, 0.0007012102869339287f, 0.0005263573839329183f, 0.00046997886965982616f, 0.0003176789323333651f, 0.000366178312106058f, 0.00045091015635989606f, 0.00042526089237071574f, 0.0003713816695380956f, 0.0006518840091302991f, 0.0007774753030389547f, 0.0004709174099843949f, 0.00042031551129184663f, 0.00043968611862510443f, 0.0003448470088187605f, 0.0007850404945202172f, 0.0007046600221656263f, 0.0005084043368697166f, 0.0006123041384853423f, 0.00027063547167927027f, 0.0006060220766812563f, 0.0003430507204029709f, 0.0004214082146063447f, 0.0005129088531248271f, 0.0003833749215118587f, 0.0003151960263494402f, 0.0003176426107529551f, 0.0006275088526308537f, 0.0006159581826068461f, 0.0003392292419448495f, 0.0006842061993665993f, 0.00044986294233240187f, 0.0008000446250662208f, 0.00031712857889942825f, 0.0007581221871078014f, 0.00043364634620957077f, 0.00043702565017156303f, 0.0004277853877283633f, 0.0007254484808072448f, 0.0005315390299074352f, 0.0013130393344908953f, 0.000248561060288921f, 0.00033606801298446953f, 0.00039089092751964927f, 0.0009521851316094398f, 0.0007587728323414922f, 0.0004163529083598405f, 0.000387132924515754f, 0.00032130954787135124f, 0.000362471240805462f, 0.0003717610379680991f, 0.0009736118372529745f, 0.0004174062632955611f, 0.00046148744877427816f, 0.0005390623700805008f, 0.0004956495831720531f, 0.00046199181815609336f, 0.0004408480308484286f, 0.00047585394349880517f, 0.00039310386637225747f, 0.000978427124209702f, 0.0004501246730796993f, 0.0007877835887484252f, 0.0003403238079044968f, 0.0009012577938847244f, 0.0005790141876786947f, 0.00032437435584142804f, 0.000356856151483953f, 0.0006837326218374074f, 0.00027934901299886405f, 0.0004728292115032673f, 0.0004615968791767955f, 0.00025399442529305816f, 0.0004605520225595683f, 0.0004791506507899612f, 0.0005358382477425039f, 0.0006421395810320973f, 0.0006256484193727374f, 0.000518529792316258f, 0.00039678122266195714f, 0.0004747810889966786f, 0.0005869777523912489f, 0.0003172581491526216f, 0.0006017785053700209f, 0.0003235120966564864f, 0.0004075684119015932f, 0.00036224391078576446f, 0.0003282578836660832f, 0.0005219530430622399f, 0.00025093983276747167f, 0.00048286005039699376f, 0.00048489129403606057f, 0.0003736556973308325f, 0.00037211700691841543f, 0.0008329494739882648f, 0.0005912737105973065f, 0.0003444441535975784f, 0.0006205365643836558f, 0.000320830091368407f, 0.00036834290949627757f, 0.0005308992695063353f, 0.0004670750058721751f, 0.0003702658286783844f, 0.0004847670497838408f, 0.0003966162621509284f, 0.00028180499793961644f, 0.0003285644925199449f, 0.00037582547520287335f, 0.0002862379769794643f, 0.0003372109786141664f, 0.00037539697950705886f, 0.0003565101942513138f, 0.0005922063137404621f, 0.00038095013587735593f, 0.00029294221894815564f, 0.0007081659277901053f, 0.0006009237258695066f, 0.000564822752494365f, 0.00029178851400502026f, 0.000699603755492717f, 0.000571704818867147f, 0.0005383926909416914f, 0.0004674262017942965f, 0.00045304003288038075f, 0.0003193283046130091f, 0.00035579357063397765f, 0.0003819430712610483f, 0.00057935097720474f, 0.0004313910030759871f, 0.0003526983200572431f, 0.0002491866471245885f, 0.0005266310763545334f, 0.0006189954583533108f, 0.0005960132111795247f, 0.0003540220786817372f, 0.00032200702116824687f, 0.0002477033413015306f, 0.0003920161398127675f, 0.0004607386072166264f, 0.00028857708093710244f, 0.0007000321638770401f, 0.0008466027211397886f, 0.0007258462719619274f, 0.0002956702664960176f, 0.0007962395902723074f, 0.0005023355479352176f, 0.0005260641919448972f, 0.0003804601728916168f, 0.0002477973175700754f, 0.0004291594959795475f, 0.0004439282638486475f, 0.0003114703285973519f, 0.00042045392910949886f, 0.0004912128206342459f, 0.00047330197412520647f, 0.0005559471319429576f, 0.000707732979208231f, 0.0003522365295793861f, 0.00036107280175201595f, 0.0005508975009433925f, 0.00047425914090126753f, 0.0005803779931738973f, 0.000492924707941711f, 0.00037321491981856525f, 0.0004985281848348677f, 0.00045584450708702207f, 0.00040264963172376156f, 0.0005205620545893908f, 0.000467424193629995f, 0.0003501409955788404f, 0.00039444793947041035f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.906253964989446e-05f, 5.7070221373578534e-05f, 7.75161461206153e-05f, 6.176582246553153e-05f, 7.757005369057879e-05f, 3.2071966415969655e-05f, 5.3791758546140045e-05f, 6.803940050303936e-05f, 3.535619907779619e-05f, 4.0253682527691126e-05f, 4.0916249417932704e-05f, 3.1910025427350774e-05f, 4.487413389142603e-05f, 7.813842239556834e-05f, 4.156198338023387e-05f, 4.376824290375225e-05f, 4.814507337869145e-05f, 4.767103018821217e-05f, 3.683451359393075e-05f, 6.549276440637186e-05f, 4.6916495193727314e-05f, 3.5816701711155474e-05f, 4.1475865145912394e-05f, 3.175662277499214e-05f, 3.820742858806625e-05f, 0.00011916430230485275f, 3.2579446269664913e-05f, 2.575689177319873e-05f, 3.590543201426044e-05f, 3.8662401493638754e-05f, 4.41447518824134e-05f, 4.646974048228003e-05f, 5.071812847745605e-05f, 0.000106053936178796f, 7.958064816193655e-05f, 3.928121077478863e-05f, 5.419142689788714e-05f, 5.472861812449992e-05f, 3.815614400082268e-05f, 3.2009134883992374e-05f, 9.165978553937748e-05f, 4.228253965266049e-05f, 3.691926758619957e-05f, 4.1322615288663656e-05f, 0.00011080320837209001f, 4.8242836783174425e-05f, 4.2478859541006386e-05f, 3.734300480573438e-05f, 3.3333013561787084e-05f, 2.1238985937088728e-05f, 4.682438157033175e-05f, 5.857002906850539e-05f, 5.415391206042841e-05f, 7.007917156443e-05f, 0.00014140576240606606f, 2.993243106175214e-05f, 4.4524334953166544e-05f, 3.889459549100138e-05f, 2.392304304521531e-05f, 4.294675454730168e-05f, 4.2672276322264224e-05f, 4.368255758890882e-05f, 0.0001709156495053321f, 6.459897122113034e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000645100197289139f, 0.0019313277443870902f, 0.0026232434902340174f, 0.002090232679620385f, 0.0026250677183270454f, 0.0010853555286303163f, 0.0018203804502263665f, 0.0023025383707135916f, 0.0011964980512857437f, 0.0013622349360957742f, 0.001384657109156251f, 0.0010798751609399915f, 0.0015185968950390816f, 0.0026443020906299353f, 0.0014065095456317067f, 0.0014811721630394459f, 0.0016292895888909698f, 0.0016132473247125745f, 0.0012465260224416852f, 0.0022163570392876863f, 0.0015877129044383764f, 0.0012120819883421063f, 0.0014035952044650912f, 0.001074683852493763f, 0.0012929871445521712f, 0.004032669123262167f, 0.0011025292333215475f, 0.0008716454613022506f, 0.0012150848051533103f, 0.001308384002186358f, 0.001493913703598082f, 0.0015725941630080342f, 0.0017163649899885058f, 0.0035889979917556047f, 0.0026931087486445904f, 0.0013293253723531961f, 0.0018339056987315416f, 0.0018520848825573921f, 0.0012912516249343753f, 0.0010832292027771473f, 0.0031018818262964487f, 0.0014308940153568983f, 0.0012493942631408572f, 0.0013984090182930231f, 0.0037497191224247217f, 0.0016325979959219694f, 0.0014375377213582397f, 0.0012637339532375336f, 0.0011280309408903122f, 0.0007187538431026042f, 0.0015845956513658166f, 0.0019820830784738064f, 0.001832636189647019f, 0.0023715668357908726f, 0.004785347729921341f, 0.0010129509028047323f, 0.0015067592030391097f, 0.0013162418035790324f, 0.0008095857338048518f, 0.0014533719513565302f, 0.001444083172827959f, 0.0014782723737880588f, 0.005783999338746071f, 0.002186110010370612f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.55157374846749e-05f, 0.00022195714700501412f, 7.47662634239532e-05f, 0.00015984535275492817f, 0.00030450342455878854f, 3.878674397128634e-05f, 0.00012347422307357192f, 8.853046165313572e-05f, 0.00027052315999753773f, 0.00020965233852621168f, 0.0002587763301562518f, 0.00014517438830807805f, 0.00011112663196399808f, 9.221374057233334e-05f, 9.963092452380806e-05f, 0.0004964046529494226f, 0.00010638430103426799f, 0.00016890875122044235f, 4.686876491177827e-05f, 0.0001501841761637479f, 5.96829158894252e-05f, 0.000132998640765436f, 0.0001566943246871233f, 8.705292566446587e-05f, 7.69105608924292e-05f, 0.00014176047989167273f, 0.00011365054524503648f, 8.898136002244428e-05f, 9.199626947520301e-05f, 6.525839125970379e-05f, 5.8435289247427136e-05f, 0.00010441656922921538f, 0.00011165921023348346f, 8.554634405300021e-05f, 0.00015001572319306433f, 0.0001934066676767543f, 8.704364881850779e-05f, 6.671882147202268e-05f, 0.0005903413984924555f, 0.00012368826719466597f, 0.00010840847971849144f, 0.00010574159387033433f, 0.00011482851550681517f, 4.724967948277481e-05f, 0.00011673104745568708f, 7.311497029149905e-05f, 7.277807162608951e-05f, 9.68071399256587e-05f, 0.00010444168583489954f, 0.000257862382568419f, 0.00011991537758149207f, 6.678199861198664e-05f, 5.472254633787088e-05f, 0.0001869085244834423f, 0.00012039049761369824f, 6.359409599099308e-05f, 8.525849261786789e-05f, 0.00017829718126449734f, 4.497225017985329e-05f, 7.405709038721398e-05f, 3.985113653470762e-05f, 0.00010108746209880337f, 0.00016212269838433713f, 0.00016801197489257902f, 0.00010493601439520717f, 0.0001243998995050788f, 0.0001734781835693866f, 4.241123315296136e-05f, 7.891577843111008e-05f, 8.523553697159514e-05f, 0.00026290296227671206f, 0.00010781306627904996f, 0.00011064802674809471f, 0.0001100950175896287f, 0.00012069726653862745f, 5.666358265443705e-05f, 4.464718222152442e-05f, 0.0001589066960150376f, 5.128257907927036e-05f, 5.161616354598664e-05f, 0.0001434419391443953f, 9.036184201249853e-05f, 5.204181434237398e-05f, 0.0001576430950080976f, 8.388479909626767e-05f, 5.4934505897108465e-05f, 0.00010900160850724205f, 0.0001173708587884903f, 5.2275991038186476e-05f, 0.00023232742387335747f, 0.00011409068974899128f, 0.0001050021019182168f, 9.752115147421136e-05f, 6.24815293122083e-05f, 0.0001203431238536723f, 6.330667383736e-05f, 8.075149526121095e-05f, 1.9241166228312068e-05f, 8.59284118632786e-05f, 8.051705663092434e-05f, 8.137591794366017e-05f, 6.298638618318364e-05f, 7.966508565004915e-05f, 6.883659079903737e-05f, 0.00010003960778703913f, 6.350475450744852e-05f, 9.202727960655466e-05f, 4.830104444408789e-05f, 0.00011528033064678311f, 0.00011766959505621344f, 0.0006652599549852312f, 0.00017898560327012092f, 7.087193807819858e-05f, 0.00010446181840961799f, 0.00010558271605987102f, 0.00010665720765246078f, 6.758340168744326e-05f, 0.00022027846716810018f, 4.7782879846636206e-05f, 7.112596358638257e-05f, 0.00014241009193938226f, 3.80457604478579e-05f, 0.000175242152181454f, 0.00026747796800918877f, 2.07802040677052e-05f, 0.00016974781465251f, 3.952001497964375e-05f, 0.00011137813271488994f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005705069750547409f, 0.013257302343845367f, 0.004465722478926182f, 0.009547420777380466f, 0.018187718465924263f, 0.002316697733476758f, 0.007375005166977644f, 0.005287845619022846f, 0.016158107668161392f, 0.012522347271442413f, 0.015456479042768478f, 0.008671136572957039f, 0.006637494545429945f, 0.005507844500243664f, 0.005950866267085075f, 0.029649807140231133f, 0.0063542393036186695f, 0.010088768787682056f, 0.002799429465085268f, 0.008970366790890694f, 0.003564807353541255f, 0.007943890057504177f, 0.009359212592244148f, 0.0051995934918522835f, 0.004593799356371164f, 0.008467227220535278f, 0.006788245867937803f, 0.005314777139574289f, 0.005494855344295502f, 0.003897825488820672f, 0.003490287810564041f, 0.006236708723008633f, 0.006669305264949799f, 0.005109606776386499f, 0.008960305713117123f, 0.011552007868885994f, 0.005199039354920387f, 0.003985055722296238f, 0.03526056557893753f, 0.007387789897620678f, 0.006475141737610102f, 0.006315851118415594f, 0.006858604960143566f, 0.002822181209921837f, 0.006972241215407848f, 0.0043670921586453915f, 0.004346969537436962f, 0.0057822042144834995f, 0.006238208618015051f, 0.015401889570057392f, 0.007162438705563545f, 0.00398882944136858f, 0.003268528962507844f, 0.011163879185914993f, 0.0071908170357346535f, 0.003798418678343296f, 0.005092413630336523f, 0.010649532079696655f, 0.0026861524675041437f, 0.004423364065587521f, 0.002380272839218378f, 0.006037863902747631f, 0.009683444164693356f, 0.010035205632448196f, 0.006267734803259373f, 0.007430295459926128f, 0.010361697524785995f, 0.002533185062929988f, 0.004713569302111864f, 0.005091042723506689f, 0.015702959150075912f, 0.006439578253775835f, 0.00660890806466341f, 0.00657587731257081f, 0.007209140341728926f, 0.0033844653517007828f, 0.002666736487299204f, 0.009491355158388615f, 0.00306306267157197f, 0.0030829873867332935f, 0.008567659184336662f, 0.005397232249379158f, 0.003108411096036434f, 0.009415881708264351f, 0.005010364111512899f, 0.003281189128756523f, 0.006510568782687187f, 0.007010456640273333f, 0.0031223983969539404f, 0.013876710087060928f, 0.006814535241574049f, 0.006271681748330593f, 0.0058248513378202915f, 0.003731966018676758f, 0.007187987677752972f, 0.0037812513764947653f, 0.004823214840143919f, 0.00114925776142627f, 0.00513242743909359f, 0.004809211939573288f, 0.004860511049628258f, 0.003762120846658945f, 0.004758324474096298f, 0.0041115484200417995f, 0.005975276697427034f, 0.0037930821999907494f, 0.005496707279235125f, 0.0028849784284830093f, 0.0068855914287269115f, 0.0070282998494803905f, 0.03973538428544998f, 0.010690650902688503f, 0.004233117680996656f, 0.006239411421120167f, 0.00630636140704155f, 0.006370539776980877f, 0.004036696162074804f, 0.013157036155462265f, 0.0028540287166833878f, 0.0042482903227210045f, 0.008506027981638908f, 0.0022724394220858812f, 0.01046705711632967f, 0.01597622036933899f, 0.0012411830248311162f, 0.01013888604938984f, 0.0023604952730238438f, 0.006652516778558493f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.74391446611844e-05f, 8.164774044416845e-05f, 0.00010083235974889249f, 5.2474621043074876e-05f, 0.00011397023627068847f, 7.58078895159997e-05f, 7.910721615189686e-05f, 8.243780030170456e-05f, 4.731257286039181e-05f, 6.591524288523942e-05f, 0.0001086093470803462f, 6.56516567687504e-05f, 6.684893742203712e-05f, 8.06711905170232e-05f, 0.0001019137489493005f, 7.421681220876053e-05f, 8.043496200116351e-05f, 6.887117342557758e-05f, 8.115873788483441e-05f, 5.8594003348844126e-05f, 0.00010177787771681324f, 7.926593389129266e-05f, 6.063002365408465e-05f, 6.231851875782013e-05f, 0.00010220103285973892f, 9.133361891144887e-05f, 8.054376667132601e-05f, 0.0001252007350558415f, 5.8273712056688964e-05f, 6.846198084531352e-05f, 0.00011550718772923574f, 0.00010766249033622444f, 0.0001127488721976988f, 0.00010593212209641933f, 4.225310476613231e-05f, 9.707351273391396e-05f, 0.00012421674910001457f, 8.691880066180602e-05f, 7.795185229042545e-05f, 6.584565562661737e-05f, 6.311641482170671e-05f, 8.387478737859055e-05f, 0.00011803799134213477f, 6.995136936893687e-05f, 9.455921099288389e-05f, 5.807526031276211e-05f, 8.277492452180013e-05f, 8.954219811130315e-05f, 0.0001243313163286075f, 6.89731168677099e-05f, 7.655726949451491e-05f, 8.164926111930981e-05f, 8.745449304115027e-05f, 6.952801049919799e-05f, 0.0001020341005641967f, 8.420618542004377e-05f, 8.239664020948112e-05f, 9.023967868415639e-05f, 0.00010595105413813144f, 7.63408315833658e-05f, 7.811760588083416e-05f, 9.526046051178128e-05f, 8.316194725921378e-05f, 7.954489410622045e-05f, 9.82322744675912e-05f, 8.967422763817012e-05f, 3.5008601116715e-05f, 9.25472195376642e-05f, 0.00010206520528299734f, 9.051716915564612e-05f, 6.921055319253355e-05f, 7.608817395521328e-05f, 7.297631236724555e-05f, 6.282358663156629e-05f, 6.807340832892805e-05f, 9.144097566604614e-05f, 0.00010473398288013414f, 6.193105946294963e-05f, 7.708542398177087e-05f, 7.045984239084646e-05f, 6.740078242728487e-05f, 0.00012125405919505283f, 0.00010448110697325319f, 7.489848212571815e-05f, 8.939083636505529e-05f, 5.070831684861332e-05f, 0.00012242660159245133f, 7.358135189861059e-05f, 7.063426164677367e-05f, 5.2730392781086266e-05f, 9.488155046710745e-05f, 0.00010634002683218569f, 0.0001352372346445918f, 0.0001024804005282931f, 7.920442294562235e-05f, 0.00011702410847647116f, 9.060685988515615e-05f, 0.00013230660988483578f, 0.00010398371523479f, 0.00010300479334546253f, 0.00010642887355061248f, 8.931028423830867e-05f, 0.00011897801596205682f, 7.277089025592431e-05f, 6.34377938695252e-05f, 7.311928493436426e-05f, 0.00011765753879444674f, 0.00012125734065193683f, 0.00010901076893787831f, 8.99348669918254e-05f, 7.06590071786195e-05f, 5.5018703278619796e-05f, 0.0001160325700766407f, 7.098202331690118e-05f, 7.993618055479601e-05f, 0.00020036875503137708f, 7.28505983715877e-05f, 6.389433110598475e-05f, 0.00010432938870508224f, 6.499270966742188e-05f, 0.00012064993643434718f, 6.75002665957436e-05f, 7.001440098974854e-05f, 7.381398609140888e-05f, 5.680559843312949e-05f, 0.00010637572268024087f, 6.8262466811575e-05f, 6.945736822672188e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007857044693082571f, 0.0008284052601084113f, 0.0010230541229248047f, 0.0005324122030287981f, 0.0011563522275537252f, 0.0007691536447964609f, 0.0008026289287954569f, 0.0008364212699234486f, 0.0004800375900231302f, 0.0006687819841317832f, 0.0011019601952284575f, 0.0006661075749434531f, 0.000678255339153111f, 0.0008184971520677209f, 0.0010340260341763496f, 0.0007530103903263807f, 0.000816100335214287f, 0.0006987730739638209f, 0.0008234438137151301f, 0.0005944999866187572f, 0.001032647443935275f, 0.000804239243734628f, 0.0006151576526463032f, 0.000632289273198694f, 0.0010369408410042524f, 0.0009266790584661067f, 0.0008172043017111719f, 0.0012702979147434235f, 0.0005912503111176193f, 0.0006946214125491679f, 0.0011719462927430868f, 0.0010923532536253333f, 0.0011439601657912135f, 0.001074796775355935f, 0.00042870378820225596f, 0.0009849165799096227f, 0.0012603142531588674f, 0.0008818859350867569f, 0.0007909064879640937f, 0.0006680759252049029f, 0.000640384794678539f, 0.000851001066621393f, 0.0011976240202784538f, 0.000709732819814235f, 0.0009594061993993819f, 0.0005892367917113006f, 0.0008398417849093676f, 0.0009085031342692673f, 0.0012614766601473093f, 0.0006998074240982533f, 0.0007767569040879607f, 0.0008284207433462143f, 0.0008873211336322129f, 0.0007054373854771256f, 0.0010352471144869924f, 0.0008543634903617203f, 0.0008360036881640553f, 0.000915579847060144f, 0.0010749888606369495f, 0.0007745609036646783f, 0.0007925882237032056f, 0.0009665211546234787f, 0.000843768531922251f, 0.0008070695912465453f, 0.0009966734796762466f, 0.0009098427253775299f, 0.00035520040546543896f, 0.0009389923652634025f, 0.0010355627164244652f, 0.0009183952934108675f, 0.0007022164645604789f, 0.0007719974382780492f, 0.0007404242060147226f, 0.0006374137592501938f, 0.0006906788912601769f, 0.0009277682984247804f, 0.001062640338204801f, 0.0006283580441959202f, 0.0007821156177669764f, 0.0007148918812163174f, 0.0006838543922640383f, 0.0012302545364946127f, 0.0010600746609270573f, 0.0007599266828037798f, 0.0009069674415513873f, 0.0005144911119714379f, 0.0012421512510627508f, 0.0007465630187653005f, 0.0007166615105234087f, 0.0005350072751753032f, 0.0009626767132431269f, 0.0010789354564622045f, 0.0013721290742978454f, 0.0010397753212600946f, 0.0008036151411943138f, 0.0011873370967805386f, 0.0009193053119815886f, 0.001342394738458097f, 0.0010550280567258596f, 0.001045095850713551f, 0.0010798368602991104f, 0.0009061501477845013f, 0.0012071615783497691f, 0.0007383399643003941f, 0.0006436455296352506f, 0.0007418747991323471f, 0.0011937639210373163f, 0.0012302878312766552f, 0.0011060329852625728f, 0.0009124872158281505f, 0.0007169126183725893f, 0.0005582246812991798f, 0.0011772768339142203f, 0.0007201899425126612f, 0.0008110396447591484f, 0.0020329593680799007f, 0.0007391487015411258f, 0.0006482776370830834f, 0.0010585353011265397f, 0.0006594218430109322f, 0.001224125036969781f, 0.0006848637713119388f, 0.0007103723473846912f, 0.0007489233394153416f, 0.0005763546796515584f, 0.001079297624528408f, 0.0006925970665179193f, 0.0007047206745482981f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.75090661086142e-05f, 0.00010385656059952453f, 0.00015543692279607058f, 9.266536653740332e-05f, 0.00011287330562481657f, 0.00010691258648876101f, 7.602127880090848e-05f, 9.738140943227336e-05f, 9.512124233879149e-05f, 0.00011166299373144284f, 8.828188583720475e-05f, 0.00012584755313582718f, 0.00012113958655390888f, 0.0001294644025620073f, 9.391506318934262e-05f, 0.00012214899470563978f, 8.955100929597393e-05f, 0.0001122661997214891f, 0.00014763118815608323f, 9.39646633923985e-05f, 8.787564001977444e-05f, 9.05236738617532e-05f, 9.1345893451944e-05f, 0.00010457202006364241f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00415841257199645f, 0.004429110325872898f, 0.006628828123211861f, 0.003951846156269312f, 0.004813642241060734f, 0.004559439141303301f, 0.003242035396397114f, 0.004152968525886536f, 0.004056580364704132f, 0.004762026946991682f, 0.0037649061996489763f, 0.005366947501897812f, 0.005166169721633196f, 0.0055211931467056274f, 0.004005141090601683f, 0.0052092173136770725f, 0.003819029778242111f, 0.0047877514734864235f, 0.006295941770076752f, 0.004007256589829922f, 0.0037475815042853355f, 0.003860510652884841f, 0.003895575413480401f, 0.00445962231606245f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016861897893249989f, 0.0001379085297230631f, 0.00011223405454074964f, 6.89453590894118e-05f, 9.178562322631478e-05f, 0.0001409326505381614f, 0.00010997072968166322f, 0.00016761109873186797f, 7.20956886652857e-05f, 0.00025111218565143645f, 0.00011797501792898402f, 0.00020579210831783712f, 0.00010224732250208035f, 0.00015123403863981366f, 0.00014522983110509813f, 8.890598837751895e-05f, 0.00015618903853464872f, 0.00013618743105325848f, 0.00010283858864568174f, 9.009814675664529e-05f, 0.00010559375368757173f, 9.541574399918318e-05f, 9.346014121547341e-05f, 0.00019429421809036285f, 8.497755334246904e-05f, 0.00016767556371632963f, 0.0001103491522371769f, 0.0001630581682547927f, 0.00017890955496113747f, 8.856879139784724e-05f, 0.00012810331827495247f, 6.310849857982248e-05f, 0.000216243919567205f, 0.0001466642861487344f, 0.0003010568907484412f, 0.00012276349298190325f, 0.00012123096530558541f, 8.96974524948746e-05f, 0.00014674998237751424f, 0.00022365024778991938f, 0.00010142925748368725f, 8.338180487044156e-05f, 0.00013792501704301685f, 0.0001102637907024473f, 0.00030686415266245604f, 8.761700883042067e-05f, 9.018821583595127e-05f, 7.085148536134511e-05f, 0.00021401567209977657f, 0.00010209826723439619f, 6.037286948412657e-05f, 0.00010789124644361436f, 9.484546899329871e-05f, 0.00011022376565961167f, 9.675342153059319e-05f, 0.00011149405327159911f, 8.859345689415932e-05f, 7.378708687610924e-05f, 0.0001217880126205273f, 0.0001542699319543317f, 7.282612205017358e-05f, 0.00015302997780963778f, 8.718548633623868e-05f, 0.00015648808039259166f, 0.00014631697558797896f, 0.0003248223219998181f, 0.0001409476826665923f, 0.0002539495180826634f, 0.00012721655366476625f, 6.949195812921971e-05f, 0.00011956423259107396f, 0.00013958544877823442f, 0.0001546932035125792f, 7.604176789755002e-05f, 0.00015224756498355418f, 6.31986913504079e-05f, 8.700926264282316e-05f, 0.0001771206734701991f, 0.0001195648146676831f, 0.00018529764201957732f, 0.00013459018373396248f, 0.00010858003224711865f, 0.00020691793179139495f, 0.0001891024294309318f, 0.00014536024536937475f, 0.00011388298298697919f, 0.00018131107208319008f, 0.00010622564877849072f, 0.00024104476324282587f, 0.0001701728324405849f, 0.00027381718973629177f, 9.38460070756264e-05f, 0.00012694057659246027f, 0.00010165191633859649f, 0.00018710813310462981f, 8.997838449431583e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010307547636330128f, 0.008430241607129574f, 0.006860780995339155f, 0.004214576445519924f, 0.0056107840500772f, 0.008615103550255299f, 0.006722425576299429f, 0.010245936922729015f, 0.004407153464853764f, 0.01535029336810112f, 0.0072117215022444725f, 0.012579912319779396f, 0.006250299513339996f, 0.009244820103049278f, 0.008877786807715893f, 0.005434754304587841f, 0.009547715075314045f, 0.008325031958520412f, 0.0062864432111382484f, 0.005507629830390215f, 0.006454864516854286f, 0.005832690745592117f, 0.0057131461799144745f, 0.011877055279910564f, 0.005194611847400665f, 0.010249877348542213f, 0.0067455582320690155f, 0.009967619553208351f, 0.01093660295009613f, 0.005414141807705164f, 0.007830856367945671f, 0.0038577737286686897f, 0.013218823820352554f, 0.008965474553406239f, 0.018403375521302223f, 0.007504437584429979f, 0.007410754915326834f, 0.005483136046677828f, 0.00897071324288845f, 0.013671566732227802f, 0.006200292147696018f, 0.00509706512093544f, 0.008431249298155308f, 0.006740340031683445f, 0.018758367747068405f, 0.0053559597581624985f, 0.005513135809451342f, 0.004331096541136503f, 0.013082612305879593f, 0.006241187918931246f, 0.0036905468441545963f, 0.006595308426767588f, 0.005797829944640398f, 0.00673789344727993f, 0.005914461798965931f, 0.0068155452609062195f, 0.005415649618953466f, 0.004510547500103712f, 0.0074448068626224995f, 0.00943040195852518f, 0.004451804328709841f, 0.00935460440814495f, 0.005329581443220377f, 0.009565995074808598f, 0.00894424319267273f, 0.019856136292219162f, 0.008616022765636444f, 0.015523738227784634f, 0.0077766492031514645f, 0.004247989505529404f, 0.007308869156986475f, 0.00853275042027235f, 0.009456275962293148f, 0.004648374393582344f, 0.009306775406002998f, 0.0038632871583104134f, 0.0053188088349998f, 0.010827249847352505f, 0.00730890454724431f, 0.011327101849019527f, 0.008227393962442875f, 0.0066374135203659534f, 0.012648733332753181f, 0.01155968476086855f, 0.008885758928954601f, 0.006961578503251076f, 0.011083405464887619f, 0.0064934915862977505f, 0.014734880067408085f, 0.01040253322571516f, 0.016738232225179672f, 0.005736733786761761f, 0.00775977922603488f, 0.006213902961462736f, 0.011437775567173958f, 0.00550030916929245f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001195753357023932f, 8.854256884660572e-05f, 7.806602661730722e-05f, 0.00010953636228805408f, 0.0001099928340408951f, 0.00010204875434283167f, 7.70126425777562e-05f, 6.22193911112845e-05f, 8.912968769436702e-05f, 0.00012050529767293483f, 0.00012285054253879935f, 0.00010587384167592973f, 6.0658028814941645e-05f, 7.746205665171146e-05f, 8.568878547521308e-05f, 8.777801122050732e-05f, 6.741610559402034e-05f, 0.000112916313810274f, 8.562907896703109e-05f, 8.203214383684099e-05f, 9.684657561592758e-05f, 8.520328992744908e-05f, 6.977886368986219e-05f, 8.981268183561042e-05f, 7.58709356887266e-05f, 9.730886085890234e-05f, 0.00010548465070314705f, 7.188624294940382e-05f, 7.618407835252583e-05f, 8.685711509315297e-05f, 7.504606037400663e-05f, 7.57996822358109e-05f, 7.836947770556435e-05f, 7.309336069738492e-05f, 7.889047992648557e-05f, 8.562752918805927e-05f, 7.111703598638996e-05f, 7.487178663723171e-05f, 6.517104338854551e-05f, 6.106777436798438e-05f, 7.518036727560684e-05f, 9.260496153729036e-05f, 9.079302253667265e-05f, 5.8341771364212036e-05f, 4.745612750411965e-05f, 8.137062104651704e-05f, 6.644611130468547e-05f, 0.00010962457599816844f, 6.346752343233675e-05f, 7.641144475201145e-05f, 0.00013190993922762573f, 8.526002056896687e-05f, 0.00010206917067989707f, 6.36082113487646e-05f, 7.327876664930955e-05f, 0.00010098008351633325f, 8.174542745109648e-05f, 7.80781265348196e-05f, 0.0001007898390525952f, 8.60114159877412e-05f, 7.23508492228575e-05f, 0.00011810437717940658f, 9.67207015492022e-05f, 9.95904701994732e-05f, 8.378020720556378e-05f, 6.408803892554715e-05f, 6.0908019804628566e-05f, 6.199134077178314e-05f, 7.475475285900757e-05f, 8.71606171131134e-05f, 6.795742956455797e-05f, 8.786536636762321e-05f, 9.80728364083916e-05f, 6.742153345840052e-05f, 6.773018685635179e-05f, 6.355856021400541e-05f, 8.976289245765656e-05f, 0.0001331488019786775f, 8.400298975175247e-05f, 6.493733235402033e-05f, 4.873696525464766e-05f, 0.00010566577839199454f, 0.00010511156870052218f, 7.877941243350506e-05f, 8.508452447131276e-05f, 4.117421849514358e-05f, 9.352623601444066e-05f, 9.533193951938301e-05f, 5.83332366659306e-05f, 6.109020614530891e-05f, 8.538278780179098e-05f, 6.759657844668254e-05f, 0.00010970769653795287f, 8.152842201525345e-05f, 9.519812738290057e-05f, 7.019774784566835e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00207576178945601f, 0.0015370501205325127f, 0.0013551830779761076f, 0.0019014907302334905f, 0.0019094148883596063f, 0.0017715099966153502f, 0.0013368969084694982f, 0.0010800942545756698f, 0.001547242165543139f, 0.0020919053349643946f, 0.002132617635652423f, 0.0018379114335402846f, 0.0010529898572713137f, 0.0013446984812617302f, 0.001487509929575026f, 0.0015237777261063457f, 0.0011703063501045108f, 0.0019601648673415184f, 0.0014864734839648008f, 0.0014240327291190624f, 0.0016812030225992203f, 0.001479082042351365f, 0.0012113224947825074f, 0.0015590984839946032f, 0.001317077549174428f, 0.00168922811280936f, 0.0018311552703380585f, 0.0012479054275900126f, 0.0013225135626271367f, 0.001507791574113071f, 0.0013027581153437495f, 0.0013158406363800168f, 0.0013604508712887764f, 0.0012688604183495045f, 0.001369495177641511f, 0.0014864465920254588f, 0.0012345524737611413f, 0.001299732830375433f, 0.0011313332943245769f, 0.0010601028334349394f, 0.0013050896814092994f, 0.0016075709136202931f, 0.0015761166578158736f, 0.001012780936434865f, 0.0008238121517933905f, 0.0014125490561127663f, 0.0011534678051248193f, 0.001903022057376802f, 0.0011017611250281334f, 0.001326460507698357f, 0.00228988379240036f, 0.001480066915974021f, 0.0017718643648549914f, 0.0011042034020647407f, 0.0012720789527520537f, 0.0017529584001749754f, 0.0014190555084496737f, 0.0013553930912166834f, 0.001749655930325389f, 0.0014931106707081199f, 0.0012559707975015044f, 0.0020502267871052027f, 0.0016790179070085287f, 0.001728835515677929f, 0.0014543781289830804f, 0.0011125329183414578f, 0.0010573295876383781f, 0.001076135435141623f, 0.0012977012665942311f, 0.0015130601823329926f, 0.001179703394882381f, 0.0015252942685037851f, 0.0017024902626872063f, 0.0011704005300998688f, 0.0011757586617022753f, 0.001103341463021934f, 0.00155823421664536f, 0.002311389660462737f, 0.0014582454459741712f, 0.0011272762203589082f, 0.0008460467797704041f, 0.0018342995317652822f, 0.0018246787367388606f, 0.0013675671070814133f, 0.00147702032700181f, 0.000714761670678854f, 0.0016235638177022338f, 0.0016549098072573543f, 0.0010126327397301793f, 0.0010604922426864505f, 0.0014821980148553848f, 0.0011734392028301954f, 0.0019044650252908468f, 0.001415288308635354f, 0.0016525868559256196f, 0.0012185941450297832f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.9811369283124804e-05f, 5.0595182983670384e-05f, 7.42521951906383e-05f, 7.48948659747839e-05f, 6.21292638243176e-05f, 4.6766486775595695e-05f, 5.030534521210939e-05f, 5.263060666038655e-05f, 4.798185545951128e-05f, 6.173075234983116e-05f, 6.167194806039333e-05f, 6.410271453205496e-05f, 7.185223512351513e-05f, 5.819028592668474e-05f, 5.8745627029566094e-05f, 5.283673090161756e-05f, 7.381054456345737e-05f, 5.333556327968836e-05f, 6.366229354171082e-05f, 6.196703179739416e-05f, 4.85668788314797e-05f, 4.842972703045234e-05f, 7.293716043932363e-05f, 4.0143528167391196e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003203641390427947f, 0.0027100001461803913f, 0.003977126907557249f, 0.004011549986898899f, 0.0033277934417128563f, 0.0025049259420484304f, 0.0026944756973534822f, 0.002819022396579385f, 0.0025700239930301905f, 0.003306447993963957f, 0.003303298493847251f, 0.0034334962256252766f, 0.0038485792465507984f, 0.003116812091320753f, 0.003146557603031397f, 0.002830062760040164f, 0.003953470848500729f, 0.0028567814733833075f, 0.00340990605764091f, 0.0033191039692610502f, 0.002601359272375703f, 0.002594012999907136f, 0.003906690515577793f, 0.00215018424205482f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016143427637871355f, 7.16252252459526e-05f, 8.27497206046246e-05f, 0.0001625523582333699f, 0.00010692051728256047f, 8.02158028818667e-05f, 0.00014065959840081632f, 8.546738536097109e-05f, 0.00017137006216216832f, 9.691760351415724e-05f, 0.00016943366790656f, 0.0001455537130823359f, 0.00011833268945338205f, 0.00010742822632892057f, 0.00010027665848610923f, 9.089017839869484e-05f, 0.00020603353914339095f, 0.00012492240057326853f, 0.00032594776712358f, 0.000106519837572705f, 0.00010041491623269394f, 0.0001545514678582549f, 9.153794235317037e-05f, 0.0001090138393919915f, 0.0001583584089530632f, 0.0001997082872549072f, 0.00012008862540824339f, 7.87364479037933e-05f, 0.00014425271365325898f, 0.00012407940812408924f, 0.00012937842984683812f, 0.00010445476800668985f, 0.00015833637735340744f, 0.00012756483920384198f, 0.00010460075282026082f, 0.00012448853522073478f, 0.0001854805595939979f, 0.0001300162257393822f, 8.633320976514369e-05f, 0.0001993651530938223f, 0.00010534141620155424f, 0.00011941741104237735f, 0.00016766494081821293f, 0.00013672534259967506f, 0.00012525335478130728f, 0.00012493816029746085f, 0.00018946519412565976f, 0.00014625849144067615f, 0.00016437930753454566f, 0.00021782882686238736f, 7.323536556214094e-05f, 0.00010395063873147592f, 0.00012128936941735446f, 0.0001837368035921827f, 0.00014883934636600316f, 7.238604302983731e-05f, 0.00010362241300754249f, 0.0001726991031318903f, 0.00012924960174132138f, 5.603871977655217e-05f, 0.00011311862908769399f, 0.00012343267735559493f, 7.446942618116736e-05f, 0.00010877405293285847f, 0.00011419132351875305f, 0.0001719808642519638f, 9.902370220515877e-05f, 9.441395377507433e-05f, 0.00015997646551113576f, 0.00014449248556047678f, 0.00020075266365893185f, 0.0001466888061258942f, 0.00021150564134586602f, 0.00010009175457525998f, 8.940775296650827e-05f, 0.00013860748731531203f, 0.00012645013339351863f, 0.00012542797776404768f, 0.00012211702414788306f, 0.00016915384912863374f, 9.980955655919388e-05f, 0.00010541269148234278f, 9.822878200793639e-05f, 9.054709516931325e-05f, 7.65760923968628e-05f, 0.00014946874580346048f, 7.153790647862479e-05f, 0.0001199079051730223f, 0.0001981949171749875f, 7.280142017407343e-05f, 8.667425572639331e-05f, 0.00012721701932605356f, 0.00018367389566265047f, 9.35450370889157e-05f, 0.00013365899212658405f, 0.0001561077660880983f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010352563112974167f, 0.0045932293869555f, 0.005306628532707691f, 0.010424264706671238f, 0.006856669206172228f, 0.00514413183555007f, 0.009020310826599598f, 0.005480908788740635f, 0.01098973210901022f, 0.006215195637196302f, 0.01086555328220129f, 0.00933416374027729f, 0.00758851645514369f, 0.006889227777719498f, 0.0064306072890758514f, 0.005828665103763342f, 0.013212653808295727f, 0.008011105470359325f, 0.020902592688798904f, 0.006830974016338587f, 0.006439473945647478f, 0.009911177679896355f, 0.005870205350220203f, 0.0069909109733998775f, 0.010155311785638332f, 0.012807024642825127f, 0.00770112220197916f, 0.005049262661486864f, 0.009250733070075512f, 0.007957045920193195f, 0.008296865038573742f, 0.0066985441371798515f, 0.01015389896929264f, 0.008180561475455761f, 0.006707905791699886f, 0.007983282208442688f, 0.011894619092345238f, 0.00833776593208313f, 0.005536432843655348f, 0.012785019353032112f, 0.006755403708666563f, 0.007658078335225582f, 0.010752127505838871f, 0.008768012747168541f, 0.008032329380512238f, 0.008012116886675358f, 0.01215014886111021f, 0.00937936082482338f, 0.01054142415523529f, 0.01396907027810812f, 0.004696485586464405f, 0.006666214670985937f, 0.007778124418109655f, 0.011782794259488583f, 0.00954486709088087f, 0.004642019513994455f, 0.00664516631513834f, 0.01107496116310358f, 0.008288603276014328f, 0.0035936878994107246f, 0.007254145573824644f, 0.007915572263300419f, 0.004775624256581068f, 0.006975533906370401f, 0.0073229363188147545f, 0.011028901673853397f, 0.006350256968289614f, 0.006054640281945467f, 0.01025907602161169f, 0.009266109205782413f, 0.01287399884313345f, 0.009406955912709236f, 0.01356357242912054f, 0.006418749690055847f, 0.005733598954975605f, 0.008888712152838707f, 0.008109076879918575f, 0.008043527603149414f, 0.007831200957298279f, 0.010847609490156174f, 0.0064006526954472065f, 0.0067599741742014885f, 0.006299280095845461f, 0.005806663539260626f, 0.004910721909254789f, 0.009585229679942131f, 0.004587629809975624f, 0.007689532823860645f, 0.012709974311292171f, 0.004668657202273607f, 0.00555830355733633f, 0.00815825629979372f, 0.011778760701417923f, 0.005998917389661074f, 0.00857137143611908f, 0.010010981000959873f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.4002186516299844e-05f, 0.00012663521920330822f, 9.983502968680114e-05f, 9.408522601006553e-05f, 0.00013123232929501683f, 9.513846453046426e-05f, 0.00011735910084098577f, 0.0001144426641985774f, 8.53422170621343e-05f, 7.723436283413321e-05f, 0.000113469926873222f, 7.854447903810069e-05f, 0.00011073983478127047f, 0.0001014942245092243f, 0.0001286791666643694f, 8.023789996514097e-05f, 8.901411638362333e-05f, 7.316038681892678e-05f, 8.343209628947079e-05f, 0.00011248010559938848f, 0.00019138182688038796f, 6.929762457730249e-05f, 0.00013686019519809633f, 9.595930896466598e-05f, 0.00010825878416653723f, 9.773336932994425e-05f, 9.110368409892544e-05f, 7.430098776239902e-05f, 0.00012118953600293025f, 7.024320802884176e-05f, 0.0001613227213965729f, 0.00010848257079487666f, 9.653922461438924e-05f, 7.600727258250117e-05f, 9.589867113390937e-05f, 8.765835082158446e-05f, 8.883756527211517e-05f, 0.00011999653361272067f, 0.00012906064512208104f, 6.477597344201058e-05f, 0.00010387801739852875f, 7.31172040104866e-05f, 0.00011533697397680953f, 8.252227416960523e-05f, 5.0012087740469724e-05f, 0.0001155512873083353f, 9.436649270355701e-05f, 9.203250374412164e-05f, 8.48738563945517e-05f, 0.00010761729208752513f, 0.00011840413935715333f, 0.0001264374441234395f, 8.932004129746929e-05f, 8.108020847430453e-05f, 0.00010436905722599477f, 7.132776954676956e-05f, 0.00015188792895060033f, 0.00010899432527367026f, 0.00011594135139603168f, 0.00015957100549712777f, 0.00011632448149612173f, 0.000126036029541865f, 7.758332503726706e-05f, 9.98569157673046e-05f, 8.610080112703145e-05f, 9.755104110809043e-05f, 0.00013905897503718734f, 0.00011019282101187855f, 0.00010692834621295333f, 9.206518006976694e-05f, 8.285482181236148e-05f, 8.71896991156973e-05f, 7.307752093765885e-05f, 0.00010804324847413227f, 0.0001075024192687124f, 8.062181586865336e-05f, 9.388583566760644e-05f, 0.0001388248201692477f, 0.00012511960812844336f, 7.80522168497555e-05f, 9.278190555050969e-05f, 0.0001066129480022937f, 7.038727926556021e-05f, 0.00011134173109894618f, 0.00011281872139079496f, 0.00010510587890166789f, 0.00012775207869708538f, 7.775062840664759e-05f, 0.00010536819172557443f, 0.00011379268107702956f, 9.583905921317637e-05f, 0.00010308079072274268f, 4.990777961211279e-05f, 0.00013841065810993314f, 9.301667887484655e-05f, 0.00013644200225826353f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010152057511731982f, 0.0023806593380868435f, 0.0018768331501632929f, 0.0017687405925244093f, 0.002467081882059574f, 0.0017885408597066998f, 0.0022062743082642555f, 0.0021514471154659986f, 0.0016043777577579021f, 0.00145195540972054f, 0.00213316036388278f, 0.0014765848172828555f, 0.0020818363409489393f, 0.0019080250058323145f, 0.0024190840777009726f, 0.0015084199840202928f, 0.001673407037742436f, 0.0013753673993051052f, 0.0015684687532484531f, 0.002114552306011319f, 0.0035978530067950487f, 0.0013027499662712216f, 0.0025728819891810417f, 0.0018039721762761474f, 0.0020351943094283342f, 0.0018373234197497368f, 0.0017126896418631077f, 0.0013968099374324083f, 0.0022782839369028807f, 0.001320526353083551f, 0.003032761625945568f, 0.002039401326328516f, 0.0018148742383345962f, 0.0014288868987932801f, 0.001802832237444818f, 0.0016479195328429341f, 0.00167008803691715f, 0.002255856292322278f, 0.0024262554943561554f, 0.0012177458265796304f, 0.0019528387347236276f, 0.0013745555188506842f, 0.002168259583413601f, 0.0015513646649196744f, 0.0009401945280842483f, 0.0021722884848713875f, 0.0017740282928571105f, 0.0017301507759839296f, 0.0015955729177221656f, 0.0020231346134096384f, 0.0022259203251451254f, 0.002376941265538335f, 0.001679158303886652f, 0.0015242547960951924f, 0.0019620698876678944f, 0.0013409153325483203f, 0.0028553935699164867f, 0.002049021888524294f, 0.002179621485993266f, 0.0029998302925378084f, 0.0021868241019546986f, 0.0023693947587162256f, 0.0014585156459361315f, 0.001877244678325951f, 0.0016186387510970235f, 0.0018338956870138645f, 0.0026142175775021315f, 0.002071552909910679f, 0.0020101829431951046f, 0.0017307650996372104f, 0.0015576164005324244f, 0.0016391092212870717f, 0.0013738095294684172f, 0.002031142357736826f, 0.0020209751091897488f, 0.0015156373847275972f, 0.0017649922519922256f, 0.0026098156813532114f, 0.002352166688069701f, 0.001467330614104867f, 0.0017442391254007816f, 0.002004253678023815f, 0.0013232347555458546f, 0.0020931516773998737f, 0.0021209181286394596f, 0.001975921681150794f, 0.0024016553070396185f, 0.0014616608386859298f, 0.001980853034183383f, 0.0021392279304564f, 0.0018017115071415901f, 0.001937851426191628f, 0.0009382335701957345f, 0.002602029824629426f, 0.0017486526630818844f, 0.002565020229667425f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.024250640417449e-05f, 9.344821592094377e-05f, 6.092321564210579e-05f, 9.152264101430774e-05f, 7.958582864375785e-05f, 8.781056385487318e-05f, 5.2055107516935095e-05f, 7.013938011368737e-05f, 5.88026741752401e-05f, 8.478058589389548e-05f, 0.00010590232704998925f, 6.842381117166951e-05f, 8.277109736809507e-05f, 6.695078627672046e-05f, 7.946132245706394e-05f, 7.76420347392559e-05f, 5.783827509731054e-05f, 7.200668915174901e-05f, 0.00010179558739764616f, 6.71152665745467e-05f, 5.594771573669277e-05f, 7.466384704457596e-05f, 8.566875476390123e-05f, 9.975978173315525e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0019412441179156303f, 0.0036106042098253965f, 0.002353919902816415f, 0.003536204807460308f, 0.0030749961733818054f, 0.003392779268324375f, 0.002011278411373496f, 0.002710009226575494f, 0.002271987497806549f, 0.0032757085282355547f, 0.004091799724847078f, 0.0026437239721417427f, 0.0031980671919882298f, 0.002586809918284416f, 0.003070185659453273f, 0.0029998929239809513f, 0.0022347255144268274f, 0.002782157389447093f, 0.003933125641196966f, 0.0025931652635335922f, 0.0021616790909320116f, 0.002884823363274336f, 0.003310025203973055f, 0.0038544670678675175f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001148455121438019f, 0.00010493098670849577f, 0.00028376109548844397f, 0.0002594784600660205f, 0.00018809606262948364f, 0.00016497919568791986f, 0.00016482154023833573f, 0.00029008169076405466f, 0.0002633999101817608f, 0.00020689029770437628f, 0.00014560969430021942f, 0.0002936243254225701f, 0.00017554356600157917f, 0.00036791732418350875f, 0.00019979650096502155f, 0.0002107948821503669f, 0.0001880983036244288f, 0.00029666448244825006f, 0.00014790728164371103f, 0.0002874053898267448f, 0.0003507148358039558f, 0.0003067112702410668f, 0.00020339252660050988f, 0.00016541575314477086f, 0.00015802046982571483f, 0.00013746462354902178f, 0.00013466060045175254f, 0.00013016402954235673f, 0.00026892515597864985f, 0.00012621282075997442f, 0.00014038589142728597f, 0.0001966424024431035f, 0.00014142182772047818f, 0.00037503259954974055f, 0.00015120192256290466f, 0.00022644274577032775f, 0.0001854708098107949f, 0.00020710876560769975f, 0.0002922351995948702f, 0.00021681439829990268f, 0.00017456221394240856f, 0.00012257747584953904f, 0.0002366519474890083f, 0.00022785499459132552f, 0.00022708043979946524f, 0.0002784336684271693f, 0.00012815326044801623f, 0.00018487524357624352f, 0.0003138651663903147f, 0.00023193798551801592f, 0.00011052785703213885f, 0.00032993574859574437f, 0.0002205063501605764f, 0.00026683619944378734f, 0.00013774920080322772f, 0.0003613865119405091f, 0.0004010486591141671f, 0.0003120419569313526f, 0.0002834381302818656f, 0.00012373639037832618f, 0.0001919394708238542f, 0.00030540168518200517f, 0.00023083503765519708f, 0.00013362598838284612f, 0.00021163802011869848f, 0.00018645511590875685f, 0.00032353875576518476f, 0.00024951400700956583f, 0.00028667779406532645f, 0.0001961390662472695f, 0.0002661286562215537f, 0.0004217491368763149f, 0.00014773178554605693f, 0.00030911495559848845f, 0.0002713064895942807f, 0.00020098873937968165f, 0.00022879916650708765f, 0.0002854068297892809f, 0.000317600293783471f, 0.00028709202888421714f, 0.0002101750287692994f, 0.00023047449940349907f, 0.00021666915563400835f, 0.0002767567348200828f, 0.00019023488857783377f, 0.00015215719758998603f, 0.00024319383373949677f, 0.0003843323793262243f, 0.00018705020193010569f, 0.00037824679748155177f, 0.0001824117061914876f, 0.0003576079325284809f, 0.00029064289992675185f, 0.00010167871369048953f, 0.0002610415976960212f, 0.0002550815115682781f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0044066463597118855f, 0.0040262239053845406f, 0.010887973010540009f, 0.009956242516636848f, 0.007217285223305225f, 0.006330286152660847f, 0.006324237212538719f, 0.011130494996905327f, 0.010106709785759449f, 0.007938424125313759f, 0.005587074439972639f, 0.011266427114605904f, 0.006735643371939659f, 0.014117064885795116f, 0.00766623392701149f, 0.008088244125247002f, 0.007217371370643377f, 0.011383078061044216f, 0.00567523343488574f, 0.011027805507183075f, 0.013457002118229866f, 0.011768575757741928f, 0.007804214023053646f, 0.006347036920487881f, 0.006063278764486313f, 0.005274546332657337f, 0.005166955292224884f, 0.004994421266019344f, 0.010318714193999767f, 0.0048428126610815525f, 0.00538663612678647f, 0.007545210421085358f, 0.005426385439932346f, 0.01439007930457592f, 0.005801649764180183f, 0.00868865568190813f, 0.0071165538392961025f, 0.007946806959807873f, 0.01121312566101551f, 0.00831921398639679f, 0.006697988603264093f, 0.004703323356807232f, 0.009080384857952595f, 0.008742843754589558f, 0.008713124319911003f, 0.010683557949960232f, 0.004917267244309187f, 0.0070937019772827625f, 0.01204307284206152f, 0.008899508975446224f, 0.0042409771122038364f, 0.012659703381359577f, 0.008460874669253826f, 0.01023856084793806f, 0.005285465624183416f, 0.013866475783288479f, 0.01538832113146782f, 0.011973115615546703f, 0.010875580832362175f, 0.004747791215777397f, 0.00736475782468915f, 0.01171832624822855f, 0.008857188746333122f, 0.005127257201820612f, 0.00812059547752142f, 0.007154321763664484f, 0.01241424959152937f, 0.009573904797434807f, 0.010999887250363827f, 0.007525897119194269f, 0.01021141279488802f, 0.01618260331451893f, 0.005668499507009983f, 0.011860805563628674f, 0.010410087183117867f, 0.007711980026215315f, 0.0087790722027421f, 0.010951120406389236f, 0.012186390347778797f, 0.011015781201422215f, 0.008064460009336472f, 0.008843354880809784f, 0.00831364095211029f, 0.010619213804602623f, 0.007299352437257767f, 0.005838303826749325f, 0.009331398643553257f, 0.014746914617717266f, 0.007177155464887619f, 0.0145134087651968f, 0.006999175529927015f, 0.01372149121016264f, 0.011152029037475586f, 0.003901433665305376f, 0.01001622062176466f, 0.00978753063827753f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011582743900362402f, 0.00011694728891598061f, 7.068464765325189e-05f, 0.00010560313239693642f, 9.46235959418118e-05f, 8.627224451629445e-05f, 0.00010523939272388816f, 0.00011573482333915308f, 6.496754213003442e-05f, 5.585668623098172e-05f, 0.00010390621901024133f, 8.240602619480342e-05f, 9.744850103743374e-05f, 0.00012133561540395021f, 0.00013378671428654343f, 9.437205881113186e-05f, 0.00011584642197703943f, 9.973900887416676e-05f, 0.00013045189552940428f, 0.00013736620894633234f, 8.854862244334072e-05f, 0.00010619826934998855f, 0.00010725301399361342f, 0.00014787953114137053f, 0.00012288472498767078f, 0.00014573019871022552f, 9.791830234462395e-05f, 0.00011672058462863788f, 8.668298687553033e-05f, 7.750610529910773e-05f, 8.111724309856072e-05f, 0.00011346022074576467f, 8.502438140567392e-05f, 0.00012016981054330245f, 0.00012559584865812212f, 9.124108328251168e-05f, 9.441951988264918e-05f, 8.31860161270015e-05f, 8.517901005689055e-05f, 0.0001127467694459483f, 0.00012160211917944252f, 0.00016221837722696364f, 8.935186633607373e-05f, 0.00012435539974831045f, 8.660033199703321e-05f, 4.97874898428563e-05f, 5.023166522732936e-05f, 0.0001351302780676633f, 9.834660886554047e-05f, 8.671847899677232e-05f, 0.00011825847468571737f, 6.161675264593214e-05f, 8.088245522230864e-05f, 9.324299753643572e-05f, 0.00017078660312108696f, 0.00012810024782083929f, 7.147476571844891e-05f, 6.990905239945278e-05f, 8.536629320587963e-05f, 0.00013635247887577862f, 0.00013422025949694216f, 0.00011854367039632052f, 8.565513417124748e-05f, 0.0001104033290175721f, 7.860996265662834e-05f, 0.00013821625907439739f, 6.510925595648587e-05f, 5.8345511206425726e-05f, 9.409966878592968e-05f, 0.00013224678696133196f, 0.0001084053292288445f, 5.5075033742468804e-05f, 9.730087185744196e-05f, 7.251183706102893e-05f, 9.556854638503864e-05f, 0.00011509376054164022f, 0.00012126123328926042f, 6.031058728694916e-05f, 7.024073420325294e-05f, 7.022365025477484e-05f, 8.062406413955614e-05f, 7.695281965425238e-05f, 7.790275412844494e-05f, 8.497591625200585e-05f, 9.775007492862642e-05f, 0.00012956450518686324f, 8.757400064496323e-05f, 0.00011182844900758937f, 0.0001556014467496425f, 5.323787627276033e-05f, 0.00011837089550681412f, 5.3395684517454356e-05f, 0.00012191564019303769f, 0.0001554335467517376f, 0.00012626311217900366f, 9.570008842274547e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002660926664248109f, 0.002686653286218643f, 0.0016238524112850428f, 0.002426041755825281f, 0.0021738065406680107f, 0.001981949433684349f, 0.0024176854640245438f, 0.0026587990578264f, 0.0014925121795386076f, 0.001283206744119525f, 0.002387058222666383f, 0.0018931300146505237f, 0.0022387036588042974f, 0.0027874670922756195f, 0.0030735088512301445f, 0.0021680279169231653f, 0.0026613627560436726f, 0.002291324082762003f, 0.0029968973249197006f, 0.0031557411421090364f, 0.0020342450588941574f, 0.00243971380405128f, 0.002463944721966982f, 0.0033972659148275852f, 0.0028230552561581135f, 0.003347888821735978f, 0.0022494965232908726f, 0.0026814450975507498f, 0.0019913853611797094f, 0.0017805630341172218f, 0.0018635224550962448f, 0.002606544177979231f, 0.0019532819278538227f, 0.0027606848161667585f, 0.0028853381518274546f, 0.0020960995461791754f, 0.0021691182628273964f, 0.0019110487774014473f, 0.00195683422498405f, 0.002590153831988573f, 0.0027935896068811417f, 0.0037266749422997236f, 0.002052698051556945f, 0.0028568413108587265f, 0.001989486627280712f, 0.0011437778593972325f, 0.0011539820116013288f, 0.003104374511167407f, 0.0022593361791223288f, 0.0019922007340937853f, 0.0027167752850800753f, 0.001415533828549087f, 0.0018581287004053593f, 0.0021420898847281933f, 0.003923514392226934f, 0.0029428722336888313f, 0.0016420040046796203f, 0.001606034580618143f, 0.0019611367024481297f, 0.003132452489808202f, 0.003083468647673726f, 0.002723327139392495f, 0.001967772375792265f, 0.002536317566409707f, 0.0018059222493320704f, 0.003175269579514861f, 0.0014957678504288197f, 0.0013403829652816057f, 0.002161770360544324f, 0.003038131631910801f, 0.0024904171004891396f, 0.0012652496807277203f, 0.002235312247648835f, 0.0016658288659527898f, 0.00219551520422101f, 0.0026440718211233616f, 0.0027857583481818438f, 0.0013855270808562636f, 0.0016136543126776814f, 0.0016132618766278028f, 0.001852192566730082f, 0.0017678523436188698f, 0.0017896754434332252f, 0.00195216853171587f, 0.002245631767436862f, 0.002976511139422655f, 0.002011854900047183f, 0.002569057047367096f, 0.0035746628418564796f, 0.0012230442371219397f, 0.0027193580754101276f, 0.001226669643074274f, 0.002800792222842574f, 0.0035708057694137096f, 0.0029006674885749817f, 0.0021985371131449938f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.131780825555325e-05f, 9.090905223274603e-05f, 0.00016416730068158358f, 0.00014166907931212336f, 0.0001574368216097355f, 0.00014378890045918524f, 0.0001184419306810014f, 0.00011074912617914379f, 0.00011135177919641137f, 6.495272100437433e-05f, 9.429836791241542e-05f, 8.875331695890054e-05f, 0.0001028359038173221f, 0.00014155944518279284f, 0.00010344999463995919f, 9.270209557143971e-05f, 0.00011508430179674178f, 0.00012215471360832453f, 0.00012289262667763978f, 0.00011293068382656202f, 0.00012183275248389691f, 0.00015237106708809733f, 0.00010145386477233842f, 0.00012264552060514688f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001551084453240037f, 0.0015441415598616004f, 0.002788474317640066f, 0.0024063291493803263f, 0.002674153307452798f, 0.0024423354770988226f, 0.0020118029788136482f, 0.0018811363261193037f, 0.001891372725367546f, 0.0011032585753127933f, 0.0016017109155654907f, 0.001507525215856731f, 0.0017467258730903268f, 0.0024044669698923826f, 0.0017571565695106983f, 0.0015745974378660321f, 0.001954771811142564f, 0.0020748667884618044f, 0.0020874005276709795f, 0.001918191323056817f, 0.0020693980623036623f, 0.0025881086476147175f, 0.0017232510726898909f, 0.002083203289657831f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002869676682166755f, 0.00015122912009246647f, 0.0001001740456558764f, 0.0005710211698897183f, 0.00032112206099554896f, 0.00019565442926250398f, 0.00023134765797294676f, 0.00028817937709391117f, 0.0002521255810279399f, 0.00036823374102823436f, 0.00024490192299708724f, 0.00028248497983440757f, 0.0001810357643989846f, 0.00013599505473393947f, 0.0003117299056611955f, 0.0002746365498751402f, 0.0001708789641270414f, 0.00012812438944820315f, 0.0003225273103453219f, 0.00020273537666071206f, 0.0002332807198399678f, 0.00015851830539759248f, 0.00030227386741898954f, 0.00024283338279929012f, 0.00030935477116145194f, 0.00011879207886522636f, 0.00024006491003092378f, 0.00025869515957310796f, 0.00012838361726608127f, 0.00023057081853039563f, 0.00019436994625721127f, 0.00011617807467700914f, 0.0003261119418311864f, 0.0001511463342467323f, 0.0002698498428799212f, 0.00023881206288933754f, 0.00031740209669806063f, 0.0003245834377594292f, 0.00021530795493163168f, 0.00035353837301954627f, 0.00015693882596679032f, 0.0005893539055250585f, 0.00029644177993759513f, 0.00016985839465633035f, 0.00012973697448614985f, 0.0002401612000539899f, 0.0001347605139017105f, 0.00021261470101308078f, 0.00014445075066760182f, 0.00012505917402449995f, 0.00017796066822484136f, 0.0003848715277854353f, 0.0006498066359199584f, 0.00016695268277544528f, 0.000338220241246745f, 0.00017918141384143382f, 0.0003594393201638013f, 0.00022463682398665696f, 0.00016958887863438576f, 0.00030054571107029915f, 0.0004833962884731591f, 0.00015063145838212222f, 0.0003726960567291826f, 0.0005986257456243038f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011603523045778275f, 0.00611494155600667f, 0.004050532355904579f, 0.0230892114341259f, 0.012984554283320904f, 0.007911277003586292f, 0.009354530833661556f, 0.011652518063783646f, 0.010194685310125351f, 0.01488951314240694f, 0.009902596473693848f, 0.011422265321016312f, 0.0073201716877520084f, 0.00549895316362381f, 0.012604782357811928f, 0.011104914359748363f, 0.006909482181072235f, 0.00518070301041007f, 0.013041375204920769f, 0.008197594434022903f, 0.00943269394338131f, 0.006409679539501667f, 0.012222428806126118f, 0.009818955324590206f, 0.01250874437391758f, 0.00480335159227252f, 0.009707012213766575f, 0.01046032551676035f, 0.005191185045987368f, 0.009323119185864925f, 0.007859339006245136f, 0.0046976543962955475f, 0.0131863197311759f, 0.006111594382673502f, 0.010911365039646626f, 0.00965635385364294f, 0.012834137305617332f, 0.013124514371156693f, 0.008705966174602509f, 0.0142953060567379f, 0.006345813162624836f, 0.02383049577474594f, 0.011986608617007732f, 0.006868215277791023f, 0.005245907697826624f, 0.009710906073451042f, 0.00544903427362442f, 0.008597064763307571f, 0.005840858910232782f, 0.005056761205196381f, 0.007195830345153809f, 0.015562260523438454f, 0.026274897158145905f, 0.006750723347067833f, 0.01367591880261898f, 0.007245191372931004f, 0.014533910900354385f, 0.009083178825676441f, 0.0068573178723454475f, 0.012152550742030144f, 0.019546104595065117f, 0.00609077513217926f, 0.015069946646690369f, 0.02420540153980255f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00032255129190161824f, 0.00023630091163795441f, 0.0001918560010381043f, 0.00015816114319022745f, 0.00019056892779190093f, 0.00027571129612624645f, 0.00017153099179267883f, 0.00016528810374438763f, 0.00019132123270537704f, 0.00014042379916645586f, 0.00015270337462425232f, 0.0001871670101536438f, 0.0002336640900466591f, 0.0002663416671566665f, 0.00029726207139901817f, 0.00032210382050834596f, 0.00019849755335599184f, 0.00019792720559053123f, 0.00018478772835806012f, 0.00019018961756955832f, 0.00021609233226627111f, 0.00027198161114938557f, 0.00018928464851342142f, 0.00021399073011707515f, 0.00024605297949165106f, 0.00018889376951847225f, 0.00016817994765006006f, 0.00014968281902838498f, 0.00023340537154581398f, 0.0002299664483871311f, 0.0002110375207848847f, 0.00017724608187563717f, 0.00011597389675443992f, 0.0002768588892649859f, 0.0002593708923086524f, 0.00014496920630335808f, 0.00016073952428996563f, 0.00011928173626074567f, 0.00019863262423314154f, 0.0002168704231735319f, 0.00022265790903475136f, 7.544503023382276e-05f, 0.00044237246038392186f, 0.0003398088156245649f, 0.00016875150322448462f, 0.00011254033597651869f, 0.0002783719974104315f, 0.0002761478826869279f, 0.00020028573635499924f, 0.0002977960975840688f, 0.00014711444964632392f, 0.0002441328833810985f, 0.00018771123723126948f, 0.00017230819503311068f, 0.0002196416462538764f, 0.0003297659568488598f, 0.00019702267309185117f, 0.00022978076594881713f, 0.00023247941862791777f, 0.0003479932202026248f, 0.0003183922672178596f, 0.00027370909810997546f, 0.00015742596588097513f, 7.865167572163045e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0034966133534908295f, 0.00256161717697978f, 0.0020798125769943f, 0.001714543905109167f, 0.0020658602006733418f, 0.002988845109939575f, 0.001859479583799839f, 0.0017918036319315434f, 0.002074015559628606f, 0.0015222624642774463f, 0.0016553790774196386f, 0.002028981689363718f, 0.0025330327916890383f, 0.002887273672968149f, 0.003222465980798006f, 0.0034917625598609447f, 0.0021518103312700987f, 0.00214562751352787f, 0.0020031891763210297f, 0.0020617481786757708f, 0.002342546358704567f, 0.0029484133701771498f, 0.002051937859505415f, 0.002319763880223036f, 0.002667334396392107f, 0.002047700574621558f, 0.0018231526482850313f, 0.001622634707018733f, 0.0025302281137555838f, 0.0024929484352469444f, 0.0022877496667206287f, 0.0019214340718463063f, 0.0012572136474773288f, 0.003001285484060645f, 0.0028117068577557802f, 0.0015715369954705238f, 0.0017424948746338487f, 0.0012930722441524267f, 0.002153274603188038f, 0.0023509811144322157f, 0.0024137203581631184f, 0.0008178609423339367f, 0.004795533139258623f, 0.0036836934741586447f, 0.0018293486209586263f, 0.001219992176629603f, 0.0030176884029060602f, 0.0029935776256024837f, 0.002171195112168789f, 0.0032282548490911722f, 0.001594792352989316f, 0.0026465195696800947f, 0.0020348813850432634f, 0.0018679049098864198f, 0.0023810225538909435f, 0.003574823960661888f, 0.0021358218509703875f, 0.0024909356143325567f, 0.002520190319046378f, 0.0037724163848906755f, 0.003451527561992407f, 0.002967140171676874f, 0.001706574228592217f, 0.0008526225574314594f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024992018006742f, 0.00017499302339274436f, 0.00020047430007252842f, 0.0003443456953391433f, 0.0002902650157921016f, 0.00020955193031113595f, 0.00023878281353972852f, 0.00019082835933659226f, 0.00020276948635000736f, 0.00021678392658941448f, 0.000264930073171854f, 0.0001767209469107911f, 0.0002724224468693137f, 0.0002874686906579882f, 0.00022531303693540394f, 0.00035366066731512547f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004946491215378046f, 0.003463511820882559f, 0.003967844415456057f, 0.0068153878673911095f, 0.005745007656514645f, 0.004147511441260576f, 0.004726057406514883f, 0.0037769293412566185f, 0.004013271536678076f, 0.004290649201720953f, 0.005243571475148201f, 0.003497711382806301f, 0.0053918627090752125f, 0.005689662415534258f, 0.00445945980027318f, 0.00699975248426199f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005932358908466995f, 0.0002752026484813541f, 0.0003865671460516751f, 0.0005178326973691583f, 0.0003314365167170763f, 0.0001827654050430283f, 0.0002867420844268054f, 0.00033348548458889127f, 0.0002727896498981863f, 0.00046188864507712424f, 0.0003281235694885254f, 0.00020712291006930172f, 0.0002686482621356845f, 0.0001925180695252493f, 0.000165986581123434f, 0.000534974446054548f, 0.0006417923723347485f, 0.0002700473996810615f, 0.0005294462316669524f, 0.0001781005848897621f, 0.000840372929815203f, 0.00033321103546768427f, 0.00047575533972121775f, 0.00030235640588216484f, 0.0003989820252172649f, 0.00027286855038255453f, 0.00032347964588552713f, 0.0004876833991147578f, 0.0009604161023162305f, 0.0006953381234779954f, 0.000283116678474471f, 0.000487637851620093f, 0.0002730853157117963f, 0.0005799931823275983f, 0.00043551521957851946f, 0.0005627773934975266f, 0.00036191559047438204f, 0.0004527319106273353f, 0.00048284290824085474f, 0.0006171356071718037f, 0.00024731786106713116f, 0.0006711173336952925f, 0.00026140594854950905f, 0.00014605828619096428f, 0.0010877600871026516f, 0.00016701253480277956f, 0.0008715564617887139f, 0.0006627519614994526f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017041746526956558f, 0.007905681617558002f, 0.011104823090136051f, 0.014875656925141811f, 0.009521097876131535f, 0.00525025837123394f, 0.008237171918153763f, 0.009579958394169807f, 0.007836363278329372f, 0.013268565759062767f, 0.009425927884876728f, 0.005949970800429583f, 0.0077173952013254166f, 0.005530421156436205f, 0.004768257029354572f, 0.015368083491921425f, 0.018436618149280548f, 0.0077575878240168095f, 0.015209277160465717f, 0.005116253159940243f, 0.02414119429886341f, 0.009572074748575687f, 0.0136669110506773f, 0.008685721084475517f, 0.011461461894214153f, 0.007838630117475986f, 0.009292523376643658f, 0.014009565114974976f, 0.027589645236730576f, 0.019974812865257263f, 0.008133025839924812f, 0.01400825660675764f, 0.007844856940209866f, 0.016661327332258224f, 0.012510942295193672f, 0.016166772693395615f, 0.010396663099527359f, 0.013005522079765797f, 0.013870513997972012f, 0.017728308215737343f, 0.007104641292244196f, 0.019279029220342636f, 0.007509347051382065f, 0.0041957818903028965f, 0.031247826293110847f, 0.004797729663550854f, 0.025036996230483055f, 0.019038718193769455f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015534560952801257f, 0.0002503896248526871f, 9.691664308775216e-05f, 0.00015557884762529284f, 0.000183907279279083f, 0.0003244855615776032f, 0.00020082057744730264f, 7.994651969056576e-05f, 0.0002348026173422113f, 0.00033176084980368614f, 0.0002552890218794346f, 0.0003296043141745031f, 0.0002311298158019781f, 0.00022264460858423263f, 0.00020570511696860194f, 0.00012908746430184692f, 0.0001945599797181785f, 0.00019457236339803785f, 7.632153574377298e-05f, 0.000332863099174574f, 0.00011471100151538849f, 7.755884871585295e-05f, 0.00010335310798836872f, 0.00016929759294725955f, 0.000281671091215685f, 9.41131729632616e-05f, 0.00013070966815575957f, 0.00015626844833604991f, 0.00011339545017108321f, 0.00021843472495675087f, 0.0001956126361619681f, 0.00026040730881504714f, 0.00015119470481295139f, 0.00013942939403932542f, 0.00013658273383043706f, 0.00010096863115904853f, 0.00022942974464967847f, 0.0003078470181208104f, 0.0001721410808386281f, 0.000210145692108199f, 0.00022483312932308763f, 0.00012890191283077002f, 0.00022715966042596847f, 0.00035241342266090214f, 0.000254046666668728f, 0.00030139595037326217f, 0.0001779786398401484f, 9.112968109548092e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029610933270305395f, 0.004772758577018976f, 0.0018473597010597587f, 0.00296553922817111f, 0.0035055167973041534f, 0.006185125093907118f, 0.0038279066793620586f, 0.0015238866908475757f, 0.004475649446249008f, 0.0063238018192350864f, 0.004866147413849831f, 0.006282695569097996f, 0.004405640996992588f, 0.004243901465088129f, 0.00392101239413023f, 0.0024605782236903906f, 0.003708571195602417f, 0.003708807285875082f, 0.0014547897735610604f, 0.006344811990857124f, 0.0021865437738597393f, 0.001478374470025301f, 0.001970047364011407f, 0.003227036679163575f, 0.005369024351239204f, 0.0017939219251275063f, 0.00249149976298213f, 0.002978683914989233f, 0.002161467680707574f, 0.004163655452430248f, 0.003728636307641864f, 0.004963708575814962f, 0.0028819716535508633f, 0.002657709177583456f, 0.0026034479960799217f, 0.0019245960284024477f, 0.004373235162347555f, 0.005867972504347563f, 0.0032812373246997595f, 0.004005655646324158f, 0.004285617731511593f, 0.0024570415262132883f, 0.004329964518547058f, 0.006717467214912176f, 0.004842466674745083f, 0.00574500672519207f, 0.003392508951947093f, 0.0017370525747537613f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024314713664352894f, 0.000264705071458593f, 0.0002490195620339364f, 0.00025753219961188734f, 0.0003225928812753409f, 0.00020912208128720522f, 0.00025478180032223463f, 0.0002460177056491375f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013066959800198674f, 0.00142255041282624f, 0.0013382548931986094f, 0.00138400262221694f, 0.001733644981868565f, 0.0011238420847803354f, 0.0013692218344658613f, 0.0013221227563917637f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008614578400738537f, 0.0010602186666801572f, 0.0007664879667572677f, 0.0010025977389886975f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007589214015752077f, 0.009340244345366955f, 0.006752554792910814f, 0.008832618594169617f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009606150561012328f, 0.0027060210704803467f, 0.0033344749826937914f, 0.0002914730575866997f, 0.0007781559252180159f, 0.0009829520713537931f, 0.00046568724792450666f, 0.0004934003227390349f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007404783274978399f, 0.02085903100669384f, 0.025703391060233116f, 0.0022467842791229486f, 0.0059983194805681705f, 0.007576965261250734f, 0.0035896929912269115f, 0.003803315805271268f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000760185532271862f, 0.0003368303005117923f, 0.0002641303581185639f, 0.0006719176890328526f, 0.000848270021378994f, 0.0004492744046729058f, 0.0011452377075329423f, 0.0012506600469350815f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008457745425403118f, 0.0037475391291081905f, 0.0029386868700385094f, 0.007475686259567738f, 0.009437764063477516f, 0.004998580552637577f, 0.012741795741021633f, 0.013914713636040688f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003108151431661099f, 0.0003369820478837937f, 6.335261423373595e-05f, 0.00034117657924070954f, 0.0005375723703764379f, 0.00018210537382401526f, 8.40643624542281e-05f, 0.00023497975780628622f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07925785332918167f, 0.08593041449785233f, 0.01615491509437561f, 0.08700001984834671f, 0.13708095252513885f, 0.046436868607997894f, 0.021436411887407303f, 0.05991983413696289f),
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
    AI_PACK_INTQ_SCALE(0.08988039940595627f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1297289878129959f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11351080983877182f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18607781827449799f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.052462246268987656f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03481074422597885f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05052473768591881f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07925856858491898f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09224677085876465f),
    AI_PACK_INTQ_ZP(-18)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02473108097910881f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05887352302670479f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04352898523211479f),
    AI_PACK_INTQ_ZP(10)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.026061885058879852f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.025881601497530937f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.030966540798544884f),
    AI_PACK_INTQ_ZP(18)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0531933419406414f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015593652613461018f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01866980828344822f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.031727541238069534f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05760551989078522f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016358787193894386f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023448627442121506f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0444810688495636f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07926547527313232f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0985601395368576f),
    AI_PACK_INTQ_ZP(-25)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01674225553870201f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02954973466694355f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04499407112598419f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.029235150665044785f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11395160108804703f),
    AI_PACK_INTQ_ZP(45)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1374, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1374, 1374),
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
  AI_SHAPE_INIT(4, 1, 35, 1, 1), AI_STRIDE_INIT(4, 4, 4, 140, 140),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 35), AI_STRIDE_INIT(4, 1, 256, 256, 256),
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
  AI_SHAPE_INIT(4, 1, 35, 5, 5), AI_STRIDE_INIT(4, 1, 1, 35, 175),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conversion_40_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 35, 5, 5), AI_STRIDE_INIT(4, 4, 4, 140, 700),
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
                     1, 1, 74364, 1,
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
    conv2d_39_output_array.data = AI_PTR(activations + 1376);
    conv2d_39_output_array.data_start = AI_PTR(activations + 1376);
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
    conv2d_39_bias_array.data = AI_PTR(weights + 74224);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 74224);
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
      
      .n_macc            = 6308109,
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

