/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2' in SOPC Builder design 'finalHardware'
 * SOPC Builder design path: ../../finalHardware.sopcinfo
 *
 * Generated: Thu Mar 16 20:09:01 GMT 2023
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x08000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x04000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "nios2"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x04000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x08000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x04000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x04000000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_FPH2(n,A,B) __builtin_custom_inii(ALT_CI_FPH2_N+(n&ALT_CI_FPH2_N_MASK),(A),(B))
#define ALT_CI_FPH2_1(n,A,B) __builtin_custom_inii(ALT_CI_FPH2_1_N+(n&ALT_CI_FPH2_1_N_MASK),(A),(B))
#define ALT_CI_FPH2_1_FADDS_N ALT_CI_FPH2_1_N+5
#define ALT_CI_FPH2_1_FDIVS_N ALT_CI_FPH2_1_N+7
#define ALT_CI_FPH2_1_FIXSI_N ALT_CI_FPH2_1_N+1
#define ALT_CI_FPH2_1_FLOATIS_N ALT_CI_FPH2_1_N+2
#define ALT_CI_FPH2_1_FMULS_N ALT_CI_FPH2_1_N+4
#define ALT_CI_FPH2_1_FSUBS_N ALT_CI_FPH2_1_N+6
#define ALT_CI_FPH2_1_N 0xf8
#define ALT_CI_FPH2_1_N_MASK ((1<<3)-1)
#define ALT_CI_FPH2_1_ROUND_N ALT_CI_FPH2_1_N+0
#define ALT_CI_FPH2_FABSS_N ALT_CI_FPH2_N+0
#define ALT_CI_FPH2_FCMPEQS_N ALT_CI_FPH2_N+3
#define ALT_CI_FPH2_FCMPGES_N ALT_CI_FPH2_N+4
#define ALT_CI_FPH2_FCMPGTS_N ALT_CI_FPH2_N+5
#define ALT_CI_FPH2_FCMPLES_N ALT_CI_FPH2_N+6
#define ALT_CI_FPH2_FCMPLTS_N ALT_CI_FPH2_N+7
#define ALT_CI_FPH2_FCMPNES_N ALT_CI_FPH2_N+2
#define ALT_CI_FPH2_FMAXS_N ALT_CI_FPH2_N+8
#define ALT_CI_FPH2_FMINS_N ALT_CI_FPH2_N+9
#define ALT_CI_FPH2_FNEGS_N ALT_CI_FPH2_N+1
#define ALT_CI_FPH2_N 0xe0
#define ALT_CI_FPH2_N_MASK ((1<<4)-1)
#define fmaxf(A,B) __builtin_custom_fnff(ALT_CI_FPH2_FMAXS_N,(A),(B))
#define fminf(A,B) __builtin_custom_fnff(ALT_CI_FPH2_FMINS_N,(A),(B))
#define lroundf(A) __builtin_custom_inf(ALT_CI_FPH2_1_ROUND_N,(A))


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_NIOS_CUSTOM_INSTR_FLOATING_POINT_2
#define __ALTERA_UP_AVALON_ACCELEROMETER_SPI


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_IRQ_BASE NULL
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x80010b0
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x80010b0
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x80010b0
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "finalHardware"


/*
 * accelerometer_spi configuration
 *
 */

#define ACCELEROMETER_SPI_BASE 0x80010b8
#define ACCELEROMETER_SPI_IRQ 3
#define ACCELEROMETER_SPI_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ACCELEROMETER_SPI_NAME "/dev/accelerometer_spi"
#define ACCELEROMETER_SPI_SPAN 2
#define ACCELEROMETER_SPI_TYPE "altera_up_avalon_accelerometer_spi"
#define ALT_MODULE_CLASS_accelerometer_spi altera_up_avalon_accelerometer_spi


/*
 * dram configuration
 *
 */

#define ALT_MODULE_CLASS_dram altera_avalon_new_sdram_controller
#define DRAM_BASE 0x4000000
#define DRAM_CAS_LATENCY 3
#define DRAM_CONTENTS_INFO
#define DRAM_INIT_NOP_DELAY 0.0
#define DRAM_INIT_REFRESH_COMMANDS 2
#define DRAM_IRQ -1
#define DRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DRAM_IS_INITIALIZED 1
#define DRAM_NAME "/dev/dram"
#define DRAM_POWERUP_DELAY 100.0
#define DRAM_REFRESH_PERIOD 15.625
#define DRAM_REGISTER_DATA_IN 1
#define DRAM_SDRAM_ADDR_WIDTH 0x19
#define DRAM_SDRAM_BANK_WIDTH 2
#define DRAM_SDRAM_COL_WIDTH 10
#define DRAM_SDRAM_DATA_WIDTH 16
#define DRAM_SDRAM_NUM_BANKS 4
#define DRAM_SDRAM_NUM_CHIPSELECTS 1
#define DRAM_SDRAM_ROW_WIDTH 13
#define DRAM_SHARED_DATA 0
#define DRAM_SIM_MODEL_BASE 0
#define DRAM_SPAN 67108864
#define DRAM_STARVATION_INDICATOR 0
#define DRAM_TRISTATE_BRIDGE_SLAVE ""
#define DRAM_TYPE "altera_avalon_new_sdram_controller"
#define DRAM_T_AC 5.5
#define DRAM_T_MRD 3
#define DRAM_T_RCD 20.0
#define DRAM_T_RFC 70.0
#define DRAM_T_RP 20.0
#define DRAM_T_WR 14.0


