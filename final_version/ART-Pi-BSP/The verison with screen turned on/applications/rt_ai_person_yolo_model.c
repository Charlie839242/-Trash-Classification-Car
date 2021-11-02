#include <board.h>
#include <rt_ai.h>
#include <backend_cubeai.h>
#include <rt_ai_person_yolo_model.h>
#include <person_yolo.h>
#include <person_yolo_data.h>

/* based on cube */
#define RT_AI_PERSON_YOLO_INFO    {       \
    RT_AI_PERSON_YOLO_IN_NUM,             \
    RT_AI_PERSON_YOLO_OUT_NUM,            \
    RT_AI_PERSON_YOLO_IN_SIZE_BYTES,      \
    RT_AI_PERSON_YOLO_OUT_SIZE_BYTES,     \
    RT_AI_PERSON_YOLO_WORK_BUFFER_BYTES,  \
    ALLOC_WORK_BUFFER_FLAG | ALLOC_INPUT_BUFFER_FLAG | ALLOC_OUTPUT_BUFFER_FLAG \
}

#define RT_AI_PERSON_YOLO_HANDLE  {         \
    .info   =     RT_AI_PERSON_YOLO_INFO    \
}

#define CUBE_AI_PERSON_YOLO_PARAMS     {      \
    .params        = AI_PERSON_YOLO_DATA_WEIGHTS(NULL),   \
    .activations   = AI_PERSON_YOLO_DATA_ACTIVATIONS(NULL), \
}

#define RT_CUBE_AI_PERSON_YOLO {      \
    .parent         = RT_AI_PERSON_YOLO_HANDLE,          \
    .handle         = AI_HANDLE_NULL,     \
    .params         = CUBE_AI_PERSON_YOLO_PARAMS,         \
    .get_info       = ai_person_yolo_get_info,  \
    .get_error      = ai_person_yolo_get_error, \
    .create         = ai_person_yolo_create,    \
    .destroy        = ai_person_yolo_destroy,   \
    .init           = ai_person_yolo_init,      \
    .run            = ai_person_yolo_run,       \
    .forward        = ai_person_yolo_forward,   \
    .weights_get    = ai_person_yolo_data_weights_get, \
}

static struct cube_ai rt_cube_ai_person_yolo_model = RT_CUBE_AI_PERSON_YOLO;

static int rt_ai_person_yolo_model_init(){
    rt_ai_register(RT_AI_T(&rt_cube_ai_person_yolo_model),RT_AI_PERSON_YOLO_MODEL_NAME,0,backend_cubeai,&rt_cube_ai_person_yolo_model);
    return 0;
}
INIT_APP_EXPORT(rt_ai_person_yolo_model_init);

// stm32 ai environment
CRC_HandleTypeDef hcrc;
/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static int MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
  hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
  hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
  hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
  hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */
  return 0;
}
INIT_APP_EXPORT(MX_CRC_Init);

/**
* @brief CRC MSP Initialization
* This function configures the hardware resources used in this example
* @param hcrc: CRC handle pointer
* @retval None
*/
void HAL_CRC_MspInit(CRC_HandleTypeDef* hcrc)
{
  if(hcrc->Instance==CRC)
  {
  /* USER CODE BEGIN CRC_MspInit 0 */

  /* USER CODE END CRC_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_CRC_CLK_ENABLE();
  /* USER CODE BEGIN CRC_MspInit 1 */

  /* USER CODE END CRC_MspInit 1 */
  }

}

/**
* @brief CRC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hcrc: CRC handle pointer
* @retval None
*/
void HAL_CRC_MspDeInit(CRC_HandleTypeDef* hcrc)
{
  if(hcrc->Instance==CRC)
  {
  /* USER CODE BEGIN CRC_MspDeInit 0 */

  /* USER CODE END CRC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CRC_CLK_DISABLE();
  /* USER CODE BEGIN CRC_MspDeInit 1 */

  /* USER CODE END CRC_MspDeInit 1 */
  }

}

