
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/LAMP_Printer.cpp
	src/LAMP_PerformanceModel.cpp
	src/LAMP_InstructionPrinters.cpp
	src/LAMP_Channel.cpp
	src/LAMP_SchedulingFunction.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
