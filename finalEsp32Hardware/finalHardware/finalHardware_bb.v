
module finalHardware (
	clk_clk,
	reset_reset_n,
	sdram_clk,
	accelerometer_I2C_SDAT,
	accelerometer_I2C_SCLK,
	accelerometer_G_SENSOR_CS_N,
	accelerometer_G_SENSOR_INT,
	hex_5_export,
	hex_4_export,
	hex_3_export,
	hex_2_export,
	hex_1_export,
	hex_0_export,
	keys_0_export,
	esp32_MISO,
	esp32_MOSI,
	esp32_SCLK,
	esp32_SS_n,
	dram_addr,
	dram_ba,
	dram_cas_n,
	dram_cke,
	dram_cs_n,
	dram_dq,
	dram_dqm,
	dram_ras_n,
	dram_we_n);	

	input		clk_clk;
	input		reset_reset_n;
	output		sdram_clk;
	inout		accelerometer_I2C_SDAT;
	output		accelerometer_I2C_SCLK;
	output		accelerometer_G_SENSOR_CS_N;
	input		accelerometer_G_SENSOR_INT;
	output	[6:0]	hex_5_export;
	output	[6:0]	hex_4_export;
	output	[6:0]	hex_3_export;
	output	[6:0]	hex_2_export;
	output	[6:0]	hex_1_export;
	output	[6:0]	hex_0_export;
	input	[1:0]	keys_0_export;
	input		esp32_MISO;
	output		esp32_MOSI;
	output		esp32_SCLK;
	output		esp32_SS_n;
	output	[12:0]	dram_addr;
	output	[1:0]	dram_ba;
	output		dram_cas_n;
	output		dram_cke;
	output		dram_cs_n;
	inout	[15:0]	dram_dq;
	output	[1:0]	dram_dqm;
	output		dram_ras_n;
	output		dram_we_n;
endmodule
