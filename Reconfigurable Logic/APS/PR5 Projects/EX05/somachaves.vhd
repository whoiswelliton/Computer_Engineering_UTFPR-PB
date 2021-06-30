library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;
use work.meupacote05.all;

entity somachaves is

	port( soma: inout std_logic_vector(11 downto 0);
			chaves: in std_logic_vector(7 downto 0);
			saida3: out integer range 0 to 15;
			saida2: out integer range 0 to 15;
			saida1: out integer range 0 to 15 );
end somachaves;

architecture Behavioral of somachaves is

	begin
		soma <= to_bcd( chaves );
		saida3 <= to_integer(unsigned( soma(11 downto 8) ));
		saida2 <= to_integer(unsigned( soma(7 downto 4) ));
		saida1 <= to_integer(unsigned( soma(3 downto 0) ));
		
end Behavioral;