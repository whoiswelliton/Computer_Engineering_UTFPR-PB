--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: P.20131013
--  \   \         Application: netgen
--  /   /         Filename: divisao.vhd
-- /___/   /\     Timestamp: Sat Sep 14 17:10:07 2019
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -w -sim -ofmt vhdl ./tmp/_cg/divisao.ngc ./tmp/_cg/divisao.vhd 
-- Device	: 3s100ecp132-5
-- Input file	: ./tmp/_cg/divisao.ngc
-- Output file	: ./tmp/_cg/divisao.vhd
-- # of Entities	: 1
-- Design Name	: divisao
-- Xilinx	: D:\Programas\ISE14-7\14.7\ISE_DS\ISE\
--             
-- Purpose:    
--     This VHDL netlist is a verification model and uses simulation 
--     primitives which may not represent the true implementation of the 
--     device, however the netlist is functionally correct and should not 
--     be modified. This file cannot be synthesized and should only be used 
--     with supported simulation tools.
--             
-- Reference:  
--     Command Line Tools User Guide, Chapter 23
--     Synthesis and Simulation Design Guide, Chapter 6
--             
--------------------------------------------------------------------------------


-- synthesis translate_off
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
use UNISIM.VPKG.ALL;

entity divisao is
  port (
    rfd : out STD_LOGIC; 
    clk : in STD_LOGIC := 'X'; 
    dividend : in STD_LOGIC_VECTOR ( 2 downto 0 ); 
    quotient : out STD_LOGIC_VECTOR ( 2 downto 0 ); 
    divisor : in STD_LOGIC_VECTOR ( 2 downto 0 ); 
    fractional : out STD_LOGIC_VECTOR ( 2 downto 0 ) 
  );
end divisao;

