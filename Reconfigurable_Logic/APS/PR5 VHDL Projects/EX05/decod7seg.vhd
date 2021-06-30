library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.meupacote05.all;

entity decod7seg is

	GENERIC (N : integer := 3);
	port( chaves: in std_logic_vector(3 downto 0);
			chaves_display: in std_logic_vector(3 downto 0);
			anodos: out std_logic_vector(3 downto 0);
			catodos: out std_logic_vector(0 to 7) );
end decod7seg;

architecture Behavioral of decod7seg is

	begin
		anodos <=not(chaves_display);		catodos<=not("11111100") when chaves = "0000" else -- 0
					not("01100000") when chaves = "0001" else -- 1
					not("11011010") when chaves = "0010" else -- 2
					not("11110010") when chaves = "0011" else -- 3
					not("01100110") when chaves = "0100" else -- 4
					not("10110110") when chaves = "0101" else -- 5
					not("10111110") when chaves = "0110" else -- 6
					not("11100000") when chaves = "0111" else -- 7	
					not("11111110") when chaves = "1000" else -- 8
					not("11110110") when chaves = "1001" else -- 9
					not("11101110") when chaves = "1010" else -- A
					not("00111110") when chaves = "1011" else -- b
					not("10011100") when chaves = "1100" else -- C
					not("01111010") when chaves = "1101" else -- d
					not("10011110") when chaves = "1110" else -- E
					not("10001110") when chaves = "1111"; -- F
					--not("11100000"); -- F
end Behavioral;