/*
 * esp32_spi configuration
 *
 */

#define ALT_MODULE_CLASS_esp32_spi altera_avalon_spi
#define ESP32_SPI_BASE 0x8001020
#define ESP32_SPI_CLOCKMULT 1
#define ESP32_SPI_CLOCKPHASE 0
#define ESP32_SPI_CLOCKPOLARITY 0
#define ESP32_SPI_CLOCKUNITS "Hz"
#define ESP32_SPI_DATABITS 32
#define ESP32_SPI_DATAWIDTH 32
#define ESP32_SPI_DELAYMULT "1.0E-9"
#define ESP32_SPI_DELAYUNITS "ns"
#define ESP32_SPI_EXTRADELAY 0
#define ESP32_SPI_INSERT_SYNC 0
#define ESP32_SPI_IRQ 1
#define ESP32_SPI_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ESP32_SPI_ISMASTER 1
#define ESP32_SPI_LSBFIRST 0
#define ESP32_SPI_NAME "/dev/esp32_spi"
#define ESP32_SPI_NUMSLAVES 1
#define ESP32_SPI_PREFIX "spi_"
#define ESP32_SPI_SPAN 32
#define ESP32_SPI_SYNC_REG_DEPTH 2
#define ESP32_SPI_TARGETCLOCK 40000000u
#define ESP32_SPI_TARGETSSDELAY "0.0"
#define ESP32_SPI_TYPE "altera_avalon_spi"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK SYS_CLK
#define ALT_TIMESTAMP_CLK none


/*
 * hex_0 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_0 altera_avalon_pio
#define HEX_0_BASE 0x8001090
#define HEX_0_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_0_CAPTURE 0
#define HEX_0_DATA_WIDTH 7
#define HEX_0_DO_TEST_BENCH_WIRING 0
#define HEX_0_DRIVEN_SIM_VALUE 0
#define HEX_0_EDGE_TYPE "NONE"
#define HEX_0_FREQ 100000000
#define HEX_0_HAS_IN 0
#define HEX_0_HAS_OUT 1
#define HEX_0_HAS_TRI 0
#define HEX_0_IRQ -1
#define HEX_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_0_IRQ_TYPE "NONE"
#define HEX_0_NAME "/dev/hex_0"
#define HEX_0_RESET_VALUE 0
#define HEX_0_SPAN 16
#define HEX_0_TYPE "altera_avalon_pio"


/*
 * hex_1 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_1 altera_avalon_pio
#define HEX_1_BASE 0x8001080
#define HEX_1_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_1_CAPTURE 0
#define HEX_1_DATA_WIDTH 7
#define HEX_1_DO_TEST_BENCH_WIRING 0
#define HEX_1_DRIVEN_SIM_VALUE 0
#define HEX_1_EDGE_TYPE "NONE"
#define HEX_1_FREQ 100000000
#define HEX_1_HAS_IN 0
#define HEX_1_HAS_OUT 1
#define HEX_1_HAS_TRI 0
#define HEX_1_IRQ -1
#define HEX_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_1_IRQ_TYPE "NONE"
#define HEX_1_NAME "/dev/hex_1"
#define HEX_1_RESET_VALUE 0
#define HEX_1_SPAN 16
#define HEX_1_TYPE "altera_avalon_pio"


/*
 * hex_2 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_2 altera_avalon_pio
#define HEX_2_BASE 0x8001070
#define HEX_2_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_2_CAPTURE 0
#define HEX_2_DATA_WIDTH 7
#define HEX_2_DO_TEST_BENCH_WIRING 0
#define HEX_2_DRIVEN_SIM_VALUE 0
#define HEX_2_EDGE_TYPE "NONE"
#define HEX_2_FREQ 100000000
#define HEX_2_HAS_IN 0
#define HEX_2_HAS_OUT 1
#define HEX_2_HAS_TRI 0
#define HEX_2_IRQ -1
#define HEX_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_2_IRQ_TYPE "NONE"
#define HEX_2_NAME "/dev/hex_2"
#define HEX_2_RESET_VALUE 0
#define HEX_2_SPAN 16
#define HEX_2_TYPE "altera_avalon_pio"


/*
 * hex_3 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_3 altera_avalon_pio
#define HEX_3_BASE 0x8001060
#define HEX_3_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_3_CAPTURE 0
#define HEX_3_DATA_WIDTH 7
#define HEX_3_DO_TEST_BENCH_WIRING 0
#define HEX_3_DRIVEN_SIM_VALUE 0
#define HEX_3_EDGE_TYPE "NONE"
#define HEX_3_FREQ 100000000
#define HEX_3_HAS_IN 0
#define HEX_3_HAS_OUT 1
#define HEX_3_HAS_TRI 0
#define HEX_3_IRQ -1
#define HEX_3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_3_IRQ_TYPE "NONE"
#define HEX_3_NAME "/dev/hex_3"
#define HEX_3_RESET_VALUE 0
#define HEX_3_SPAN 16
#define HEX_3_TYPE "altera_avalon_pio"


/*
 * hex_4 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_4 altera_avalon_pio
#define HEX_4_BASE 0x8001050
#define HEX_4_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_4_CAPTURE 0
#define HEX_4_DATA_WIDTH 7
#define HEX_4_DO_TEST_BENCH_WIRING 0
#define HEX_4_DRIVEN_SIM_VALUE 0
#define HEX_4_EDGE_TYPE "NONE"
#define HEX_4_FREQ 100000000
#define HEX_4_HAS_IN 0
#define HEX_4_HAS_OUT 1
#define HEX_4_HAS_TRI 0
#define HEX_4_IRQ -1
#define HEX_4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_4_IRQ_TYPE "NONE"
#define HEX_4_NAME "/dev/hex_4"
#define HEX_4_RESET_VALUE 0
#define HEX_4_SPAN 16
#define HEX_4_TYPE "altera_avalon_pio"


/*
 * hex_5 configuration
 *
 */

