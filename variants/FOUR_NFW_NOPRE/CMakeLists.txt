
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/FOUR_NFW_NOPRE_InstructionPrinters.cpp
	src/FOUR_NFW_NOPRE_Printer.cpp
	src/FOUR_NFW_NOPRE_SchedulingFunction.cpp
	src/FOUR_NFW_NOPRE_Channel.cpp
	src/FOUR_NFW_NOPRE_PerformanceModel.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
