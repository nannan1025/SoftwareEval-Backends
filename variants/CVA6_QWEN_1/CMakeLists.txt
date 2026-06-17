
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/CVA6_QWEN_1_InstructionPrinters.cpp
	src/CVA6_QWEN_1_PerformanceModel.cpp
	src/CVA6_QWEN_1_Printer.cpp
	src/CVA6_QWEN_1_Channel.cpp
	src/CVA6_QWEN_1_SchedulingFunction.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
