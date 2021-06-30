library IEEE;
use IEEE.STD_LOGIC_1164.all;

package meupacote02 is

	component clkgen2 is
		port(mclk, reset: in std_logic;
			clk1: out std_logic );
	end component;

	component clkgen4 is
		port(mclk, reset: in std_logic;
			clk2: out std_logic );
	end component;
	
	component clkgen8 is
		port(mclk, reset: in std_logic;
			clk3: out std_logic );
	end component;
	
	component clkgen16 is
		port(mclk, reset: in std_logic;
			clk4: out std_logic );
	end component;
	
end package;