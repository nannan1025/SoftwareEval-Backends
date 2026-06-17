
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/ROCKET_Printer.cpp
	src/ROCKET_PerformanceModel.cpp
	src/ROCKET_Channel.cpp
	src/ROCKET_InstructionPrinters.cpp
	src/ROCKET_SchedulingFunction.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
