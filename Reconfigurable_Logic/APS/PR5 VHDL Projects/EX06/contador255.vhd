library ieee;
use ieee.std_logic_1164.all;

entity contador255 is
	port( seletor, reset: in std_logic;
			saida: out integer range 0 to 255 );
end contador255;

architecture Behavioral of contador255 is

	begin
		process (seletor)
			variable i : integer range 0 to 255 := 0;
			begin
				if (reset='1' or i>255) then
					i := 0;
				elsif (seletor='1' and seletor'event) then
					i := i + 1;
				end if;
				saida <= i;
		end process;
end Behavioral;