#define ALT_MODULE_CLASS_hex_5 altera_avalon_pio
#define HEX_5_BASE 0x8001040
#define HEX_5_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_5_CAPTURE 0
#define HEX_5_DATA_WIDTH 7
#define HEX_5_DO_TEST_BENCH_WIRING 0
#define HEX_5_DRIVEN_SIM_VALUE 0
#define HEX_5_EDGE_TYPE "NONE"
#define HEX_5_FREQ 100000000
#define HEX_5_HAS_IN 0
#define HEX_5_HAS_OUT 1
#define HEX_5_HAS_TRI 0
#define HEX_5_IRQ -1
#define HEX_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_5_IRQ_TYPE "NONE"
#define HEX_5_NAME "/dev/hex_5"
#define HEX_5_RESET_VALUE 0
#define HEX_5_SPAN 16
#define HEX_5_TYPE "altera_avalon_pio"


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x80010b0
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * keys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_keys_0 altera_avalon_pio
#define KEYS_0_BASE 0x80010a0
#define KEYS_0_BIT_CLEARING_EDGE_REGISTER 0
#define KEYS_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEYS_0_CAPTURE 0
#define KEYS_0_DATA_WIDTH 2
#define KEYS_0_DO_TEST_BENCH_WIRING 0
#define KEYS_0_DRIVEN_SIM_VALUE 0
#define KEYS_0_EDGE_TYPE "NONE"
#define KEYS_0_FREQ 100000000
#define KEYS_0_HAS_IN 1
#define KEYS_0_HAS_OUT 0
#define KEYS_0_HAS_TRI 0
#define KEYS_0_IRQ -1
#define KEYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KEYS_0_IRQ_TYPE "NONE"
#define KEYS_0_NAME "/dev/keys_0"
#define KEYS_0_RESET_VALUE 0
#define KEYS_0_SPAN 16
#define KEYS_0_TYPE "altera_avalon_pio"


/*
 * sys_clk configuration
 *
 */

#define ALT_MODULE_CLASS_sys_clk altera_avalon_timer
#define SYS_CLK_ALWAYS_RUN 0
#define SYS_CLK_BASE 0x8001000
#define SYS_CLK_COUNTER_SIZE 32
#define SYS_CLK_FIXED_PERIOD 0
#define SYS_CLK_FREQ 100000000
#define SYS_CLK_IRQ 2
#define SYS_CLK_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SYS_CLK_LOAD_VALUE 99999
#define SYS_CLK_MULT 0.001
#define SYS_CLK_NAME "/dev/sys_clk"
#define SYS_CLK_PERIOD 1
#define SYS_CLK_PERIOD_UNITS "ms"
#define SYS_CLK_RESET_OUTPUT 0
#define SYS_CLK_SNAPSHOT 1
#define SYS_CLK_SPAN 32
#define SYS_CLK_TICKS_PER_SEC 1000
#define SYS_CLK_TIMEOUT_PULSE_OUTPUT 0
#define SYS_CLK_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
