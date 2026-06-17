
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/FIVE_FW_DYPRE_InstructionPrinters.cpp
	src/FIVE_FW_DYPRE_PerformanceModel.cpp
	src/FIVE_FW_DYPRE_SchedulingFunction.cpp
	src/FIVE_FW_DYPRE_Printer.cpp
	src/FIVE_FW_DYPRE_Channel.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
