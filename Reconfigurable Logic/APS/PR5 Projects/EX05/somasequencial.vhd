library ieee;
use ieee.std_logic_1164.all;

use work.meu_pacote05.all;

entity somasequencial is
	generic (N : integer);
	port( chaves: in std_logic_vector (7 downto 0);
			soma: out integer range 0 to 255 );
end entity;

architecture Behavioral of somasequencial is

	process( chaves )

		variable i: integer range 0 to 255 := 0;

		begin
			for j in 0 to 7 loop
				if (chaves(j) = '1') then i := i + 2**j;
				end if;
			end loop;
			i <= soma;
	end process;
	
end Behavioral;