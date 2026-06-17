
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/SIX_NFW_SPRE_Channel.cpp
	src/SIX_NFW_SPRE_Printer.cpp
	src/SIX_NFW_SPRE_InstructionPrinters.cpp
	src/SIX_NFW_SPRE_PerformanceModel.cpp
	src/SIX_NFW_SPRE_SchedulingFunction.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
