
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/RC_Printer.cpp
	src/RC_SchedulingFunction.cpp
	src/RC_Channel.cpp
	src/RC_PerformanceModel.cpp
	src/RC_InstructionPrinters.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
