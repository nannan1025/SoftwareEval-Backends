
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/CV32E40P_LLM_Printer.cpp
	src/CV32E40P_LLM_PerformanceModel.cpp
	src/CV32E40P_LLM_Channel.cpp
	src/CV32E40P_LLM_InstructionPrinters.cpp
	src/CV32E40P_LLM_SchedulingFunction.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
