
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/CVA62_InstructionPrinters.cpp
	src/CVA62_Printer.cpp
	src/CVA62_PerformanceModel.cpp
	src/CVA62_SchedulingFunction.cpp
	src/CVA62_Channel.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
