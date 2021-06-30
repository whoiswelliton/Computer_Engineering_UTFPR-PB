--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:40:45 12/12/2019
-- Design Name:   
-- Module Name:   C:/Xilinx/Projects/PR5/EX01/tb_clkgen.vhd
-- Project Name:  EX01
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: clkgen1
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_clkgen IS
END tb_clkgen;
 
ARCHITECTURE behavior OF tb_clkgen IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT clkgen1
    PORT(
         mclk : IN  std_logic;
         reset : IN  std_logic;
         clk : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal mclk : std_logic := '0';
   signal reset : std_logic := '0';

 	--Outputs
   signal clk : std_logic;

   -- Clock period definitions
   constant mclk_period : time := 10 ns;
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: clkgen1 PORT MAP (
          mclk => mclk,
          reset => reset,
          clk => clk
        );

   -- Clock process definitions
   mclk_process :process
   begin
		mclk <= '0';
		wait for mclk_period/2;
		mclk <= '1';
		wait for mclk_period/2;
   end process;
 
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for mclk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
