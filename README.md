# FPGA-Tetris

Two players join a game of Tetris where each line they complete is sent to the other player. The Tetris games are made on PyGame and are controlled by a wireless FPGA controller. The DE-10 Lite runs an FFT spike detection algorithm to determine whether a player has tilted the FPGA in a direction (left, right, or down). Left and right tilts are used to rotate the blocks, while the down tilt drops the block to the bottom of the floor. The two buttons on the FPGA are used to move the block left and right.
