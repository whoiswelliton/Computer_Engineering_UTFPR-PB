library IEEE;
use IEEE.STD_LOGIC_1164.all;

package meupacote04 is

	component clkgen2 is
		port(mclk, reset: in std_logic;
			clk1: out std_logic);
	end component;

	component clkgen4 is
		port(mclk, reset: in std_logic;
			clk2: out std_logic);
	end component;
	
	component mux2x1 is
		port( seletor: in std_logic;
				entrada1: in integer range 0 to 15;
				entrada2: in integer range 0 to 15;
				saida: out integer range 0 to 15);
	end component;
	
	component dem2x4 is
		port( aux3 : in std_logic_vector(1 downto 0);
				aux4 : out std_logic_vector(3 downto 0));
	end component;

	component decod7seg is
		GENERIC (N : integer := 3);
		port( chaves: in std_logic_vector(3 downto 0);
				chaves_display: in std_logic_vector(3 downto 0);
				anodos: out std_logic_vector(3 downto 0);
				catodos: out std_logic_vector(0 to 7));
	end component;
	
end package;