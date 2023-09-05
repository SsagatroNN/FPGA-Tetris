	finalHardware u0 (
		.clk_clk                     (<connected-to-clk_clk>),                     //           clk.clk
		.reset_reset_n               (<connected-to-reset_reset_n>),               //         reset.reset_n
		.sdram_clk                   (<connected-to-sdram_clk>),                   //         sdram.clk
		.accelerometer_I2C_SDAT      (<connected-to-accelerometer_I2C_SDAT>),      // accelerometer.I2C_SDAT
		.accelerometer_I2C_SCLK      (<connected-to-accelerometer_I2C_SCLK>),      //              .I2C_SCLK
		.accelerometer_G_SENSOR_CS_N (<connected-to-accelerometer_G_SENSOR_CS_N>), //              .G_SENSOR_CS_N
		.accelerometer_G_SENSOR_INT  (<connected-to-accelerometer_G_SENSOR_INT>),  //              .G_SENSOR_INT
		.hex_5_export                (<connected-to-hex_5_export>),                //         hex_5.export
		.hex_4_export                (<connected-to-hex_4_export>),                //         hex_4.export
		.hex_3_export                (<connected-to-hex_3_export>),                //         hex_3.export
		.hex_2_export                (<connected-to-hex_2_export>),                //         hex_2.export
		.hex_1_export                (<connected-to-hex_1_export>),                //         hex_1.export
		.hex_0_export                (<connected-to-hex_0_export>),                //         hex_0.export
		.keys_0_export               (<connected-to-keys_0_export>),               //        keys_0.export
		.esp32_MISO                  (<connected-to-esp32_MISO>),                  //         esp32.MISO
		.esp32_MOSI                  (<connected-to-esp32_MOSI>),                  //              .MOSI
		.esp32_SCLK                  (<connected-to-esp32_SCLK>),                  //              .SCLK
		.esp32_SS_n                  (<connected-to-esp32_SS_n>),                  //              .SS_n
		.dram_addr                   (<connected-to-dram_addr>),                   //          dram.addr
		.dram_ba                     (<connected-to-dram_ba>),                     //              .ba
		.dram_cas_n                  (<connected-to-dram_cas_n>),                  //              .cas_n
		.dram_cke                    (<connected-to-dram_cke>),                    //              .cke
		.dram_cs_n                   (<connected-to-dram_cs_n>),                   //              .cs_n
		.dram_dq                     (<connected-to-dram_dq>),                     //              .dq
		.dram_dqm                    (<connected-to-dram_dqm>),                    //              .dqm
		.dram_ras_n                  (<connected-to-dram_ras_n>),                  //              .ras_n
		.dram_we_n                   (<connected-to-dram_we_n>)                    //              .we_n
	);

