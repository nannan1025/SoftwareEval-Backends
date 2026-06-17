
TARGET_SOURCES(SWEVAL_BACKENDS_LIB PRIVATE
  	src/FIVE_NFW_NPRE_Channel.cpp
	src/FIVE_NFW_NPRE_Printer.cpp
	src/FIVE_NFW_NPRE_SchedulingFunction.cpp
	src/FIVE_NFW_NPRE_InstructionPrinters.cpp
	src/FIVE_NFW_NPRE_PerformanceModel.cpp

)

TARGET_INCLUDE_DIRECTORIES(SWEVAL_BACKENDS_LIB PRIVATE
include
)