architecture STRUCTURE of divisao is
  signal NlwRenamedSig_OI_rfd : STD_LOGIC; 
  signal blk00000003_sig0000006c : STD_LOGIC; 
  signal blk00000003_sig0000006b : STD_LOGIC; 
  signal blk00000003_sig0000006a : STD_LOGIC; 
  signal blk00000003_sig00000069 : STD_LOGIC; 
  signal blk00000003_sig00000068 : STD_LOGIC; 
  signal blk00000003_sig00000067 : STD_LOGIC; 
  signal blk00000003_sig00000066 : STD_LOGIC; 
  signal blk00000003_sig00000065 : STD_LOGIC; 
  signal blk00000003_sig00000064 : STD_LOGIC; 
  signal blk00000003_sig00000063 : STD_LOGIC; 
  signal blk00000003_sig00000062 : STD_LOGIC; 
  signal blk00000003_sig00000061 : STD_LOGIC; 
  signal blk00000003_sig00000060 : STD_LOGIC; 
  signal blk00000003_sig0000005f : STD_LOGIC; 
  signal blk00000003_sig0000005e : STD_LOGIC; 
  signal blk00000003_sig0000005d : STD_LOGIC; 
  signal blk00000003_sig0000005c : STD_LOGIC; 
  signal blk00000003_sig0000005b : STD_LOGIC; 
  signal blk00000003_sig0000005a : STD_LOGIC; 
  signal blk00000003_sig00000059 : STD_LOGIC; 
  signal blk00000003_sig00000058 : STD_LOGIC; 
  signal blk00000003_sig00000057 : STD_LOGIC; 
  signal blk00000003_sig00000056 : STD_LOGIC; 
  signal blk00000003_sig00000055 : STD_LOGIC; 
  signal blk00000003_sig00000054 : STD_LOGIC; 
  signal blk00000003_sig00000053 : STD_LOGIC; 
  signal blk00000003_sig00000052 : STD_LOGIC; 
  signal blk00000003_sig00000051 : STD_LOGIC; 
  signal blk00000003_sig00000050 : STD_LOGIC; 
  signal blk00000003_sig0000004f : STD_LOGIC; 
  signal blk00000003_sig0000004e : STD_LOGIC; 
  signal blk00000003_sig0000004d : STD_LOGIC; 
  signal blk00000003_sig0000004c : STD_LOGIC; 
  signal blk00000003_sig0000004b : STD_LOGIC; 
  signal blk00000003_sig0000004a : STD_LOGIC; 
  signal blk00000003_sig00000049 : STD_LOGIC; 
  signal blk00000003_sig00000048 : STD_LOGIC; 
  signal blk00000003_sig00000047 : STD_LOGIC; 
  signal blk00000003_sig00000046 : STD_LOGIC; 
  signal blk00000003_sig00000045 : STD_LOGIC; 
  signal blk00000003_sig00000044 : STD_LOGIC; 
  signal blk00000003_sig00000043 : STD_LOGIC; 
  signal blk00000003_sig00000042 : STD_LOGIC; 
  signal blk00000003_sig00000041 : STD_LOGIC; 
  signal blk00000003_sig00000040 : STD_LOGIC; 
  signal blk00000003_sig0000003f : STD_LOGIC; 
  signal blk00000003_sig0000003e : STD_LOGIC; 
  signal blk00000003_sig0000003d : STD_LOGIC; 
  signal blk00000003_sig0000003c : STD_LOGIC; 
  signal blk00000003_sig0000003b : STD_LOGIC; 
  signal blk00000003_sig0000003a : STD_LOGIC; 
  signal blk00000003_sig00000039 : STD_LOGIC; 
  signal blk00000003_sig00000038 : STD_LOGIC; 
  signal blk00000003_sig00000037 : STD_LOGIC; 
  signal blk00000003_sig00000036 : STD_LOGIC; 
  signal blk00000003_sig00000035 : STD_LOGIC; 
  signal blk00000003_sig00000034 : STD_LOGIC; 
  signal blk00000003_sig00000033 : STD_LOGIC; 
  signal blk00000003_sig00000032 : STD_LOGIC; 
  signal blk00000003_sig00000031 : STD_LOGIC; 
  signal blk00000003_sig00000030 : STD_LOGIC; 
  signal blk00000003_sig0000002f : STD_LOGIC; 
  signal blk00000003_sig0000002e : STD_LOGIC; 
  signal blk00000003_sig0000002d : STD_LOGIC; 
  signal blk00000003_sig0000002c : STD_LOGIC; 
  signal blk00000003_sig0000002b : STD_LOGIC; 
  signal blk00000003_sig0000002a : STD_LOGIC; 
  signal blk00000003_sig00000029 : STD_LOGIC; 
  signal blk00000003_sig00000028 : STD_LOGIC; 
  signal blk00000003_sig00000027 : STD_LOGIC; 
  signal blk00000003_sig00000026 : STD_LOGIC; 
  signal blk00000003_sig00000025 : STD_LOGIC; 
  signal blk00000003_sig00000024 : STD_LOGIC; 
  signal blk00000003_sig00000023 : STD_LOGIC; 
  signal blk00000003_sig00000022 : STD_LOGIC; 
  signal blk00000003_sig00000021 : STD_LOGIC; 
  signal blk00000003_sig00000020 : STD_LOGIC; 
  signal blk00000003_sig0000001f : STD_LOGIC; 
  signal blk00000003_sig0000001e : STD_LOGIC; 
  signal blk00000003_sig0000001d : STD_LOGIC; 
  signal blk00000003_sig0000001c : STD_LOGIC; 
  signal blk00000003_sig0000001b : STD_LOGIC; 
  signal blk00000003_sig0000001a : STD_LOGIC; 
  signal blk00000003_sig00000019 : STD_LOGIC; 
  signal blk00000003_sig00000018 : STD_LOGIC; 
  signal blk00000003_sig00000017 : STD_LOGIC; 
  signal blk00000003_sig00000016 : STD_LOGIC; 
  signal blk00000003_sig00000015 : STD_LOGIC; 
  signal blk00000003_sig00000014 : STD_LOGIC; 
  signal blk00000003_sig00000013 : STD_LOGIC; 
  signal blk00000003_sig00000012 : STD_LOGIC; 
  signal blk00000003_sig00000011 : STD_LOGIC; 
  signal blk00000003_sig00000010 : STD_LOGIC; 
  signal blk00000003_sig0000000e : STD_LOGIC; 
  signal NLW_blk00000001_P_UNCONNECTED : STD_LOGIC; 
  signal NLW_blk00000002_G_UNCONNECTED : STD_LOGIC; 
  signal dividend_0 : STD_LOGIC_VECTOR ( 2 downto 0 ); 
  signal divisor_1 : STD_LOGIC_VECTOR ( 2 downto 0 ); 
  signal quotient_2 : STD_LOGIC_VECTOR ( 2 downto 0 ); 
  signal fractional_3 : STD_LOGIC_VECTOR ( 2 downto 0 ); 
