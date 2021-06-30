library IEEE;
use IEEE.STD_LOGIC_1164.all;

package meupacote03 is

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
	
	component decod7seg is
		GENERIC (N : integer := 3);
		port( chaves: in std_logic_vector(N-1 downto 0);
				anodos: out std_logic_vector(N-1 downto 0);
				catodos: out std_logic_vector(0 to 7));
	end component;
	
end package;