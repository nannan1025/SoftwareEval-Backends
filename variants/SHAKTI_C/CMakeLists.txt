
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/SHAKTI_C_PerformanceModel.cpp
	src/SHAKTI_C_Printer.cpp
	src/SHAKTI_C_SchedulingFunction.cpp
	src/SHAKTI_C_InstructionPrinters.cpp
	src/SHAKTI_C_Channel.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