begin
  dividend_0(2) <= dividend(2);
  dividend_0(1) <= dividend(1);
  dividend_0(0) <= dividend(0);
  quotient(2) <= quotient_2(2);
  quotient(1) <= quotient_2(1);
  quotient(0) <= quotient_2(0);
  divisor_1(2) <= divisor(2);
  divisor_1(1) <= divisor(1);
  divisor_1(0) <= divisor(0);
  rfd <= NlwRenamedSig_OI_rfd;
  fractional(2) <= fractional_3(2);
  fractional(1) <= fractional_3(1);
  fractional(0) <= fractional_3(0);
  blk00000001 : VCC
    port map (
      P => NLW_blk00000001_P_UNCONNECTED
    );
  blk00000002 : GND
    port map (
      G => NLW_blk00000002_G_UNCONNECTED
    );
  blk00000003_blk00000068 : INV
    port map (
      I => blk00000003_sig0000001c,
      O => blk00000003_sig0000002d
    );
  blk00000003_blk00000067 : INV
    port map (
      I => blk00000003_sig0000001b,
      O => blk00000003_sig00000030
    );
  blk00000003_blk00000066 : INV
    port map (
      I => blk00000003_sig00000013,
      O => blk00000003_sig00000029
    );
  blk00000003_blk00000065 : INV
    port map (
      I => blk00000003_sig00000011,
      O => blk00000003_sig00000028
    );
  blk00000003_blk00000064 : INV
    port map (
      I => blk00000003_sig00000010,
      O => blk00000003_sig00000054
    );
  blk00000003_blk00000063 : INV
    port map (
      I => blk00000003_sig00000014,
      O => blk00000003_sig00000043
    );
  blk00000003_blk00000062 : LUT3
    generic map(
      INIT => X"6A"
    )
    port map (
      I0 => blk00000003_sig00000059,
      I1 => blk00000003_sig00000025,
      I2 => blk00000003_sig0000005a,
      O => blk00000003_sig0000005d
    );
  blk00000003_blk00000061 : LUT3
    generic map(
      INIT => X"6A"
    )
    port map (
      I0 => blk00000003_sig00000058,
      I1 => blk00000003_sig00000024,
      I2 => blk00000003_sig0000005a,
      O => blk00000003_sig00000062
    );
  blk00000003_blk00000060 : LUT3
    generic map(
      INIT => X"6A"
    )
    port map (
      I0 => blk00000003_sig00000057,
      I1 => blk00000003_sig00000023,
      I2 => blk00000003_sig0000005a,
      O => blk00000003_sig00000068
    );
  blk00000003_blk0000005f : LUT2
    generic map(
      INIT => X"9"
    )
    port map (
      I0 => blk00000003_sig00000048,
      I1 => blk00000003_sig00000010,
      O => blk00000003_sig0000004b
    );
  blk00000003_blk0000005e : LUT3
    generic map(
      INIT => X"69"
    )
    port map (
      I0 => blk00000003_sig00000047,
      I1 => blk00000003_sig00000022,
      I2 => blk00000003_sig00000010,
      O => blk00000003_sig0000004e
    );
  blk00000003_blk0000005d : LUT3
    generic map(
      INIT => X"69"
    )
    port map (
      I0 => blk00000003_sig00000046,
      I1 => blk00000003_sig00000021,
      I2 => blk00000003_sig00000010,
      O => blk00000003_sig00000051
    );
  blk00000003_blk0000005c : LUT3
    generic map(
      INIT => X"69"
    )
    port map (
      I0 => blk00000003_sig00000019,
      I1 => blk00000003_sig00000020,
      I2 => blk00000003_sig00000010,
      O => blk00000003_sig00000055
    );
  blk00000003_blk0000005b : LUT2
    generic map(
      INIT => X"9"
    )
    port map (
      I0 => blk00000003_sig00000037,
      I1 => blk00000003_sig00000014,
      O => blk00000003_sig0000003a
    );
  blk00000003_blk0000005a : LUT3
    generic map(
      INIT => X"69"
    )
    port map (
      I0 => blk00000003_sig00000036,
      I1 => blk00000003_sig0000001f,
      I2 => blk00000003_sig00000014,
      O => blk00000003_sig0000003d
    );
  blk00000003_blk00000059 : LUT3
    generic map(
      INIT => X"69"
    )
    port map (
      I0 => blk00000003_sig00000035,
      I1 => blk00000003_sig0000001e,
      I2 => blk00000003_sig00000014,
      O => blk00000003_sig00000040
    );
  blk00000003_blk00000058 : LUT3
    generic map(
      INIT => X"69"
    )
    port map (
      I0 => blk00000003_sig00000018,
      I1 => blk00000003_sig0000001d,
      I2 => blk00000003_sig00000014,
      O => blk00000003_sig00000044
    );
  blk00000003_blk00000057 : LUT2
    generic map(
      INIT => X"9"
    )
    port map (
      I0 => blk00000003_sig00000026,
      I1 => blk00000003_sig0000001a,
      O => blk00000003_sig00000033
    );
  blk00000003_blk00000056 : LUT1
    generic map(
      INIT => X"1"
    )
    port map (
      I0 => blk00000003_sig0000005a,
      O => blk00000003_sig00000027
    );
  blk00000003_blk00000055 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000066,
      Q => blk00000003_sig0000006c
    );
  blk00000003_blk00000054 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000067,
      Q => blk00000003_sig0000006b
    );
  blk00000003_blk00000053 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000005e,
      Q => fractional_3(2)
    );
  blk00000003_blk00000052 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000063,
      Q => fractional_3(1)
    );
  blk00000003_blk00000051 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000069,
      Q => fractional_3(0)
    );
  blk00000003_blk00000050 : MULT_AND
    port map (
      I0 => blk00000003_sig00000023,
      I1 => blk00000003_sig0000005a,
      LO => blk00000003_sig0000006a
    );
  blk00000003_blk0000004f : MULT_AND
    port map (
      I0 => blk00000003_sig00000024,
      I1 => blk00000003_sig0000005a,
      LO => blk00000003_sig00000064
    );
  blk00000003_blk0000004e : MULT_AND
    port map (
      I0 => blk00000003_sig00000025,
      I1 => blk00000003_sig0000005a,
      LO => blk00000003_sig0000005f
    );
  blk00000003_blk0000004d : MULT_AND
    port map (
      I0 => blk00000003_sig0000000e,
      I1 => blk00000003_sig0000005a,
      LO => blk00000003_sig00000065
    );
  blk00000003_blk0000004c : MUXCY
    port map (
      CI => blk00000003_sig0000000e,
      DI => blk00000003_sig0000006a,
      S => blk00000003_sig00000068,
      O => blk00000003_sig00000061
    );
  blk00000003_blk0000004b : XORCY
    port map (
      CI => blk00000003_sig0000000e,
      LI => blk00000003_sig00000068,
      O => blk00000003_sig00000069
    );
  blk00000003_blk0000004a : XORCY
    port map (
      CI => blk00000003_sig00000060,
      LI => blk00000003_sig0000000e,
      O => blk00000003_sig00000067
    );
  blk00000003_blk00000049 : MUXCY
    port map (
      CI => blk00000003_sig00000060,
      DI => blk00000003_sig00000065,
      S => blk00000003_sig0000000e,
      O => blk00000003_sig00000066
    );
  blk00000003_blk00000048 : MUXCY
    port map (
      CI => blk00000003_sig00000061,
      DI => blk00000003_sig00000064,
      S => blk00000003_sig00000062,
      O => blk00000003_sig0000005c
    );
  blk00000003_blk00000047 : XORCY
    port map (
      CI => blk00000003_sig00000061,
      LI => blk00000003_sig00000062,
      O => blk00000003_sig00000063
    );
  blk00000003_blk00000046 : MUXCY
    port map (
      CI => blk00000003_sig0000005c,
      DI => blk00000003_sig0000005f,
      S => blk00000003_sig0000005d,
      O => blk00000003_sig00000060
    );
  blk00000003_blk00000045 : XORCY
    port map (
      CI => blk00000003_sig0000005c,
      LI => blk00000003_sig0000005d,
      O => blk00000003_sig0000005e
    );
  blk00000003_blk00000044 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000053,
      Q => blk00000003_sig0000005b
    );
  blk00000003_blk00000043 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000004c,
      Q => blk00000003_sig0000005a
    );
  blk00000003_blk00000042 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000004f,
      Q => blk00000003_sig00000059
    );
  blk00000003_blk00000041 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000052,
      Q => blk00000003_sig00000058
    );
  blk00000003_blk00000040 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000056,
      Q => blk00000003_sig00000057
    );
  blk00000003_blk0000003f : MUXCY
    port map (
      CI => blk00000003_sig00000054,
      DI => blk00000003_sig00000019,
      S => blk00000003_sig00000055,
      O => blk00000003_sig00000050
    );
  blk00000003_blk0000003e : XORCY
    port map (
      CI => blk00000003_sig00000054,
      LI => blk00000003_sig00000055,
      O => blk00000003_sig00000056
    );
  blk00000003_blk0000003d : MUXCY
    port map (
      CI => blk00000003_sig0000004a,
      DI => blk00000003_sig00000048,
      S => blk00000003_sig0000004b,
      O => blk00000003_sig00000053
    );
  blk00000003_blk0000003c : MUXCY
    port map (
      CI => blk00000003_sig00000050,
      DI => blk00000003_sig00000046,
      S => blk00000003_sig00000051,
      O => blk00000003_sig0000004d
    );
  blk00000003_blk0000003b : MUXCY
    port map (
      CI => blk00000003_sig0000004d,
      DI => blk00000003_sig00000047,
      S => blk00000003_sig0000004e,
      O => blk00000003_sig0000004a
    );
  blk00000003_blk0000003a : XORCY
    port map (
      CI => blk00000003_sig00000050,
      LI => blk00000003_sig00000051,
      O => blk00000003_sig00000052
    );
  blk00000003_blk00000039 : XORCY
    port map (
      CI => blk00000003_sig0000004d,
      LI => blk00000003_sig0000004e,
      O => blk00000003_sig0000004f
    );
  blk00000003_blk00000038 : XORCY
    port map (
      CI => blk00000003_sig0000004a,
      LI => blk00000003_sig0000004b,
      O => blk00000003_sig0000004c
    );
  blk00000003_blk00000037 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000042,
      Q => blk00000003_sig00000049
    );
  blk00000003_blk00000036 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000003b,
      Q => blk00000003_sig00000010
    );
  blk00000003_blk00000035 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000003e,
      Q => blk00000003_sig00000048
    );
  blk00000003_blk00000034 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000041,
      Q => blk00000003_sig00000047
    );
  blk00000003_blk00000033 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000045,
      Q => blk00000003_sig00000046
    );
  blk00000003_blk00000032 : MUXCY
    port map (
      CI => blk00000003_sig00000043,
      DI => blk00000003_sig00000018,
      S => blk00000003_sig00000044,
      O => blk00000003_sig0000003f
    );
  blk00000003_blk00000031 : XORCY
    port map (
      CI => blk00000003_sig00000043,
      LI => blk00000003_sig00000044,
      O => blk00000003_sig00000045
    );
  blk00000003_blk00000030 : MUXCY
    port map (
      CI => blk00000003_sig00000039,
      DI => blk00000003_sig00000037,
      S => blk00000003_sig0000003a,
      O => blk00000003_sig00000042
    );
  blk00000003_blk0000002f : MUXCY
    port map (
      CI => blk00000003_sig0000003f,
      DI => blk00000003_sig00000035,
      S => blk00000003_sig00000040,
      O => blk00000003_sig0000003c
    );
  blk00000003_blk0000002e : MUXCY
    port map (
      CI => blk00000003_sig0000003c,
      DI => blk00000003_sig00000036,
      S => blk00000003_sig0000003d,
      O => blk00000003_sig00000039
    );
  blk00000003_blk0000002d : XORCY
    port map (
      CI => blk00000003_sig0000003f,
      LI => blk00000003_sig00000040,
      O => blk00000003_sig00000041
    );
  blk00000003_blk0000002c : XORCY
    port map (
      CI => blk00000003_sig0000003c,
      LI => blk00000003_sig0000003d,
      O => blk00000003_sig0000003e
    );
  blk00000003_blk0000002b : XORCY
    port map (
      CI => blk00000003_sig00000039,
      LI => blk00000003_sig0000003a,
      O => blk00000003_sig0000003b
    );
  blk00000003_blk0000002a : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000032,
      Q => blk00000003_sig00000038
    );
  blk00000003_blk00000029 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000002b,
      Q => blk00000003_sig00000014
    );
  blk00000003_blk00000028 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000002e,
      Q => blk00000003_sig00000037
    );
  blk00000003_blk00000027 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000031,
      Q => blk00000003_sig00000036
    );
  blk00000003_blk00000026 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000034,
      Q => blk00000003_sig00000035
    );
  blk00000003_blk00000025 : MUXCY
    port map (
      CI => NlwRenamedSig_OI_rfd,
      DI => blk00000003_sig00000026,
      S => blk00000003_sig00000033,
      O => blk00000003_sig0000002f
    );
  blk00000003_blk00000024 : XORCY
    port map (
      CI => NlwRenamedSig_OI_rfd,
      LI => blk00000003_sig00000033,
      O => blk00000003_sig00000034
    );
  blk00000003_blk00000023 : MUXCY
    port map (
      CI => blk00000003_sig0000002a,
      DI => blk00000003_sig0000000e,
      S => NlwRenamedSig_OI_rfd,
      O => blk00000003_sig00000032
    );
  blk00000003_blk00000022 : MUXCY
    port map (
      CI => blk00000003_sig0000002f,
      DI => blk00000003_sig0000000e,
      S => blk00000003_sig00000030,
      O => blk00000003_sig0000002c
    );
  blk00000003_blk00000021 : MUXCY
    port map (
      CI => blk00000003_sig0000002c,
      DI => blk00000003_sig0000000e,
      S => blk00000003_sig0000002d,
      O => blk00000003_sig0000002a
    );
  blk00000003_blk00000020 : XORCY
    port map (
      CI => blk00000003_sig0000002f,
      LI => blk00000003_sig00000030,
      O => blk00000003_sig00000031
    );
  blk00000003_blk0000001f : XORCY
    port map (
      CI => blk00000003_sig0000002c,
      LI => blk00000003_sig0000002d,
      O => blk00000003_sig0000002e
    );
  blk00000003_blk0000001e : XORCY
    port map (
      CI => blk00000003_sig0000002a,
      LI => NlwRenamedSig_OI_rfd,
      O => blk00000003_sig0000002b
    );
  blk00000003_blk0000001d : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000029,
      Q => quotient_2(2)
    );
  blk00000003_blk0000001c : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000028,
      Q => quotient_2(1)
    );
  blk00000003_blk0000001b : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000027,
      Q => quotient_2(0)
    );
  blk00000003_blk0000001a : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => dividend_0(2),
      Q => blk00000003_sig00000026
    );
  blk00000003_blk00000019 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => dividend_0(1),
      Q => blk00000003_sig00000017
    );
  blk00000003_blk00000018 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => dividend_0(0),
      Q => blk00000003_sig00000015
    );
  blk00000003_blk00000017 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000022,
      Q => blk00000003_sig00000025
    );
  blk00000003_blk00000016 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000021,
      Q => blk00000003_sig00000024
    );
  blk00000003_blk00000015 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000020,
      Q => blk00000003_sig00000023
    );
  blk00000003_blk00000014 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000001f,
      Q => blk00000003_sig00000022
    );
  blk00000003_blk00000013 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000001e,
      Q => blk00000003_sig00000021
    );
  blk00000003_blk00000012 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000001d,
      Q => blk00000003_sig00000020
    );
  blk00000003_blk00000011 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000001c,
      Q => blk00000003_sig0000001f
    );
  blk00000003_blk00000010 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000001b,
      Q => blk00000003_sig0000001e
    );
  blk00000003_blk0000000f : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig0000001a,
      Q => blk00000003_sig0000001d
    );
  blk00000003_blk0000000e : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => divisor_1(2),
      Q => blk00000003_sig0000001c
    );
  blk00000003_blk0000000d : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => divisor_1(1),
      Q => blk00000003_sig0000001b
    );
  blk00000003_blk0000000c : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => divisor_1(0),
      Q => blk00000003_sig0000001a
    );
  blk00000003_blk0000000b : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000016,
      Q => blk00000003_sig00000019
    );
  blk00000003_blk0000000a : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000017,
      Q => blk00000003_sig00000018
    );
  blk00000003_blk00000009 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000015,
      Q => blk00000003_sig00000016
    );
  blk00000003_blk00000008 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000014,
      Q => blk00000003_sig00000012
    );
  blk00000003_blk00000007 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000012,
      Q => blk00000003_sig00000013
    );
  blk00000003_blk00000006 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk,
      D => blk00000003_sig00000010,
      Q => blk00000003_sig00000011
    );
  blk00000003_blk00000005 : VCC
    port map (
      P => NlwRenamedSig_OI_rfd
    );
  blk00000003_blk00000004 : GND
    port map (
      G => blk00000003_sig0000000e
    );

end STRUCTURE;

-- synthesis translate_on
